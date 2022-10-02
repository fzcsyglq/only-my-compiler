#include "ir.h"

void IR::module::enter_function(shared_ptr<IR> ir) {    
    functions.push_back(make_shared<function>(function()));
    auto tem = ir;
    ir = functions.back();
    ir->fa = tem;
}
void IR::module::add_to_int(shared_ptr<Var::data> son) {
    if (son->type == Int) return;
    else {
        if (son->is_const) {
            son = make_shared<Var::var_int>((int)dynamic_pointer_cast<Var::var_int>(son)->value);
        } else {
            shared_ptr<Var::data> result = make_shared<Var::var_int>();
            result->add_id(++id_cnt);
            add_instruction(Fptosi, result, son);
            son = result;
        }
    }
}
void IR::module::add_to_float(shared_ptr<Var::data> son) {
    if (son->type == Float) return;
    else {
        if (son->is_const) {
            son = make_shared<Var::var_float>((float)dynamic_pointer_cast<Var::var_int>(son)->value);
        } else {
            shared_ptr<Var::data> result = make_shared<Var::var_float>();
            result->add_id(++id_cnt);
            add_instruction(Sitofp, result, son);
            son = result;
        }
    }
}
void IR::module::add_unary_minus(shared_ptr<Var::data> son) {
    if (son->is_const) {
        if (son->type == Int) {
            int value = (int)dynamic_pointer_cast<Var::var_int>(son)->value;
            son = make_shared<Var::var_int>(-value);
        } else {
            float value = (float)dynamic_pointer_cast<Var::var_float>(son)->value;
            son = make_shared<Var::var_float>(-value);
        }        
    } else {
        shared_ptr<Var::data> result;        
        if (son->type == Int) result = make_shared<Var::var_int>();
        else result = make_shared<Var::var_float>();
        result->add_id(++id_cnt);
        add_instruction(Fneg, result, son);
        son = result;
    }
}
shared_ptr<Var::data> IR::module::add_binary_exp(int type, shared_ptr<Var::data> left, shared_ptr<Var::data> right) {    
    if (left->type != right->type) {
        add_to_float(left);
        add_to_float(right);
    }
    shared_ptr<Var::data> result;
    if (left->is_const && right->is_const) {

        if (left->type == Int) {
            int left_value = dynamic_pointer_cast<Var::var_int>(left)->value;
            int right_value = dynamic_pointer_cast<Var::var_int>(right)->value;
            if (type == Mul) result = make_shared<Var::var_int>(left_value * right_value);
            else if (type == Sdiv) result = make_shared<Var::var_int>(left_value / right_value);
            else if (type == Add) result = make_shared<Var::var_int>(left_value + right_value);
            else if (type == Sub) result = make_shared<Var::var_int>(left_value - right_value);
            else  result = make_shared<Var::var_int>(left_value % right_value);
            result->is_const = true;
        } else {
            float left_value = dynamic_pointer_cast<Var::var_float>(left)->value;
            float right_value = dynamic_pointer_cast<Var::var_float>(right)->value;
            if (type == Mul) result = make_shared<Var::var_float>(left_value * right_value);
            else if (type == Sdiv) result = make_shared<Var::var_float>(left_value / right_value);
            else if (type == Add) result = make_shared<Var::var_float>(left_value + right_value);
            else if (type == Sub) result = make_shared<Var::var_float>(left_value - right_value);
            result->is_const = true;
        }
    } else {
        if (left->type == Int) {
            result = make_shared<Var::var_int>(Var::var_int());
            result->add_id(++id_cnt);
            add_instruction(type, result, left, right);
        } else {
            result = make_shared<Var::var_float>(Var::var_float());
            result->add_id(++id_cnt);
            add_instruction(type, result, left, right);
        }
    }
    return result;
}
void IR::module::add_gep(shared_ptr<Var::data> son, shared_ptr<Var::data> left, shared_ptr<Var::data> right) {
    shared_ptr<Var::data> result;
    if (left->type == Int) result = make_shared<Var::var_int>();
    else result = make_shared<Var::var_float>();
    result->add_id(++id_cnt);
    add_instruction(Gep, result, left, right);
    son = result;
}
void IR::module::add_def(shared_ptr<Var::data> son) {
    global_var.push_back(son->copy());
}
void IR::function::exit_function(shared_ptr<IR> ir) {
    ir = fa;
}

void IR::function::add_function_type(int type) {
    return_type = type;
}

void IR::function::add_function_name(string name) {
    function_name = name;
}

shared_ptr<IR::para_data> IR::function::add_function_parameter() {    
    parameters.push_back(make_shared<para_data>());
    return parameters.back();    
}

void IR::function::enter_block(shared_ptr<IR> ir) {
    blocks.push_back(make_shared<block>(block(++id_cnt)));
    auto tem = ir;    
    ir = blocks.back();
    ir->fa = tem;    
}

void IR::block::exit_block(shared_ptr<IR> ir) {
    ir = fa;
}

void IR::block::add_block_id(int id) {
    block_id = id;
}
void IR::block::add_instruction(int type, shared_ptr<Var::data> result, shared_ptr<Var::data> left = nullptr, shared_ptr<Var::data> right = nullptr) {
    result = result->copy();
    if (left != nullptr) left = left->copy();
    if (right != nullptr) right = right->copy();
    instructions.push_back(make_shared<instruction>(instruction(type, result, left, right)));
}
void IR::block::add_alloca(shared_ptr<Var::data> son) {
    son->add_id(++id_cnt);
    add_instruction(Alloca, son);
}
void IR::block::add_def(shared_ptr<Var::data> son) {
    add_instruction(Store, son);
}
