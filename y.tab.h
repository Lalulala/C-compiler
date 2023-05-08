
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     DO = 260,
     WHILE = 261,
     SWITCH = 262,
     CASE = 263,
     DEFAULT = 264,
     BREAK = 265,
     CONTINUE = 266,
     RETURN = 267,
     LPAREN = 268,
     RPAREN = 269,
     LBRACE = 270,
     RBRACE = 271,
     ASSIGN = 272,
     LBRACKET = 273,
     RBRACKET = 274,
     FOR = 275,
     MUL = 276,
     DIV = 277,
     PLUS = 278,
     SUB = 279,
     AND = 280,
     OR = 281,
     MOD = 282,
     SAND = 283,
     NOT = 284,
     EQU = 285,
     GE = 286,
     LE = 287,
     GT = 288,
     LT = 289,
     NE = 290,
     SEMI = 291,
     COLON = 292,
     COMMA = 293,
     INT = 294,
     BOOL = 295,
     CHAR = 296,
     FLOAT = 297,
     DOUBLE = 298,
     SHORT = 299,
     LONG = 300,
     VOID = 301,
     INTERGER = 302,
     REAL = 303,
     STRING = 304,
     Identifier = 305,
     CHARACTER = 306
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define DO 260
#define WHILE 261
#define SWITCH 262
#define CASE 263
#define DEFAULT 264
#define BREAK 265
#define CONTINUE 266
#define RETURN 267
#define LPAREN 268
#define RPAREN 269
#define LBRACE 270
#define RBRACE 271
#define ASSIGN 272
#define LBRACKET 273
#define RBRACKET 274
#define FOR 275
#define MUL 276
#define DIV 277
#define PLUS 278
#define SUB 279
#define AND 280
#define OR 281
#define MOD 282
#define SAND 283
#define NOT 284
#define EQU 285
#define GE 286
#define LE 287
#define GT 288
#define LT 289
#define NE 290
#define SEMI 291
#define COLON 292
#define COMMA 293
#define INT 294
#define BOOL 295
#define CHAR 296
#define FLOAT 297
#define DOUBLE 298
#define SHORT 299
#define LONG 300
#define VOID 301
#define INTERGER 302
#define REAL 303
#define STRING 304
#define Identifier 305
#define CHARACTER 306




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 13 "parser.y"

    int inum;
    double dnum;
    char cval;
    string * str;
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



/* Line 1676 of yacc.c  */
#line 193 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


