#include "out_ir.h"

enum {Int, Float, Void};
enum {Alloca, Store, Load, Br, Call, Const, Ret, Function, Add, Sub, Mul, Sdiv, Srew, Fptosi, Sitofp, Fneg, Gep};

void out_alloca(shared_ptr<IR::instruction> ir, std::ofstream &out) {
    out << "%" << ir->result->id << " alloca ";
    if (!ir->result->is_array()) {
        
        if (ir->type == Int) out << "i32" << endl;
        else out << "float" << endl;
    } else {
        if (ir->type == Int) out << "[" << ir->result->get_size(0) << " x i32]" << endl;
        else out << "[" << ir->result->get_size(0) << " x float]" << endl;
    }
}
void out_store(shared_ptr<IR::instruction> ir, std::ofstream &out) {
    
}
void out_load(shared_ptr<IR::instruction> ir, std::ofstream &out) {
    
}
void out_block(shared_ptr<IR::block> ir, std::ofstream &out) {
    for (auto k : ir->blocks) {
        shared_ptr<IR::instruction> to = dynamic_pointer_cast<IR::instruction>(k);
        if (to->type == Alloca) out_alloca(to, out);
        else if (to->type == Store) out_store(to, out);
        else if (to->type == Load) out_load(to, out);
    }
}

void out_function(shared_ptr<IR::function> ir, std::ofstream &out) {
    for (auto k : ir->blocks) {
        shared_ptr<IR::block> to = dynamic_pointer_cast<IR::block>(ir); 
        if (~k->block_id) out << k->block_id << ":" << endl;
        out_block(to, out);
    }    
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
        for (int i = 0; i < k->parameters.size(); i++) {
            if (k->parameters[i]->type == Int) out << "i32";
            else out << "float";

            if (k->parameters[i]->is_array()) out << "*";
            
            out << " " << k->parameters[i]->id;            
            if (i < k->parameters.size()) out << ", ";
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
