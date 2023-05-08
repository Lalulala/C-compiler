%{
#include"AST.h"
#include<string>
#include<iostream>
#include<vector>

int yylex(void);
void yyerror(char *s){
    std::printf("Error: %s\n", s);
    std::exit(1); 
}
AST::Program * Root;
%}
%union{
    int inum;
    double dnum;
    char cval;
    std:: string * str;
    AST::Program * program;
     AST::Stmt * stmt;
     AST::Decl * decl;
     AST::Fundecl * fundecl;
    AST::Block * block;
    AST::Arg * arg;
    AST::Vardecl * vardecl;
     AST::Vartype * vartype;
    AST::Var * var;
    AST::ConditionStmt * conditionStmt;
     AST::LoopStmt * loopStmt;
    AST:: WhileStmt * whileStmt;
    AST::DoStmt * doStmt;
    AST::ForStmt * forStmt;
    AST::SwitchStmt * switchStmt;
    AST::Case * casel;
    AST::ReturnStmt * returnStmt;
    AST::BreakStmt *  breakStmt;
    AST::ContinueStmt* continueStmt;
    AST::Expression * expression;
    AST::Id * id;
    AST::Value * value;
    AST::Var_id * var_id;
    AST::Var_array * var_array;
    AST::ArgList *argList;
    AST::VarList *varList;
    AST::ExpressionList * expressionList;
    AST:: CaseList * caseList;
    AST:: ValueList * valueList;
    AST::Stmts* stmts;
}

%token IF ELSE DO WHILE SWITCH CASE DEFAULT BREAK CONTINUE RETURN 
        LPAREN RPAREN LBRACE RBRACE ASSIGN LBRACKET RBRACKET FOR
        MUL DIV PLUS SUB AND OR MOD
        SAND NOT
        EQU GE LE GT LT NE 
        SEMI COLON COMMA
        INT BOOL CHAR FLOAT DOUBLE SHORT LONG VOID
        
%token <inum> INTERGER
%token <dnum> REAL
%token <str> STRING Identifier
%token <cval> CHARACTER
%type<program> Program 
%type<stmts> Stmts
%type<stmt>   Stmt
%type<decl> Decl
%type<fundecl> Fundecl
%type<vartype>   Vartype
%type<id>        ID
%type<argList>   FunArg_list
%type<arg>       Arg
%type<vardecl>  Vardecl
%type<var>      Var
%type<expression> Exp Expression
%type<varList> Varlist
%type<expressionList> Call_arglist
%type<var_id> Var_id
%type<var_array> Var_array
%type<valueList> Init
%type<value> VALUE
%type<block> Block
%type<loopStmt>                                                 LoopStmt
%type<conditionStmt>	 				 	ConditionStmt
%type<forStmt>							ForStmt
%type<whileStmt>						WhileStmt
%type<doStmt>							DoStmt
%type<switchStmt>						SwitchStmt
%type<breakStmt>						BreakStmt
%type<continueStmt>						ContinueStmt
%type<returnStmt>						ReturnStmt
%type<casel>                                                     Case
%type<caseList>                                                 CaseStmt 




%right ASSIGN
%left OR
%left AND
%left NE EQU
%left GE LE GT LT 
%left PLUS SUB 
%left MUL DIV MOD
%left NOT 
%right SAND
%left LPAREN RPAREN

%nonassoc ELSE

%start Program
%%

Program: Stmts  {$$ = new AST::Program($1); Root = $$;  }
;

Stmts: Stmts Stmt  {$$=$1; $$->push_back($2);}
              |    {$$=new AST::Stmts(); }
              ;

Stmt: Decl                       {$$=$1;}
      | ConditionStmt              {$$=$1;}          
      | LoopStmt              {$$=$1;}
      | Exp SEMI              {$$=$1;}
      | Block              {$$=$1;}
      | SwitchStmt              {$$=$1;}
      | ContinueStmt             {$$=$1;}
      | BreakStmt             {$$=$1;}
      | ReturnStmt             {$$=$1;}
      ;

Decl: Fundecl {$$=$1;}
      |Vardecl  {$$=$1;}
      ;

Fundecl: Vartype ID LPAREN FunArg_list RPAREN  SEMI  {$$ = new AST::Fundecl ($1,$2,$4); }
           |Vartype ID LPAREN FunArg_list RPAREN Block {$$ = new AST::Fundecl ($1,$2,$4, $6); }
           ;

Block: LBRACE Stmts RBRACE  {$$= new AST::Block($2);}
        ;

FunArg_list:FunArg_list COMMA Arg   {$$=$1; $$->push_back($3);}
            |Arg {$$=new AST::ArgList(); $$->push_back($1);}
            |  {$$=NULL;}
            ;

Arg: Vartype ID {$$= new AST::Arg($1,$2);}
        |Vartype {$$= new AST::Arg($1);}
        ;  

Vardecl: Vartype Varlist SEMI {$$ = new AST::Vardecl ($1,$2);}
                ;

Vartype: INT   {$$ = new AST::Vartype(AST::Vartype::Types::_Int);}
          |CHAR {$$ = new AST::Vartype(AST::Vartype::Types::_Char);}
          |FLOAT {$$ = new AST::Vartype(AST::Vartype::Types::_Float);}
          |DOUBLE {$$ = new AST::Vartype(AST::Vartype::Types::_Double);}
          |SHORT {$$ = new AST::Vartype(AST::Vartype::Types::_Short);}
          |LONG {$$ = new AST::Vartype(AST::Vartype::Types::_Long);}
          |VOID {$$ = new AST::Vartype(AST::Vartype::Types::_Void);}
          ;

