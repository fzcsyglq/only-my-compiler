#pragma once

#include "SysYBaseVisitor.h"
#include "../ir/ir.h"

class Visitor : public SysYBaseVisitor {

    enum { Int, Float, Void};
    
    IR::CompUnit &ir;
    
public:

    IR::data pre;
    int pre_pos, pre_dimension, pre_len; //arr init
    
    Visitor(IR::CompUnit &_ir);

    
    virtual antlrcpp::Any visitCompUnit(SysYParser::CompUnitContext *ctx) override;

    virtual antlrcpp::Any visitDecl(SysYParser::DeclContext *ctx) override;

    virtual antlrcpp::Any visitConstDecl(SysYParser::ConstDeclContext *ctx) override;

    virtual antlrcpp::Any visitBType(SysYParser::BTypeContext *ctx) override;

    virtual antlrcpp::Any visitConstDef(SysYParser::ConstDefContext *ctx) override;

    virtual antlrcpp::Any visitConstInitVal(SysYParser::ConstInitValContext *ctx) override;

    virtual antlrcpp::Any visitVarDecl(SysYParser::VarDeclContext *ctx) override;
    
    virtual antlrcpp::Any visitVarDef(SysYParser::VarDefContext *ctx) override;

    virtual antlrcpp::Any visitInitVal(SysYParser::InitValContext *ctx) override;

    virtual antlrcpp::Any visitFuncDef(SysYParser::FuncDefContext *ctx) override;

    virtual antlrcpp::Any visitFuncType(SysYParser::FuncTypeContext *ctx) override;

    virtual antlrcpp::Any visitFuncFParams(SysYParser::FuncFParamsContext *ctx) override;

    virtual antlrcpp::Any visitFuncFParam(SysYParser::FuncFParamContext *ctx) override;

    virtual antlrcpp::Any visitBlock(SysYParser::BlockContext *ctx) override;

    virtual antlrcpp::Any visitBlockItem(SysYParser::BlockItemContext *ctx) override;

    virtual antlrcpp::Any visitStmtAssignment(SysYParser::StmtAssignmentContext *ctx) override;
    virtual antlrcpp::Any visitStmtExp(SysYParser::StmtExpContext *ctx) override;

    virtual antlrcpp::Any visitStmtBlock(SysYParser::StmtBlockContext *ctx) override;

    virtual antlrcpp::Any visitStmtIf(SysYParser::StmtIfContext *ctx) override;

    virtual antlrcpp::Any visitStmtWhile(SysYParser::StmtWhileContext *ctx) override;

    virtual antlrcpp::Any visitStmtBreak(SysYParser::StmtBreakContext *ctx) override;

    virtual antlrcpp::Any visitStmtContinue(SysYParser::StmtContinueContext *ctx) override;

    virtual antlrcpp::Any visitStmtReturn(SysYParser::StmtReturnContext *ctx) override;

    virtual antlrcpp::Any visitExp(SysYParser::ExpContext *ctx) override;

    virtual antlrcpp::Any visitCond(SysYParser::CondContext *ctx) override;

    virtual antlrcpp::Any visitLVal(SysYParser::LValContext *ctx) override;

    virtual antlrcpp::Any visitPrimaryExp1(SysYParser::PrimaryExp1Context *ctx) override;

    virtual antlrcpp::Any visitPrimaryExp2(SysYParser::PrimaryExp2Context *ctx) override;
    
    virtual antlrcpp::Any visitPrimaryExp3(SysYParser::PrimaryExp3Context *ctx) override;

    virtual antlrcpp::Any visitNumber(SysYParser::NumberContext *ctx) override;

    virtual antlrcpp::Any visitUnaryExp(SysYParser::UnaryExpContext *ctx) override;

    virtual antlrcpp::Any visitUnaryOp(SysYParser::UnaryOpContext *ctx) override;

    virtual antlrcpp::Any visitFuncRParams(SysYParser::FuncRParamsContext *ctx) override;

    virtual antlrcpp::Any visitMulExp(SysYParser::MulExpContext *ctx) override;
    
    virtual antlrcpp::Any visitAddExp(SysYParser::AddExpContext *ctx) override;

    virtual antlrcpp::Any visitRelExp(SysYParser::RelExpContext *ctx) override;

    virtual antlrcpp::Any visitEqExp(SysYParser::EqExpContext *ctx) override;

    virtual antlrcpp::Any visitLAndExp(SysYParser::LAndExpContext *ctx) override;

    virtual antlrcpp::Any visitLOrExp(SysYParser::LOrExpContext *ctx) override;

    virtual antlrcpp::Any visitConstExp(SysYParser::ConstExpContext *ctx) override;

    virtual antlrcpp::Any visitChildren(antlr4::tree::ParseTree *ctx) override;
};
