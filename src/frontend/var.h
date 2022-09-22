#pragma once

#include "../common/utility.h"

enum {Int, Float, Void};

namespace Var {
    class data {
        
    public:
        
        int id;
        string name;
        bool is_global, is_const;
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
}
