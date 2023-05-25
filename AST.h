#ifndef AST_H
#define AST_H

#include <iostream>
#include <string>
#include <vector>

#include <llvm/IR/Value.h>

class Codegen;
namespace AST {
class Node;
class Program;
class Stmt;
using Stmts = std::vector<Stmt*>;
class Decl;
class Fundecl;
class Block;
class Arg;
class Vardecl;
class ArgList ;
class Vartype;
class Var;
class Var_id;
using VarList = std::vector<Var_id*>;

class Var_array;
class ConditionStmt;
class LoopStmt;
class WhileStmt;
class DoStmt;
class ForStmt;
class SwitchStmt;
class Case;
using CaseList = std::vector<Case*>;
class ReturnStmt;
class BreakStmt;
class Expression;

using ExpressionList = std ::vector<Expression*>;

class Func_call;
class Div;
class Mul;
class Plus;
class Sub;
class Mod;
class And;
class Or;
class Equ;
class Ne;
class Lt;
class Le;
class Gt;
class Ge;
class AssignNode;
class Getaddess;
class Not;
class Id;
class Value;
using ValueList = std::vector<Value*>;
class CharNode;
class IntNode;
class StrNode;
class DoubleNode;
}  // namespace AST

namespace AST {
class Node {
 public:
  Node(void) {}
  ~Node(void) {}
  virtual llvm::Value* CodeGen(Codegen& __Generator) = 0;
  //virtual llvm::Value* codeGen(CodeGenContext& context) { }
};
class Program : public Node {
 public:
  Stmts* stmts;
  Program(Stmts* stmts) : stmts(stmts) {}
  ~Program() {}
  // llvm::Value* codeGen(CodeGenContext& context);
   llvm::Value* CodeGen(Codegen& __Generator) ;
};

class Stmt : public Node {
 public:
  Stmt(void) {}
  ~Stmt(void) {}
  virtual llvm::Value* CodeGen(Codegen& __Generator) = 0;
};

class Decl : public Stmt {
 public:
  Decl(void) {}
  ~Decl(void) {}
  virtual llvm::Value* CodeGen(Codegen& __Generator) = 0;
};

class Fundecl : public Decl {
 public:
  //返回类型
  Vartype* Retype;
  //函数名
  std::string Func_name;
  //参数
  ArgList* Arg_list;
  //函数体
  Block* Func_body;
  Fundecl(Vartype* Retype, std::string Func_name, ArgList* Arg_list, Block* Func_body = NULL)
      : Retype(Retype), Func_name(Func_name), Arg_list(Arg_list), Func_body(Func_body) {}

  ~Fundecl(void) {}
  // llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Block : public Stmt {
 public:
  Stmts* statements;
  Block(Stmts* statements) : statements(statements) {}
  // llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class ArgList : public std::vector<Arg*>, public Node {
 public:
  //Set true if the argument list contains "..."
  bool _VarArg;
  void SetVarArg(void) {
    this->_VarArg = true;
  }

  ArgList(void) : _VarArg(false) {}
  ~ArgList(void) {}
  //ArgList class don't need an actual CodeGen function
  llvm::Value* CodeGen(Codegen& __Generator) {
    return NULL;
  }
  //std::string astJson();
};

class Arg : public Node {
 public:
  //参数类型
  Vartype* var_type;
  //参数名
  std::string id;
  Arg(Vartype* var_type, std::string id = NULL) : var_type(var_type), id(id) {}
  // llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Vardecl : public Decl {
 public:
  //变量类型
  Vartype* type;
  //变量列表
  VarList* var_list;

  Vardecl(Vartype* type, VarList* var_list) : type(type), var_list(var_list){};
  ~Vardecl() {}
  // llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Vartype : public Node {
 public:
  enum Types { _Bool, _Short, _Long, _Int, _Float, _Double, _Void, _Char };
  Types type;
  Vartype(Types type) : type(type) {}
  ~Vartype() {}
  llvm::Type* _LLVMType;
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Type* GetLLVMType(Codegen& __Generator) ;
  llvm::Value* CodeGen(Codegen& __Generator);
};
/*
class Var : public Decl {
 public:
  
  Var() {}
  ~Var() {}
  llvm::Value* CodeGen(Codegen& __Generator) ;
};*/

class Var_id : public Decl {
 public:
  //id
  std::string name;
  //赋值表达式
  Expression* Assign_Exp;
  Var_id(std::string name, Expression* Assign_Exp = NULL) : Assign_Exp(Assign_Exp) {}
  ~Var_id() {}
  llvm::Value* CodeGen(Codegen& __Generator);
};
/*
class Var_array : public Var {
 public:
  Expression* index;
  ValueList* inital_list;
  Var_array(std::string name, Expression* index, ValueList* inital_list = NULL) {}
  ~Var_array() {}
  llvm::Value* CodeGen(Codegen& __Generator);
};*/

class ConditionStmt : public Stmt {
 public:
  //条件表达式
  Expression* C_Expression;
  //Then
  Stmt* stmt1;
  //else
  Stmt* stmt2;

