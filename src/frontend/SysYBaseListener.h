
// Generated from SysY.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SysYListener.h"


/**
 * This class provides an empty implementation of SysYListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SysYBaseListener : public SysYListener {
public:

  virtual void enterCompUnit(SysYParser::CompUnitContext * /*ctx*/) override { }
  virtual void exitCompUnit(SysYParser::CompUnitContext * /*ctx*/) override { }

  virtual void enterDecl(SysYParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(SysYParser::DeclContext * /*ctx*/) override { }

  virtual void enterConstDecl(SysYParser::ConstDeclContext * /*ctx*/) override { }
  virtual void exitConstDecl(SysYParser::ConstDeclContext * /*ctx*/) override { }

  virtual void enterBType(SysYParser::BTypeContext * /*ctx*/) override { }
  virtual void exitBType(SysYParser::BTypeContext * /*ctx*/) override { }

  virtual void enterConstDef(SysYParser::ConstDefContext * /*ctx*/) override { }
  virtual void exitConstDef(SysYParser::ConstDefContext * /*ctx*/) override { }

  virtual void enterConstInitVal(SysYParser::ConstInitValContext * /*ctx*/) override { }
  virtual void exitConstInitVal(SysYParser::ConstInitValContext * /*ctx*/) override { }

  virtual void enterVarDecl(SysYParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(SysYParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterVarDef(SysYParser::VarDefContext * /*ctx*/) override { }
  virtual void exitVarDef(SysYParser::VarDefContext * /*ctx*/) override { }

  virtual void enterInitVal(SysYParser::InitValContext * /*ctx*/) override { }
  virtual void exitInitVal(SysYParser::InitValContext * /*ctx*/) override { }

  virtual void enterFuncDef(SysYParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(SysYParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterFuncType(SysYParser::FuncTypeContext * /*ctx*/) override { }
  virtual void exitFuncType(SysYParser::FuncTypeContext * /*ctx*/) override { }

  virtual void enterFuncFParams(SysYParser::FuncFParamsContext * /*ctx*/) override { }
  virtual void exitFuncFParams(SysYParser::FuncFParamsContext * /*ctx*/) override { }

  virtual void enterFuncFParam(SysYParser::FuncFParamContext * /*ctx*/) override { }
  virtual void exitFuncFParam(SysYParser::FuncFParamContext * /*ctx*/) override { }

  virtual void enterBlock(SysYParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(SysYParser::BlockContext * /*ctx*/) override { }

  virtual void enterBlockItem(SysYParser::BlockItemContext * /*ctx*/) override { }
  virtual void exitBlockItem(SysYParser::BlockItemContext * /*ctx*/) override { }

  virtual void enterStmtAssignment(SysYParser::StmtAssignmentContext * /*ctx*/) override { }
  virtual void exitStmtAssignment(SysYParser::StmtAssignmentContext * /*ctx*/) override { }

  virtual void enterStmtExp(SysYParser::StmtExpContext * /*ctx*/) override { }
  virtual void exitStmtExp(SysYParser::StmtExpContext * /*ctx*/) override { }

  virtual void enterStmtBlock(SysYParser::StmtBlockContext * /*ctx*/) override { }
  virtual void exitStmtBlock(SysYParser::StmtBlockContext * /*ctx*/) override { }

  virtual void enterStmtIf(SysYParser::StmtIfContext * /*ctx*/) override { }
  virtual void exitStmtIf(SysYParser::StmtIfContext * /*ctx*/) override { }

  virtual void enterStmtWhile(SysYParser::StmtWhileContext * /*ctx*/) override { }
  virtual void exitStmtWhile(SysYParser::StmtWhileContext * /*ctx*/) override { }

  virtual void enterStmtBreak(SysYParser::StmtBreakContext * /*ctx*/) override { }
  virtual void exitStmtBreak(SysYParser::StmtBreakContext * /*ctx*/) override { }

  virtual void enterStmtContinue(SysYParser::StmtContinueContext * /*ctx*/) override { }
  virtual void exitStmtContinue(SysYParser::StmtContinueContext * /*ctx*/) override { }

  virtual void enterStmtReturn(SysYParser::StmtReturnContext * /*ctx*/) override { }
  virtual void exitStmtReturn(SysYParser::StmtReturnContext * /*ctx*/) override { }

  virtual void enterExp(SysYParser::ExpContext * /*ctx*/) override { }
  virtual void exitExp(SysYParser::ExpContext * /*ctx*/) override { }

  virtual void enterCond(SysYParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(SysYParser::CondContext * /*ctx*/) override { }

  virtual void enterLVal(SysYParser::LValContext * /*ctx*/) override { }
  virtual void exitLVal(SysYParser::LValContext * /*ctx*/) override { }

  virtual void enterPrimaryExp1(SysYParser::PrimaryExp1Context * /*ctx*/) override { }
  virtual void exitPrimaryExp1(SysYParser::PrimaryExp1Context * /*ctx*/) override { }

  virtual void enterPrimaryExp2(SysYParser::PrimaryExp2Context * /*ctx*/) override { }
  virtual void exitPrimaryExp2(SysYParser::PrimaryExp2Context * /*ctx*/) override { }

  virtual void enterPrimaryExp3(SysYParser::PrimaryExp3Context * /*ctx*/) override { }
  virtual void exitPrimaryExp3(SysYParser::PrimaryExp3Context * /*ctx*/) override { }

  virtual void enterNumber(SysYParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(SysYParser::NumberContext * /*ctx*/) override { }

  virtual void enterUnaryExp(SysYParser::UnaryExpContext * /*ctx*/) override { }
  virtual void exitUnaryExp(SysYParser::UnaryExpContext * /*ctx*/) override { }

  virtual void enterUnaryOp(SysYParser::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(SysYParser::UnaryOpContext * /*ctx*/) override { }

  virtual void enterFuncRParams(SysYParser::FuncRParamsContext * /*ctx*/) override { }
  virtual void exitFuncRParams(SysYParser::FuncRParamsContext * /*ctx*/) override { }

  virtual void enterMulExp(SysYParser::MulExpContext * /*ctx*/) override { }
  virtual void exitMulExp(SysYParser::MulExpContext * /*ctx*/) override { }

  virtual void enterAddExp(SysYParser::AddExpContext * /*ctx*/) override { }
  virtual void exitAddExp(SysYParser::AddExpContext * /*ctx*/) override { }

  virtual void enterRelExp(SysYParser::RelExpContext * /*ctx*/) override { }
  virtual void exitRelExp(SysYParser::RelExpContext * /*ctx*/) override { }

  virtual void enterEqExp(SysYParser::EqExpContext * /*ctx*/) override { }
  virtual void exitEqExp(SysYParser::EqExpContext * /*ctx*/) override { }

  virtual void enterLAndExp(SysYParser::LAndExpContext * /*ctx*/) override { }
  virtual void exitLAndExp(SysYParser::LAndExpContext * /*ctx*/) override { }

  virtual void enterLOrExp(SysYParser::LOrExpContext * /*ctx*/) override { }
  virtual void exitLOrExp(SysYParser::LOrExpContext * /*ctx*/) override { }

  virtual void enterConstExp(SysYParser::ConstExpContext * /*ctx*/) override { }
  virtual void exitConstExp(SysYParser::ConstExpContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

