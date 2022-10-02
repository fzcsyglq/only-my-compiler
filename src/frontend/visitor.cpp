#include "visitor.h"

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
    cout<<"BType"<<endl;
    if (ctx->getText() == "int") decl_type = Int;
    else decl_type = Float;
    // visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitConstDef(SysYParser::ConstDefContext *ctx) {
    string name = ctx->children[0]->getText();
    if (ctx->children[1]->getText() != "[") {
        visitChildren(ctx);
        if (decl_type == Int) ir->add_to_int(son);            
        else ir->add_to_float(son);        
        ir->add_alloca(son);
        son->add_name(name);
        ir->add_def(son);
        symbol_table.add_var(name, son);
    } else {
        shared_ptr<Var::data> var;
        if (decl_type == Int) {
            var = make_shared<Var::var_int_array>();
            for (int k = 2; k < ctx->children.size(); k += 3) {                
                ctx->children[k]->accept(this);
                var->add_size(dynamic_pointer_cast<Var::var_int>(son)->value);
            }
        } else {
            var = make_shared<Var::var_float_array>();
            for (int k = 2; k < ctx->children.size(); k += 3) {
                ctx->children[k]->accept(this);
                var->add_size(dynamic_pointer_cast<Var::var_float>(son)->value);
            }
        }        
        var->alloca();
        son = var;
        ir->add_alloca(son);
        son->add_name(name);
        ctx->children.back()->accept(this);
        symbol_table.add_var_array(name, son);
    }
    return nullptr;
}

antlrcpp::Any Visitor::visitConstInitVal(SysYParser::ConstInitValContext *ctx) {
//    cout<<"ConstInitVal"<<endl;
    if (ctx->children.size() == 1) {
        visitChildren(ctx);
    } else {
        shared_ptr<Var::data> var = son;
        int dimension = 0, pos = 0;
        for (auto to : ctx->children) {
            if (to->getText() == ",") continue;
                
            if (to->getText() == "{") {
                dimension++;
            } else if (to->getText() == "}") {
                pos = (pos + var->get_size(dimension) - 1) / var->get_size(dimension) * var->get_size(dimension);
                dimension--;
            } else {
                to->accept(this);
                if (decl_type == Int) ir->add_to_int(son);
                else ir->add_to_float(son);
                ir->add_gep(son, var, make_shared<Var::var_int>(pos));
                ir->add_def(son);
                var->change(pos, son);
                pos++;
            }
        }        
        son = var;
    }
    return nullptr;
}

