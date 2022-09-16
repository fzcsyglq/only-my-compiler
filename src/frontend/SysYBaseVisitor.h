
// Generated from SysY.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SysYVisitor.h"


/**
 * This class provides an empty implementation of SysYVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SysYBaseVisitor : public SysYVisitor {
public:

  virtual antlrcpp::Any visitCompUnit(SysYParser::CompUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecl(SysYParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstDecl(SysYParser::ConstDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBType(SysYParser::BTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstDef(SysYParser::ConstDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstInitVal(SysYParser::ConstInitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDecl(SysYParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDef(SysYParser::VarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitVal(SysYParser::InitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncDef(SysYParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncType(SysYParser::FuncTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncFParams(SysYParser::FuncFParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncFParam(SysYParser::FuncFParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(SysYParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlockItem(SysYParser::BlockItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmtAssignment(SysYParser::StmtAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmtExp(SysYParser::StmtExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmtBlock(SysYParser::StmtBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmtIf(SysYParser::StmtIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmtWhile(SysYParser::StmtWhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmtBreak(SysYParser::StmtBreakContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmtContinue(SysYParser::StmtContinueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmtReturn(SysYParser::StmtReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExp(SysYParser::ExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCond(SysYParser::CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLVal(SysYParser::LValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimaryExp1(SysYParser::PrimaryExp1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimaryExp2(SysYParser::PrimaryExp2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimaryExp3(SysYParser::PrimaryExp3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(SysYParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryExp(SysYParser::UnaryExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryOp(SysYParser::UnaryOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncRParams(SysYParser::FuncRParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulExp(SysYParser::MulExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddExp(SysYParser::AddExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelExp(SysYParser::RelExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqExp(SysYParser::EqExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLAndExp(SysYParser::LAndExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLOrExp(SysYParser::LOrExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstExp(SysYParser::ConstExpContext *ctx) override {
    return visitChildren(ctx);
  }


};

