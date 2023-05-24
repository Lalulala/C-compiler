#include "Codegen.h"

extern llvm::LLVMContext Context;
extern llvm::IRBuilder<> IR_Builder;

// -----------------------------Codegen class中函数的实现-------------------------------

// 默认构造函数
Codegen::Codegen()
{
    Module = new llvm::Module("main", Context);
    current_function = NULL;
    basicblock = NULL;
    function = NULL;
}

// 符号表相关操作
// 建立并添加符号表
void Codegen::AddSymbolTable()
{
    SymbolTable_stack.push_back(new SymbolTable);
}
// 删除并弹出符号表
void Codegen::DeleteSymbolTable()
{
    if (SymbolTable_stack.size() == 0)
    {
        return ;
    }
    // 删除回收
    delete SymbolTable_stack.back();
    SymbolTable_stack.pop_back();
}
        
// 函数相关操作
// 查找对应函数
llvm::Function* Codegen::FindFunction(string name)
{
    if (SymbolTable_stack.size() == 0)
    {
        return NULL;
    }
    // 在符号表栈中依次查找
    for (auto iter : SymbolTable_stack)
    {
        // 在具体的符号表中查找
        auto pair = (**iter).find(name);
        if (pair != (**iter).end())
        {
            return pair->second.GetFunction();
        }
    }
    return NULL;
}
// 添加函数
int Codegen::AddFunction(llvm::Function* function, string name)
{
    if (SymbolTable_stack.size() == 0)
    {
        return 0;
    }
    // 在目前的符号表中添加
    auto current_table = *(SymbolTable_stack.back());
    // 确保不重名
    if (current_table.find(name) == current_table.end())
    {
        return 0;
    }
    // 插入(name, Symbol)对
    current_table.insert(name, Symbol(function));
    return 1;
}
// 进入函数
void Codegen::EnterFunction(llvm::Function* function)
{
    current_function = function;
}
// 得到当前函数
llvm::Function* Codegen::GetCurrentFunction()
{
    return current_function;
}
// 离开当前函数
void Codegen::LeaveCurrentFunction()
{
    current_function = NULL;
}      

// 变量类型相关操作
// 查找变量类型
llvm::Type* Codegen::FindType(string name)
{
    if (SymbolTable_stack.size() == 0)
    {
        return 0;
    }
    // 在符号表栈中依次查找
    for (auto iter : SymbolTable_stack)
    {
        // 在具体的符号表中查找
        auto pair = (**iter).find(name);
        if (pair != (**iter).end())
        {
            return pair->second.GetType();
        }
    }
    return NULL;
}
// 添加变量类型
int Codegen::AddType(llvm::Type* type, string name)
{
    if (SymbolTable_stack.size() == 0)
    {
        return 0;
    }
    // 在目前的符号表中添加
    auto current_table = *(SymbolTable_stack.back());
    // 确保不重名
    if (current_table.find(name) == current_table.end())
    {
        return 0;
    }
    // 插入(name, Symbol)对
    current_table.insert(name, Symbol(type));
    return 1;
}

// 变量、常量相关操作
// 查找变量
llvm::Value* Codegen::FindVal(string name)
{
    if (SymbolTable_stack.size() == 0)
    {
        return 0;
    }
    // 在符号表栈中依次查找
    for (auto iter : SymbolTable_stack)
    {
        // 在具体的符号表中查找
        auto pair = (**iter).find(name);
        if (pair != (**iter).end())
        {
            return pair->second.GetVarible();
        }
    }
    return NULL;
}
// 查找常量
llvm::Value* Codegen::FindConst(string name)
{
    if (SymbolTable_stack.size() == 0)
    {
        return 0;
    }
    // 在符号表栈中依次查找
    for (auto iter : SymbolTable_stack)
    {
        // 在具体的符号表中查找
        auto pair = (**iter).find(name);
        if (pair != (**iter).end())
        {
            return pair->second.GetConstant();
        }
    }
    return NULL;
}
// 添加变量
int Codegen::AddVal(llvm::Value* Val, string name)
{
    if (SymbolTable_stack.size() == 0)
    {
        return 0;
    }
    // 在目前的符号表中添加
    auto current_table = *(SymbolTable_stack.back());
    // 确保不重名
    if (current_table.find(name) == current_table.end())
    {
        return 0;
    }
    // 插入(name, Symbol)对
    current_table.insert(name, Symbol(Val));
    return 1;
}
// 添加常量
int Codegen::AddConst(llvm::Value* Const, string name)
{
    if (SymbolTable_stack.size() == 0)
    {
        return 0;
    }
    // 在目前的符号表中添加
    auto current_table = *(SymbolTable_stack.back());
    // 确保不重名
    if (current_table.find(name) == current_table.end())
    {
        return 0;
    }
    // 插入(name, Symbol)对
    current_table.insert(name, Symbol(Const));
    return 1;
}

