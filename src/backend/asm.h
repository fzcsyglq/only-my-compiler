#pragma once

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <map>
#include "../ir/ir.h"

namespace ASM {
    
    enum {Alloca, Store, Load, Br, Call, Const, Ret, Function, Add, Sub, Mul, Sdiv, Srew};
    enum {Int, Float, Void};

    class Asm {

      public:
        int cnt, regi;
        map<int, int> ma;
        vector<IR::data> global_var;
        map<int, string> global_name;
        map<string, bool> is_init;
        Asm(){cnt=0, regi = 0;};
        
        void add_id(int x);

        int get_id(int x);

        void out_value(int value, std::ofstream &out);
            
        void get_asm(IR::CompUnit *ir, std::ofstream &out);
    };
};
