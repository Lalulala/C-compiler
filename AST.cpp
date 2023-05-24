#include "Codegen.h"
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>



namespace AST{
  //递归调用子节点的codegen
llvm::Value* Program::CodeGen(Codegen& __Generator) {
      for(auto stmt:*(this->stmts)){
          if(stmt){
            stmt->CodeGen(__Generator);
          }
      }
      return nullptr;
}

llvm::Value* Fundecl::CodeGen(Codegen&__Generator){
      std::vector<llvm::Type*> ArgTypes;
      for(auto Argtype : *(this->Arg_list)){          
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
      llvm::Function* Func = llvm::Function::Create(FuncType, llvm::GlobalValue::ExternalLinkage, this->Func_name, __Generator.Module);
      //如果存在funbody
      if(this->Func_body){
          llvm::BasicBlock* FuncBlock = llvm::BasicBlock::Create(Context, "entry", Func);
          IR_Builder.SetInsertPoint(FuncBlock);
          __Generator.AddSymbolTable();
          //后面没看懂在干什么

          //
          __Generator.EnterFunction(Func);
          __Generator.AddSymbolTable();
          this->Func_body->CodeGen(__Generator);
          __Generator.DeleteSymbolTable();
          __Generator.LeaveCurrentFunction();
          __Generator.DeleteSymbolTable();
      }
      return nullptr;
}

llvm::Value* Block ::CodeGen(Codegen& __Generator){
    //调用block中每个语句的codegen
    for(auto& stmt :*(this->statements)){
          if (IR_Builder.GetInsertBlock()->getTerminator()) {
            break;
          }  
          stmt->CodeGen(__Generator);
         
    }
    //为没有返回语句的函数体创建默认返回语句
    if (!IR_Builder.GetInsertBlock()->getTerminator()) {
          llvm::Type* RetTy = __Generator.GetCurrentFunction()->getReturnType();
          if (RetTy->isVoidTy()) {
            IR_Builder.CreateRetVoid();
          } else {
            IR_Builder.CreateRet(llvm::UndefValue::get(RetTy));
          }
    }
    return nullptr;
}

llvm::Value* Vardecl::CodeGen(Codegen& __Generator){
  llvm::Type* vartype = this->type->GetLLVMType(__Generator);
  
  for(auto* var: *(this->var_list)){
          if (__Generator.GetCurrentFunction()){
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
        }else{
          //创建全局变量
            
        }
  }
  return nullptr;
}
} // namespace AST