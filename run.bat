del lex.yy.c y.tab.c y.tab.h y.output a.exe
bison --yacc -dv parser.y
flex token.l
g++ y.tab.c lex.yy.c