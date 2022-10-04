#pragma once

#include "../common/utility.h"

namespace Var {
    
    enum {Int, Float, Void};

    class data {
        
    public:        
        
        int id, type;
        string name;
        bool is_const;

        void add_name(string name);

        void add_id(int id);

        void add_type(int type);
        
        virtual void add_size(int length) {}

        virtual int get_size(int demension) {return -1;}

        virtual void alloca() {}

        virtual void change(int pos, shared_ptr<data> son) {}

        virtual shared_ptr<data> copy() {return nullptr;}

        virtual void out_def_ir(std::ofstream &out) {}
    };

    class var_int : public data {
        
    public:        
        int value;

        var_int(int value = 0) : value(value) {
            type = Int;
            is_const = true;
        }
        
        shared_ptr<data> copy();

        void out_def_ir(std::ofstream &out);
    };

    class var_float : public data {
        
    public:

        float value;
        
        var_float(float value = 0.0) : value(value) {
            type = Float;
            is_const = true;
        }
        
        shared_ptr<data> copy();

        void out_def_ir(std::ofstream &out);
        
    };
    
    class var_bool : public data {
        
    public:

        bool value;

        var_bool() {}

        shared_ptr<data> copy();
    };
        
    class var_int_array : public data {
        
    public:

        vector<shared_ptr<data>> value;
        vector<int> size;

        var_int_array() {
            type = Int;
        }

        void add_size(int length);

        int get_size(int dimension);

        void alloca();

        void change(int pos, shared_ptr<data> son);
        
        shared_ptr<data> copy();

        void out_def_ir(std::ofstream &out);
    };

    class var_float_array : public data {
        
    public:

        vector<shared_ptr<data>> value;
        vector<int> size;

        var_float_array() {
            type = Float;
        }
        
        void add_size(int length);

        int get_size(int dimension);

        void alloca();

        void change(int pos, shared_ptr<data> son);

        shared_ptr<data> copy();

        void out_def_ir(std::ofstream &out);
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
