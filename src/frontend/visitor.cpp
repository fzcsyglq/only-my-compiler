#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#include "visitor.h"
#include "../ir/ir.h"

using namespace std;

antlrcpp::Any Visitor::visitCompUnit(SysYParser::CompUnitContext *ctx) {
    Var::data x;
//    cout<<"CompUnit"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitDecl(SysYParser::DeclContext *ctx) {
//    cout<<"Decl"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitConstDecl(SysYParser::ConstDeclContext *ctx) {
//    cout<<"ConstDecl"<<endl;
    // bool tem = ir.is_const;
    // ir.is_const = true;
    // visitChildren(ctx);
    // ir.is_const = tem;
    return nullptr;
}

antlrcpp::Any Visitor::visitBType(SysYParser::BTypeContext *ctx) {
//    cout<<"BType"<<endl;
    // if (ctx->getText() == "void") ir.pre_type = Void;
    // else if (ctx->getText() == "int") ir.pre_type = Int;
    // else ir.pre_type = Float;
     
    // visitChildren(ctx);
    // ir.pre_type = -1;
    return nullptr;
}

antlrcpp::Any Visitor::visitConstDef(SysYParser::ConstDefContext *ctx) {
//    cout<<"ConstDef"<<endl;    
    // pre = IR::data(++ir.cnt, ir.pre_type, ir.is_global);
    // pre.name = ctx->children[0]->getText();
    // pre.pos = 1;
    // pre.arr.clear();
    // bool StartInit = false;
    // pre_pos = 0, pre_dimension = -1, pre_len = 1;
    // int k;
    // for (k = 1; k < ctx->children.size(); k++) {
    //     string nxt = ctx->children[k]->getText();
    //     if (nxt == "[" || nxt == "]") continue;
    //     else if (nxt == "=") {
    //         ir.add_VarDef1(pre);
    //         StartInit = true;
    //         break;
    //     }
    //     ctx->children[k]->accept(this);
    //     if (!StartInit) {
    //         pre_len *= ir.lst_value;
    //         pre.pos *= ir.lst_value;
    //         cout<<"!!!"<<ir.lst_value<<" "<<pre.pos<<endl;
    //         pre.arr.push_back(ir.lst_value);            
    //     }
    // }
    // if (!StartInit) {
    //     ir.add_VarDef1(pre);
    // } else {
    //     for (k = k + 1; k < ctx->children.size(); k++) {
    //         ctx->children[k]->accept(this);        
    //     }
    // }
//    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitConstInitVal(SysYParser::ConstInitValContext *ctx) {
//    cout<<"ConstInitVal"<<endl;
    // string nxt = ctx->getText();
    // if (nxt[0] == '{') {
    //     pre_pos = ((pre_pos + pre_len -1) / pre_len) * pre_len;
    //     pre_dimension++;
    //     pre_len /= pre.arr[pre_dimension];
    // } else {
    //     pre_pos++;
    // }
    // visitChildren(ctx);
    
    // if (nxt.back() == '}') {
    //     pre_len *= pre.arr[pre_dimension];
    //     pre_pos = ((pre_pos + pre_len -1) / pre_len) * pre_len;
    //     pre_dimension--;        
    // } else {
    //     ir.add_VarDef2(pre.name, pre_pos);
    // }
    return nullptr;
}

antlrcpp::Any Visitor::visitVarDecl(SysYParser::VarDeclContext *ctx) {    
//    cout<<"VarDecl"<<endl;
    // bool tem = ir.is_const;
    // if (ir.is_global) ir.is_const = true;
    // visitChildren(ctx);
    // if (ir.is_global) ir.is_const = tem;

    if (ctx->children[0]->getText() == "Int") {
//        symbol_table.add_var_int(son);
    } else {
//        symbol_table.add_bar_int(son);
    }
    
    return nullptr;
}

