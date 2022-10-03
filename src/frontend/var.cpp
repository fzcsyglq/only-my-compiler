#include "var.h"

void Var::data::add_name(string name) {
    this->name = name;
}
void Var::data::add_id(int id) {
    this->id = id;
}
void Var::data::add_type(int type) {
    this->type = type;
}
shared_ptr<Var::data> Var::var_int::copy() {
    return make_shared<Var::var_int>(*this);
}
shared_ptr<Var::data> Var::var_float::copy() {
    return make_shared<Var::var_float>(*this);
}
shared_ptr<Var::data> Var::var_bool::copy() {
    return make_shared<Var::var_bool>(*this);
}
shared_ptr<Var::data> Var::var_int_array::copy() {
    return make_shared<Var::var_int_array>(*this);
}
shared_ptr<Var::data> Var::var_float_array::copy() {
    return make_shared<Var::var_float_array>(*this);
}
void Var::var_int_array::add_size(shared_ptr<Var::data> son) {
    size.push_back(son);
}

void Var::var_float_array::add_size(shared_ptr<Var::data> son) {
    size.push_back(son);    
}
int Var::var_int_array::get_size(int dimension) {
    int ans = 1;
    for (int k = dimension; k < size.size(); k++)
        ans *= dynamic_pointer_cast<var_int>(size[k])->value;
    return ans;
}
int Var::var_float_array::get_size(int dimension) {
    int ans = 1;
    for (int k = dimension; k < size.size(); k++)
        ans *= dynamic_pointer_cast<var_int>(size[k])->value;
    return ans;
}
void Var::var_int_array::alloca() {
    for (int k = 1; k <= get_size(0); k++)
        value.push_back(make_shared<var_int>());
}
void Var::var_float_array::alloca() {
    for (int k = 1; k <= get_size(0); k++)
        value.push_back(make_shared<var_float>());
}
void Var::var_int_array::change(int pos, shared_ptr<data> son) {
    value[pos] = son->copy();    
}
void Var::var_float_array::change(int pos, shared_ptr<data> son) {
    value[pos] = son->copy();
}
void Var::var_int::out_def_ir(std::ofstream &out) {
    out << "@" << name << " = global i32 " << value << endl; 
}
void Var::var_float::out_def_ir(std::ofstream &out) {
    out << "@" << name << " = global float " << std::scientific << value << endl;
}
void Var::var_int_array::out_def_ir(std::ofstream &out) {
    out << "@" << name << " = global [" << get_size(0) << " x i32] [";
    for (int k = 0; k < value.size(); k++)
        out << "i32 " << dynamic_pointer_cast<Var::var_int>(value[k])->value << ",]"[k == value.size() - 1];
    out << endl;    
}
void Var::var_float_array::out_def_ir(std::ofstream &out) {
    out << "@" << name << " = global [" << get_size(0) << " x float] [";
    for (int k = 0; k < value.size(); k++)
        out << "float " << std::scientific << dynamic_pointer_cast<Var::var_float>(value[k])->value << ",]"[k == value.size() - 1];
    out << endl;
}
void Var::symbol_table::in_stack() {
    var.push_back(map<string, shared_ptr<data>>());
    var_array.push_back(map<string, shared_ptr<data>>());
}
void Var::symbol_table::out_stack() {    
    var.pop_back();
}
shared_ptr<Var::data> Var::symbol_table::get_var(string name) {
    for (int k = var.size() - 1; k >= 0; k--) {
        if (var[k].find(name) != var[k].end()) {            
            return var[k][name]->copy();
        }
    }
}
shared_ptr<Var::data> Var::symbol_table::get_var_array(string name) {
    for (int k = var.size() - 1; k >= 0; k--) {
        if (var_array[k].find(name) != var_array[k].end()) {
            return var[k][name]->copy();
        }
    }
}
void Var::symbol_table::add_var(string name, shared_ptr<data> son) {
    var.back()[name] = son->copy();
}
void Var::symbol_table::add_var_array(string name, shared_ptr<data> son) {
    var.back()[name] = son->copy();
}