  ConditionStmt(Expression* C_Expression, Stmt* stmt1, Stmt* stmt2 = NULL)
      : C_Expression(C_Expression), stmt1(stmt1), stmt2(stmt2) {}
  ~ConditionStmt() {}
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

/*
class LoopStmt : public Stmt {
 public:
  //条件表达式
  Expression* C_Expression;
  //循环体
  Stmt* Loopbody;
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};*/

class WhileStmt : public Stmt {
 public:
  //条件表达式
  Expression* C_Expression;
  //循环体
  Stmt* Loopbody;
  WhileStmt(Expression* C_Expression, Stmt* Loopbody) {}
  ~WhileStmt() {}
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class DoStmt : public Stmt {
 public:
  //条件表达式
  Expression* C_Expression;
  //循环体
  Stmt* Loopbody;
  DoStmt(Expression* C_Expression, Stmt* Loopbody) {}
  ~DoStmt() {}
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class ForStmt : public Stmt {
 public:
  //条件表达式
  Expression* C_Expression;
  //循环体
  Stmt* Loopbody;

  Stmt* Init;
  Expression* then;
  ForStmt(Stmt* Init, Expression* C_Expression, Expression* then, Stmt* Loopbody)
      : Init(Init), C_Expression(C_Expression), then(then), Loopbody(Loopbody) {}
  ~ForStmt() {}
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class SwitchStmt : public Stmt {
 public:
  Expression* To_match;
  CaseList case_list;
  SwitchStmt(Expression* To_match, CaseList case_list) {}
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Case : public Stmt {
 public:
  Expression* C_Expression;
  Stmts* Content;
  Case(Expression* C_Expression, Stmts* Content) {}
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class ReturnStmt : public Stmt {
 public:
  Expression* To_return;
  ReturnStmt(Expression* To_return = NULL) : To_return(To_return) {}
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class BreakStmt : public Stmt {
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class ContinueStmt : public Stmt {
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Expression : public Stmt {
 public:
  Expression() {}
  //virtual llvm::Value* codeGen(CodeGenContext& context);
  virtual llvm::Value* CodeGen(Codegen& __Generator) = 0;
};

class Func_call : public Expression {
 public:
  std::string name;
  ExpressionList* arglist;
  Func_call(std::string name, ExpressionList* arglist = NULL) : name(name), arglist(arglist) {}
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Div : public Expression {
 public:
  Expression* lhs;
  Expression* rhs;
  Div(Expression* lhs, Expression* rhs){};
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Mul : public Expression {
 public:
  Expression* lhs;
  Expression* rhs;
  Mul(Expression* lhs, Expression* rhs){};
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Plus : public Expression {
 public:
  Expression* lhs;
  Expression* rhs;
  Plus(Expression* lhs, Expression* rhs){};
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Sub : public Expression {
 public:
  Expression* lhs;
  Expression* rhs;
  Sub(Expression* lhs, Expression* rhs){};
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Mod : public Expression {
 public:
  Expression* lhs;
  Expression* rhs;
  Mod(Expression* lhs, Expression* rhs){};
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class And : public Expression {
 public:
  Expression* lhs;
  Expression* rhs;
  And(Expression* lhs, Expression* rhs){};
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Or : public Expression {
 public:
  Expression* lhs;
  Expression* rhs;
  Or(Expression* lhs, Expression* rhs){};
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Equ : public Expression {
 public:
  Expression* lhs;
  Expression* rhs;
  Equ(Expression* lhs, Expression* rhs){};
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Ne : public Expression {
 public:
  Expression* lhs;
  Expression* rhs;
  Ne(Expression* lhs, Expression* rhs){};
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Lt : public Expression {
 public:
  Expression* lhs;
  Expression* rhs;
  Lt(Expression* lhs, Expression* rhs){};
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Le : public Expression {
 public:
  Expression* lhs;
  Expression* rhs;
  Le(Expression* lhs, Expression* rhs){};
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Gt : public Expression {
 public:
  Expression* lhs;
  Expression* rhs;
  Gt(Expression* lhs, Expression* rhs){};
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Ge : public Expression {
 public:
  Expression* lhs;
  Expression* rhs;
  Ge(Expression* lhs, Expression* rhs){};
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class AssignNode : public Expression {
 public:
  Expression* lhs;
  Expression* rhs;
  AssignNode(Expression* lhs, Expression* rhs){};
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Getaddess : public Expression {
 public:
  Expression* rhs;
  Getaddess(Expression* rhs) {}
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class Not : public Expression {
 public:
  Expression* rhs;
  Not(Expression* rhs) {}
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};


class Id: public Expression{
public :
    std::string name;
    Id(std::string name){}
    //llvm::Value* codeGen(CodeGenContext& context);
};

class Value : public Expression {
 public:
  Value() {}
  //virtual llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class CharNode : public Value {
 public:
  char value;
  CharNode(char value) {}
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class IntNode : public Value {
 public:
  int value;
  IntNode(int value) {}
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class StrNode : public Value {
 public:
  std::string* value;
  StrNode(std::string* value) {}
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

class DoubleNode : public Value {
 public:
  double value;
  DoubleNode(double value) {}
  //llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value* CodeGen(Codegen& __Generator);
};

}  // namespace AST

#endif