antlrcpp::Any Visitor::visitVarDef(SysYParser::VarDefContext *ctx) {
//    cout<<"VarDef"<<endl;
    // pre = IR::data(++ir.cnt, ir.pre_type, ir.is_global);
    // pre.name = ctx->children[0]->getText();
    // pre.pos = 1;
    // pre.arr.clear();
    // bool StartInit = false;
    // pre_pos = 0, pre_dimension = -1, pre_len = 1;
    // int k;
    // for (k = 1; k < ctx->children.size(); k++) {
    //     string nxt = ctx->children[k]->getText();
    //     if (nxt == "[" || nxt == "]") continue;
    //     else if (nxt == "=") {
    //         ir.add_VarDef1(pre);
    //         StartInit = true;
    //         break;
    //     }
    //     ctx->children[k]->accept(this);
    //     if (!StartInit) {
    //         pre_len *= ir.lst_value;
    //         pre.pos *= ir.lst_value;
    //         cout<<"!!!"<<ir.lst_value<<" "<<pre.pos<<endl;
    //         pre.arr.push_back(ir.lst_value);            
    //     }
    // }
    // if (!StartInit) {
    //     ir.add_VarDef1(pre);
    // } else {
    //     for (k = k + 1; k < ctx->children.size(); k++) {
    //         ctx->children[k]->accept(this);        
    //     }
    // }

    return nullptr;
}

antlrcpp::Any Visitor::visitInitVal(SysYParser::InitValContext *ctx) {    
//    cout<<"InitVal"<<endl;
    // string nxt = ctx->getText();
    // if (nxt[0] == '{') {
    //     pre_pos = ((pre_pos + pre_len -1) / pre_len) * pre_len;
    //     pre_dimension++;
    //     pre_len /= pre.arr[pre_dimension];
    // } else {
    //     pre_pos++;
    // }
    // visitChildren(ctx);
    
    // if (nxt.back() == '}') {
    //     pre_len *= pre.arr[pre_dimension];
    //     pre_pos = ((pre_pos + pre_len -1) / pre_len) * pre_len;
    //     pre_dimension--;        
    // } else {
    //     ir.add_VarDef2(pre.name, pre_pos);
    // }
    return nullptr;    
}

antlrcpp::Any Visitor::visitFuncDef(SysYParser::FuncDefContext *ctx) {
//    cout<<"FuncDef"<<endl;
    
    // int type;    
    // string name = ctx->children[1]->getText();
    // if (ctx->children[0]->getText() == "Int") type = Int;
    // else type = Float;
    // ir.enter_Func(Int, name);
    // visitChildren(ctx);
    // ir.exit_Func();

    ir->enter_function(ir);
    
    int type;
    if (ctx->children[0]->getText() == "Int") type = Int;
    else if (ctx->children[0]->getText() == "Float") type = Float;
    else type = Void;
    ir->add_function_type(type);
    
    
    string name = ctx->children[1]->getText();
    ir->add_function_name(name);

    visitChildren(ctx);
    
    ir->exit_function(ir);

    return nullptr;

}

