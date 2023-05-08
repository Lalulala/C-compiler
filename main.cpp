#include <iostream>
#include "AST.h"
extern AST::Program * Root;
extern int yyparse();

int main(int argc, char **argv)
{
    yyparse();
    std::cout << Root << std::endl;
    return 0;
}