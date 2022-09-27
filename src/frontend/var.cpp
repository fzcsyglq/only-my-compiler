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
Var::data* Var::symbol_table::get_var(string name) {
    for (int k = var.size() - 1; k >= 0; k--) {
        if (var[k].find(name) != var[k].end()) {
            return new Var::data(var[k][name]);
        }
    }
}

Var::data* Var::symbol_table::get_var_array(string name) {
    for (int k = var.size() - 1; k >= 0; k--) {
        if (var_array[k].find(name) != var_array[k].end()) {
            return new Var::data(var[k][name]);
        }
    }
}
void Var::symbol_table::add_var(string name, data *son) {
    vector.back()[name] = *son;
}
void Var::symbol_table::add_var_array(string name, data *son) {
    vector.back()[name] = 
}
void Var::var_int_array::add_size(data *array_size) {
    size.push_back(*array_size);
}

void Var::var_float_array::add_size(data *array_size) {
    size.push_back(*array_size);    
}