antlrcpp::Any Visitor::visitFuncType(SysYParser::FuncTypeContext *ctx) {
//    cout<<"FuncType"<<endl;    
    
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitFuncFParams(SysYParser::FuncFParamsContext *ctx) {

//    cout<<"FuncFParams"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitFuncFParam(SysYParser::FuncFParamContext *ctx) {
//    cout<<"FuncFParam"<<endl;
    IR::para_data *para = ir->add_function_parameter();
    
    if (ctx->children[0]->getText() == "Int") para->type = Int;
    else para->type = Float;

    para->name = ctx->children[1]->getText();

    for (int k = 3; k < ctx->children.size(); k += 3) {
        ctx->children[k]->accept(this);
        para->exp.push_back(son);
    }    
    cout<<ctx->children.size()<<endl;
    return nullptr;
}

antlrcpp::Any Visitor::visitBlock(SysYParser::BlockContext *ctx) {    
//    cout<<"Block"<<endl;
    ir->enter_block(ir);    
    ir->add_block_id(0);
    
    visitChildren(ctx);
    
    ir->exit_block(ir);
    return nullptr;
}

antlrcpp::Any Visitor::visitBlockItem(SysYParser::BlockItemContext *ctx) {
//    cout<<"BLockItem"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitStmtAssignment(SysYParser::StmtAssignmentContext *ctx) {
//    cout<<"Stmt"<<endl;
    
    // IR::data result = IR::data(++ir.cnt, ir.pre_type, ir.is_global);
    // result.name = ctx->children[0]->getText();
    // result.pos = 1;
    // bool StartInit = false;
    // int pos = 0, dimension = 0, len = 1;
    // for (int k = 1; k < ctx->children.size(); k++) {
    //     string nxt = ctx->children[k]->getText();
    //     if (nxt == "[" || nxt == "]") continue;
    //     else if (nxt == "=") {
    //         ir.add_VarDef1(result);
    //         StartInit = true;
    //         continue;
    //     } else if (nxt == "{") {
    //         pos = ((pos + len -1) / len) * len;
    //         dimension++;
    //         len /= result.arr[dimension];
    //         continue;
    //     } else if (nxt == "}") {
    //         len *= result.arr[dimension];
    //         dimension--;
    //         continue;
    //     }
    //     ctx->children[k]->accept(this);

    //     if (!StartInit) {
    //         len *= ir.lst_value;
    //         result.pos *= ir.lst_value;
    //         result.arr.push_back(ir.lst_value);            
    //     } else {
    //         pos++;
    //         ir.add_VarDef2(result.name, pos);
    //     }
    // }
    // if (!StartInit) {
    //     ir.add_VarDef1(result);        
    // }
//    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitStmtExp(SysYParser::StmtExpContext *ctx) {
//    cout<<"Stmt"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitStmtBlock(SysYParser::StmtBlockContext *ctx) {
//    cout<<"Stmt"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitStmtIf(SysYParser::StmtIfContext *ctx) {
//    cout<<"Stmt"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitStmtWhile(SysYParser::StmtWhileContext *ctx) {
//    cout<<"Stmt"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitStmtBreak(SysYParser::StmtBreakContext *ctx) {
//    cout<<"Stmt"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitStmtContinue(SysYParser::StmtContinueContext *ctx) {
//    cout<<"Stmt"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitStmtReturn(SysYParser::StmtReturnContext *ctx) {
//    cout<<"Stmt"<<endl;    
    visitChildren(ctx);
//    ir.add_Return();
    return nullptr;
}

antlrcpp::Any Visitor::visitExp(SysYParser::ExpContext *ctx) {
//    cout<<"Exp"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitCond(SysYParser::CondContext *ctx) {
//    cout<<"Cond"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitLVal(SysYParser::LValContext *ctx) {    
//    cout<<"LVal"<<endl;
    delete son;
    std::string name = ctx->children[0]->getText();

    if (ctx->children.size() == 1) {
        son = symbol_table.get_var(name);
    } else {
        son = symbol_table.get_var_array(name);
    }
    // string name = ctx->children[0]->getText();
    // ir.add_Int(0);
    // IR::data sum = IR::data(ir.lst, ir.lst_type, ir.is_global);
    // int dimension = 0;
    // IR::data *top;
    // for (int k = ir.var.size() - 1; k >= 0 ; k--) {
    //     if (ir.var[k].find(name) != ir.var[k].end()) {
    //         top = &ir.var[k][name];
    //         break;
    //     }
    // }
    // for (int k = 1; k < ctx->children.size(); k++) {
    //     string nxt = ctx->children[k]->getText();
    //     if (nxt == "[" || nxt == "]") continue;
    //     IR::data x, y;

    //     ctx->children[k]->accept(this);
    //     x = IR::data(ir.lst, ir.lst_type, ir.is_global);

    //     ir.add_Int(top->arr[dimension++]);
    //     y = IR::data(ir.lst, ir.lst_type, ir.is_global);
    //     ir.add_MulExp(IR::Mul, sum, y);

    //     sum = IR::data(ir.lst, ir.lst_type, ir.is_global);
    //     ir.add_MulExp(IR::Add, sum, x);
    //     sum = IR::data(ir.lst, ir.lst_type, ir.is_global);
    // }

    // IR::data result, left, right;
    // result = IR::data();
    // left = IR::data();
    // right = sum, right.arr_index = ir.lst;
    // int id;
    // for (int k = ir.var.size() - 1; k >= 0; k--){
    //     if (ir.var[k].find(name) != ir.var[k].end()) {
    //         id = ir.var[k][name].id;
    //         break;
    //     }
    // }
    // right.id = id;
    // ir.content.push_back(IR::command(IR::Load, result, left, right));

    // result = IR::data(++ir.cnt, ir.lst_type, ir.is_global);
    // left = IR::data();
    // right = IR::data();
    // ir.content.push_back(IR::command(IR::Alloca, result, left, right));
    
    // result = IR::data();
    // left = IR::data();
    // right = IR::data(ir.cnt, ir.lst_type, ir.is_global);
    // ir.content.push_back(IR::command(IR::Store, result, left, right));
    
    // ir.lst = ir.cnt;
    // ir.lst_type = Int;
    return nullptr;
}

antlrcpp::Any Visitor::visitPrimaryExp1(SysYParser::PrimaryExp1Context *ctx) {
//    cout<<"PrimaryExp"<<endl;
    visitChildren(ctx);
    return nullptr;    
}

antlrcpp::Any Visitor::visitPrimaryExp2(SysYParser::PrimaryExp2Context *ctx) {
//    cout<<"PrimaryExp"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitPrimaryExp3(SysYParser::PrimaryExp3Context *ctx) {
//    cout<<"PrimaryExp"<<endl;
    visitChildren(ctx);
    return nullptr;    
}

antlrcpp::Any Visitor::visitNumber(SysYParser::NumberContext *ctx) {
//    cout<<"Number"<<endl;
    string number = ctx->children[0]->getText();
    
    if (number.find(".") == string::npos) {
        int value = 0;
        if (number.length() > 1 && number[0] == '0' && (number[1] == 'x' || number[1] == 'X')) {
            for (auto k : number)
                value = value * 16 + (k - '0');
        } else if (number[0] == '0') {
            for (auto k : number)
                value = value * 8 + (k - '0'), cout<<k<<endl;
        } else {
            for (auto k : number)
                value = value * 10 + (k - '0');
        }
        delete son;
        son = new Var::var_int(value);
    } else {
        float value = stof(number);
        delete son;
        son = new Var::var_float(value);
    }
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitUnaryExp(SysYParser::UnaryExpContext *ctx) {
//    cout<<"UnaryExp"<<endl;
    if (ctx->children.size() == 1) {
        visitChildren(ctx);
    }
    return nullptr;
}

antlrcpp::Any Visitor::visitUnaryOp(SysYParser::UnaryOpContext *ctx) {
//    cout<<"UnaryOp"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitFuncRParams(SysYParser::FuncRParamsContext *ctx) {
//    cout<<"FuncRParams"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitMulExp(SysYParser::MulExpContext *ctx) {
//    cout<<"MulExp"<<endl;
    // if (ctx->children.size() == 1) {
    //     visitChildren(ctx);
    // } else {
    //     ctx->children[0]->accept(this);
    //     IR::data left = IR::data(ir.lst, ir.lst_type, ir.is_global);
    //     if (ir.is_const) left.value = ir.lst_value;
        
    //     ctx->children[2]->accept(this);
    //     IR::data right = IR::data(ir.lst, ir.lst_type, ir.is_global);
    //     if (ir.is_const) right.value = ir.lst_value;

    //     int type;
    //     if (ctx->children[1]->getText() == "*") type = IR::Mul;
    //     else if (ctx->children[1]->getText() == "/") type = IR::Sdiv;
    //     else type = IR::Srew;
    //     ir.add_MulExp(type, left, right);
    // }

    return nullptr;
}
    
antlrcpp::Any Visitor::visitAddExp(SysYParser::AddExpContext *ctx) {
//    cout<<"AddExp"<<endl;    
    // if (ctx->children.size() == 1) {
    //     visitChildren(ctx);
    // } else {
    //     ctx->children[0]->accept(this);
    //     IR::data left = IR::data(ir.lst, ir.lst_type, ir.is_global);
    //     if (ir.is_const) left.value = ir.lst_value;
        
    //     ctx->children[2]->accept(this);
    //     IR::data right = IR::data(ir.lst, ir.lst_type, ir.is_global);
    //     if (ir.is_const) left.value = ir.lst_value;
        
    //     int type;
    //     if (ctx->children[1]->getText() == "+") type = IR::Add;
    //     else type = IR::Sub;
    //     ir.add_MulExp(type, left, right);
    // }

    return nullptr;
}

antlrcpp::Any Visitor::visitRelExp(SysYParser::RelExpContext *ctx) {
//    cout<<"RelExp"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitEqExp(SysYParser::EqExpContext *ctx) {
//    cout<<"EqExp"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitLAndExp(SysYParser::LAndExpContext *ctx) {
//    cout<<"AndExp"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitLOrExp(SysYParser::LOrExpContext *ctx) {
//    cout<<"LOrExp"<<endl;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitConstExp(SysYParser::ConstExpContext *ctx) {
//    cout<<"ConstExp"<<endl;
    // bool tem = ir.is_const;
    // ir.is_const = true;
    // visitChildren(ctx);
    // ir.is_const = tem;
    return nullptr;
}

antlrcpp::Any Visitor::visitChildren(antlr4::tree::ParseTree *ctx) {
    int n = ctx->children.size();
//    cout<<n<<endl;
    for (int k = 0; k < n; k++) {
        ctx->children[k]->accept(this);
    }
    return nullptr;    
}


