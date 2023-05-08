%{
#include "AST.h"
#include "y.tab.h"
#include <stdio.h>
#include <iostream>
#include <string>
extern "C" int yywrap() {return 1;}
 
%}
INUM [1-9]+[0-9]*|0
DNUM [0-9]+"."[0-9]*
%%
"if"              {return IF;}
"else"            {return ELSE;}
"do"              {return DO;}
"for"             {return FOR;}
"while"           {return WHILE;}
"switch"          {return SWITCH;}
"case"			  {return CASE;}
"default"		  {return DEFAULT;}
"continue"		  {return CONTINUE;}
"break"			  {return BREAK; }
"return"		  {return RETURN;}
"char"			  {return CHAR; }
"float"			  {return FLOAT; }
"double"		  {return DOUBLE; }
"void"			  {return VOID; }
"bool"			  {return BOOL; }
"short"			  {return SHORT; }
"int"			  {return INT; }
"long"		      {return LONG; }

","               {return COMMA;}
":"               {return COLON;}
";"               {return SEMI;}
"("               {return LPAREN;}
")"               {return RPAREN;}
"{"               {return LBRACE;}
"}"               {return RBRACE;}
"["               {return LBRACKET;}
"]"               {return RBRACKET;}
"="               {return ASSIGN;}
"=="              {return EQU;}
"!="              {return NE;}
">"               {return GT;}
">="              {return GE;}
"<"               {return LT;}
"<="              {return LE;}
"+"               {return PLUS;}
"-"               {return SUB;}
"*"               {return MUL;}
"/"               {return DIV;}
"&"               {return SAND;}
"!"               {return NOT;}
"%"               {return MOD;}
"&&"              {return AND;}
"||"              {return OR;}

[ \t\n]													
"/*"[^*]*[*]+([^*/][^*]*[*]+)*"/"						
"//".*	
\'[^\\']\'                                 {yylval.cval = yytext[1]; return CHARACTER;  }
\"(\\.|[^\\"])*\"                          {yylval.str= new std:: string(yytext,yyleng); return STRING;}

[a-zA-Z_][a-zA-Z0-9_]*	                   {yylval.str= new std:: string(yytext,yyleng); return Identifier;}
{INUM}                                     {sscanf(yytext,"%d",&yylval.inum); return INTERGER;}
{DNUM}                                     {sscanf(yytext,"%lf",&yylval.dnum); return REAL;	}											
%%