antlrcpp::Any Visitor::visitVarDecl(SysYParser::VarDeclContext *ctx) {    
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitVarDef(SysYParser::VarDefContext *ctx) {
    cout<<"VarDef"<<endl;
    string name = ctx->children[0]->getText();
    cout << name << endl;
    if (ctx->children.size() == 1 || ctx->children[1]->getText() != "[") {
        if (decl_type == Int) son = make_shared<Var::var_int>();
        else son = make_shared<Var::var_float>();
        visitChildren(ctx);
        if (decl_type == Int) ir->add_to_int(son);            
        else ir->add_to_float(son);
        son->add_name(name);
        ir->add_alloca(son);        
        ir->add_def(son);
        symbol_table.add_var(name, son);
    } else {
        shared_ptr<Var::data> var;
        if (decl_type == Int) {
            var = make_shared<Var::var_int_array>();
            for (int k = 2; k < ctx->children.size() - 1; k += 3) {
                ctx->children[k]->accept(this);
                var->add_size(dynamic_pointer_cast<Var::var_int>(son)->value);
            }
        } else {
            var = make_shared<Var::var_float_array>();
            for (int k = 2; k < ctx->children.size() - 1; k += 3) {
                ctx->children[k]->accept(this);
                var->add_size(dynamic_pointer_cast<Var::var_int>(son)->value);
            }
        }
        var->alloca();
        son = var;
        ir->add_alloca(son);
        son->add_name(name);
        ctx->children.back()->accept(this);
        ir->add_def(son);
        symbol_table.add_var_array(name, son);
        cout << " "<<son->get_size(0) << endl;
    }
    return nullptr;
}

antlrcpp::Any Visitor::visitInitVal(SysYParser::InitValContext *ctx) {    
    cout<<"InitVal"<<endl;
    if (ctx->children.size() == 1) {
        visitChildren(ctx);
    } else {
        shared_ptr<Var::data> var = son;
        int dimension = 0, pos = 0;
        for (auto to : ctx->children) {
            if (to->getText() == ",") continue;
            if (to->getText() == "{") {
                dimension++;
            } else if (to->getText() == "}") {                
                pos = (pos + var->get_size(dimension) - 1) / var->get_size(dimension) * var->get_size(dimension);
                dimension--;
            } else {
                to->accept(this);
                if (decl_type == Int) ir->add_to_int(son);
                else ir->add_to_float(son);
//                ir->add_gep(son, var, make_shared<Var::var_int>(pos));
//                ir->add_def(son);
                var->change(pos, son);
                pos++;
            }
        }
        son = var;
    }
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
    symbol_table.in_stack();
    
    int type;
    if (ctx->children[0]->getText() == "Int") type = Int;
    else if (ctx->children[0]->getText() == "Float") type = Float;
    else type = Void;
    ir->add_function_type(type);
    
    
    string name = ctx->children[1]->getText();
    ir->add_function_name(name);

    visitChildren(ctx);

    symbol_table.out_stack();
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
    shared_ptr<IR::para_data> para = ir->add_function_parameter();
    
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
    std::string name = ctx->children[0]->getText();
    if (ctx->children.size() == 1) {
        son = symbol_table.get_var(name)->copy();        
    } else {
        shared_ptr<Var::data> var_array = symbol_table.get_var_array(name)->copy();
        shared_ptr<Var::data> var_sum = make_shared<Var::var_int>();
        int dimension = 1;
        for (int k = 2; k <= ctx->children.size(); k += 3) {
            ctx->children[k]->accept(this);
            son = ir->add_binary_exp(IR::Mul, son, make_shared<Var::var_int>(var_array->get_size(dimension)));
            var_sum = ir->add_binary_exp(IR::Add, var_sum, son);
            dimension++;
        }        
        ir->add_gep(son, var_array, var_sum);
    }
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
    //cout<<"Number"<<endl;
    string number = ctx->children[0]->getText();
    
    if (number.find(".") == string::npos) {
        int value = 0;
        if (number.length() > 1 && number[0] == '0' && (number[1] == 'x' || number[1] == 'X')) {
            for (auto k : number)
                value = value * 16 + (k - '0');
        } else if (number[0] == '0') {
            for (auto k : number)
                value = value * 8 + (k - '0');
        } else {
            for (auto k : number)
                value = value * 10 + (k - '0');
        }
        son = make_shared<Var::var_int>(value);
    } else {
        float value = stof(number);
        son = make_shared<Var::var_float>(value);
    }
    son->is_const = true;
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any Visitor::visitUnaryExp(SysYParser::UnaryExpContext *ctx) {
//    cout<<"UnaryExp"<<endl;
    visitChildren(ctx);
    if (ctx->children[0]->getText() == "-") {
        ir->add_unary_minus(son);
    } else {
        ir->add_unary_not(son);
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
    if (ctx->children.size() == 1) {
        visitChildren(ctx);
    } else {
        ctx->children[0]->accept(this);        
        shared_ptr<Var::data> left = son->copy();
        
        ctx->children[2]->accept(this);
        shared_ptr<Var::data> right = son->copy();

        int type;
        if (ctx->children[1]->getText() == "*") type = IR::Mul;
        else if (ctx->children[1]->getText() == "/") type = IR::Sdiv;
        else type = IR::Srew;
        
        son = ir->add_binary_exp(type, left, right);
    }

    return nullptr;
}
    
antlrcpp::Any Visitor::visitAddExp(SysYParser::AddExpContext *ctx) {
//    cout<<"AddExp"<<endl;    
    if (ctx->children.size() == 1) {
        visitChildren(ctx);
    } else {
        ctx->children[0]->accept(this);
        shared_ptr<Var::data> left = son->copy();
        
        ctx->children[2]->accept(this);
        shared_ptr<Var::data> right = son->copy();
        
        int type;
        if (ctx->children[1]->getText() == "+") type = IR::Add;
        else type = IR::Sub;
        
        son = ir->add_binary_exp(type, left, right);
    }

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
    visitChildren(ctx);
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


