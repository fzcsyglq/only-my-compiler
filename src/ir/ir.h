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

    class IR {
        
    public:
        
        shared_ptr<IR> fa;
        
        virtual void enter_function(shared_ptr<IR> ir) {}

        virtual void exit_function(shared_ptr<IR> ir) {}

        virtual void add_function_type(int type) {}
        
        virtual void add_function_name(string name) {}
        
        virtual shared_ptr<Var::data> add_function_parameter() {}
        
        virtual void enter_block(shared_ptr<IR> ir) {}
        
        virtual void exit_block(shared_ptr<IR> ir) {}

        virtual void add_block_id(int id) {}

        virtual void add_to_int(shared_ptr<Var::data> son) {}

        virtual void add_to_float(shared_ptr<Var::data> son) {}

        virtual void add_def(shared_ptr<Var::data> son) {}

        virtual void add_instruction(int type, shared_ptr<Var::data> result, shared_ptr<Var::data> left = nullptr, shared_ptr<Var::data> right = nullptr) {}

        virtual void  add_unary_minus(shared_ptr<Var::data> son) {}

        virtual void add_unary_not(shared_ptr<Var::data> son) {}

        virtual shared_ptr<Var::data> add_binary_exp(int type, shared_ptr<Var::data> left, shared_ptr<Var::data> right) {}

        virtual void add_gep(shared_ptr<Var::data> son, shared_ptr<Var::data> left, shared_ptr<Var::data> right) {}

        virtual void add_alloca(shared_ptr<Var::data> son) {}

        virtual void add_para(shared_ptr<Var::data> son) {}
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
        
        void add_def(shared_ptr<Var::data> son);

        shared_ptr<Var::data> add_binary_exp(int type, shared_ptr<Var::data> left, shared_ptr<Var::data> right);

        void add_gep(shared_ptr<Var::data> son, shared_ptr<Var::data> left, shared_ptr<Var::data> right);        
    };

    class function : public module {
        
    public:

        int return_type;        
        string function_name;        

        vector<shared_ptr<Var::data>> parameters;
        
        vector<shared_ptr<block>> blocks;
        
        function() {
            id_cnt = -1;
        }

        void add_function_type(int type);

        void add_function_name(string name);

        shared_ptr<Var::data> add_function_parameter();

        void exit_function(shared_ptr<IR> ir);

        void enter_block(shared_ptr<IR> ir);

        void add_para(shared_ptr<Var::data> son);
    };
    
    class block : public  function {

    public:
        
        int block_id;
        vector<shared_ptr<instruction>> instructions;

        block() {}
        block(int id) : block_id(id) {}

        void add_block_id(int id);
        
        void exit_block(shared_ptr<IR> ir);

        void add_alloca(shared_ptr<Var::data> son);

        void add_def(shared_ptr<Var::data> son);

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
        
};
