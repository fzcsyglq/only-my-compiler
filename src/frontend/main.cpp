#include "../common/utility.h"
#include "SysYLexer.h"
#include "SysYParser.h"
#include "visitor.h"
#include "../ir/ir.h"
//#include "../backend/asm.h"

using namespace antlr4;
using namespace std;

int main(int argc, char *argv[])
{
    string filename = argv[1];
    cout<<filename<<endl;
 
    ifstream source(filename);
    
        
    ANTLRInputStream input(source);
    SysYLexer lexer(&input);    
    CommonTokenStream tokens(&lexer);    
    SysYParser parser(&tokens);

    SysYParser::CompUnitContext *root = parser.compUnit();

    
    IR::module ir;

    Visitor visitor(&ir);
    

    visitor.visitCompUnit(root); 

    // ofstream out;
    // string out_filename = argv[3];
    // out.open(out_filename);
    // ASM::Asm Asm;
     // Asm.get_asm(&ir, out);
    return 0;
}
