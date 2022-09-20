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
    
    class data {
        
    public:
        
        int id;
        string name;
        bool is_global, is_const;
    };

    class var_int : public data {

    public:
        
        int value;        
    };

    class var_float : public data {
        
    public:
        
        float value;
    };

    class var_int_array : public data {
        
    public:

        vector<int> value;
        vector<int> size;
        
    };

    class var_float_array : public data {
        
    public:

        vector<float> value;
        vector<int> size;
    };

    class symbol_table {
        
    public:

        vector<map<string, data>> var, var_array;
        
    };

    class module;
    class function;
    class block;
    class instruction;
    
    class module {
        
    public:

        vector<data> global_var;
        vector<function> functions;
        module *fa;

        void enter_function(module *ir);

        virtual void add_function_type(int type) {};

        virtual void add_function_name(string name) {};

        virtual void add_function_parameter(data parameter) {};
        
        void exit_function(module *ir);

    };

    class function : public module{
        
    public:

        int id_cnt, return_type;        
        string function_name;        
        
        class para_data {
        public:
            int type;
            string name;
            vector<data> exp;
        };
        vector<para_data> oparameters;
        
        vector<block> blocks;
        
        function() {
            id_cnt = 0;
        }

        void add_function_type(int type);

        void add_function_name(string name);

        void add_function_parameter(data parameter);
    };
    
    class block : function{

    public:

        int block_id;
        vector<instruction> instructions;

    };

    class instruction : block{

    public:
        int type, instruction_id;
        data result, left, right;
    };

    
    

    // class CompUnit {
        
    // public:
        
    //     vector<command> content; //store command
    //     vector<command> &now; //define ir need
    //     int cnt; //count command id
    //     bool is_const, is_global; // is const define, is global define
    //     int pre_type; // define type
    //     int lst, lst_type, lst_value; //lst id, lst type, lst const number
    //     int lst_arr_index;
    //     int lst_pos;
    //     CompUnit(vector<command> &now):
    //         now(now) {
    //         pre_type = -1;
    //         cnt = 0;
    //         is_const = false;
    //         is_global = true;
    //     }

    //     void add_VarDef1(data _result);

    //     void add_VarDef2(string name, int pos);

    //     void add_MulExp(int type, data _left, data _right);

    //     void add_Int(int value);

    //     void add_Float(float value);

    //     void add_Return();

    //     void add_LVal(string name);

    //     void enter_Func(int type, string name);

    //     void exit_Func();
    // };
    
    
};
