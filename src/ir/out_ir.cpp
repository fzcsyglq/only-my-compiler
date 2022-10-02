#include "out_ir.h"

enum {Int, Float, Void};

void out_function(shared_ptr<IR::function> ir, std::ofstream &out) {
    
}

void out_module(shared_ptr<IR::module> ir, std::ofstream &out) {    
    for (auto k : ir->global_var) {
        k->out_def_ir(out);
    }
    for (auto k : ir->functions) {
        
        shared_ptr<IR::function> to = dynamic_pointer_cast<IR::function>(k);
        out << "define ";
        if (k->return_type == Int) out << "i32 @";
        else if (k->return_type == Float) out << "float @";
        else out << "void @";
        out << k->function_name << "(";
        for (auto i : k->parameters) {
            
        }
        out << ")" << endl;
        out_function(to, out);        
    }
}

void out_ir(shared_ptr<IR::IR> ir) {
    std::ofstream out("1.ll");
    out << "target triple = \"x86_64-pc-linux-gnu\"" << endl;
    out_module(dynamic_pointer_cast<IR::module>(ir), out);
    return;
}
