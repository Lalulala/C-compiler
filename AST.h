#ifndef AST_H
#define AST_H



#include<iostream>
#include<string>
#include <vector>
//#include <llvm/Value.h>


class CodeGenContext;
namespace AST{
    class Node;
    class Program;
    class Stmt;
    using Stmts=std::vector<Stmt*>;
    class Decl;
    class Fundecl ;
    class Block ;
    class Arg ;
    class Vardecl;
    using ArgList = std::vector<Arg*>;
    class Vartype;
    class Var;
    using VarList = std::vector<Var*> ;
    class Var_id;
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

using ExpressionList = std :: vector<Expression*>;

class Func_call;
class Div ;
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
using ValueList = std::vector<Value *>;
class CharNode;
class IntNode;
class StrNode;
class DoubleNode;
}

namespace AST {
class Node{
public:
    		Node(void) {}
		~Node(void) {}

     //virtual llvm::Value* codeGen(CodeGenContext& context) { }
};
class Program :public Node{
public:
    Stmts*  stmt;
    Program(Stmts*  stmt):stmt(stmt){}
    ~Program(){}
    // llvm::Value* codeGen(CodeGenContext& context);
};

class Stmt:public Node{
public:
    	Stmt(void) {}
		~Stmt(void) {}
};

class Decl: public Stmt{
public:
		Decl(void) {}
		~Decl(void) {}
};

class Fundecl : public Decl{
public:
    //返回类型
      Vartype * Retype;
    //函数名
      Id* Func_name;
    //参数
    ArgList* Arg_list;
    //函数体
    Block * Func_body;
   Fundecl (Vartype * Retype,Id* Func_name,ArgList* Arg_list,Block * Func_body=NULL):
            Retype(Retype), Func_name(Func_name), Arg_list(Arg_list), Func_body(Func_body)  {}
   
   ~Fundecl(void){}
   // llvm::Value* codeGen(CodeGenContext& context);
};

class Block : public Stmt{
public:
    Stmts* statements;
    Block(Stmts* statements):statements(statements){}
    // llvm::Value* codeGen(CodeGenContext& context);
};



class Arg:public Node{
public:
    //参数类型
    Vartype* var_type;
    //参数名
    Id* id;
    Arg(Vartype* var_type,Id* id = NULL): var_type(var_type), id(id) {}
    // llvm::Value* codeGen(CodeGenContext& context);
};

class Vardecl: public Decl{
public:
    //变量类型
    Vartype* type;
    //变量列表
    VarList* var_list;

    Vardecl(Vartype* type,VarList* var_list):type(type),var_list(var_list){};
    ~Vardecl(){}
    // llvm::Value* codeGen(CodeGenContext& context);
};

class Vartype: public Node{
public:
     enum Types{
        _Bool,
        _Short,
        _Long,
        _Int,
        _Float,
        _Double,
        _Void,
        _Char
     };
    Types type;
    Vartype(Types type): type(type){}
    ~Vartype(){}
    //llvm::Type* _LLVMType;
    //llvm::Value* codeGen(CodeGenContext& context);
};

class Var : public Decl{
public: Var(){}
        ~Var(){}
};

class Var_id: public Var{
public:
    //id
     Id* name;
    //赋值表达式
    Expression * Assign_Exp;
    Var_id(Id* name,Expression * Assign_Exp=NULL): name(name),Assign_Exp(Assign_Exp){}
    ~Var_id(){}
};

class Var_array : public Var{
public :
    Id * name;
    Expression * index;
    ValueList * inital_list;
    Var_array(Id * name,Expression * index,ValueList * inital_list=NULL){}
    ~Var_array(){}
};

class ConditionStmt : public Stmt{
public:
      //条件表达式
      Expression * C_Expression;
      //Then
      Stmt* stmt1;
      //else
      Stmt* stmt2;

      ConditionStmt(Expression * C_Expression,Stmt* stmt1,Stmt* stmt2=NULL) :C_Expression(C_Expression),stmt1(stmt1),stmt2(stmt2){}
      ~ConditionStmt(){}
      //llvm::Value* codeGen(CodeGenContext& context);
};

class LoopStmt: public Stmt{
public:
    //条件表达式
      Expression * C_Expression;
    //循环体
      Stmt* Loopbody;
      //llvm::Value* codeGen(CodeGenContext& context);
};

class WhileStmt: public LoopStmt{
public:
    WhileStmt(Expression * C_Expression,Stmt* Loopbody){}
    ~WhileStmt(){}
    //llvm::Value* codeGen(CodeGenContext& context);
};

class DoStmt: public LoopStmt{
public:
    DoStmt(Expression * C_Expression,Stmt* Loopbody){}
    ~DoStmt(){}
    //llvm::Value* codeGen(CodeGenContext& context);
};

class ForStmt: public LoopStmt{
public:

