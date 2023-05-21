#include <iostream>
#include "AST.h"
extern AST::Program * Root;
extern int yyparse();

int main(int argc, char **argv)
{
    yyparse();

    std::string Json = Root.astJson();
    ofstream fout;
    fout.open("AST.json");
    fout << jsonString;
    fout.close();

    std::cout << Root << std::endl;
    return 0;
}

//仿照那个C-compoler中的Visualization.cpp，给每个节点class写一个astJson函数，
//astJson函数中的字符串处理和Visualization.cpp中一样就行，保证能跑通就可以
//最上面的getJson和getString函数直接复制过来就行
//把AST.json放进目录，main.cpp替换原来的
//测试的话，就输完要分析的C语言，看AST.json文件里写进去的是什么就行
//先把能写进去实现就行，写的结果我来看对不对