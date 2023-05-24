// Codegen类为语义分析提供相关支持
#ifndef CODEGEN_H
#define CODEGEN_H

#include "AST.h"
#include "Utils.hpp"
// using namespace llvm;
#include <iostream>
#include <iterator>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/Interpreter.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/ValueSymbolTable.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/MC/TargetRegistry.h>
#include <llvm/Passes/PassBuilder.h>
#include <llvm/Passes/PassPlugin.h>
#include <llvm/Support/DynamicLibrary.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/ManagedStatic.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Scalar/GVN.h>

using namespace std;

// 上下文
llvm::LLVMContext Context;

// 生成IR指令
llvm::IRBuilder<> IR_Builder(Context);

// 定义符号
class Symbol {
 private:
  // 内容
  void* Content;
  // 类型
  enum { FUNCTION, TYPE, VARIABLE, CONSTANT, UNDEFINED } Type;

 public:
  // 默认构造函数
  Symbol() {
    Content = NULL;
    Type    = UNDEFINED;
  }
  // 函数符号
  Symbol(llvm::Function* function) {
    Content = function;
    Type    = FUNCTION;
  }
  // 类型符号
  Symbol(llvm::Type* Ty) {
    Content = Ty;
    Type    = TYPE;
  }
  // 变量/常量
  Symbol(llvm::Value* value, int flag) {
    Content = value;
    Type    = (flag == 1 ? CONSTANT : VARIABLE);
  }
  // 获取函数
  llvm::Function* GetFunction() {
    if (Type == FUNCTION) {
      return (llvm::Function*)Content;
    } else {
      return NULL;
    }
  }
  // 获取类型
  llvm::Type* GetType() {
    if (Type == TYPE) {
      return (llvm::Type*)Content;
    } else {
      return NULL;
    }
  }
  // 获取变量
  llvm::Value* GetVariable() {
    if (Type == VARIABLE) {
      return (llvm::Value*)Content;
    } else {
      return NULL;
    }
  }
  // 获取常量
  llvm::Value* GetConstant() {
    if (Type == CONSTANT) {
      return (llvm::Value*)Content;
    } else {
      return NULL;
    }
  }
};

// 定义符号表
using SymbolTable = map<string, Symbol>;

// 定义Codegen类
class Codegen {
 private:
  // 当前函数指针
  llvm::Function* current_function;
  // 保存符号表的栈
  vector<SymbolTable*> SymbolTable_stack;
  // 用于记录continue返回块的栈
  vector<llvm::BasicBlock*> ContinueBlockStack;
  // 用于记录break返回块的栈
  vector<llvm::BasicBlock*> BreakBlockStack;
  // 基本块
  llvm::BasicBlock* basicblock;
  // 函数
  llvm::Function* function;

 public:
  // 模块
  llvm::Module* Module;
  // 默认构造函数
  Codegen();

  // 符号表相关操作
  // 建立并添加符号表
  void AddSymbolTable();
  // 删除并弹出符号表
  void DeleteSymbolTable();

  // 函数相关操作
  // 查找对应函数
  llvm::Function* FindFunction(string name);
  // 添加函数
  int AddFunction(llvm::Function* function, string name);
  // 进入函数
  void EnterFunction(llvm::Function* function);
  // 得到当前函数
  llvm::Function* GetCurrentFunction();
  // 离开当前函数
  void LeaveCurrentFunction();

  // 变量类型相关操作
  // 查找变量类型
  llvm::Type* FindType(string name);
  // 添加变量类型
  int AddType(llvm::Type* type, string name);

  // 变量、常量相关操作
  // 查找变量
  llvm::Value* FindVal(string name);
  // 查找常量
  llvm::Value* FindConst(string name);
  // 添加变量
  int AddVal(llvm::Value* Val, string name);
  // 添加常量
  int AddConst(llvm::Value* Const, string name);

  // 循环相关操作
  // 进入循环
  void EnterLoop(llvm::BasicBlock* ContinueBlock, llvm::BasicBlock* BreakBlock);
  // 离开循环
  void LeaveLoop();
  // 查找continue语句后跳转的块
  llvm::BasicBlock* GetContinueBlock();
  // 查找break语句后跳转的块
  llvm::BasicBlock* GetBreakBlock();

  // ?
  void ExchangeInsertPoint();

  // 生成代码
  void GenerateCode(AST::Program& program);

  // 向文件中写IR代码
  void GenerateIRCode(string flie);

  // 向文件中写Object代码
  void GenerateObjectCode(string file);

  // 可视化 ？
  void visual(string file, AST::Program& program);
};

#endif
