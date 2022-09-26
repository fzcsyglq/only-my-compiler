#pragma once

#include "../common/utility.h"
#include "../ir/ir.h"

namespace Var {
    
    enum {Int, Float, Void};
    
    class data {
        
    public:        
        
        int id;
        string name;
        bool is_global, is_const;

        data(){}
        virtual ~data(){}

        void add_name(string name);
        
        virtual void add_size(data *array_size);

        virtual void to_int(IR:: ir *);
    };

    class var_int : public data {

    public:
        
        int value;

        var_int(int value) : value(value) {}
    };

    class var_float : public data {
        
    public:
        
        float value;

        var_float(float value) : value(value) {}
    };

    class var_int_array : public data {
        
    public:

        vector<int> value;
        vector<data> size;

        void add_size(data *array_size);
        
    };

    class var_float_array : public data {
        
    public:

        vector<float> value;
        vector<data> size;

        void add_size(data *array_size);
    };


    class symbol_table {
        
    public:

        vector<map<string, data>> var, var_array;

        data* get_var(string name);

        data* get_var_array(string name);
    };
}
