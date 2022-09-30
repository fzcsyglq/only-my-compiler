#include "ir.h"

// void IR::CompUnit::add_VarDef1(IR::data _result) {
//     IR::data result, left, right;


//     result = _result, result.pos *= 4;
//     cout<<"hahahahaha"<<result.pos<<endl;
//     left = IR::data();
//     right = IR::data();
//     content.push_back(IR::command(Alloca, result, left, right));

//     IR::data x = IR::data(cnt, pre_type, is_global, result.pos);
//     x.arr = _result.arr;
//     var.back()[result.name] = x;
//     return;    
// }

// void IR::CompUnit::add_VarDef2(string name, int pos) {
//     IR::data result, left, right;
//     if (is_const) {
//         result = IR::data();
//         left = IR::data();
//         right = IR::data(0, lst_type, is_global, (pos - 1) * 4, lst_value, true), right.name = name;
//         content.push_back(IR::command(Load, result, left, right));

//         result = IR::data();
//         left = IR::data(0, lst_type, is_global, (pos - 1) * 4, lst_value, true);
//         int id;
//         for (int k = var.size() - 1; k >= 0; k--) {
//             if (var[k].find(name) != var[k].end()) {
//                 id = var[k][name].id;
//                 break;
//             }
//         }//Type conversion
//         right = IR::data(id, pre_type, is_global, (pos - 1) * 4);
//         content.push_back(IR::command(Store, result, left, right));
//         IR::data x = IR::data(id, pre_type, is_global);
//         x.value = lst_value;
//         value.back()[name + "[" + to_string(pos) + "]"] = x;
//     } else {
//         result = IR::data();
//         left = IR::data(lst, lst_type, is_global);
//         int id;
//         for (int k = var.size() - 1; k >= 0; k--) {
//             if (var[k].find(name) != var[k].end()) {
//                 id = var[k][name].id;
//                 break;
//             }
//         }//Type conversion
//         right = IR::data(id, pre_type, is_global, (pos - 1) * 4);
//         content.push_back(IR::command(Store, result, left, right));
//     }
//     return;
// }

// void IR::CompUnit::add_MulExp(int type, IR::data _left, IR::data _right) {

//     IR::data result, left, right;
//     if(is_const) {
//         if (type == Add) lst_value = _left.value + _right.value;
//         else if (type == Sub) lst_value = _left.value - _right.value;
//         else if (type == Mul) lst_value = _left.value * _right.value;
//         else if (type == Sdiv) lst_value = _left.value / _right.value;
//         else if (type == Srew) lst_value = _left.value % _right.value;
//     } else {
//         cout<<_left.id<<" "<<_right.id<<endl;
//         if (_left.type == _right.type) {
//             result = IR::data();
//             left = IR::data();
//             right = _left;
//             content.push_back(IR::command(Load, result, left, right));
            
//             result = IR::data();
//             left = IR::data();
//             right = _right;
//             content.push_back(IR::command(Load, result, left, right));

//             result = IR::data();
//             left = _left;
//             right = _right;
//             content.push_back(IR::command(type, result, left, right));

//             result = IR::data(++cnt, _left.type, is_global, 4);
//             left = IR::data();
//             right = IR::data();
//             content.push_back(IR::command(Alloca, result, left, right));

//             result = IR::data();
//             left = IR::data();
//             right = IR::data(cnt, _left.type, is_global);
//             content.push_back(IR::command(Store, result, left, right));

//             lst_type = Int;
//         }
//         lst = cnt;
//     }

//     return;
// }

// void IR::CompUnit::add_Int(int value) {
//     cout<<"nizdgjufme"<<value<<endl;
//     IR::data result, left, right;
//     if (is_const) {
//         lst_value = value;
//     } else {
//         result = IR::data(++cnt, Int, is_global, 4, value);
//         left = IR::data();
//         right = IR::data();
//         now.push_back(command(Alloca, result, left, right, is_const));

//         result = IR::data();
//         left = IR::data();
//         right = IR::data(cnt, Int, is_global, 0, value, true);
//         now.push_back(command(Load, result, left, right));
    
//         result = IR::data();
//         left = IR::data(0, Int, is_global);
//         right = IR::data(cnt, Int, is_global);
//         now.push_back(command(Store, result, left, right));

//         lst = cnt;
//         lst_type = Int;
//     }
//     return;
// }

// void IR::CompUnit::add_Float(float value) {
//     cnt++;
// }

// void IR::CompUnit::add_Return() {
//     IR::data result, left, right;

//     result = IR::data();
//     left = IR::data();
//     right = IR::data(lst, lst_type, is_global);
//     content.push_back(IR::command(Ret, result, left, right));
//     return;
// }

// void IR::CompUnit::add_LVal(string name) {
//     IR::data result, left, right;
//     result = IR::data();
//     left = IR::data();
//     for (int k = var.size() - 1; k >= 0; k--) {
//         if (var[k].find(name) != var[k].end()) {
//             right = var[k][name];
//             lst = var[k][name].id;
// //            if (is_const)
// //                lst_value = value[k][name + "[" + to_string(pos) + "]"].value;
//             break;
//         }
//     }
// //    right.pos = -1;
// //    content.push_back(IR::command(Load, result, left, right));
//     lst = right.id;
//     return;
// }

// void IR::CompUnit::enter_Func(int type, string name) {
//     is_global = false;
//     var.push_back(map<string, IR::data>());
    
//     IR::data result, left, right;

//     result = IR::data();
//     left = IR::data();
//     right = IR::data(0, type, is_global), right.name = name;
//     content.push_back(IR::command(Function, result, left, right));
//     return;
// }

// void IR::CompUnit::exit_Func() {
//     is_global = true;
//     var.pop_back();
//     return;
// }

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
            son = make_shared<Var::data>(Var::var_int());
            son = make_shared<Var::data>(Var::var_int((int)dynamic_pointer_cast<Var::var_int>(son)->value));
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
            son = make_shared<Var::data>(Var::var_float((float)dynamic_pointer_cast<Var::var_int>(son)->value));
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
            son = make_shared<Var::data>(Var::var_int(-value));
        } else {
            float value = (float)dynamic_pointer_cast<Var::var_float>(son)->value;
            son = make_shared<Var::data>(Var::var_float(-value));
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
void IR::module::add_binary_exp(int type, shared_ptr<Var::data> son, shared_ptr<Var::data> left, shared_ptr<Var::data> right) {    
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
            son = result;
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
    son = result;
}
void IR::module::add_gep(shared_ptr<Var::data> son, shared_ptr<Var::data> left, shared_ptr<Var::data> right) {
    shared_ptr<Var::data> result;
    if (left->type == Int) result = make_shared<Var::var_int>();
    else result = make_shared<Var::var_float>();
    result->add_id(++id_cnt);
    add_instruction(Gep, result, left, right);
    son = result;
}
void IR::module::add_def(string name, shared_ptr<Var::data> son) {
    global_var.push_back(son->copy());
    global_var.back()->add_name(name);    
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
    parameters.push_back(make_shared<para_data>(para_data()));
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
void IR::block::add_def(string name, shared_ptr<Var::data> son) {
    add_instruction(Store, son);
}
