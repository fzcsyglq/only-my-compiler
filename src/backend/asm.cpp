#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>

#include "asm.h"
#include "../ir/ir.h"
#include "asm.h"

#define nxt_regi ((++regi)%=12)
#define get_regi(x) (((regi+x)%12+12)%12)

void ASM::Asm::add_id(int x) {

    ma[x] = cnt;
}

int ASM::Asm::get_id(int x) {
    return cnt - ma[x];
}

void ASM::Asm::out_value(int value, std::ofstream &out) {
    if (value < (1 << 16)) {
        out << "movw r" << nxt_regi << ",#" << value << std::endl;
    } else {
        out << "movw r" << nxt_regi << ",#" << value % (1 << 16) << std::endl;
        out << "movt r" << regi << ",#" << (value >> 16) << std::endl;
    }
    return;
}

void ASM::Asm::get_asm(IR::CompUnit *ir, std::ofstream &out) {
    out << ".global main" << std::endl;
    for (IR::command now : ir->content) {
        if (now.type == Alloca) {
            if(now.result.is_global) {
                out << ".data" << std::endl;
                out << now.result.name << ":" << std::endl;
                out << ".skip " << now.result.pos << std::endl;
                cnt += now.result.pos;
                global_name[now.result.id] = now.result.name;
//                add_id(now.result.id);
            } else {
                out << "sub sp,#" << now.result.pos << std::endl;
                cnt += now.result.pos;
                add_id(now.result.id);
            }
        } else if (now.type == Store) {
            if (!now.right.is_global) {                
                out << "str r" << regi << ",[sp,#" << get_id(now.right.id) + now.right.pos << "]" << std::endl;
            }
        } else if (now.type == Load) {
            if (now.right.is_global) {
                if (is_init.find(now.right.name) != is_init.end()) {
                    global_var.push_back(now.right);
                } else {
                    if (ma.find(now.right.id) != ma.end()) {
                        if (!now.right.arr_index) {
                            out << "ldr r" << nxt_regi << ",[sp,#" << get_id(now.right.id) + now.right.pos<< "]" << std::endl;
                        } else {
                            out << "ldr r" << nxt_regi << ",[sp,#" << get_id(now.right.arr_index) << "]" << std::endl;
                            out << "add r" << nxt_regi << ",sp,#" << get_id(now.right.id) << std::endl;
                            out << "ldr r" << nxt_regi << ",[r" << get_regi(-1) << ",r" << get_regi(-2) << ", LSL #2]" << std::endl;
                        }
                    } else {
                        out << "ldr r" << nxt_regi << ",=" << global_name[now.right.id] << std::endl;
                        out << "ldr r" << regi << ",[r" << regi << "]" << std::endl;
                    }
                }                    
            } else {
                if (!now.right.is_const) {                    
                    if (ma.find(now.right.id) != ma.end()) {
                        if (!now.right.arr_index) {
                            out << "ldr r" << nxt_regi << ",[sp,#" << get_id(now.right.id) + now.right.pos<< "]" << std::endl;
                        } else {
                            out << "ldr r" << nxt_regi << ",[sp,#" << get_id(now.right.arr_index) << "]" << std::endl;
                            out << "add r" << nxt_regi << ",sp,#" << get_id(now.right.id) << std::endl;
                            out << "ldr r" << nxt_regi << ",[r" << get_regi(-1) << ",r" << get_regi(-2) << ", LSL #2]" << std::endl;
                        }
                    } else {
                        out << "ldr r" << nxt_regi << ",=" << global_name[now.right.id] << std::endl;
                        out << "ldr r" << regi << ",[r" << regi << "]" << std::endl;
                    }
                } else {
                    out_value(now.right.value, out);
                }
            }
        } else if (now.type == Function) {
            out << ".text" << std::endl;
            out << now.right.name << ":" << std::endl;
            if (now.right.name == "main") {
                for (auto k : global_var) {
                    out << "ldr r" << nxt_regi << ",=" << k.name << std::endl;
                    out_value(k.value, out);
                    out << "str r" << regi << ",[r" << get_regi(-1) << ",#" << k.pos << "]" <<std::endl;
                    is_init[k.name] = true;
                }
            }
        } else if (now.type == Ret) {
            out << "mov r0,r" << regi << std::endl;
            out << "bx lr" << std::endl;
        } else if (now.type == Add) {
            out << "add r" << nxt_regi << ",r" << get_regi(-2) << ",r" << get_regi(-1) << std::endl;
        } else if (now.type == Sub) {
            out << "sub r" << nxt_regi << ",r" << get_regi(-2) << ",r" << get_regi(-1) << std::endl;
        } else if (now.type == Mul) {
            out << "mul r" << nxt_regi << ",r" << get_regi(-2) << ",r" << get_regi(-1) << std::endl;
        } else if (now.type == Sdiv) {
        } else if (now.type == Srew) {
        }
    }
    return;
}
