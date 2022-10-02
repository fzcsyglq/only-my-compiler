#include "../common/utility.h"
#include "SysYLexer.h"
#include "SysYParser.h"
#include "visitor.h"
#include "../ir/ir.h"
#include "../ir/out_ir.h"
//#include "../backend/asm.h"

using namespace antlr4;
using namespace std;

int main(int argc, char *argv[])
{
    string filename = argv[1];
    cout << filename << endl;
    ifstream source(filename);
    
        
    ANTLRInputStream input(source);
    SysYLexer lexer(&input);    
    CommonTokenStream tokens(&lexer);    
    SysYParser parser(&tokens);

    SysYParser::CompUnitContext *root = parser.compUnit();

    
    shared_ptr<IR::IR> ir = make_shared<IR::module>();

    Visitor visitor(ir);
    

    visitor.visitCompUnit(root);
    
    out_ir(ir);
    // ofstream out;
    // string out_filename = argv[3];
    // out.open(out_filename);
    // ASM::Asm Asm;
     // Asm.get_asm(&ir, out);
    return 0;
}
