#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>

#include "SysYLexer.h"
#include "SysYParser.h"
#include "visitor.h"
#include "../ir/ir.h"
#include "../backend/asm.h"

using namespace antlr4;
using namespace std;

int main(int argc, char *argv[])
{
    string filename = argv[4];
    ifstream source;
    source.open(filename);

    
    ANTLRInputStream input(source);
    SysYLexer lexer(&input);

    CommonTokenStream tokens(&lexer);

//    int n = tokens.getNumberOfOnChannelTokens();
//    cout<<n<<endl;
    
    SysYParser parser(&tokens);

    SysYParser::CompUnitContext *root = parser.compUnit();

    IR::CompUnit ir(ir.content);
    Visitor visitor(ir);
    visitor.visitCompUnit(root);

    ofstream out;
    string out_filename = argv[3];
    out.open(out_filename);
    ASM::Asm Aas;
    Aas.get_asm(&ir, out);
    return 0;
}
