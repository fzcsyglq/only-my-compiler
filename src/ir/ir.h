#pragma once

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>

using std::string;
using std::vector;
using std::map;
using std::stack;

namespace IR {
    
    enum {Alloca, Store, Load, Br, Call, Const, Ret, Function, Add, Sub, Mul, Sdiv, Srew};
    enum {Int, Float, Void};

    class code {};
    
    class part : public code {};

    class data {
        
    public:
        int id, type, value, pos;
        string name;
        bool is_global, is_const;
        vector<int> arr;
        int arr_index;
        
        data() {
            arr_index = 0;
            pos = 0;
            is_const = false;
            value = 0;
        }
        data(int id, int type, bool is_global, int pos = 0, int value = 0, bool is_const = false):
            id(id), type(type), is_global(is_global), pos(pos), value(value), is_const(is_const){
            arr_index = 0;
        }

    };
    
    class function : public code{
        data ret;
        string name;
        vector<data> para;
        vector<part> content;
    };
    
    class command : public part {
        
    public:
        
        data result, left, right;
        int type;
        bool is_const;

        
        command(){is_const = false;}
        command(int type, data result, data left, data right, bool is_const = false):
            type(type), result(result), left(left), right(right) {
            this->is_const = is_const;
        }

        void add(bool _is_const) {
            is_const = _is_const;
        }
    };
    
    class block : public part {
        int id;
        vector<command> content;
        map<string, int> ma;
    };
    
    class CompUnit {
    public:
        
        vector<command> content; //store command
        vector<command> &now; //define ir need
        int cnt; //count command id
        bool is_const, is_global; // is const define, is global define
        int pre_type; // define type
        int lst, lst_type, lst_value; //lst id, lst type, lst const number
        vector<map<string, data>> var, value; //var name to information, global name to informatoin
        int lst_arr_index;
        int lst_pos;
        CompUnit(vector<command> &now):
            now(now) {
            pre_type = -1;
            cnt = 0;
            var.push_back(map<string, data>());
            value.push_back(map<string, data>());
            is_const = false;
            is_global = true;
        }

        void add_VarDef1(data _result);

        void add_VarDef2(string name, int pos);

        void add_MulExp(int type, data _left, data _right);

        void add_Int(int value);

        void add_Float(float value);

        void add_Return();

        void add_LVal(string name);

        void enter_Func(int type, string name);

        void exit_Func();
    };
};
