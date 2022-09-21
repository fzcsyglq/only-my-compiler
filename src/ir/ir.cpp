#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

#include "ir.h"

using namespace std;

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

void IR::module::enter_function(module *ir) {
    functions.push_back(IR::function());
    module *tem = ir;
    ir = &functions.back();
    ir->fa = tem;
}


void IR::function::exit_function(module *ir) {
    ir = fa;
}

void IR::function::add_function_type(int type) {
    return_type = type;
}

void IR::function::add_function_name(string name) {
    function_name = name;
}

IR::para_data* IR::function::add_function_parameter() {
    parameters.push_back(para_data());
    return &parameters.back();    
}

void IR::function::enter_block(module *ir) {
    blocks.push_back(block(0));
    module *tem = ir;    
    ir = &blocks.back();
    ir->fa = tem;    
}

void IR::block::exit_block(module *ir) {
    ir = fa;
}

void IR::block::add_block_id(int id) {
    block_id = id;
}
