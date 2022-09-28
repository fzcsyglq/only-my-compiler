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
        virtual ~data(){}

        void add_name(string name);

        void add_id(int id);

        void add_type(int type);
        
        virtual void add_size(int array_size) {}

        virtual int get_size(int dimension) {}

        virtual void alloca() {}

        virtual void change(int pos, data *son) {}

        virtual data* copy() {}
    };

    class var_int : public data {
        
    public:

        int value;
        
        var_int(int value = 0) : value(value) {
            type = Int;
            is_const = true;
        }
        data* copy();
    };

    class var_float : public data {
        
    public:

        float value;
        
        var_float(float value = 0.0) : value(value){
            type = Float;
            is_const = true;
        }
        data* copy();
    };
    
    class var_bool : public data {
        
    public:

        bool value;

        data* copy();
    };
        
    class var_int_array : public data {
        
    public:

        vector<data*> value;
        vector<int> size;
        
        var_int_array() {
            type = Int;
        }
        ~var_int_array();
        
        void add_size(int dimension);

        int get_size(int pos);

        void alloca();

        void change(int pos, data *son);
        
        data* copy();
    };

    class var_float_array : public data {
        
    public:

        vector<data*> value;
        vector<int> size;

        var_float_array() {
            type = Float;
        }
        ~var_float_array();
        
        void add_size(int dimension);

        int get_size(int pos);

        void alloca();

        void change(int pos, data *son);

        data* copy();
    };


    class symbol_table {
        
    public:
        
        vector<map<string, data*>> var, var_array;

        symbol_table() {
            in_stack();
        }
        ~symbol_table(); 

        void in_stack();

        void out_stack();

        data* get_var(string name);

        data* get_var_array(string name);

        void add_var(string name, data* son);

        void add_var_array(string name, data* son);
    };
}