// 循环相关操作
// 进入循环
void Codegen::EnterLoop(llvm::BasicBlock* ContinueBlock, llvm::BasicBlock* BreakBlock)
{
    ContinueBlockStack.push_back(ContinueBlock);
    BreakBlockStack.push_back(BreakBlock);
}
// 离开循环
void Codegen::LeaveLoop()
{
    // 确保处在循环中
    if (ContinueBlockStack.size() == 0 || BreakBlockStack.size() == 0)
    {
        return ;
    }
    ContinueBlockStack.pop_back();
    BreakBlockStack.pop_back();
}
// 查找continue语句后跳转的块
llvm::BasicBlock* Codegen::GetContinueBlock()
{
    return ContinueBlockStack.size() == 0 ? NULL : ContinueBlockStack.back();
}
// 查找break语句后跳转的块
llvm::BasicBlock* Codegen::GetBreakBlock()
{
    return BreakBlockStack.size() == 0 ? NULL : BreakBlockStack.back();
}

// ? 
void Codegen::ExchangeInsertPoint()
{
    auto temp = IR_Builder.GetInsertBlock();
    IR_Builder.SetInsertPoint(basicblock);
    basicblock = temp;
}

// 生成代码
void Codegen::GenerateCode(AST::Program& program)
{
    // 初始化符号表
    AddSymbolTable();

    // 新建函数和基本块
    function = llvm::Function::Create(llvm::FunctionType::get(IR_Builder.getVoidTy(), false), llvm::GlobalValue::InternalLinkage, "0Tmp", this->Module);
	basicblock = llvm::BasicBlock::Create(Context, "Temp", this->TmpFunc);

    // 生成代码
    cout << "Generating code .../n" << endl;
    program.CodeGen(*this);
    cout << "Successfully!" << endl;

    // 删除新建的函数和基本块
    basicblock->eraseFromParent();
    function->eraseFromParent();

    // 删除符号表
    DeleteSymbolTable();
}

// 向文件中写IR代码
void Codegen::GenerateIRCode(string flie)
{
    if (file == "")
    {
        file = "_";
    }
    std::error_code EC;
	llvm::raw_fd_ostream Out(FileName, EC);
	Out << "********************  IRCode  ********************\n";
	this->Module->print(Out, NULL);
	Out << "*****************  Verification  *****************\n";
	if (llvm::verifyModule(*this->Module, &Out) == 0)
	Out << "No errors.\n";
}

// 向文件中写Object代码
void Codegen::GenerateObjectCode(string file)
{
    auto TargetTriple = llvm::sys::getDefaultTargetTriple();
	llvm::InitializeAllTargetInfos();
	llvm::InitializeAllTargets();
	llvm::InitializeAllTargetMCs();
	llvm::InitializeAllAsmParsers();
	llvm::InitializeAllAsmPrinters();
	std::string Error;
	auto Target = llvm::TargetRegistry::lookupTarget(TargetTriple, Error);
	if (!Target) {
		throw std::runtime_error(Error);
		return;
	}
	auto CPU = "generic";
	auto Features = "";
	llvm::TargetOptions opt;
	auto RM = llvm::Optional<llvm::Reloc::Model>();
	auto TargetMachine = Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);
	Module->setDataLayout(TargetMachine->createDataLayout());
	Module->setTargetTriple(TargetTriple);
	std::error_code EC;
	llvm::raw_fd_ostream Dest(FileName, EC, llvm::sys::fs::OF_None);
	if (EC) {
		throw std::runtime_error("Could not open file: " + EC.message());
		return;
	}
	auto FileType = llvm::CGFT_ObjectFile;
	llvm::legacy::PassManager PM;
	if (TargetMachine->addPassesToEmitFile(PM, Dest, nullptr, FileType)) {
		throw std::runtime_error("TargetMachine can't emit a file of this type");
		return;
	}
	PM.run(*Module);
	Dest.flush();
}

// 可视化 ？
void visual(string file, AST::Program& program)
{
    
}
