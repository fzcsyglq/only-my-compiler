
// Generated from SysY.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SysYParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SysYParser.
 */
class  SysYListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCompUnit(SysYParser::CompUnitContext *ctx) = 0;
  virtual void exitCompUnit(SysYParser::CompUnitContext *ctx) = 0;

  virtual void enterDecl(SysYParser::DeclContext *ctx) = 0;
  virtual void exitDecl(SysYParser::DeclContext *ctx) = 0;

  virtual void enterConstDecl(SysYParser::ConstDeclContext *ctx) = 0;
  virtual void exitConstDecl(SysYParser::ConstDeclContext *ctx) = 0;

  virtual void enterBType(SysYParser::BTypeContext *ctx) = 0;
  virtual void exitBType(SysYParser::BTypeContext *ctx) = 0;

  virtual void enterConstDef(SysYParser::ConstDefContext *ctx) = 0;
  virtual void exitConstDef(SysYParser::ConstDefContext *ctx) = 0;

  virtual void enterConstInitVal(SysYParser::ConstInitValContext *ctx) = 0;
  virtual void exitConstInitVal(SysYParser::ConstInitValContext *ctx) = 0;

  virtual void enterVarDecl(SysYParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(SysYParser::VarDeclContext *ctx) = 0;

  virtual void enterVarDef(SysYParser::VarDefContext *ctx) = 0;
  virtual void exitVarDef(SysYParser::VarDefContext *ctx) = 0;

  virtual void enterInitVal(SysYParser::InitValContext *ctx) = 0;
  virtual void exitInitVal(SysYParser::InitValContext *ctx) = 0;

  virtual void enterFuncDef(SysYParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(SysYParser::FuncDefContext *ctx) = 0;

  virtual void enterFuncType(SysYParser::FuncTypeContext *ctx) = 0;
  virtual void exitFuncType(SysYParser::FuncTypeContext *ctx) = 0;

  virtual void enterFuncFParams(SysYParser::FuncFParamsContext *ctx) = 0;
  virtual void exitFuncFParams(SysYParser::FuncFParamsContext *ctx) = 0;

  virtual void enterFuncFParam(SysYParser::FuncFParamContext *ctx) = 0;
  virtual void exitFuncFParam(SysYParser::FuncFParamContext *ctx) = 0;

  virtual void enterBlock(SysYParser::BlockContext *ctx) = 0;
  virtual void exitBlock(SysYParser::BlockContext *ctx) = 0;

  virtual void enterBlockItem(SysYParser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(SysYParser::BlockItemContext *ctx) = 0;

  virtual void enterStmtAssignment(SysYParser::StmtAssignmentContext *ctx) = 0;
  virtual void exitStmtAssignment(SysYParser::StmtAssignmentContext *ctx) = 0;

  virtual void enterStmtExp(SysYParser::StmtExpContext *ctx) = 0;
  virtual void exitStmtExp(SysYParser::StmtExpContext *ctx) = 0;

  virtual void enterStmtBlock(SysYParser::StmtBlockContext *ctx) = 0;
  virtual void exitStmtBlock(SysYParser::StmtBlockContext *ctx) = 0;

  virtual void enterStmtIf(SysYParser::StmtIfContext *ctx) = 0;
  virtual void exitStmtIf(SysYParser::StmtIfContext *ctx) = 0;

  virtual void enterStmtWhile(SysYParser::StmtWhileContext *ctx) = 0;
  virtual void exitStmtWhile(SysYParser::StmtWhileContext *ctx) = 0;

  virtual void enterStmtBreak(SysYParser::StmtBreakContext *ctx) = 0;
  virtual void exitStmtBreak(SysYParser::StmtBreakContext *ctx) = 0;

  virtual void enterStmtContinue(SysYParser::StmtContinueContext *ctx) = 0;
  virtual void exitStmtContinue(SysYParser::StmtContinueContext *ctx) = 0;

  virtual void enterStmtReturn(SysYParser::StmtReturnContext *ctx) = 0;
  virtual void exitStmtReturn(SysYParser::StmtReturnContext *ctx) = 0;

  virtual void enterExp(SysYParser::ExpContext *ctx) = 0;
  virtual void exitExp(SysYParser::ExpContext *ctx) = 0;

  virtual void enterCond(SysYParser::CondContext *ctx) = 0;
  virtual void exitCond(SysYParser::CondContext *ctx) = 0;

  virtual void enterLVal(SysYParser::LValContext *ctx) = 0;
  virtual void exitLVal(SysYParser::LValContext *ctx) = 0;

  virtual void enterPrimaryExp1(SysYParser::PrimaryExp1Context *ctx) = 0;
  virtual void exitPrimaryExp1(SysYParser::PrimaryExp1Context *ctx) = 0;

  virtual void enterPrimaryExp2(SysYParser::PrimaryExp2Context *ctx) = 0;
  virtual void exitPrimaryExp2(SysYParser::PrimaryExp2Context *ctx) = 0;

  virtual void enterPrimaryExp3(SysYParser::PrimaryExp3Context *ctx) = 0;
  virtual void exitPrimaryExp3(SysYParser::PrimaryExp3Context *ctx) = 0;

  virtual void enterNumber(SysYParser::NumberContext *ctx) = 0;
  virtual void exitNumber(SysYParser::NumberContext *ctx) = 0;

  virtual void enterUnaryExp(SysYParser::UnaryExpContext *ctx) = 0;
  virtual void exitUnaryExp(SysYParser::UnaryExpContext *ctx) = 0;

  virtual void enterUnaryOp(SysYParser::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(SysYParser::UnaryOpContext *ctx) = 0;

  virtual void enterFuncRParams(SysYParser::FuncRParamsContext *ctx) = 0;
  virtual void exitFuncRParams(SysYParser::FuncRParamsContext *ctx) = 0;

  virtual void enterMulExp(SysYParser::MulExpContext *ctx) = 0;
  virtual void exitMulExp(SysYParser::MulExpContext *ctx) = 0;

  virtual void enterAddExp(SysYParser::AddExpContext *ctx) = 0;
  virtual void exitAddExp(SysYParser::AddExpContext *ctx) = 0;

  virtual void enterRelExp(SysYParser::RelExpContext *ctx) = 0;
  virtual void exitRelExp(SysYParser::RelExpContext *ctx) = 0;

  virtual void enterEqExp(SysYParser::EqExpContext *ctx) = 0;
  virtual void exitEqExp(SysYParser::EqExpContext *ctx) = 0;

  virtual void enterLAndExp(SysYParser::LAndExpContext *ctx) = 0;
  virtual void exitLAndExp(SysYParser::LAndExpContext *ctx) = 0;

  virtual void enterLOrExp(SysYParser::LOrExpContext *ctx) = 0;
  virtual void exitLOrExp(SysYParser::LOrExpContext *ctx) = 0;

  virtual void enterConstExp(SysYParser::ConstExpContext *ctx) = 0;
  virtual void exitConstExp(SysYParser::ConstExpContext *ctx) = 0;


};

