#include "Codegen.h"

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>

namespace AST {
//递归调用子节点的codegen
llvm::Value* Program::CodeGen(Codegen& __Generator) {
  for (auto stmt : *(this->stmts)) {
    if (stmt) {
      stmt->CodeGen(__Generator);
    }
  }
  return nullptr;
}

llvm::Value* Fundecl::CodeGen(Codegen& __Generator) {
  std::vector<llvm::Type*> ArgTypes;
  for (auto Argtype : *(this->Arg_list)) {
    llvm::Type* LLVMTy = Argtype->var_type->GetLLVMType(__Generator);
    //如果是数组，传指针，数组语法还没实现
    if (LLVMTy->isArrayTy()) {
      LLVMTy = LLVMTy->getPointerTo();
    }
    ArgTypes.push_back(LLVMTy);
  }
  //获得返回类型
  llvm::Type* RetTy = this->Retype->GetLLVMType(__Generator);
  //得到函数类型
  llvm::FunctionType* FuncType = llvm::FunctionType::get(RetTy, ArgTypes, this->Arg_list->_VarArg);
  //得到函数
  llvm::Function* Func
      = llvm::Function::Create(FuncType, llvm::GlobalValue::ExternalLinkage, this->Func_name, __Generator.Module);
  //如果存在funbody
  if (this->Func_body) {
    llvm::BasicBlock* FuncBlock = llvm::BasicBlock::Create(Context, "entry", Func);
    IR_Builder.SetInsertPoint(FuncBlock);
    __Generator.AddSymbolTable();
    //后面没看懂在干什么
    size_t Index = 0;
    for (auto ArgItor = Func->arg_begin(); ArgItor < Func->arg_end(); ArgItor++, Index++) {
      //If the argument is an array, just use its pointer.
      //Otherwise, create an alloca.
      if (this->Arg_list->at(Index)->var_type->GetLLVMType(__Generator)->isArrayTy()) {
        __Generator.AddVariable(this->Arg_list->at(Index)->id, ArgItor);
      } else {
        //Create alloca
        auto Alloc = CreateEntryBlockAlloca(Func, this->Arg_list->at(Index)->id, ArgTypes[Index]);
        //Assign the value by "store" instruction
        IR_Builder.CreateStore(ArgItor, Alloc);
        //Add to the symbol table
        __Generator.AddVariable(this->Arg_list->at(Index)->id, Alloc);
      }
    }
    //
    __Generator.EnterFunction(Func);

    this->Func_body->CodeGen(__Generator);
    //为没有返回语句的函数体创建默认返回语句
    if (!IR_Builder.GetInsertBlock()->getTerminator()) {
      llvm::Type* RetTy = __Generator.GetCurrentFunction()->getReturnType();
      if (RetTy->isVoidTy()) {
        IR_Builder.CreateRetVoid();
      } else {
        IR_Builder.CreateRet(llvm::UndefValue::get(RetTy));
      }
    }

    __Generator.LeaveCurrentFunction();
    __Generator.DeleteSymbolTable();
  }
  return nullptr;
}

llvm::Value* Block ::CodeGen(Codegen& __Generator) {
  //调用block中每个语句的codegen
  __Generator.AddSymbolTable();
  for (auto& stmt : *(this->statements)) {
    if (IR_Builder.GetInsertBlock()->getTerminator()) {
      break;
    }
    stmt->CodeGen(__Generator);
  }
  __Generator.DeleteSymbolTable();
  return nullptr;
}

llvm::Value* Vardecl::CodeGen(Codegen& __Generator) {
  llvm::Type* vartype = this->type->GetLLVMType(__Generator);

  for (auto* var : *(this->var_list)) {
    if (__Generator.GetCurrentFunction()) {
      auto Alloc = CreateEntryBlockAlloca(__Generator.GetCurrentFunction(), var->name, vartype);
      //Assign the initial value by "store" instruction.
      if (var->Assign_Exp) {
        llvm::Value* Initializer = TypeCasting(var->Assign_Exp->CodeGen(__Generator), vartype);
        if (Initializer == NULL) {
          throw std::logic_error("Initializing variable " + var->name + " with value of different type.");
          return NULL;
        }
        IR_Builder.CreateStore(Initializer, Alloc);
      }
    } else {
      //todo:创建全局变量
      llvm::Constant* Initializer = NULL;
      if (var->Assign_Exp) {
        //Global variable must be initialized (if any) by a constant.
        __Generator.ExchangeInsertPoint();
        auto TmpBBSize           = IR_Builder.GetInsertBlock()->size();
        llvm::Value* InitialExpr = TypeCasting(var->Assign_Exp->CodeGen(__Generator), vartype);
        __Generator.ExchangeInsertPoint();
        Initializer = (llvm::Constant*)InitialExpr;
      } else {
        //We must create an undef value manually. If no initializer is given,
        //this global value will be recognized as "extern" by llvm.
        Initializer = llvm::UndefValue::get(VarType);
      }
      //Create a global variable
      auto Alloc = new llvm::GlobalVariable(
          *(__Generator.Module), vartype, false, llvm::Function::ExternalLinkage, Initializer, var->id);
      if (!__Generator.AddVariable(var->name, Alloc)) {
        throw std::logic_error("Redefining global variable " + var->id + ".");
        Alloc->eraseFromParent();
        return NULL;
      }
    }
  }
  return nullptr;
}

llvm::Value* ConditionStmt::CodeGen(Codegen& __Generator) {
  llvm::Value* Condition = this->C_Expression->CodeGen(__Generator);
  //Cast the type to i1
  if (!(Condition = Cast2I1(Condition))) {
    throw std::logic_error(
        "The condition value of if-statement must be either an integer, or a floating-point number, or a pointer.");
    return NULL;
  }
  //创建三个block，first,mid,last
  llvm::Function* CurrentFunc = __Generator.GetCurrentFunction();
  llvm::BasicBlock* TrueBB    = llvm::BasicBlock::Create(Context, "TrueBB");
  llvm::BasicBlock* FalseBB   = llvm::BasicBlock::Create(Context, "FalseBB ");
  llvm::BasicBlock* MergeBB   = llvm::BasicBlock::Create(Context, "Merge");
  //创建条件分支
  IR_Builder.CreateCondBr(Condition, TrueBB, FalseBB);
  CurrentFunc->getBasicBlockList().push_back(TrueBB);
  IR_Builder.SetInsertPoint(TrueBB);
  if (this->stmt1) {
    __Generator.AddSymbolTable();
    this->stmt1->codeGen(__Generator);
    __Generator->DeleteSymbolTable();
  }
  TerminateBlockByBr(MergeBB);
  CurrentFunc->getBasicBlockList().push_back(FalseBB);
  IR_Builder.SetInsertPoint(FalseBB);
  if (this->stmt2) {
    __Generator.AddSymbolTable();
    this->stmt2->codeGen(__Generator);
    __Generator->DeleteSymbolTable();
  }
  TerminateBlockByBr(MergeBB);
  if (MergeBB->hasNPredecessorsOrMore(1)) {
    CurrentFunc->getBasicBlockList().push_back(MergeBB);
    IR_Builder.SetInsertPoint(MergeBB);
  }
  return NULL;
}

llvm::Value* WhileStmt::CodeGen(Codegen& __Generator) {
  llvm::Function* CurrentFunc = __Generator.GetCurrentFunction();
  llvm::BasicBlock* CondBB    = llvm::BasicBlock::Create(Context, "WhileCond");
  llvm::BasicBlock* LoopBB    = llvm::BasicBlock::Create(Context, "WhileLoop");
  llvm::BasicBlock* EndBB     = llvm::BasicBlock::Create(Context, "WhileEnd");
  //Create an unconditional branch, jump to "WhileCond" block.
  IR_Builder.CreateBr(CondBB);

  CurrentFunc->getBasicBlockList().push_back(CondBB);
  IR_Builder.SetInsertPoint(CondBB);
  llvm::Value* Condition = this->C_Expression->CodeGen(__Generator);
  if (!(Condition = Cast2I1(Condition))) {
    throw std::logic_error(
        "The condition value of while-statement must be either an integer, or a floating-point number, or a pointer.");
    return NULL;
  }
  IR_Builder.CreateCondBr(Condition, LoopBB, EndBB);
  //Generate code in the "WhileLoop" block
  CurrentFunc->getBasicBlockList().push_back(LoopBB);
  IRBuilder.SetInsertPoint(LoopBB);
  if (this->_LoopBody) {
    __Generator.EnterLoop(CondBB, EndBB);  //Don't forget to call "EnterLoop"
    __Generator.AddSymbolTable();
    this->_LoopBody->CodeGen(__Generator);
    __Generator.DeleteSymbolTable();
    __Generator.LeaveLoop();  //Don't forget to call "LeaveLoop"
  }
  TerminateBlockByBr(CondBB);
  //Finish "WhileEnd" block
  CurrentFunc->getBasicBlockList().push_back(EndBB);
  IR_Builder.SetInsertPoint(EndBB);
  return NULL;
}

llvm::Value* DoStmt::CodeGen(Codegen __Generator) {
  llvm::Function* CurrentFunc = __Generator.GetCurrentFunction();
  llvm::BasicBlock* LoopBB    = llvm::BasicBlock::Create(Context, "DoLoop");
  llvm::BasicBlock* CondBB    = llvm::BasicBlock::Create(Context, "DoCond");
  llvm::BasicBlock* EndBB     = llvm::BasicBlock::Create(Context, "DoEnd");
  IR_Builder.CreateBr(LoopBB);

  CurrentFunc->getBasicBlockList().push_back(LoopBB);
  IR_Builder.SetInsertPoint(LoopBB);
  if (this->Loopbody) {
    __Generator.EnterLoop(CondBB, EndBB);
    this->Loopbody->CodeGen(__Generator);
    __Generator.DeleteSymbolTable();
    __Generator.LeaveLoop();
  }
  TerminateBlockByBr(CondBB);

  CurrentFunc->getBasicBlockList().push_back(CondBB);
  IRBuilder.SetInsertPoint(CondBB);
  llvm::Value* Condition = this->C_Expression->CodeGen(__Generator);
  if (!(Condition = Cast2I1(Condition))) {
    throw std::logic_error(
        "The condition value of do-statement must be either an integer, or a floating-point number, or a pointer.");
    return NULL;
  }
  IR_Builder.CreateCondBr(Condition, LoopBB, EndBB);

  CurrentFunc->getBasicBlockList().push_back(EndBB);
  IR_Builder.SetInsertPoint(EndBB);
  return NULL;
}

llvm::Value* ForStmt::CodeGen(Codegen& __Generator) {
  //Create "ForCond", "ForLoop", "ForTail" and "ForEnd"
  llvm::Function* CurrentFunc = __Generator.GetCurrentFunction();
  llvm::BasicBlock* CondBB    = llvm::BasicBlock::Create(Context, "ForCond");
  llvm::BasicBlock* LoopBB    = llvm::BasicBlock::Create(Context, "ForLoop");
  llvm::BasicBlock* TailBB    = llvm::BasicBlock::Create(Context, "ForTail");
  llvm::BasicBlock* EndBB     = llvm::BasicBlock::Create(Context, "ForEnd");
  //Evaluate the initial statement, and create an unconditional branch to "ForCond" block
  //Since we allow variable declarations here, we need to push a new symbol table
  //e.g., for (int i = 0; ...; ...) { ... }
  if (this->Init) {
    __Generator.AddSymbolTable();
    this->Init->CodeGen(__Generator);
  }
  TerminateBlockByBr(CondBB);
  //Generate code in the "ForCond" block
  CurrentFunc->getBasicBlockList().push_back(CondBB);
  IR_Builder.SetInsertPoint(CondBB);
  if (this->C_Expression) {
    //If it has a loop condition, evaluate it (cast the type to i1 if necessary).
    llvm::Value* Condition = this->C_Expression->CodeGen(__Generator);
    if (!(Condition = Cast2I1(Condition))) {
      throw std::logic_error(
          "The condition value of for-statement must be either an integer, or a floating-point number, or a pointer.");
      return NULL;
    }
    IR_Builder.CreateCondBr(Condition, LoopBB, EndBB);
  } else {
    //Otherwise, it is an unconditional loop condition (always returns true)
    IR_Builder.CreateBr(LoopBB);
  }
  //Generate code in the "ForLoop" block
  CurrentFunc->getBasicBlockList().push_back(LoopBB);
  IR_Builder.SetInsertPoint(LoopBB);
  if (this->Loopbody) {
    __Generator.EnterLoop(TailBB, EndBB);  //Don't forget to call "EnterLoop"
    __Generator.AddSymbolTable();
    this->Loopbody->CodeGen(__Generator);
    __Generator.DeleteSymbolTable();
    __Generator.LeaveLoop();  //Don't forget to call "LeaveLoop"
  }
  //If not terminated, jump to "ForTail"
  TerminateBlockByBr(TailBB);
  //Generate code in the "ForTail" block
  CurrentFunc->getBasicBlockList().push_back(TailBB);
  IR_Builder.SetInsertPoint(TailBB);
  if (this->then) {
    this->then->CodeGen(__Generator);
  }
  IR_Builder.CreateBr(CondBB);
  //Finish "ForEnd" block
  CurrentFunc->getBasicBlockList().push_back(EndBB);
  IR_Builder.SetInsertPoint(EndBB);
  if (this->Init) {
    __Generator.DeleteSymbolTable();
  }
  return NULL;
}

llvm::Value* SwitchStmt::CodeGen(Codegen& __Generator) {
  llvm::Function* CurrentFunc = __Generator.GetCurrentFunction();
  llvm::Value* Matcher        = this->To_match->CodeGen(__Generator);
  std::vector<llvm::BasicBlock*> CaseBB;
  //把每个case压栈
  for (int i = 0; i < this->case_list->size(); i++) {
    CaseBB.push_back(llvm::BasicBlock::Create(Context, "Case" + std::to_string(i)));
  }

  CaseBB.push_back(llvm::BasicBlock::Create(Context, "SwitchEnd"));

  std::vector<llvm::BasicBlock*> ComparisonBB;
  ComparisonBB.push_back(IR_Builder.GetInsertBlock());
  for (int i = 1; i < this->case_list->size(); i++) {
    ComparisonBB.push_back(llvm::BasicBlock::Create(Context, "Comparison" + std::to_string(i)));
  }
  ComparisonBB.push_back(CaseBB.back());
  //生成分支
  for (int i = 0; i < this->case_list->size(); i++) {
    if (i) {
      CurrentFunc->getBasicBlockList().push_back(ComparisonBB[i]);
      IR_Builder.SetInsertPoint(ComparisonBB[i]);
    }
    if (this->case_list->at(i)->C_Expression) {  //Have condition
      IR_Builder.CreateCondBr(CreateCmpEQ(Matcher, this->case_list->at(i)->C_Expression->CodeGen(__Generator)),
                              CaseBB[i],
                              ComparisonBB[i + 1]);
    } else {  //Default
      IRBuilder.CreateBr(CaseBB[i]);
    }
  }

  //生成code
  __Generator.AddSymbolTable();
  for (int i = 0; i < this->case_list->size(); i++) {
    CurrentFunc->getBasicBlockList().push_back(CaseBB[i]);
    IR_Builder.SetInsertPoint(CaseBB[i]);
    __Generator.EnterLoop(CaseBB[i + 1], CaseBB.back());
    this->case_list->at(i)->CodeGen(__Generator);
    __Generator.LeaveLoop();
  }
  __Generator.DeleteSymbolTable
      //Finish "SwitchEnd" block
      if (CaseBB.back()->hasNPredecessorsOrMore(1)) {
    CurrentFunc->getBasicBlockList().push_back(CaseBB.back());
    IR_Builder.SetInsertPoint(CaseBB.back());
  }
  return NULL;
}

llvm::Value* CaseStmt::CodeGen(CodeGenerator& __Generator) {
  //生成每个语句
  for (auto& Stmt : *(this->Content)) {
    if (IR_Builder.GetInsertBlock()->getTerminator()) {
      break;
    } else if (Stmt) {  //We allow empty-statement which is represented by NULL pointer.
      Stmt->CodeGen(__Generator);
    }
  }
  //If not terminated, jump to the next case block
  TerminateBlockByBr(__Generator.GetContinueBlock());
  return NULL;
}

llvm::Value* ContinueStmt::CodeGen(CodeGenerator& __Generator) {
  llvm::BasicBlock* ContinueTarget = __Generator.GetContinueBlock();
  if (ContinueTarget) {
    IR_Builder.CreateBr(ContinueTarget);
  } else {
    throw std::logic_error("Continue statement should only be used in loops or switch statements.");
  }
  return NULL;
}

llvm::Value* BreakStmt::CodeGen(CodeGenerator& __Generator) {
  llvm::BasicBlock* BreakTarget = __Generator.GetBreakBlock();
  if (BreakTarget) {
    IR_Builder.CreateBr(BreakTarget);
  } else {
    throw std::logic_error("Break statement should only be used in loops or switch statements.");
  }
  return NULL;
}

llvm::Value* ReturnStmt::CodeGen(CodeGenerator& __Generator) {
  llvm::Function* Func = __Generator.GetCurrentFunction();
  if (this->To_return == NULL) {
    if (Func->getReturnType()->isVoidTy()) {
      IR_Builder.CreateRetVoid();
    } else {
      throw std::logic_error("Expected an expression after return statement.");
      return NULL;
    }
  } else {
    llvm::Value* RetVal = TypeCasting(this->To_return->CodeGen(__Generator), Func->getReturnType());
    if (!RetVal) {
      throw std::logic_error("The type of return value doesn't match and cannot be cast to the return type.");
      return NULL;
    }
    IR_Builder.CreateRet(RetVal);
  }
}

llvm::Type* Vartype::GetLLVMType(Codegen& __Generator)
{
    // 如果类型已知，则直接返回
    if (this->_LLVMType)
    {
        return this->_LLVMType;
    }
    // 类型未知，则根据不同情况返回
    switch (this->_Type) 
    {
		case _Bool: this->_LLVMType = IRBuilder.getInt1Ty(); break;
		case _Short: this->_LLVMType = IRBuilder.getInt16Ty(); break;
		case _Int: this->_LLVMType = IRBuilder.getInt32Ty(); break;
		case _Long: this->_LLVMType = IRBuilder.getInt64Ty(); break;
		case _Char: this->_LLVMType = IRBuilder.getInt8Ty(); break;
		case _Float: this->_LLVMType = IRBuilder.getFloatTy(); break;
		case _Double: this->_LLVMType = IRBuilder.getDoubleTy(); break;
		case _Void: this->_LLVMType = IRBuilder.getVoidTy(); break;
		default: break;
	}
	return this->_LLVMType;
}


// 函数调用
llvm::Value* FunctionCall::CodeGen(CodeGenerator& __Generator) {
	// 查找函数名对应的函数
	llvm::Function* func = __Generator.FindFunction(this->name);
	if (func == NULL) {
		throw std::domain_error(this->name + " dosen't exist\n");
		return NULL;
	}
	// 检查参数
	if (func->isVarArg() && this->arglist->size() < func->arg_size() ||
		!func->isVarArg() && this->arglist->size() != func->arg_size()) {
		throw std::invalid_argument("Args doesn't match when calling function " + this->_FuncName + ".\n Expected " + std::to_string(Func->arg_size()) + ", got " + std::to_string(this->_ArgList->size()));
		return NULL;
	}
	// 检查参数类型
	std::vector<llvm::Value*> ArgList;
	size_t Index = 0;
	for (auto ArgIter = func->arg_begin(); ArgIter < func->arg_end(); ArgIter++, Index++) {
		llvm::Value* Arg = this->arglist->at(Index)->CodeGen(__Generator);
		Arg = TypeCasting(Arg, ArgIter->getType());
		if (Arg == NULL) {
			throw std::invalid_argument(std::to_string(Index) + "-th arg type doesn't match when calling function " + this->_FuncName + ".");
			return NULL;
		}
		ArgList.push_back(Arg);
	}
	// 继续读取参数
	if (func->isVarArg())
		for (; Index < this->_ArgList->size(); Index++) {
			llvm::Value* Arg = this->_ArgList->at(Index)->CodeGen(__Generator);
			ArgList.push_back(Arg);
		}
	// 创建函数调用
	return IRBuilder.CreateCall(func, ArgList);
}

// 除法 /
llvm::Value* Div::CodeGen(CodeGenerator& __Generator) {
	llvm::Value* LHS = this->lhs->CodeGen(__Generator);
	llvm::Value* RHS = this->rhs->CodeGen(__Generator);
	return CreateDiv(LHS, RHS, __Generator);
}

// 乘法 *
llvm::Value* Mul::CodeGen(CodeGenerator& __Generator) {
	llvm::Value* LHS = this->lhs->CodeGen(__Generator);
	llvm::Value* RHS = this->rhs->CodeGen(__Generator);
	return CreateMul(LHS, RHS, __Generator);
}

// 加法 +
llvm::Value* Plus::CodeGen(CodeGenerator& __Generator) {
	llvm::Value* LHS = this->lhs->CodeGen(__Generator);
	llvm::Value* RHS = this->rhs->CodeGen(__Generator);
	return CreateAdd(LHS, RHS, __Generator);
}

// 减法 - 
llvm::Value* Sub::CodeGen(CodeGenerator& __Generator) {
	llvm::Value* LHS = this->lhs->CodeGen(__Generator);
	llvm::Value* RHS = this->rhs->CodeGen(__Generator);
	return CreateSub(LHS, RHS, __Generator);
}

// 余数除法 %
llvm::Value* Mod::CodeGen(CodeGenerator& __Generator) {
	llvm::Value* LHS = this->lhs->CodeGen(__Generator);
	llvm::Value* RHS = this->rhs->CodeGen(__Generator);
	return CreateMod(LHS, RHS, __Generator);
}

// 与 &
llvm::Value* And::CodeGen(CodeGenerator& __Generator) {
	llvm::Value* LHS = this->lhs->CodeGen(__Generator);
	llvm::Value* RHS = this->rhs->CodeGen(__Generator);
	return CreateBitwiseAND(LHS, RHS, __Generator);
}

// 或 |
llvm::Value* Or::CodeGen(CodeGenerator& __Generator) {
	llvm::Value* LHS = this->lhs->CodeGen(__Generator);
	llvm::Value* RHS = this->rhs->CodeGen(__Generator);
	return CreateBitwiseOR(LHS, RHS, __Generator);
}

// 相等 ==
llvm::Value* Equ::CodeGen(CodeGenerator& __Generator) {
	llvm::Value* LHS = this->_LHS->CodeGen(__Generator);
	llvm::Value* RHS = this->_RHS->CodeGen(__Generator);
	return CreateCmpEQ(LHS, RHS);
}

// 不相等 != 
llvm::Value* Ne::CodeGen(CodeGenerator& __Generator) {
	llvm::Value* LHS = this->lhs->CodeGen(__Generator);
	llvm::Value* RHS = this->rhs->CodeGen(__Generator);
	return IRBuilder.CreateICmpNE(LHS, RHS);
}

// 小于 <
llvm::Value* Lt::CodeGen(CodeGenerator& __Generator) {
	llvm::Value* LHS = this->lhs->CodeGen(__Generator);
	llvm::Value* RHS = this->rhs->CodeGen(__Generator);
	return IRBuilder.CreateICmpSLT(LHS, RHS);
}

// 小于等于 <=
llvm::Value* Le::CodeGen(CodeGenerator& __Generator) {
	llvm::Value* LHS = this->lhs->CodeGen(__Generator);
	llvm::Value* RHS = this->rhs->CodeGen(__Generator);
	return IRBuilder.CreateICmpSLE(LHS, RHS);
}

// 大于 > 
llvm::Value* Gt::CodeGen(CodeGenerator& __Generator) {
	llvm::Value* LHS = this->lhs->CodeGen(__Generator);
	llvm::Value* RHS = this->rhs->CodeGen(__Generator);
	return IRBuilder.CreateICmpSGT(LHS, RHS);
}

// 大于等于 >=
llvm::Value* Ge::CodeGen(CodeGenerator& __Generator) {
	llvm::Value* LHS = this->lhs->CodeGen(__Generator);
	llvm::Value* RHS = this->rhs->CodeGen(__Generator);
	return IRBuilder.CreateICmpSGE(LHS, RHS);
}

// 赋值 =
llvm::Value* AssignNode::CodeGen(CodeGenerator& __Generator) {
	return CreateLoad(this->CodeGenPtr(__Generator), __Generator);
}
llvm::Value* DirectAssign::CodeGenPtr(CodeGenerator& __Generator) {
	llvm::Value* LHS = this->lhs->CodeGenPtr(__Generator);
	llvm::Value* RHS = this->rhs->CodeGen(__Generator);
	return CreateAssignment(LHS, RHS, __Generator);
}

// 取地址
llvm::Value* Getaddress::CodeGen(CodeGenerator& __Generator) {
		return this->_Operand->CodeGenPtr(__Generator);
}

// 否 ~
llvm::Value* LogicNot::CodeGen(CodeGenerator& __Generator) {
	return IRBuilder.CreateICmpEQ(this->_Operand->CodeGen(__Generator), IRBuilder.getInt1(false));
}

// 常量
llvm::Value* constant::CodeGen(CodeGenerator& __Generator) {
	switch (this->_Type) {
	case BuiltInType::Types::_Bool:
		return IRBuilder.getInt1(this->_bool);
	case BuiltInType::Types::_Char:
		return IRBuilder.getInt8(this->_char);
	case BuiltInType::Types::_Int:
		return IRBuilder.getInt32(this->_int);
	case BuiltInType::Types::_Double:
		return llvm::ConstantFP::get(IRBuilder.getDoubleTy(), this->_double);
	}
}

// 变量
llvm::Value* Id::CodeGen(CodeGenerator& __Generator) {
	// 查找变量
	llvm::Value* VarPtr = __Generator.FindVal(this->name);
	if (VarPtr) return CreateLoad(VarPtr, __Generator);
	VarPtr = __Generator.FindConst(this->name);
	if (VarPtr) return VarPtr;
	throw std::logic_error("Identifier \"" + this->name + "\" is neither a variable nor a constant.");
	return NULL;
}
}  // namespace AST