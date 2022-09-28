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
Var::data* Var::var_int::copy() {
    return new var_int(*this);
}
Var::data* Var::var_float::copy() {
    return new var_float(*this);
}
Var::data* Var::var_bool::copy() {
    return new var_bool(*this);
}
Var::data* Var::var_int_array::copy() {
    return new var_int_array(*this);
}
Var::data* Var::var_float_array::copy() {
    return new var_float_array(*this);
}
Var::var_int_array::~var_int_array() {
    for (auto k : value)
        delete k;
}
Var::var_float_array::~var_float_array() {
    for (auto k : value)
        delete k;
}
void Var::var_int_array::add_size(int array_size) {
    size.push_back(array_size);
}

void Var::var_float_array::add_size(int array_size) {
    size.push_back(array_size);    
}
int Var::var_int_array::get_size(int dimension) {
    int ans = 1;
    for (int k = dimension; k < size.size(); k++)
        ans *= size[k];
    return ans;
}
int Var::var_float_array::get_size(int dimension) {
    int ans = 1;
    for (int k = dimension; k < size.size(); k++)
        ans *= size[k];
    return ans;
}
void Var::var_int_array::alloca() {
    for (int k = 1; k <= get_size(0); k++)
        value.push_back(new var_int());
}
void Var::var_float_array::alloca() {
    for (int k = 1; k <= get_size(0); k++)
        value.push_back(new var_float());
}
void Var::var_int_array::change(int pos, data *son) {
    delete value[pos];
    value[pos] = son->copy();    
}
void Var::var_float_array::change(int pos, data *son) {
    delete value[pos];
    value[pos] = son->copy();
}
void Var::symbol_table::in_stack() {
    var.push_back(map<string, data*>());
    var_array.push_back(map<string, data*>());
}
void Var::symbol_table::out_stack() {
    for (auto k : var.back())
        delete k.second;
    for (auto k : var_array.back())
        delete k.second;
    var.pop_back();
}
Var::data* Var::symbol_table::get_var(string name) {
    for (int k = var.size() - 1; k >= 0; k--) {
        if (var[k].find(name) != var[k].end()) {
            return new Var::data(*var[k][name]);
        }
    }
}
Var::data* Var::symbol_table::get_var_array(string name) {
    for (int k = var.size() - 1; k >= 0; k--) {
        if (var_array[k].find(name) != var_array[k].end()) {
            return new Var::data(*var[k][name]);
        }
    }
}
void Var::symbol_table::add_var(string name, data *son) {
    var.back()[name] = new Var::data(*son);
}
void Var::symbol_table::add_var_array(string name, data *son) {
    var.back()[name] = new Var::data(*son);
}
