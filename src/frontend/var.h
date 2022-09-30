#pragma once

#include "../common/utility.h"

namespace Var {
    
    enum {Int, Float, Void};

    class data {
        
    public:        
        
        int id, type;
        string name;
        bool is_const;
        data(){}

        void add_name(string name);

        void add_id(int id);

        void add_type(int type);
        
        virtual void add_size(int array_size) {}

        virtual int get_size(int dimension) {}

        virtual void alloca() {}

        virtual void change(int pos, shared_ptr<data> son) {}

        virtual shared_ptr<data> copy() {}
    };

    class var_int : public data {
        
    public:

        int value;
        
        var_int(int value = 0) : value(value) {
            type = Int;
            is_const = true;
        }
        shared_ptr<data> copy();
    };

    class var_float : public data {
        
    public:

        float value;
        
        var_float(float value = 0.0) : value(value){
            type = Float;
            is_const = true;
        }
        shared_ptr<data> copy();
    };
    
    class var_bool : public data {
        
    public:

        bool value;

        shared_ptr<data> copy();
    };
        
    class var_int_array : public data {
        
    public:

        vector<shared_ptr<data>> value;
        vector<int> size;
        
        var_int_array() {
            type = Int;
        }
        
        void add_size(int dimension);

        int get_size(int pos);

        void alloca();

        void change(int pos, shared_ptr<data> son);
        
        shared_ptr<data> copy();
    };

    class var_float_array : public data {
        
    public:

        vector<shared_ptr<data>> value;
        vector<int> size;

        var_float_array() {
            type = Float;
        }
        
        void add_size(int dimension);

        int get_size(int pos);

        void alloca();

        void change(int pos, shared_ptr<data> son);

        shared_ptr<data> copy();
    };


    class symbol_table {
        
    public:
        
        vector<map<string, shared_ptr<data>>> var, var_array;

        symbol_table() {
            in_stack();
        }

        void in_stack();

        void out_stack();

        shared_ptr<data> get_var(string name);

        shared_ptr<data> get_var_array(string name);

        void add_var(string name, shared_ptr<data> son);

        void add_var_array(string name, shared_ptr<data> son);
    };
}
