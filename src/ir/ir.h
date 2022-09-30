#pragma once

#include "../common/utility.h"
#include "../frontend/var.h"

namespace IR {
    
    enum {Alloca, Store, Load, Br, Call, Const, Ret, Function, Add, Sub, Mul, Sdiv, Srew, Fptosi, Sitofp, Fneg, Gep};
    enum {Int, Float, Void};
    
    class module;
    class function;
    class block;
    class instruction;
    class para_data {
    public:
        int type;
        string name;
        vector<Var::data> exp;
    };

    class IR {
        
    public:
        
        shared_ptr<IR> fa;
        
        
        virtual void enter_function(shared_ptr<IR> ir) {}

        virtual void exit_function(shared_ptr<IR> ir) {}

        virtual void add_function_type(int type) {}

        virtual void add_function_name(string name) {}
        
        virtual shared_ptr<para_data> add_function_parameter() {return nullptr;}

        virtual void enter_block(shared_ptr<IR> ir) {}

        virtual void exit_block(shared_ptr<IR> ir) {}

        virtual void add_block_id(int id) {}

        virtual void add_to_int(shared_ptr<Var::data> son) {}

        virtual void add_to_float(shared_ptr<Var::data> son) {}

        virtual void add_def(string name, shared_ptr<Var::data> son) {}

        virtual void add_instruction(int type, shared_ptr<Var::data> result, shared_ptr<Var::data> left = nullptr, shared_ptr<Var::data> right = nullptr) {}

        virtual void add_unary_minus(shared_ptr<Var::data> son) {}

        virtual void add_unary_not(shared_ptr<Var::data> son) {}

        virtual void add_binary_exp(int type, shared_ptr<Var::data> son, shared_ptr<Var::data> left, shared_ptr<Var::data> right) {}

        virtual void add_gep(shared_ptr<Var::data> son, shared_ptr<Var::data> left, shared_ptr<Var::data> right) {}
    };
    
    
    class module : public IR {
        
    public:
        int id_cnt;
        vector<shared_ptr<Var::data>> global_var;
        vector<shared_ptr<function>> functions;

        module(){}
        
        void enter_function(shared_ptr<IR> ir);
            
        void add_to_int(shared_ptr<Var::data> son);

        void add_to_float(shared_ptr<Var::data> son);

        void add_unary_minus(shared_ptr<Var::data> son);

        void add_mul_exp();
        
        void add_def(string name, shared_ptr<Var::data> son);

        void add_binary_exp(int type, shared_ptr<Var::data> son, shared_ptr<Var::data> left, shared_ptr<Var::data> right);

        void add_gep(shared_ptr<Var::data> son, shared_ptr<Var::data> left, shared_ptr<Var::data> right);
    };

    class function : public module {
        
    public:

        int return_type;        
        string function_name;        


        vector<shared_ptr<para_data>> parameters;
        
        vector<shared_ptr<block>> blocks;
        
        function() {
            id_cnt = -1;
        }

        void add_function_type(int type);

        void add_function_name(string name);

        shared_ptr<para_data> add_function_parameter();

        void exit_function(shared_ptr<IR> ir);

        void enter_block(shared_ptr<IR> ir);
    };
    
    class block : public  function {

    public:
        
        int block_id;
        vector<shared_ptr<instruction>> instructions;

        block() {}
        block(int id) : block_id(id) {}
        virtual ~block();

        void add_block_id(int id);
        
        void exit_block(shared_ptr<IR> ir);

        void add_to_int(shared_ptr<Var::data> son);

        void add_to_float(shared_ptr<Var::data> son);
        
        void add_unary_minus(shared_ptr<Var::data> son);
        
        void add_def(string name, shared_ptr<Var::data> son);

        void add_instruction(int type, shared_ptr<Var::data> result, shared_ptr<Var::data> left, shared_ptr<Var::data> right);
    };

    class instruction : public block {

    public:
                
        int type, instruction_id;
        shared_ptr<Var::data> result, left, right;
        
        instruction(){}        
        instruction(int type, shared_ptr<Var::data> result, shared_ptr<Var::data> left, shared_ptr<Var::data> right):
            type(type), result(result), left(left), right(right) {}
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
