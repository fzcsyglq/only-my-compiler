#pragma once

#include "../common/utility.h"

namespace Var {
    
    enum {Int, Float, Void};

    class data {
        
    public:        
        
        int id, type;
        string name;
        bool is_global, is_const;
        data(){}
        virtual ~data(){}

        void add_name(string name);

        void add_id(int id);

        void add_type(int type);
        
        virtual void add_size(data *array_size);

    };

    class var_int : public data {
        
    public:

        int value;
        
        var_int(int value = 0) : value(value) {
            type = Int;
        }

    };

    class var_float : public data {
        
    public:

        float value;
        
        var_float(float value = 0.0) : value(value){
            type = Float;
        }

    };

    class var_int_array : public data {
        
    public:

        vector<int> value;
        vector<data> size;

        var_int_array() {
            type = Int;
        }
        
        void add_size(data *array_size);
        
    };

    class var_float_array : public data {
        
    public:

        vector<float> value;
        vector<data> size;

        var_float_array() {
            type = Float;
        }
        
        void add_size(data *array_size);
    };


    class symbol_table {
        
    public:
        
        vector<map<string, data>> var, var_array;

        symbol_table() {
            var.push_back(map<string, data>());
            var_array.push_back(map<string, data>());
        }

        data* get_var(string name);

        data* get_var_array(string name);

        void add_var(string name, data* son);
    };
}