/*Varlist : Varlist COMMA Var   {$$ = $1 ; $$->push_back($3);}
           | Var  {$$ = new VarList(); $$->push_back($1);}
           ;

Var: ID {$$ = new Var($1);} 
     | ID ASSIGN Expression {$$ = new Var($1,$3);} 
     ;*/

Varlist : Varlist COMMA Var {$$ = $1 ; $$->push_back($3);}
        | Var {$$ = new AST::VarList(); $$->push_back($1);}
        ;

Var : Var_id {$$=$1;}
        | Var_array {$$=$1;}
        ;

Var_id: ID {$$ = new AST::Var_id($1);} 
     | ID ASSIGN Expression {$$ = new AST::Var_id($1,$3);} 
     ;

Var_array : ID LBRACKET Expression RBRACKET {$$ = new AST::Var_array($1,$3);}
           | ID LBRACKET Expression RBRACKET ASSIGN LBRACE Init RBRACE {$$ = new AST::Var_array($1,$3,$7);}
           ;

Init : Init COMMA VALUE {$$ = $1 ; $$->push_back($<value>3);}
      |VALUE {$$ = new AST::ValueList(); $$->push_back($<value>1);}
      |  {$$ = NULL;}
      ;
Exp :Expression {$$=$1;}
      |    {$$=NULL;}
      ;

Expression : ID   {$$= $1;} 
              |VALUE {$$= $1;} 
              |ID LPAREN Call_arglist RPAREN {$$ = new AST::Func_call($1,$3);}
              |LPAREN Expression RPAREN  {$$=$2;}
              |Expression MOD Expression  {$$=new AST::Mod($1,$3) ;}
              |Expression MUL Expression {$$=new AST::Mul($1,$3) ;}
              |Expression DIV Expression {$$=new AST::Div($1,$3) ;}
              |Expression PLUS Expression {$$=new AST::Plus($1,$3) ;}
              |Expression SUB Expression {$$=new AST::Sub($1,$3) ;}
              |Expression AND Expression  {$$=new AST::And($1,$3) ;}
              |Expression OR Expression    {$$=new AST::Or($1,$3) ;}
              |Expression EQU Expression    {$$=new AST::Equ($1,$3) ;}
              |Expression GE Expression      {$$=new AST::Ge($1,$3) ;}
              |Expression LE Expression       {$$=new AST::Le($1,$3) ;}
              |Expression GT Expression     {$$=new AST::Gt($1,$3) ;}
              |Expression LT Expression     {$$=new AST::Lt($1,$3) ;}
              |Expression NE Expression      {$$=new AST::Ne($1,$3) ;}
              |Expression ASSIGN Expression   {$$=new AST::AssignNode($1,$3) ;}
              |SAND Expression   {$$=new AST::Getaddess($2);}
              |NOT Expression  {$$=new AST::Not($2);}
                ;

ID : Identifier {$$= new AST::Id($1);}
     ;


VALUE: INTERGER  {$$ = new AST::IntNode($1);}
        |REAL    {$$ = new AST::DoubleNode($1);}
        |CHARACTER {$$ = new AST::CharNode($1);}
        |STRING  {$$ = new AST::StrNode($1);}
        ;

Call_arglist : Call_arglist COMMA Expression {$$=$1; $$->push_back($3);}
                | Expression  {$$= new AST::ExpressionList(); $$->push_back ($1);}
                | {$$= NULL;}
                ;


ConditionStmt : IF LPAREN Expression RPAREN Stmt {$$ = new AST::ConditionStmt($3,$5);}
                |IF LPAREN Expression RPAREN Stmt ELSE Stmt {$$ = new AST::ConditionStmt($3,$5,$7);}
                ;

LoopStmt: ForStmt {$$=$1;}
           |WhileStmt  {$$=$1;}
           |DoStmt {$$=$1;}
           ;

WhileStmt:WHILE LPAREN Expression RPAREN Stmt  {$$ = new AST::WhileStmt($3,$5);}
            ;
            
DoStmt: DO Stmt WHILE LPAREN Expression RPAREN SEMI {$$ = new AST::DoStmt($5,$2);}
        ;

ForStmt : FOR LPAREN Exp SEMI Expression SEMI Exp RPAREN Stmt {$$ = new AST::ForStmt($3,$5,$7,$9);}
           |FOR LPAREN Vardecl  Expression SEMI Exp RPAREN Stmt {$$ = new AST::ForStmt($3,$4,$6,$8);}
           ;

SwitchStmt : SWITCH LPAREN Exp RPAREN  LBRACE  CaseStmt RBRACE {$$ = new AST::SwitchStmt($3,*$6);}
                ;

CaseStmt : CaseStmt Case {$$=$1; $$->push_back($2);}
            | {$$ = new AST::CaseList();}
            ;

Case: CASE Exp COLON Stmts {$$= new AST::Case($2,$4);}
       |DEFAULT COLON Stmts {$$ = new AST::Case(NULL,$3);}
       ;

ContinueStmt: CONTINUE SEMI {$$ = new AST::ContinueStmt();}
                ;

BreakStmt: BREAK SEMI {$$ = new AST::BreakStmt();}
            ;

ReturnStmt: RETURN Expression SEMI {$$ = new AST::ReturnStmt($2);}
            |RETURN SEMI {$$ = new AST::ReturnStmt(); }
            ;
%%


int yywrap(){
    return 1;
}
int main()
{
    yyparse();
}
