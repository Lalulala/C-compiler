%{
#include "AST.h"
#include "y.tab.h"
#include <stdio.h>
#include <iostream>
#include <string>
extern "C" int yywrap() {return 1;}
 char Escape2Char(char ch){
	switch(ch){
	case 'b': return '\b';
	case 'n': return '\n';
	case 'r': return '\r';
	case 't': return '\t';
	case '\\': return '\\';
	case '\'': return '\'';
	case '\"': return '\"';
	default:
		if ('0'<=ch && ch<='9')
			return (char)(ch-'0');
		else
			return ch;
	}
}
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
\'"\\."\'                                  {yylval.cVal = Escape2Char(yytext[2]);return CHARACTER; }
\'[^\\']\'                                 {yylval.cval = yytext[1]; return CHARACTER;  }
\"(\\.|[^\\"])*\"                          {yylval.str= new std:: string(""); 
                                            for (int i = 1; i <= yyleng-2; i++)
											if (yytext[i] == '\\'){
												i++;
												yylval.strVal->push_back(Escape2Char(yytext[i]));
											}else{
												yylval.strVal->push_back(yytext[i]);
											    }
											 return STRING;}

[a-zA-Z_][a-zA-Z0-9_]*	                   {yylval.str= new std:: string(yytext,yyleng); return Identifier;}
{INUM}                                     {sscanf(yytext,"%d",&yylval.inum); return INTERGER;}
{DNUM}                                     {sscanf(yytext,"%lf",&yylval.dnum); return REAL;	}											
%%