    Stmt* Init;
    Expression* then;
    ForStmt(Stmt* Init,Expression * C_Expression,Expression* then,Stmt* Loopbody):Init(Init),then(then){}
    ~ForStmt(){}
    //llvm::Value* codeGen(CodeGenContext& context);
};

class SwitchStmt: public Stmt{
public:
      Expression* To_match;
      CaseList case_list;
      SwitchStmt(Expression* To_match,CaseList case_list){}
      //llvm::Value* codeGen(CodeGenContext& context);
};


class Case : public Stmt{
public: 
    Expression * C_Expression;
    Stmts * Content;
    Case(Expression * C_Expression,Stmts * Content){}
    //llvm::Value* codeGen(CodeGenContext& context);
};


class ReturnStmt: public Stmt{
public:
    Expression * To_return;
    ReturnStmt(Expression * To_return = NULL) : To_return(To_return){}
    //llvm::Value* codeGen(CodeGenContext& context);
};

class BreakStmt: public Stmt{
    //llvm::Value* codeGen(CodeGenContext& context);
};

class ContinueStmt: public Stmt{
    //llvm::Value* codeGen(CodeGenContext& context);
};


class Expression :public Stmt {
public:
     Expression(){}
     //virtual llvm::Value* codeGen(CodeGenContext& context);
};

class Func_call : public Expression{
public :
    Id* name;
     ExpressionList * arglist;
    Func_call(Id* name, ExpressionList * arglist = NULL) : 
               name(name),arglist(arglist) {}
    //llvm::Value* codeGen(CodeGenContext& context);
};



class Div : public Expression{
public:
    Expression* lhs;
    Expression* rhs;
    Div(Expression* lhs,Expression* rhs){};
    //llvm::Value* codeGen(CodeGenContext& context);
};

class Mul: public Expression{
public:
    Expression* lhs;
    Expression* rhs;
    Mul(Expression* lhs,Expression* rhs){};
    //llvm::Value* codeGen(CodeGenContext& context);
};

class Plus: public Expression{
public:
    Expression* lhs;
    Expression* rhs;
    Plus(Expression* lhs,Expression* rhs){};
    //llvm::Value* codeGen(CodeGenContext& context);
};

class Sub: public Expression{
public:
    Expression* lhs;
    Expression* rhs;
    Sub(Expression* lhs,Expression* rhs){};
    //llvm::Value* codeGen(CodeGenContext& context);
};

class Mod: public Expression{
public:
    Expression* lhs;
    Expression* rhs;
    Mod(Expression* lhs,Expression* rhs){};
    //llvm::Value* codeGen(CodeGenContext& context);
};

class And: public Expression{
public:
    Expression* lhs;
    Expression* rhs;
    And(Expression* lhs,Expression* rhs){};
    //llvm::Value* codeGen(CodeGenContext& context);
};

class Or: public Expression{
public:
    Expression* lhs;
    Expression* rhs;
    Or(Expression* lhs,Expression* rhs){};
    //llvm::Value* codeGen(CodeGenContext& context);
};

class Equ: public Expression{
public:
    Expression* lhs;
    Expression* rhs;
    Equ(Expression* lhs,Expression* rhs){};
    //llvm::Value* codeGen(CodeGenContext& context);
};

class Ne: public Expression{
public:
    Expression* lhs;
    Expression* rhs;
    Ne(Expression* lhs,Expression* rhs){};
    //llvm::Value* codeGen(CodeGenContext& context);
};

class Lt: public Expression{
public:
    Expression* lhs;
    Expression* rhs;
    Lt(Expression* lhs,Expression* rhs){};
    //llvm::Value* codeGen(CodeGenContext& context);
};

class Le: public Expression{
public:
    Expression* lhs;
    Expression* rhs;
    Le(Expression* lhs,Expression* rhs){};
    //llvm::Value* codeGen(CodeGenContext& context);
};

class Gt: public Expression{
public:
    Expression* lhs;
    Expression* rhs;
    Gt(Expression* lhs,Expression* rhs){};
    //llvm::Value* codeGen(CodeGenContext& context);
};

class Ge: public Expression{
public:
    Expression* lhs;
    Expression* rhs;
    Ge(Expression* lhs,Expression* rhs){};
    //llvm::Value* codeGen(CodeGenContext& context);
};

class AssignNode : public Expression{
public: 
    Expression* lhs;
    Expression* rhs;
   AssignNode (Expression* lhs,Expression* rhs){};
   //llvm::Value* codeGen(CodeGenContext& context);

};



class Getaddess : public Expression{
public:
    Expression * rhs;
        Getaddess(Expression * rhs){}
        //llvm::Value* codeGen(CodeGenContext& context);
};

class Not : public Expression{
public:
    Expression * rhs;
    Not(Expression * rhs){}
    //llvm::Value* codeGen(CodeGenContext& context);
};


class Id: public Expression{
public :
    std::string *name;
    Id(std::string *name){}
    //llvm::Value* codeGen(CodeGenContext& context);
};

class Value: public Expression{
public:
    Value(){}
    //virtual llvm::Value* codeGen(CodeGenContext& context);
};

class CharNode : public Value{
public:
    char value;
    CharNode(char value){}
    //llvm::Value* codeGen(CodeGenContext& context);
};

class IntNode: public Value{
public:
    int value;
    IntNode(int value){}
    //llvm::Value* codeGen(CodeGenContext& context);
};

class StrNode: public Value{
public:
    std::string *value;
    StrNode(std::string *value){}
    //llvm::Value* codeGen(CodeGenContext& context);
};

class DoubleNode: public Value{
public:
    double value;
    DoubleNode(double value){}
    //llvm::Value* codeGen(CodeGenContext& context);
};

}

#endif