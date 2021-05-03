
// Generated from qasm3.g4 by ANTLR 4.9.2


#include "qasm3Visitor.h"

#include "qasm3Parser.h"


using namespace antlrcpp;
using namespace antlr4;

qasm3Parser::qasm3Parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

qasm3Parser::~qasm3Parser() {
  delete _interpreter;
}

std::string qasm3Parser::getGrammarFileName() const {
  return "qasm3.g4";
}

const std::vector<std::string>& qasm3Parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& qasm3Parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

qasm3Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::HeaderContext* qasm3Parser::ProgramContext::header() {
  return getRuleContext<qasm3Parser::HeaderContext>(0);
}

std::vector<qasm3Parser::GlobalStatementContext *> qasm3Parser::ProgramContext::globalStatement() {
  return getRuleContexts<qasm3Parser::GlobalStatementContext>();
}

qasm3Parser::GlobalStatementContext* qasm3Parser::ProgramContext::globalStatement(size_t i) {
  return getRuleContext<qasm3Parser::GlobalStatementContext>(i);
}

std::vector<qasm3Parser::StatementContext *> qasm3Parser::ProgramContext::statement() {
  return getRuleContexts<qasm3Parser::StatementContext>();
}

qasm3Parser::StatementContext* qasm3Parser::ProgramContext::statement(size_t i) {
  return getRuleContext<qasm3Parser::StatementContext>(i);
}


size_t qasm3Parser::ProgramContext::getRuleIndex() const {
  return qasm3Parser::RuleProgram;
}


antlrcpp::Any qasm3Parser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ProgramContext* qasm3Parser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, qasm3Parser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(202);
    header();
    setState(207);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__2)
      | (1ULL << qasm3Parser::T__3)
      | (1ULL << qasm3Parser::T__4)
      | (1ULL << qasm3Parser::T__5)
      | (1ULL << qasm3Parser::T__6)
      | (1ULL << qasm3Parser::T__7)
      | (1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9)
      | (1ULL << qasm3Parser::T__10)
      | (1ULL << qasm3Parser::T__11)
      | (1ULL << qasm3Parser::T__12)
      | (1ULL << qasm3Parser::T__13)
      | (1ULL << qasm3Parser::T__15)
      | (1ULL << qasm3Parser::T__16)
      | (1ULL << qasm3Parser::T__17)
      | (1ULL << qasm3Parser::T__18)
      | (1ULL << qasm3Parser::T__19)
      | (1ULL << qasm3Parser::T__20)
      | (1ULL << qasm3Parser::T__21)
      | (1ULL << qasm3Parser::T__22)
      | (1ULL << qasm3Parser::T__23)
      | (1ULL << qasm3Parser::T__25)
      | (1ULL << qasm3Parser::T__26)
      | (1ULL << qasm3Parser::T__27)
      | (1ULL << qasm3Parser::T__42)
      | (1ULL << qasm3Parser::T__43)
      | (1ULL << qasm3Parser::T__44)
      | (1ULL << qasm3Parser::T__45)
      | (1ULL << qasm3Parser::T__46)
      | (1ULL << qasm3Parser::T__47)
      | (1ULL << qasm3Parser::T__48)
      | (1ULL << qasm3Parser::T__49)
      | (1ULL << qasm3Parser::T__50)
      | (1ULL << qasm3Parser::T__51))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (qasm3Parser::T__63 - 64))
      | (1ULL << (qasm3Parser::T__65 - 64))
      | (1ULL << (qasm3Parser::T__66 - 64))
      | (1ULL << (qasm3Parser::T__67 - 64))
      | (1ULL << (qasm3Parser::T__68 - 64))
      | (1ULL << (qasm3Parser::T__69 - 64))
      | (1ULL << (qasm3Parser::T__70 - 64))
      | (1ULL << (qasm3Parser::T__71 - 64))
      | (1ULL << (qasm3Parser::T__73 - 64))
      | (1ULL << (qasm3Parser::T__74 - 64))
      | (1ULL << (qasm3Parser::T__75 - 64))
      | (1ULL << (qasm3Parser::T__76 - 64))
      | (1ULL << (qasm3Parser::T__77 - 64))
      | (1ULL << (qasm3Parser::T__78 - 64))
      | (1ULL << (qasm3Parser::T__79 - 64))
      | (1ULL << (qasm3Parser::T__80 - 64))
      | (1ULL << (qasm3Parser::T__81 - 64))
      | (1ULL << (qasm3Parser::T__82 - 64))
      | (1ULL << (qasm3Parser::LPAREN - 64))
      | (1ULL << (qasm3Parser::MINUS - 64))
      | (1ULL << (qasm3Parser::Constant - 64))
      | (1ULL << (qasm3Parser::Integer - 64))
      | (1ULL << (qasm3Parser::Identifier - 64))
      | (1ULL << (qasm3Parser::RealNumber - 64))
      | (1ULL << (qasm3Parser::TimingLiteral - 64))
      | (1ULL << (qasm3Parser::StringLiteral - 64)))) != 0)) {
      setState(205);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case qasm3Parser::T__2:
        case qasm3Parser::T__3:
        case qasm3Parser::T__15:
        case qasm3Parser::T__70:
        case qasm3Parser::T__71:
        case qasm3Parser::T__73:
        case qasm3Parser::T__81:
        case qasm3Parser::T__82: {
          setState(203);
          globalStatement();
          break;
        }

        case qasm3Parser::T__4:
        case qasm3Parser::T__5:
        case qasm3Parser::T__6:
        case qasm3Parser::T__7:
        case qasm3Parser::T__8:
        case qasm3Parser::T__9:
        case qasm3Parser::T__10:
        case qasm3Parser::T__11:
        case qasm3Parser::T__12:
        case qasm3Parser::T__13:
        case qasm3Parser::T__16:
        case qasm3Parser::T__17:
        case qasm3Parser::T__18:
        case qasm3Parser::T__19:
        case qasm3Parser::T__20:
        case qasm3Parser::T__21:
        case qasm3Parser::T__22:
        case qasm3Parser::T__23:
        case qasm3Parser::T__25:
        case qasm3Parser::T__26:
        case qasm3Parser::T__27:
        case qasm3Parser::T__42:
        case qasm3Parser::T__43:
        case qasm3Parser::T__44:
        case qasm3Parser::T__45:
        case qasm3Parser::T__46:
        case qasm3Parser::T__47:
        case qasm3Parser::T__48:
        case qasm3Parser::T__49:
        case qasm3Parser::T__50:
        case qasm3Parser::T__51:
        case qasm3Parser::T__63:
        case qasm3Parser::T__65:
        case qasm3Parser::T__66:
        case qasm3Parser::T__67:
        case qasm3Parser::T__68:
        case qasm3Parser::T__69:
        case qasm3Parser::T__74:
        case qasm3Parser::T__75:
        case qasm3Parser::T__76:
        case qasm3Parser::T__77:
        case qasm3Parser::T__78:
        case qasm3Parser::T__79:
        case qasm3Parser::T__80:
        case qasm3Parser::LPAREN:
        case qasm3Parser::MINUS:
        case qasm3Parser::Constant:
        case qasm3Parser::Integer:
        case qasm3Parser::Identifier:
        case qasm3Parser::RealNumber:
        case qasm3Parser::TimingLiteral:
        case qasm3Parser::StringLiteral: {
          setState(204);
          statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(209);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HeaderContext ------------------------------------------------------------------

qasm3Parser::HeaderContext::HeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::VersionContext* qasm3Parser::HeaderContext::version() {
  return getRuleContext<qasm3Parser::VersionContext>(0);
}

std::vector<qasm3Parser::IncludeContext *> qasm3Parser::HeaderContext::include() {
  return getRuleContexts<qasm3Parser::IncludeContext>();
}

qasm3Parser::IncludeContext* qasm3Parser::HeaderContext::include(size_t i) {
  return getRuleContext<qasm3Parser::IncludeContext>(i);
}


size_t qasm3Parser::HeaderContext::getRuleIndex() const {
  return qasm3Parser::RuleHeader;
}


antlrcpp::Any qasm3Parser::HeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitHeader(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::HeaderContext* qasm3Parser::header() {
  HeaderContext *_localctx = _tracker.createInstance<HeaderContext>(_ctx, getState());
  enterRule(_localctx, 2, qasm3Parser::RuleHeader);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(211);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::T__0) {
      setState(210);
      version();
    }
    setState(216);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::T__1) {
      setState(213);
      include();
      setState(218);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VersionContext ------------------------------------------------------------------

qasm3Parser::VersionContext::VersionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::VersionContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

tree::TerminalNode* qasm3Parser::VersionContext::Integer() {
  return getToken(qasm3Parser::Integer, 0);
}

tree::TerminalNode* qasm3Parser::VersionContext::RealNumber() {
  return getToken(qasm3Parser::RealNumber, 0);
}


size_t qasm3Parser::VersionContext::getRuleIndex() const {
  return qasm3Parser::RuleVersion;
}


antlrcpp::Any qasm3Parser::VersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitVersion(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::VersionContext* qasm3Parser::version() {
  VersionContext *_localctx = _tracker.createInstance<VersionContext>(_ctx, getState());
  enterRule(_localctx, 4, qasm3Parser::RuleVersion);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(219);
    match(qasm3Parser::T__0);
    setState(220);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::Integer

    || _la == qasm3Parser::RealNumber)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(221);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeContext ------------------------------------------------------------------

qasm3Parser::IncludeContext::IncludeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::IncludeContext::StringLiteral() {
  return getToken(qasm3Parser::StringLiteral, 0);
}

tree::TerminalNode* qasm3Parser::IncludeContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::IncludeContext::getRuleIndex() const {
  return qasm3Parser::RuleInclude;
}


antlrcpp::Any qasm3Parser::IncludeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitInclude(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IncludeContext* qasm3Parser::include() {
  IncludeContext *_localctx = _tracker.createInstance<IncludeContext>(_ctx, getState());
  enterRule(_localctx, 6, qasm3Parser::RuleInclude);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
    match(qasm3Parser::T__1);
    setState(224);
    match(qasm3Parser::StringLiteral);
    setState(225);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlobalStatementContext ------------------------------------------------------------------

qasm3Parser::GlobalStatementContext::GlobalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::SubroutineDefinitionContext* qasm3Parser::GlobalStatementContext::subroutineDefinition() {
  return getRuleContext<qasm3Parser::SubroutineDefinitionContext>(0);
}

qasm3Parser::KernelDeclarationContext* qasm3Parser::GlobalStatementContext::kernelDeclaration() {
  return getRuleContext<qasm3Parser::KernelDeclarationContext>(0);
}

qasm3Parser::QuantumGateDefinitionContext* qasm3Parser::GlobalStatementContext::quantumGateDefinition() {
  return getRuleContext<qasm3Parser::QuantumGateDefinitionContext>(0);
}

qasm3Parser::CalibrationContext* qasm3Parser::GlobalStatementContext::calibration() {
  return getRuleContext<qasm3Parser::CalibrationContext>(0);
}

qasm3Parser::QuantumDeclarationStatementContext* qasm3Parser::GlobalStatementContext::quantumDeclarationStatement() {
  return getRuleContext<qasm3Parser::QuantumDeclarationStatementContext>(0);
}

qasm3Parser::PragmaContext* qasm3Parser::GlobalStatementContext::pragma() {
  return getRuleContext<qasm3Parser::PragmaContext>(0);
}


size_t qasm3Parser::GlobalStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleGlobalStatement;
}


antlrcpp::Any qasm3Parser::GlobalStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitGlobalStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::GlobalStatementContext* qasm3Parser::globalStatement() {
  GlobalStatementContext *_localctx = _tracker.createInstance<GlobalStatementContext>(_ctx, getState());
  enterRule(_localctx, 8, qasm3Parser::RuleGlobalStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(233);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__71: {
        enterOuterAlt(_localctx, 1);
        setState(227);
        subroutineDefinition();
        break;
      }

      case qasm3Parser::T__70: {
        enterOuterAlt(_localctx, 2);
        setState(228);
        kernelDeclaration();
        break;
      }

      case qasm3Parser::T__15: {
        enterOuterAlt(_localctx, 3);
        setState(229);
        quantumGateDefinition();
        break;
      }

      case qasm3Parser::T__81:
      case qasm3Parser::T__82: {
        enterOuterAlt(_localctx, 4);
        setState(230);
        calibration();
        break;
      }

      case qasm3Parser::T__2:
      case qasm3Parser::T__3: {
        enterOuterAlt(_localctx, 5);
        setState(231);
        quantumDeclarationStatement();
        break;
      }

      case qasm3Parser::T__73: {
        enterOuterAlt(_localctx, 6);
        setState(232);
        pragma();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

qasm3Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ExpressionStatementContext* qasm3Parser::StatementContext::expressionStatement() {
  return getRuleContext<qasm3Parser::ExpressionStatementContext>(0);
}

qasm3Parser::AssignmentStatementContext* qasm3Parser::StatementContext::assignmentStatement() {
  return getRuleContext<qasm3Parser::AssignmentStatementContext>(0);
}

qasm3Parser::ClassicalDeclarationStatementContext* qasm3Parser::StatementContext::classicalDeclarationStatement() {
  return getRuleContext<qasm3Parser::ClassicalDeclarationStatementContext>(0);
}

qasm3Parser::BranchingStatementContext* qasm3Parser::StatementContext::branchingStatement() {
  return getRuleContext<qasm3Parser::BranchingStatementContext>(0);
}

qasm3Parser::LoopStatementContext* qasm3Parser::StatementContext::loopStatement() {
  return getRuleContext<qasm3Parser::LoopStatementContext>(0);
}

qasm3Parser::ControlDirectiveStatementContext* qasm3Parser::StatementContext::controlDirectiveStatement() {
  return getRuleContext<qasm3Parser::ControlDirectiveStatementContext>(0);
}

qasm3Parser::AliasStatementContext* qasm3Parser::StatementContext::aliasStatement() {
  return getRuleContext<qasm3Parser::AliasStatementContext>(0);
}

qasm3Parser::QuantumStatementContext* qasm3Parser::StatementContext::quantumStatement() {
  return getRuleContext<qasm3Parser::QuantumStatementContext>(0);
}


size_t qasm3Parser::StatementContext::getRuleIndex() const {
  return qasm3Parser::RuleStatement;
}


antlrcpp::Any qasm3Parser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::StatementContext* qasm3Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 10, qasm3Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(243);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(235);
      expressionStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(236);
      assignmentStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(237);
      classicalDeclarationStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(238);
      branchingStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(239);
      loopStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(240);
      controlDirectiveStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(241);
      aliasStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(242);
      quantumStatement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumDeclarationStatementContext ------------------------------------------------------------------

qasm3Parser::QuantumDeclarationStatementContext::QuantumDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QuantumDeclarationContext* qasm3Parser::QuantumDeclarationStatementContext::quantumDeclaration() {
  return getRuleContext<qasm3Parser::QuantumDeclarationContext>(0);
}

tree::TerminalNode* qasm3Parser::QuantumDeclarationStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::QuantumDeclarationStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumDeclarationStatement;
}


antlrcpp::Any qasm3Parser::QuantumDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumDeclarationStatementContext* qasm3Parser::quantumDeclarationStatement() {
  QuantumDeclarationStatementContext *_localctx = _tracker.createInstance<QuantumDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 12, qasm3Parser::RuleQuantumDeclarationStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    quantumDeclaration();
    setState(246);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalDeclarationStatementContext ------------------------------------------------------------------

qasm3Parser::ClassicalDeclarationStatementContext::ClassicalDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ClassicalDeclarationStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::ClassicalDeclarationContext* qasm3Parser::ClassicalDeclarationStatementContext::classicalDeclaration() {
  return getRuleContext<qasm3Parser::ClassicalDeclarationContext>(0);
}

qasm3Parser::ConstantDeclarationContext* qasm3Parser::ClassicalDeclarationStatementContext::constantDeclaration() {
  return getRuleContext<qasm3Parser::ConstantDeclarationContext>(0);
}


size_t qasm3Parser::ClassicalDeclarationStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalDeclarationStatement;
}


antlrcpp::Any qasm3Parser::ClassicalDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitClassicalDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalDeclarationStatementContext* qasm3Parser::classicalDeclarationStatement() {
  ClassicalDeclarationStatementContext *_localctx = _tracker.createInstance<ClassicalDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 14, qasm3Parser::RuleClassicalDeclarationStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__4:
      case qasm3Parser::T__5:
      case qasm3Parser::T__6:
      case qasm3Parser::T__7:
      case qasm3Parser::T__8:
      case qasm3Parser::T__9:
      case qasm3Parser::T__10:
      case qasm3Parser::T__11:
      case qasm3Parser::T__74:
      case qasm3Parser::T__75: {
        setState(248);
        classicalDeclaration();
        break;
      }

      case qasm3Parser::T__12: {
        setState(249);
        constantDeclaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(252);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalAssignmentContext ------------------------------------------------------------------

qasm3Parser::ClassicalAssignmentContext::ClassicalAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::IndexIdentifierContext *> qasm3Parser::ClassicalAssignmentContext::indexIdentifier() {
  return getRuleContexts<qasm3Parser::IndexIdentifierContext>();
}

qasm3Parser::IndexIdentifierContext* qasm3Parser::ClassicalAssignmentContext::indexIdentifier(size_t i) {
  return getRuleContext<qasm3Parser::IndexIdentifierContext>(i);
}

qasm3Parser::AssignmentOperatorContext* qasm3Parser::ClassicalAssignmentContext::assignmentOperator() {
  return getRuleContext<qasm3Parser::AssignmentOperatorContext>(0);
}

qasm3Parser::ExpressionContext* qasm3Parser::ClassicalAssignmentContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}


size_t qasm3Parser::ClassicalAssignmentContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalAssignment;
}


antlrcpp::Any qasm3Parser::ClassicalAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitClassicalAssignment(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalAssignmentContext* qasm3Parser::classicalAssignment() {
  ClassicalAssignmentContext *_localctx = _tracker.createInstance<ClassicalAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 16, qasm3Parser::RuleClassicalAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(254);
    indexIdentifier(0);
    setState(255);
    assignmentOperator();
    setState(258);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(256);
      expression(0);
      break;
    }

    case 2: {
      setState(257);
      indexIdentifier(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

qasm3Parser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::AssignmentStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::ClassicalAssignmentContext* qasm3Parser::AssignmentStatementContext::classicalAssignment() {
  return getRuleContext<qasm3Parser::ClassicalAssignmentContext>(0);
}

qasm3Parser::QuantumMeasurementAssignmentContext* qasm3Parser::AssignmentStatementContext::quantumMeasurementAssignment() {
  return getRuleContext<qasm3Parser::QuantumMeasurementAssignmentContext>(0);
}


size_t qasm3Parser::AssignmentStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleAssignmentStatement;
}


antlrcpp::Any qasm3Parser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AssignmentStatementContext* qasm3Parser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 18, qasm3Parser::RuleAssignmentStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(260);
      classicalAssignment();
      break;
    }

    case 2: {
      setState(261);
      quantumMeasurementAssignment();
      break;
    }

    default:
      break;
    }
    setState(264);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnSignatureContext ------------------------------------------------------------------

qasm3Parser::ReturnSignatureContext::ReturnSignatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ReturnSignatureContext::ARROW() {
  return getToken(qasm3Parser::ARROW, 0);
}

qasm3Parser::ClassicalTypeContext* qasm3Parser::ReturnSignatureContext::classicalType() {
  return getRuleContext<qasm3Parser::ClassicalTypeContext>(0);
}


size_t qasm3Parser::ReturnSignatureContext::getRuleIndex() const {
  return qasm3Parser::RuleReturnSignature;
}


antlrcpp::Any qasm3Parser::ReturnSignatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitReturnSignature(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ReturnSignatureContext* qasm3Parser::returnSignature() {
  ReturnSignatureContext *_localctx = _tracker.createInstance<ReturnSignatureContext>(_ctx, getState());
  enterRule(_localctx, 20, qasm3Parser::RuleReturnSignature);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(266);
    match(qasm3Parser::ARROW);
    setState(267);
    classicalType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DesignatorContext ------------------------------------------------------------------

qasm3Parser::DesignatorContext::DesignatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::DesignatorContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::DesignatorContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::DesignatorContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}


size_t qasm3Parser::DesignatorContext::getRuleIndex() const {
  return qasm3Parser::RuleDesignator;
}


antlrcpp::Any qasm3Parser::DesignatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitDesignator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DesignatorContext* qasm3Parser::designator() {
  DesignatorContext *_localctx = _tracker.createInstance<DesignatorContext>(_ctx, getState());
  enterRule(_localctx, 22, qasm3Parser::RuleDesignator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    match(qasm3Parser::LBRACKET);
    setState(270);
    expression(0);
    setState(271);
    match(qasm3Parser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DoubleDesignatorContext ------------------------------------------------------------------

qasm3Parser::DoubleDesignatorContext::DoubleDesignatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::DoubleDesignatorContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::DoubleDesignatorContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::DoubleDesignatorContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::DoubleDesignatorContext::COMMA() {
  return getToken(qasm3Parser::COMMA, 0);
}

tree::TerminalNode* qasm3Parser::DoubleDesignatorContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}


size_t qasm3Parser::DoubleDesignatorContext::getRuleIndex() const {
  return qasm3Parser::RuleDoubleDesignator;
}


antlrcpp::Any qasm3Parser::DoubleDesignatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitDoubleDesignator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DoubleDesignatorContext* qasm3Parser::doubleDesignator() {
  DoubleDesignatorContext *_localctx = _tracker.createInstance<DoubleDesignatorContext>(_ctx, getState());
  enterRule(_localctx, 24, qasm3Parser::RuleDoubleDesignator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    match(qasm3Parser::LBRACKET);
    setState(274);
    expression(0);
    setState(275);
    match(qasm3Parser::COMMA);
    setState(276);
    expression(0);
    setState(277);
    match(qasm3Parser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

qasm3Parser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> qasm3Parser::IdentifierListContext::Identifier() {
  return getTokens(qasm3Parser::Identifier);
}

tree::TerminalNode* qasm3Parser::IdentifierListContext::Identifier(size_t i) {
  return getToken(qasm3Parser::Identifier, i);
}

std::vector<tree::TerminalNode *> qasm3Parser::IdentifierListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::IdentifierListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::IdentifierListContext::getRuleIndex() const {
  return qasm3Parser::RuleIdentifierList;
}


antlrcpp::Any qasm3Parser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IdentifierListContext* qasm3Parser::identifierList() {
  IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 26, qasm3Parser::RuleIdentifierList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(283);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(279);
        match(qasm3Parser::Identifier);
        setState(280);
        match(qasm3Parser::COMMA); 
      }
      setState(285);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
    setState(286);
    match(qasm3Parser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssociationContext ------------------------------------------------------------------

qasm3Parser::AssociationContext::AssociationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::AssociationContext::COLON() {
  return getToken(qasm3Parser::COLON, 0);
}

tree::TerminalNode* qasm3Parser::AssociationContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}


size_t qasm3Parser::AssociationContext::getRuleIndex() const {
  return qasm3Parser::RuleAssociation;
}


antlrcpp::Any qasm3Parser::AssociationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitAssociation(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AssociationContext* qasm3Parser::association() {
  AssociationContext *_localctx = _tracker.createInstance<AssociationContext>(_ctx, getState());
  enterRule(_localctx, 28, qasm3Parser::RuleAssociation);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    match(qasm3Parser::COLON);
    setState(289);
    match(qasm3Parser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumTypeContext ------------------------------------------------------------------

qasm3Parser::QuantumTypeContext::QuantumTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::QuantumTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumType;
}


antlrcpp::Any qasm3Parser::QuantumTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumTypeContext* qasm3Parser::quantumType() {
  QuantumTypeContext *_localctx = _tracker.createInstance<QuantumTypeContext>(_ctx, getState());
  enterRule(_localctx, 30, qasm3Parser::RuleQuantumType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__2

    || _la == qasm3Parser::T__3)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumDeclarationContext ------------------------------------------------------------------

qasm3Parser::QuantumDeclarationContext::QuantumDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QuantumTypeContext* qasm3Parser::QuantumDeclarationContext::quantumType() {
  return getRuleContext<qasm3Parser::QuantumTypeContext>(0);
}

qasm3Parser::IndexIdentifierListContext* qasm3Parser::QuantumDeclarationContext::indexIdentifierList() {
  return getRuleContext<qasm3Parser::IndexIdentifierListContext>(0);
}


size_t qasm3Parser::QuantumDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumDeclaration;
}


antlrcpp::Any qasm3Parser::QuantumDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumDeclarationContext* qasm3Parser::quantumDeclaration() {
  QuantumDeclarationContext *_localctx = _tracker.createInstance<QuantumDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 32, qasm3Parser::RuleQuantumDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    quantumType();
    setState(294);
    indexIdentifierList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumArgumentContext ------------------------------------------------------------------

qasm3Parser::QuantumArgumentContext::QuantumArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QuantumTypeContext* qasm3Parser::QuantumArgumentContext::quantumType() {
  return getRuleContext<qasm3Parser::QuantumTypeContext>(0);
}

qasm3Parser::AssociationContext* qasm3Parser::QuantumArgumentContext::association() {
  return getRuleContext<qasm3Parser::AssociationContext>(0);
}

qasm3Parser::DesignatorContext* qasm3Parser::QuantumArgumentContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::QuantumArgumentContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumArgument;
}


antlrcpp::Any qasm3Parser::QuantumArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumArgument(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumArgumentContext* qasm3Parser::quantumArgument() {
  QuantumArgumentContext *_localctx = _tracker.createInstance<QuantumArgumentContext>(_ctx, getState());
  enterRule(_localctx, 34, qasm3Parser::RuleQuantumArgument);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(296);
    quantumType();
    setState(298);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LBRACKET) {
      setState(297);
      designator();
    }
    setState(300);
    association();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumArgumentListContext ------------------------------------------------------------------

qasm3Parser::QuantumArgumentListContext::QuantumArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::QuantumArgumentContext *> qasm3Parser::QuantumArgumentListContext::quantumArgument() {
  return getRuleContexts<qasm3Parser::QuantumArgumentContext>();
}

qasm3Parser::QuantumArgumentContext* qasm3Parser::QuantumArgumentListContext::quantumArgument(size_t i) {
  return getRuleContext<qasm3Parser::QuantumArgumentContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::QuantumArgumentListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::QuantumArgumentListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::QuantumArgumentListContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumArgumentList;
}


antlrcpp::Any qasm3Parser::QuantumArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumArgumentList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumArgumentListContext* qasm3Parser::quantumArgumentList() {
  QuantumArgumentListContext *_localctx = _tracker.createInstance<QuantumArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 36, qasm3Parser::RuleQuantumArgumentList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(307);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(302);
        quantumArgument();
        setState(303);
        match(qasm3Parser::COMMA); 
      }
      setState(309);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
    setState(310);
    quantumArgument();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BitTypeContext ------------------------------------------------------------------

qasm3Parser::BitTypeContext::BitTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::BitTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleBitType;
}


antlrcpp::Any qasm3Parser::BitTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitBitType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BitTypeContext* qasm3Parser::bitType() {
  BitTypeContext *_localctx = _tracker.createInstance<BitTypeContext>(_ctx, getState());
  enterRule(_localctx, 38, qasm3Parser::RuleBitType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(312);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__4

    || _la == qasm3Parser::T__5)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleDesignatorTypeContext ------------------------------------------------------------------

qasm3Parser::SingleDesignatorTypeContext::SingleDesignatorTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::SingleDesignatorTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleSingleDesignatorType;
}


antlrcpp::Any qasm3Parser::SingleDesignatorTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitSingleDesignatorType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SingleDesignatorTypeContext* qasm3Parser::singleDesignatorType() {
  SingleDesignatorTypeContext *_localctx = _tracker.createInstance<SingleDesignatorTypeContext>(_ctx, getState());
  enterRule(_localctx, 40, qasm3Parser::RuleSingleDesignatorType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(314);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__6)
      | (1ULL << qasm3Parser::T__7)
      | (1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DoubleDesignatorTypeContext ------------------------------------------------------------------

qasm3Parser::DoubleDesignatorTypeContext::DoubleDesignatorTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::DoubleDesignatorTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleDoubleDesignatorType;
}


antlrcpp::Any qasm3Parser::DoubleDesignatorTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitDoubleDesignatorType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DoubleDesignatorTypeContext* qasm3Parser::doubleDesignatorType() {
  DoubleDesignatorTypeContext *_localctx = _tracker.createInstance<DoubleDesignatorTypeContext>(_ctx, getState());
  enterRule(_localctx, 42, qasm3Parser::RuleDoubleDesignatorType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(316);
    match(qasm3Parser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NoDesignatorTypeContext ------------------------------------------------------------------

qasm3Parser::NoDesignatorTypeContext::NoDesignatorTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::TimingTypeContext* qasm3Parser::NoDesignatorTypeContext::timingType() {
  return getRuleContext<qasm3Parser::TimingTypeContext>(0);
}


size_t qasm3Parser::NoDesignatorTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleNoDesignatorType;
}


antlrcpp::Any qasm3Parser::NoDesignatorTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitNoDesignatorType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::NoDesignatorTypeContext* qasm3Parser::noDesignatorType() {
  NoDesignatorTypeContext *_localctx = _tracker.createInstance<NoDesignatorTypeContext>(_ctx, getState());
  enterRule(_localctx, 44, qasm3Parser::RuleNoDesignatorType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(320);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__11: {
        enterOuterAlt(_localctx, 1);
        setState(318);
        match(qasm3Parser::T__11);
        break;
      }

      case qasm3Parser::T__74:
      case qasm3Parser::T__75: {
        enterOuterAlt(_localctx, 2);
        setState(319);
        timingType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalTypeContext ------------------------------------------------------------------

qasm3Parser::ClassicalTypeContext::ClassicalTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::SingleDesignatorTypeContext* qasm3Parser::ClassicalTypeContext::singleDesignatorType() {
  return getRuleContext<qasm3Parser::SingleDesignatorTypeContext>(0);
}

qasm3Parser::DesignatorContext* qasm3Parser::ClassicalTypeContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

qasm3Parser::DoubleDesignatorTypeContext* qasm3Parser::ClassicalTypeContext::doubleDesignatorType() {
  return getRuleContext<qasm3Parser::DoubleDesignatorTypeContext>(0);
}

qasm3Parser::DoubleDesignatorContext* qasm3Parser::ClassicalTypeContext::doubleDesignator() {
  return getRuleContext<qasm3Parser::DoubleDesignatorContext>(0);
}

qasm3Parser::NoDesignatorTypeContext* qasm3Parser::ClassicalTypeContext::noDesignatorType() {
  return getRuleContext<qasm3Parser::NoDesignatorTypeContext>(0);
}

qasm3Parser::BitTypeContext* qasm3Parser::ClassicalTypeContext::bitType() {
  return getRuleContext<qasm3Parser::BitTypeContext>(0);
}


size_t qasm3Parser::ClassicalTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalType;
}


antlrcpp::Any qasm3Parser::ClassicalTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitClassicalType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalTypeContext* qasm3Parser::classicalType() {
  ClassicalTypeContext *_localctx = _tracker.createInstance<ClassicalTypeContext>(_ctx, getState());
  enterRule(_localctx, 46, qasm3Parser::RuleClassicalType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(333);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__6:
      case qasm3Parser::T__7:
      case qasm3Parser::T__8:
      case qasm3Parser::T__9: {
        enterOuterAlt(_localctx, 1);
        setState(322);
        singleDesignatorType();
        setState(323);
        designator();
        break;
      }

      case qasm3Parser::T__10: {
        enterOuterAlt(_localctx, 2);
        setState(325);
        doubleDesignatorType();
        setState(326);
        doubleDesignator();
        break;
      }

      case qasm3Parser::T__11:
      case qasm3Parser::T__74:
      case qasm3Parser::T__75: {
        enterOuterAlt(_localctx, 3);
        setState(328);
        noDesignatorType();
        break;
      }

      case qasm3Parser::T__4:
      case qasm3Parser::T__5: {
        enterOuterAlt(_localctx, 4);
        setState(329);
        bitType();
        setState(331);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(330);
          designator();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDeclarationContext ------------------------------------------------------------------

qasm3Parser::ConstantDeclarationContext::ConstantDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::EqualsAssignmentListContext* qasm3Parser::ConstantDeclarationContext::equalsAssignmentList() {
  return getRuleContext<qasm3Parser::EqualsAssignmentListContext>(0);
}


size_t qasm3Parser::ConstantDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleConstantDeclaration;
}


antlrcpp::Any qasm3Parser::ConstantDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitConstantDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ConstantDeclarationContext* qasm3Parser::constantDeclaration() {
  ConstantDeclarationContext *_localctx = _tracker.createInstance<ConstantDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 48, qasm3Parser::RuleConstantDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
    match(qasm3Parser::T__12);
    setState(336);
    equalsAssignmentList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleDesignatorDeclarationContext ------------------------------------------------------------------

qasm3Parser::SingleDesignatorDeclarationContext::SingleDesignatorDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::SingleDesignatorTypeContext* qasm3Parser::SingleDesignatorDeclarationContext::singleDesignatorType() {
  return getRuleContext<qasm3Parser::SingleDesignatorTypeContext>(0);
}

qasm3Parser::DesignatorContext* qasm3Parser::SingleDesignatorDeclarationContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

qasm3Parser::IdentifierListContext* qasm3Parser::SingleDesignatorDeclarationContext::identifierList() {
  return getRuleContext<qasm3Parser::IdentifierListContext>(0);
}

qasm3Parser::EqualsAssignmentListContext* qasm3Parser::SingleDesignatorDeclarationContext::equalsAssignmentList() {
  return getRuleContext<qasm3Parser::EqualsAssignmentListContext>(0);
}


size_t qasm3Parser::SingleDesignatorDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleSingleDesignatorDeclaration;
}


antlrcpp::Any qasm3Parser::SingleDesignatorDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitSingleDesignatorDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SingleDesignatorDeclarationContext* qasm3Parser::singleDesignatorDeclaration() {
  SingleDesignatorDeclarationContext *_localctx = _tracker.createInstance<SingleDesignatorDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 50, qasm3Parser::RuleSingleDesignatorDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(338);
    singleDesignatorType();
    setState(339);
    designator();
    setState(342);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(340);
      identifierList();
      break;
    }

    case 2: {
      setState(341);
      equalsAssignmentList();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DoubleDesignatorDeclarationContext ------------------------------------------------------------------

qasm3Parser::DoubleDesignatorDeclarationContext::DoubleDesignatorDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::DoubleDesignatorTypeContext* qasm3Parser::DoubleDesignatorDeclarationContext::doubleDesignatorType() {
  return getRuleContext<qasm3Parser::DoubleDesignatorTypeContext>(0);
}

qasm3Parser::DoubleDesignatorContext* qasm3Parser::DoubleDesignatorDeclarationContext::doubleDesignator() {
  return getRuleContext<qasm3Parser::DoubleDesignatorContext>(0);
}

qasm3Parser::IdentifierListContext* qasm3Parser::DoubleDesignatorDeclarationContext::identifierList() {
  return getRuleContext<qasm3Parser::IdentifierListContext>(0);
}

qasm3Parser::EqualsAssignmentListContext* qasm3Parser::DoubleDesignatorDeclarationContext::equalsAssignmentList() {
  return getRuleContext<qasm3Parser::EqualsAssignmentListContext>(0);
}


size_t qasm3Parser::DoubleDesignatorDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleDoubleDesignatorDeclaration;
}


antlrcpp::Any qasm3Parser::DoubleDesignatorDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitDoubleDesignatorDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DoubleDesignatorDeclarationContext* qasm3Parser::doubleDesignatorDeclaration() {
  DoubleDesignatorDeclarationContext *_localctx = _tracker.createInstance<DoubleDesignatorDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 52, qasm3Parser::RuleDoubleDesignatorDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(344);
    doubleDesignatorType();
    setState(345);
    doubleDesignator();
    setState(348);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(346);
      identifierList();
      break;
    }

    case 2: {
      setState(347);
      equalsAssignmentList();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NoDesignatorDeclarationContext ------------------------------------------------------------------

qasm3Parser::NoDesignatorDeclarationContext::NoDesignatorDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::NoDesignatorTypeContext* qasm3Parser::NoDesignatorDeclarationContext::noDesignatorType() {
  return getRuleContext<qasm3Parser::NoDesignatorTypeContext>(0);
}

qasm3Parser::IdentifierListContext* qasm3Parser::NoDesignatorDeclarationContext::identifierList() {
  return getRuleContext<qasm3Parser::IdentifierListContext>(0);
}

qasm3Parser::EqualsAssignmentListContext* qasm3Parser::NoDesignatorDeclarationContext::equalsAssignmentList() {
  return getRuleContext<qasm3Parser::EqualsAssignmentListContext>(0);
}


size_t qasm3Parser::NoDesignatorDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleNoDesignatorDeclaration;
}


antlrcpp::Any qasm3Parser::NoDesignatorDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitNoDesignatorDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::NoDesignatorDeclarationContext* qasm3Parser::noDesignatorDeclaration() {
  NoDesignatorDeclarationContext *_localctx = _tracker.createInstance<NoDesignatorDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 54, qasm3Parser::RuleNoDesignatorDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    noDesignatorType();
    setState(353);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(351);
      identifierList();
      break;
    }

    case 2: {
      setState(352);
      equalsAssignmentList();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BitDeclarationContext ------------------------------------------------------------------

qasm3Parser::BitDeclarationContext::BitDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::BitTypeContext* qasm3Parser::BitDeclarationContext::bitType() {
  return getRuleContext<qasm3Parser::BitTypeContext>(0);
}

qasm3Parser::IndexIdentifierListContext* qasm3Parser::BitDeclarationContext::indexIdentifierList() {
  return getRuleContext<qasm3Parser::IndexIdentifierListContext>(0);
}

qasm3Parser::IndexEqualsAssignmentListContext* qasm3Parser::BitDeclarationContext::indexEqualsAssignmentList() {
  return getRuleContext<qasm3Parser::IndexEqualsAssignmentListContext>(0);
}


size_t qasm3Parser::BitDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleBitDeclaration;
}


antlrcpp::Any qasm3Parser::BitDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitBitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BitDeclarationContext* qasm3Parser::bitDeclaration() {
  BitDeclarationContext *_localctx = _tracker.createInstance<BitDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 56, qasm3Parser::RuleBitDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(355);
    bitType();
    setState(358);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(356);
      indexIdentifierList();
      break;
    }

    case 2: {
      setState(357);
      indexEqualsAssignmentList();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalDeclarationContext ------------------------------------------------------------------

qasm3Parser::ClassicalDeclarationContext::ClassicalDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::SingleDesignatorDeclarationContext* qasm3Parser::ClassicalDeclarationContext::singleDesignatorDeclaration() {
  return getRuleContext<qasm3Parser::SingleDesignatorDeclarationContext>(0);
}

qasm3Parser::DoubleDesignatorDeclarationContext* qasm3Parser::ClassicalDeclarationContext::doubleDesignatorDeclaration() {
  return getRuleContext<qasm3Parser::DoubleDesignatorDeclarationContext>(0);
}

qasm3Parser::NoDesignatorDeclarationContext* qasm3Parser::ClassicalDeclarationContext::noDesignatorDeclaration() {
  return getRuleContext<qasm3Parser::NoDesignatorDeclarationContext>(0);
}

qasm3Parser::BitDeclarationContext* qasm3Parser::ClassicalDeclarationContext::bitDeclaration() {
  return getRuleContext<qasm3Parser::BitDeclarationContext>(0);
}


size_t qasm3Parser::ClassicalDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalDeclaration;
}


antlrcpp::Any qasm3Parser::ClassicalDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitClassicalDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalDeclarationContext* qasm3Parser::classicalDeclaration() {
  ClassicalDeclarationContext *_localctx = _tracker.createInstance<ClassicalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 58, qasm3Parser::RuleClassicalDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(364);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__6:
      case qasm3Parser::T__7:
      case qasm3Parser::T__8:
      case qasm3Parser::T__9: {
        enterOuterAlt(_localctx, 1);
        setState(360);
        singleDesignatorDeclaration();
        break;
      }

      case qasm3Parser::T__10: {
        enterOuterAlt(_localctx, 2);
        setState(361);
        doubleDesignatorDeclaration();
        break;
      }

      case qasm3Parser::T__11:
      case qasm3Parser::T__74:
      case qasm3Parser::T__75: {
        enterOuterAlt(_localctx, 3);
        setState(362);
        noDesignatorDeclaration();
        break;
      }

      case qasm3Parser::T__4:
      case qasm3Parser::T__5: {
        enterOuterAlt(_localctx, 4);
        setState(363);
        bitDeclaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalTypeListContext ------------------------------------------------------------------

qasm3Parser::ClassicalTypeListContext::ClassicalTypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::ClassicalTypeContext *> qasm3Parser::ClassicalTypeListContext::classicalType() {
  return getRuleContexts<qasm3Parser::ClassicalTypeContext>();
}

qasm3Parser::ClassicalTypeContext* qasm3Parser::ClassicalTypeListContext::classicalType(size_t i) {
  return getRuleContext<qasm3Parser::ClassicalTypeContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::ClassicalTypeListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::ClassicalTypeListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::ClassicalTypeListContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalTypeList;
}


antlrcpp::Any qasm3Parser::ClassicalTypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitClassicalTypeList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalTypeListContext* qasm3Parser::classicalTypeList() {
  ClassicalTypeListContext *_localctx = _tracker.createInstance<ClassicalTypeListContext>(_ctx, getState());
  enterRule(_localctx, 60, qasm3Parser::RuleClassicalTypeList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(371);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(366);
        classicalType();
        setState(367);
        match(qasm3Parser::COMMA); 
      }
      setState(373);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
    setState(374);
    classicalType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalArgumentContext ------------------------------------------------------------------

qasm3Parser::ClassicalArgumentContext::ClassicalArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ClassicalTypeContext* qasm3Parser::ClassicalArgumentContext::classicalType() {
  return getRuleContext<qasm3Parser::ClassicalTypeContext>(0);
}

qasm3Parser::AssociationContext* qasm3Parser::ClassicalArgumentContext::association() {
  return getRuleContext<qasm3Parser::AssociationContext>(0);
}


size_t qasm3Parser::ClassicalArgumentContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalArgument;
}


antlrcpp::Any qasm3Parser::ClassicalArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitClassicalArgument(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalArgumentContext* qasm3Parser::classicalArgument() {
  ClassicalArgumentContext *_localctx = _tracker.createInstance<ClassicalArgumentContext>(_ctx, getState());
  enterRule(_localctx, 62, qasm3Parser::RuleClassicalArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(376);
    classicalType();
    setState(377);
    association();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalArgumentListContext ------------------------------------------------------------------

qasm3Parser::ClassicalArgumentListContext::ClassicalArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::ClassicalArgumentContext *> qasm3Parser::ClassicalArgumentListContext::classicalArgument() {
  return getRuleContexts<qasm3Parser::ClassicalArgumentContext>();
}

qasm3Parser::ClassicalArgumentContext* qasm3Parser::ClassicalArgumentListContext::classicalArgument(size_t i) {
  return getRuleContext<qasm3Parser::ClassicalArgumentContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::ClassicalArgumentListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::ClassicalArgumentListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::ClassicalArgumentListContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalArgumentList;
}


antlrcpp::Any qasm3Parser::ClassicalArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitClassicalArgumentList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalArgumentListContext* qasm3Parser::classicalArgumentList() {
  ClassicalArgumentListContext *_localctx = _tracker.createInstance<ClassicalArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 64, qasm3Parser::RuleClassicalArgumentList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(384);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(379);
        classicalArgument();
        setState(380);
        match(qasm3Parser::COMMA); 
      }
      setState(386);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
    setState(387);
    classicalArgument();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AliasStatementContext ------------------------------------------------------------------

qasm3Parser::AliasStatementContext::AliasStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::AliasStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::AliasStatementContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

qasm3Parser::IndexIdentifierContext* qasm3Parser::AliasStatementContext::indexIdentifier() {
  return getRuleContext<qasm3Parser::IndexIdentifierContext>(0);
}

tree::TerminalNode* qasm3Parser::AliasStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::AliasStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleAliasStatement;
}


antlrcpp::Any qasm3Parser::AliasStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitAliasStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AliasStatementContext* qasm3Parser::aliasStatement() {
  AliasStatementContext *_localctx = _tracker.createInstance<AliasStatementContext>(_ctx, getState());
  enterRule(_localctx, 66, qasm3Parser::RuleAliasStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(389);
    match(qasm3Parser::T__13);
    setState(390);
    match(qasm3Parser::Identifier);
    setState(391);
    match(qasm3Parser::EQUALS);
    setState(392);
    indexIdentifier(0);
    setState(393);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexIdentifierContext ------------------------------------------------------------------

qasm3Parser::IndexIdentifierContext::IndexIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::IndexIdentifierContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::RangeDefinitionContext* qasm3Parser::IndexIdentifierContext::rangeDefinition() {
  return getRuleContext<qasm3Parser::RangeDefinitionContext>(0);
}

tree::TerminalNode* qasm3Parser::IndexIdentifierContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::IndexIdentifierContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

tree::TerminalNode* qasm3Parser::IndexIdentifierContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}

std::vector<qasm3Parser::IndexIdentifierContext *> qasm3Parser::IndexIdentifierContext::indexIdentifier() {
  return getRuleContexts<qasm3Parser::IndexIdentifierContext>();
}

qasm3Parser::IndexIdentifierContext* qasm3Parser::IndexIdentifierContext::indexIdentifier(size_t i) {
  return getRuleContext<qasm3Parser::IndexIdentifierContext>(i);
}


size_t qasm3Parser::IndexIdentifierContext::getRuleIndex() const {
  return qasm3Parser::RuleIndexIdentifier;
}


antlrcpp::Any qasm3Parser::IndexIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitIndexIdentifier(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::IndexIdentifierContext* qasm3Parser::indexIdentifier() {
   return indexIdentifier(0);
}

qasm3Parser::IndexIdentifierContext* qasm3Parser::indexIdentifier(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::IndexIdentifierContext *_localctx = _tracker.createInstance<IndexIdentifierContext>(_ctx, parentState);
  qasm3Parser::IndexIdentifierContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 68;
  enterRecursionRule(_localctx, 68, qasm3Parser::RuleIndexIdentifier, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(405);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(396);
      match(qasm3Parser::Identifier);
      setState(397);
      rangeDefinition();
      break;
    }

    case 2: {
      setState(398);
      match(qasm3Parser::Identifier);
      setState(403);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
      case 1: {
        setState(399);
        match(qasm3Parser::LBRACKET);
        setState(400);
        expressionList();
        setState(401);
        match(qasm3Parser::RBRACKET);
        break;
      }

      default:
        break;
      }
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(412);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<IndexIdentifierContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleIndexIdentifier);
        setState(407);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(408);
        match(qasm3Parser::T__14);
        setState(409);
        indexIdentifier(2); 
      }
      setState(414);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IndexIdentifierListContext ------------------------------------------------------------------

qasm3Parser::IndexIdentifierListContext::IndexIdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::IndexIdentifierContext *> qasm3Parser::IndexIdentifierListContext::indexIdentifier() {
  return getRuleContexts<qasm3Parser::IndexIdentifierContext>();
}

qasm3Parser::IndexIdentifierContext* qasm3Parser::IndexIdentifierListContext::indexIdentifier(size_t i) {
  return getRuleContext<qasm3Parser::IndexIdentifierContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::IndexIdentifierListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::IndexIdentifierListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::IndexIdentifierListContext::getRuleIndex() const {
  return qasm3Parser::RuleIndexIdentifierList;
}


antlrcpp::Any qasm3Parser::IndexIdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitIndexIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IndexIdentifierListContext* qasm3Parser::indexIdentifierList() {
  IndexIdentifierListContext *_localctx = _tracker.createInstance<IndexIdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 70, qasm3Parser::RuleIndexIdentifierList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(420);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(415);
        indexIdentifier(0);
        setState(416);
        match(qasm3Parser::COMMA); 
      }
      setState(422);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
    setState(423);
    indexIdentifier(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexEqualsAssignmentListContext ------------------------------------------------------------------

qasm3Parser::IndexEqualsAssignmentListContext::IndexEqualsAssignmentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::IndexIdentifierContext *> qasm3Parser::IndexEqualsAssignmentListContext::indexIdentifier() {
  return getRuleContexts<qasm3Parser::IndexIdentifierContext>();
}

qasm3Parser::IndexIdentifierContext* qasm3Parser::IndexEqualsAssignmentListContext::indexIdentifier(size_t i) {
  return getRuleContext<qasm3Parser::IndexIdentifierContext>(i);
}

std::vector<qasm3Parser::EqualsExpressionContext *> qasm3Parser::IndexEqualsAssignmentListContext::equalsExpression() {
  return getRuleContexts<qasm3Parser::EqualsExpressionContext>();
}

qasm3Parser::EqualsExpressionContext* qasm3Parser::IndexEqualsAssignmentListContext::equalsExpression(size_t i) {
  return getRuleContext<qasm3Parser::EqualsExpressionContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::IndexEqualsAssignmentListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::IndexEqualsAssignmentListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::IndexEqualsAssignmentListContext::getRuleIndex() const {
  return qasm3Parser::RuleIndexEqualsAssignmentList;
}


antlrcpp::Any qasm3Parser::IndexEqualsAssignmentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitIndexEqualsAssignmentList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IndexEqualsAssignmentListContext* qasm3Parser::indexEqualsAssignmentList() {
  IndexEqualsAssignmentListContext *_localctx = _tracker.createInstance<IndexEqualsAssignmentListContext>(_ctx, getState());
  enterRule(_localctx, 72, qasm3Parser::RuleIndexEqualsAssignmentList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(431);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(425);
        indexIdentifier(0);
        setState(426);
        equalsExpression();
        setState(427);
        match(qasm3Parser::COMMA); 
      }
      setState(433);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
    setState(434);
    indexIdentifier(0);
    setState(435);
    equalsExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeDefinitionContext ------------------------------------------------------------------

qasm3Parser::RangeDefinitionContext::RangeDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::RangeDefinitionContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

std::vector<tree::TerminalNode *> qasm3Parser::RangeDefinitionContext::COLON() {
  return getTokens(qasm3Parser::COLON);
}

tree::TerminalNode* qasm3Parser::RangeDefinitionContext::COLON(size_t i) {
  return getToken(qasm3Parser::COLON, i);
}

tree::TerminalNode* qasm3Parser::RangeDefinitionContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::RangeDefinitionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::RangeDefinitionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}


size_t qasm3Parser::RangeDefinitionContext::getRuleIndex() const {
  return qasm3Parser::RuleRangeDefinition;
}


antlrcpp::Any qasm3Parser::RangeDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitRangeDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::RangeDefinitionContext* qasm3Parser::rangeDefinition() {
  RangeDefinitionContext *_localctx = _tracker.createInstance<RangeDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 74, qasm3Parser::RuleRangeDefinition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(437);
    match(qasm3Parser::LBRACKET);
    setState(439);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__4)
      | (1ULL << qasm3Parser::T__5)
      | (1ULL << qasm3Parser::T__6)
      | (1ULL << qasm3Parser::T__7)
      | (1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9)
      | (1ULL << qasm3Parser::T__10)
      | (1ULL << qasm3Parser::T__11)
      | (1ULL << qasm3Parser::T__26)
      | (1ULL << qasm3Parser::T__27)
      | (1ULL << qasm3Parser::T__42)
      | (1ULL << qasm3Parser::T__43)
      | (1ULL << qasm3Parser::T__44)
      | (1ULL << qasm3Parser::T__45)
      | (1ULL << qasm3Parser::T__46)
      | (1ULL << qasm3Parser::T__47)
      | (1ULL << qasm3Parser::T__48)
      | (1ULL << qasm3Parser::T__49)
      | (1ULL << qasm3Parser::T__50)
      | (1ULL << qasm3Parser::T__51))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 75)) & ((1ULL << (qasm3Parser::T__74 - 75))
      | (1ULL << (qasm3Parser::T__75 - 75))
      | (1ULL << (qasm3Parser::T__78 - 75))
      | (1ULL << (qasm3Parser::LPAREN - 75))
      | (1ULL << (qasm3Parser::MINUS - 75))
      | (1ULL << (qasm3Parser::Constant - 75))
      | (1ULL << (qasm3Parser::Integer - 75))
      | (1ULL << (qasm3Parser::Identifier - 75))
      | (1ULL << (qasm3Parser::RealNumber - 75))
      | (1ULL << (qasm3Parser::TimingLiteral - 75))
      | (1ULL << (qasm3Parser::StringLiteral - 75)))) != 0)) {
      setState(438);
      expression(0);
    }
    setState(441);
    match(qasm3Parser::COLON);
    setState(443);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__4)
      | (1ULL << qasm3Parser::T__5)
      | (1ULL << qasm3Parser::T__6)
      | (1ULL << qasm3Parser::T__7)
      | (1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9)
      | (1ULL << qasm3Parser::T__10)
      | (1ULL << qasm3Parser::T__11)
      | (1ULL << qasm3Parser::T__26)
      | (1ULL << qasm3Parser::T__27)
      | (1ULL << qasm3Parser::T__42)
      | (1ULL << qasm3Parser::T__43)
      | (1ULL << qasm3Parser::T__44)
      | (1ULL << qasm3Parser::T__45)
      | (1ULL << qasm3Parser::T__46)
      | (1ULL << qasm3Parser::T__47)
      | (1ULL << qasm3Parser::T__48)
      | (1ULL << qasm3Parser::T__49)
      | (1ULL << qasm3Parser::T__50)
      | (1ULL << qasm3Parser::T__51))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 75)) & ((1ULL << (qasm3Parser::T__74 - 75))
      | (1ULL << (qasm3Parser::T__75 - 75))
      | (1ULL << (qasm3Parser::T__78 - 75))
      | (1ULL << (qasm3Parser::LPAREN - 75))
      | (1ULL << (qasm3Parser::MINUS - 75))
      | (1ULL << (qasm3Parser::Constant - 75))
      | (1ULL << (qasm3Parser::Integer - 75))
      | (1ULL << (qasm3Parser::Identifier - 75))
      | (1ULL << (qasm3Parser::RealNumber - 75))
      | (1ULL << (qasm3Parser::TimingLiteral - 75))
      | (1ULL << (qasm3Parser::StringLiteral - 75)))) != 0)) {
      setState(442);
      expression(0);
    }
    setState(447);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COLON) {
      setState(445);
      match(qasm3Parser::COLON);
      setState(446);
      expression(0);
    }
    setState(449);
    match(qasm3Parser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumGateDefinitionContext ------------------------------------------------------------------

qasm3Parser::QuantumGateDefinitionContext::QuantumGateDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QuantumGateSignatureContext* qasm3Parser::QuantumGateDefinitionContext::quantumGateSignature() {
  return getRuleContext<qasm3Parser::QuantumGateSignatureContext>(0);
}

qasm3Parser::QuantumBlockContext* qasm3Parser::QuantumGateDefinitionContext::quantumBlock() {
  return getRuleContext<qasm3Parser::QuantumBlockContext>(0);
}


size_t qasm3Parser::QuantumGateDefinitionContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumGateDefinition;
}


antlrcpp::Any qasm3Parser::QuantumGateDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumGateDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumGateDefinitionContext* qasm3Parser::quantumGateDefinition() {
  QuantumGateDefinitionContext *_localctx = _tracker.createInstance<QuantumGateDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 76, qasm3Parser::RuleQuantumGateDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(451);
    match(qasm3Parser::T__15);
    setState(452);
    quantumGateSignature();
    setState(453);
    quantumBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumGateSignatureContext ------------------------------------------------------------------

qasm3Parser::QuantumGateSignatureContext::QuantumGateSignatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::IdentifierListContext *> qasm3Parser::QuantumGateSignatureContext::identifierList() {
  return getRuleContexts<qasm3Parser::IdentifierListContext>();
}

qasm3Parser::IdentifierListContext* qasm3Parser::QuantumGateSignatureContext::identifierList(size_t i) {
  return getRuleContext<qasm3Parser::IdentifierListContext>(i);
}

tree::TerminalNode* qasm3Parser::QuantumGateSignatureContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::QuantumGateSignatureContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::QuantumGateSignatureContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}


size_t qasm3Parser::QuantumGateSignatureContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumGateSignature;
}


antlrcpp::Any qasm3Parser::QuantumGateSignatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumGateSignature(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumGateSignatureContext* qasm3Parser::quantumGateSignature() {
  QuantumGateSignatureContext *_localctx = _tracker.createInstance<QuantumGateSignatureContext>(_ctx, getState());
  enterRule(_localctx, 78, qasm3Parser::RuleQuantumGateSignature);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(455);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__16

    || _la == qasm3Parser::T__17 || _la == qasm3Parser::Identifier)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(461);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(456);
      match(qasm3Parser::LPAREN);
      setState(458);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasm3Parser::Identifier) {
        setState(457);
        identifierList();
      }
      setState(460);
      match(qasm3Parser::RPAREN);
    }
    setState(463);
    identifierList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumBlockContext ------------------------------------------------------------------

qasm3Parser::QuantumBlockContext::QuantumBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::QuantumBlockContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::QuantumBlockContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

std::vector<qasm3Parser::QuantumStatementContext *> qasm3Parser::QuantumBlockContext::quantumStatement() {
  return getRuleContexts<qasm3Parser::QuantumStatementContext>();
}

qasm3Parser::QuantumStatementContext* qasm3Parser::QuantumBlockContext::quantumStatement(size_t i) {
  return getRuleContext<qasm3Parser::QuantumStatementContext>(i);
}

std::vector<qasm3Parser::QuantumLoopContext *> qasm3Parser::QuantumBlockContext::quantumLoop() {
  return getRuleContexts<qasm3Parser::QuantumLoopContext>();
}

qasm3Parser::QuantumLoopContext* qasm3Parser::QuantumBlockContext::quantumLoop(size_t i) {
  return getRuleContext<qasm3Parser::QuantumLoopContext>(i);
}


size_t qasm3Parser::QuantumBlockContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumBlock;
}


antlrcpp::Any qasm3Parser::QuantumBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumBlock(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumBlockContext* qasm3Parser::quantumBlock() {
  QuantumBlockContext *_localctx = _tracker.createInstance<QuantumBlockContext>(_ctx, getState());
  enterRule(_localctx, 80, qasm3Parser::RuleQuantumBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(465);
    match(qasm3Parser::LBRACE);
    setState(470);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__16)
      | (1ULL << qasm3Parser::T__17)
      | (1ULL << qasm3Parser::T__18)
      | (1ULL << qasm3Parser::T__19)
      | (1ULL << qasm3Parser::T__20)
      | (1ULL << qasm3Parser::T__21)
      | (1ULL << qasm3Parser::T__22)
      | (1ULL << qasm3Parser::T__23)
      | (1ULL << qasm3Parser::T__25))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (qasm3Parser::T__65 - 66))
      | (1ULL << (qasm3Parser::T__66 - 66))
      | (1ULL << (qasm3Parser::T__76 - 66))
      | (1ULL << (qasm3Parser::T__77 - 66))
      | (1ULL << (qasm3Parser::T__79 - 66))
      | (1ULL << (qasm3Parser::T__80 - 66))
      | (1ULL << (qasm3Parser::Identifier - 66)))) != 0)) {
      setState(468);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case qasm3Parser::T__16:
        case qasm3Parser::T__17:
        case qasm3Parser::T__18:
        case qasm3Parser::T__19:
        case qasm3Parser::T__20:
        case qasm3Parser::T__21:
        case qasm3Parser::T__22:
        case qasm3Parser::T__23:
        case qasm3Parser::T__25:
        case qasm3Parser::T__76:
        case qasm3Parser::T__77:
        case qasm3Parser::T__79:
        case qasm3Parser::T__80:
        case qasm3Parser::Identifier: {
          setState(466);
          quantumStatement();
          break;
        }

        case qasm3Parser::T__65:
        case qasm3Parser::T__66: {
          setState(467);
          quantumLoop();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(472);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(473);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumLoopContext ------------------------------------------------------------------

qasm3Parser::QuantumLoopContext::QuantumLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::LoopSignatureContext* qasm3Parser::QuantumLoopContext::loopSignature() {
  return getRuleContext<qasm3Parser::LoopSignatureContext>(0);
}

qasm3Parser::QuantumLoopBlockContext* qasm3Parser::QuantumLoopContext::quantumLoopBlock() {
  return getRuleContext<qasm3Parser::QuantumLoopBlockContext>(0);
}


size_t qasm3Parser::QuantumLoopContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumLoop;
}


antlrcpp::Any qasm3Parser::QuantumLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumLoop(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumLoopContext* qasm3Parser::quantumLoop() {
  QuantumLoopContext *_localctx = _tracker.createInstance<QuantumLoopContext>(_ctx, getState());
  enterRule(_localctx, 82, qasm3Parser::RuleQuantumLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(475);
    loopSignature();
    setState(476);
    quantumLoopBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumLoopBlockContext ------------------------------------------------------------------

qasm3Parser::QuantumLoopBlockContext::QuantumLoopBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::QuantumStatementContext *> qasm3Parser::QuantumLoopBlockContext::quantumStatement() {
  return getRuleContexts<qasm3Parser::QuantumStatementContext>();
}

qasm3Parser::QuantumStatementContext* qasm3Parser::QuantumLoopBlockContext::quantumStatement(size_t i) {
  return getRuleContext<qasm3Parser::QuantumStatementContext>(i);
}

tree::TerminalNode* qasm3Parser::QuantumLoopBlockContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::QuantumLoopBlockContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}


size_t qasm3Parser::QuantumLoopBlockContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumLoopBlock;
}


antlrcpp::Any qasm3Parser::QuantumLoopBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumLoopBlock(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumLoopBlockContext* qasm3Parser::quantumLoopBlock() {
  QuantumLoopBlockContext *_localctx = _tracker.createInstance<QuantumLoopBlockContext>(_ctx, getState());
  enterRule(_localctx, 84, qasm3Parser::RuleQuantumLoopBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(487);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__16:
      case qasm3Parser::T__17:
      case qasm3Parser::T__18:
      case qasm3Parser::T__19:
      case qasm3Parser::T__20:
      case qasm3Parser::T__21:
      case qasm3Parser::T__22:
      case qasm3Parser::T__23:
      case qasm3Parser::T__25:
      case qasm3Parser::T__76:
      case qasm3Parser::T__77:
      case qasm3Parser::T__79:
      case qasm3Parser::T__80:
      case qasm3Parser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(478);
        quantumStatement();
        break;
      }

      case qasm3Parser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(479);
        match(qasm3Parser::LBRACE);
        setState(483);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << qasm3Parser::T__16)
          | (1ULL << qasm3Parser::T__17)
          | (1ULL << qasm3Parser::T__18)
          | (1ULL << qasm3Parser::T__19)
          | (1ULL << qasm3Parser::T__20)
          | (1ULL << qasm3Parser::T__21)
          | (1ULL << qasm3Parser::T__22)
          | (1ULL << qasm3Parser::T__23)
          | (1ULL << qasm3Parser::T__25))) != 0) || ((((_la - 77) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 77)) & ((1ULL << (qasm3Parser::T__76 - 77))
          | (1ULL << (qasm3Parser::T__77 - 77))
          | (1ULL << (qasm3Parser::T__79 - 77))
          | (1ULL << (qasm3Parser::T__80 - 77))
          | (1ULL << (qasm3Parser::Identifier - 77)))) != 0)) {
          setState(480);
          quantumStatement();
          setState(485);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(486);
        match(qasm3Parser::RBRACE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumStatementContext ------------------------------------------------------------------

qasm3Parser::QuantumStatementContext::QuantumStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QuantumInstructionContext* qasm3Parser::QuantumStatementContext::quantumInstruction() {
  return getRuleContext<qasm3Parser::QuantumInstructionContext>(0);
}

tree::TerminalNode* qasm3Parser::QuantumStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::TimingStatementContext* qasm3Parser::QuantumStatementContext::timingStatement() {
  return getRuleContext<qasm3Parser::TimingStatementContext>(0);
}


size_t qasm3Parser::QuantumStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumStatement;
}


antlrcpp::Any qasm3Parser::QuantumStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumStatementContext* qasm3Parser::quantumStatement() {
  QuantumStatementContext *_localctx = _tracker.createInstance<QuantumStatementContext>(_ctx, getState());
  enterRule(_localctx, 86, qasm3Parser::RuleQuantumStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(493);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__16:
      case qasm3Parser::T__17:
      case qasm3Parser::T__18:
      case qasm3Parser::T__19:
      case qasm3Parser::T__20:
      case qasm3Parser::T__21:
      case qasm3Parser::T__22:
      case qasm3Parser::T__23:
      case qasm3Parser::T__25:
      case qasm3Parser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(489);
        quantumInstruction();
        setState(490);
        match(qasm3Parser::SEMICOLON);
        break;
      }

      case qasm3Parser::T__76:
      case qasm3Parser::T__77:
      case qasm3Parser::T__79:
      case qasm3Parser::T__80: {
        enterOuterAlt(_localctx, 2);
        setState(492);
        timingStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumInstructionContext ------------------------------------------------------------------

qasm3Parser::QuantumInstructionContext::QuantumInstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QuantumGateCallContext* qasm3Parser::QuantumInstructionContext::quantumGateCall() {
  return getRuleContext<qasm3Parser::QuantumGateCallContext>(0);
}

qasm3Parser::QuantumPhaseContext* qasm3Parser::QuantumInstructionContext::quantumPhase() {
  return getRuleContext<qasm3Parser::QuantumPhaseContext>(0);
}

qasm3Parser::QuantumMeasurementContext* qasm3Parser::QuantumInstructionContext::quantumMeasurement() {
  return getRuleContext<qasm3Parser::QuantumMeasurementContext>(0);
}

qasm3Parser::QuantumBarrierContext* qasm3Parser::QuantumInstructionContext::quantumBarrier() {
  return getRuleContext<qasm3Parser::QuantumBarrierContext>(0);
}


size_t qasm3Parser::QuantumInstructionContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumInstruction;
}


antlrcpp::Any qasm3Parser::QuantumInstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumInstruction(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumInstructionContext* qasm3Parser::quantumInstruction() {
  QuantumInstructionContext *_localctx = _tracker.createInstance<QuantumInstructionContext>(_ctx, getState());
  enterRule(_localctx, 88, qasm3Parser::RuleQuantumInstruction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(499);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__16:
      case qasm3Parser::T__17:
      case qasm3Parser::T__21:
      case qasm3Parser::T__22:
      case qasm3Parser::T__23:
      case qasm3Parser::T__25:
      case qasm3Parser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(495);
        quantumGateCall();
        break;
      }

      case qasm3Parser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(496);
        quantumPhase();
        break;
      }

      case qasm3Parser::T__19: {
        enterOuterAlt(_localctx, 3);
        setState(497);
        quantumMeasurement();
        break;
      }

      case qasm3Parser::T__20: {
        enterOuterAlt(_localctx, 4);
        setState(498);
        quantumBarrier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumPhaseContext ------------------------------------------------------------------

qasm3Parser::QuantumPhaseContext::QuantumPhaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::QuantumPhaseContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::QuantumPhaseContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::QuantumPhaseContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}


size_t qasm3Parser::QuantumPhaseContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumPhase;
}


antlrcpp::Any qasm3Parser::QuantumPhaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumPhase(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumPhaseContext* qasm3Parser::quantumPhase() {
  QuantumPhaseContext *_localctx = _tracker.createInstance<QuantumPhaseContext>(_ctx, getState());
  enterRule(_localctx, 90, qasm3Parser::RuleQuantumPhase);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(501);
    match(qasm3Parser::T__18);
    setState(502);
    match(qasm3Parser::LPAREN);
    setState(503);
    match(qasm3Parser::Identifier);
    setState(504);
    match(qasm3Parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumMeasurementContext ------------------------------------------------------------------

qasm3Parser::QuantumMeasurementContext::QuantumMeasurementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::IndexIdentifierListContext* qasm3Parser::QuantumMeasurementContext::indexIdentifierList() {
  return getRuleContext<qasm3Parser::IndexIdentifierListContext>(0);
}


size_t qasm3Parser::QuantumMeasurementContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumMeasurement;
}


antlrcpp::Any qasm3Parser::QuantumMeasurementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumMeasurement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumMeasurementContext* qasm3Parser::quantumMeasurement() {
  QuantumMeasurementContext *_localctx = _tracker.createInstance<QuantumMeasurementContext>(_ctx, getState());
  enterRule(_localctx, 92, qasm3Parser::RuleQuantumMeasurement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(506);
    match(qasm3Parser::T__19);
    setState(507);
    indexIdentifierList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumMeasurementAssignmentContext ------------------------------------------------------------------

qasm3Parser::QuantumMeasurementAssignmentContext::QuantumMeasurementAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QuantumMeasurementContext* qasm3Parser::QuantumMeasurementAssignmentContext::quantumMeasurement() {
  return getRuleContext<qasm3Parser::QuantumMeasurementContext>(0);
}

tree::TerminalNode* qasm3Parser::QuantumMeasurementAssignmentContext::ARROW() {
  return getToken(qasm3Parser::ARROW, 0);
}

qasm3Parser::IndexIdentifierListContext* qasm3Parser::QuantumMeasurementAssignmentContext::indexIdentifierList() {
  return getRuleContext<qasm3Parser::IndexIdentifierListContext>(0);
}

tree::TerminalNode* qasm3Parser::QuantumMeasurementAssignmentContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}


size_t qasm3Parser::QuantumMeasurementAssignmentContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumMeasurementAssignment;
}


antlrcpp::Any qasm3Parser::QuantumMeasurementAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumMeasurementAssignment(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumMeasurementAssignmentContext* qasm3Parser::quantumMeasurementAssignment() {
  QuantumMeasurementAssignmentContext *_localctx = _tracker.createInstance<QuantumMeasurementAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 94, qasm3Parser::RuleQuantumMeasurementAssignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(518);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__19: {
        enterOuterAlt(_localctx, 1);
        setState(509);
        quantumMeasurement();
        setState(512);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::ARROW) {
          setState(510);
          match(qasm3Parser::ARROW);
          setState(511);
          indexIdentifierList();
        }
        break;
      }

      case qasm3Parser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(514);
        indexIdentifierList();
        setState(515);
        match(qasm3Parser::EQUALS);
        setState(516);
        quantumMeasurement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumBarrierContext ------------------------------------------------------------------

qasm3Parser::QuantumBarrierContext::QuantumBarrierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::IndexIdentifierListContext* qasm3Parser::QuantumBarrierContext::indexIdentifierList() {
  return getRuleContext<qasm3Parser::IndexIdentifierListContext>(0);
}


size_t qasm3Parser::QuantumBarrierContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumBarrier;
}


antlrcpp::Any qasm3Parser::QuantumBarrierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumBarrier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumBarrierContext* qasm3Parser::quantumBarrier() {
  QuantumBarrierContext *_localctx = _tracker.createInstance<QuantumBarrierContext>(_ctx, getState());
  enterRule(_localctx, 96, qasm3Parser::RuleQuantumBarrier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(520);
    match(qasm3Parser::T__20);
    setState(521);
    indexIdentifierList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumGateModifierContext ------------------------------------------------------------------

qasm3Parser::QuantumGateModifierContext::QuantumGateModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::QuantumGateModifierContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::QuantumGateModifierContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::QuantumGateModifierContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}


size_t qasm3Parser::QuantumGateModifierContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumGateModifier;
}


antlrcpp::Any qasm3Parser::QuantumGateModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumGateModifier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumGateModifierContext* qasm3Parser::quantumGateModifier() {
  QuantumGateModifierContext *_localctx = _tracker.createInstance<QuantumGateModifierContext>(_ctx, getState());
  enterRule(_localctx, 98, qasm3Parser::RuleQuantumGateModifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(530);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__21: {
        setState(523);
        match(qasm3Parser::T__21);
        break;
      }

      case qasm3Parser::T__22: {
        setState(524);
        match(qasm3Parser::T__22);
        setState(525);
        match(qasm3Parser::LPAREN);
        setState(526);
        expression(0);
        setState(527);
        match(qasm3Parser::RPAREN);
        break;
      }

      case qasm3Parser::T__23: {
        setState(529);
        match(qasm3Parser::T__23);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(532);
    match(qasm3Parser::T__24);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumGateCallContext ------------------------------------------------------------------

qasm3Parser::QuantumGateCallContext::QuantumGateCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QuantumGateNameContext* qasm3Parser::QuantumGateCallContext::quantumGateName() {
  return getRuleContext<qasm3Parser::QuantumGateNameContext>(0);
}

qasm3Parser::IndexIdentifierListContext* qasm3Parser::QuantumGateCallContext::indexIdentifierList() {
  return getRuleContext<qasm3Parser::IndexIdentifierListContext>(0);
}

tree::TerminalNode* qasm3Parser::QuantumGateCallContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::QuantumGateCallContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::QuantumGateCallContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}


size_t qasm3Parser::QuantumGateCallContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumGateCall;
}


antlrcpp::Any qasm3Parser::QuantumGateCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumGateCall(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumGateCallContext* qasm3Parser::quantumGateCall() {
  QuantumGateCallContext *_localctx = _tracker.createInstance<QuantumGateCallContext>(_ctx, getState());
  enterRule(_localctx, 100, qasm3Parser::RuleQuantumGateCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(534);
    quantumGateName();
    setState(540);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(535);
      match(qasm3Parser::LPAREN);
      setState(537);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasm3Parser::T__4)
        | (1ULL << qasm3Parser::T__5)
        | (1ULL << qasm3Parser::T__6)
        | (1ULL << qasm3Parser::T__7)
        | (1ULL << qasm3Parser::T__8)
        | (1ULL << qasm3Parser::T__9)
        | (1ULL << qasm3Parser::T__10)
        | (1ULL << qasm3Parser::T__11)
        | (1ULL << qasm3Parser::T__26)
        | (1ULL << qasm3Parser::T__27)
        | (1ULL << qasm3Parser::T__42)
        | (1ULL << qasm3Parser::T__43)
        | (1ULL << qasm3Parser::T__44)
        | (1ULL << qasm3Parser::T__45)
        | (1ULL << qasm3Parser::T__46)
        | (1ULL << qasm3Parser::T__47)
        | (1ULL << qasm3Parser::T__48)
        | (1ULL << qasm3Parser::T__49)
        | (1ULL << qasm3Parser::T__50)
        | (1ULL << qasm3Parser::T__51))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 75)) & ((1ULL << (qasm3Parser::T__74 - 75))
        | (1ULL << (qasm3Parser::T__75 - 75))
        | (1ULL << (qasm3Parser::T__78 - 75))
        | (1ULL << (qasm3Parser::LPAREN - 75))
        | (1ULL << (qasm3Parser::MINUS - 75))
        | (1ULL << (qasm3Parser::Constant - 75))
        | (1ULL << (qasm3Parser::Integer - 75))
        | (1ULL << (qasm3Parser::Identifier - 75))
        | (1ULL << (qasm3Parser::RealNumber - 75))
        | (1ULL << (qasm3Parser::TimingLiteral - 75))
        | (1ULL << (qasm3Parser::StringLiteral - 75)))) != 0)) {
        setState(536);
        expressionList();
      }
      setState(539);
      match(qasm3Parser::RPAREN);
    }
    setState(542);
    indexIdentifierList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumGateNameContext ------------------------------------------------------------------

qasm3Parser::QuantumGateNameContext::QuantumGateNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::QuantumGateNameContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::QuantumGateModifierContext* qasm3Parser::QuantumGateNameContext::quantumGateModifier() {
  return getRuleContext<qasm3Parser::QuantumGateModifierContext>(0);
}

qasm3Parser::QuantumGateNameContext* qasm3Parser::QuantumGateNameContext::quantumGateName() {
  return getRuleContext<qasm3Parser::QuantumGateNameContext>(0);
}


size_t qasm3Parser::QuantumGateNameContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumGateName;
}


antlrcpp::Any qasm3Parser::QuantumGateNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumGateName(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumGateNameContext* qasm3Parser::quantumGateName() {
  QuantumGateNameContext *_localctx = _tracker.createInstance<QuantumGateNameContext>(_ctx, getState());
  enterRule(_localctx, 102, qasm3Parser::RuleQuantumGateName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(551);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__16: {
        enterOuterAlt(_localctx, 1);
        setState(544);
        match(qasm3Parser::T__16);
        break;
      }

      case qasm3Parser::T__17: {
        enterOuterAlt(_localctx, 2);
        setState(545);
        match(qasm3Parser::T__17);
        break;
      }

      case qasm3Parser::T__25: {
        enterOuterAlt(_localctx, 3);
        setState(546);
        match(qasm3Parser::T__25);
        break;
      }

      case qasm3Parser::Identifier: {
        enterOuterAlt(_localctx, 4);
        setState(547);
        match(qasm3Parser::Identifier);
        break;
      }

      case qasm3Parser::T__21:
      case qasm3Parser::T__22:
      case qasm3Parser::T__23: {
        enterOuterAlt(_localctx, 5);
        setState(548);
        quantumGateModifier();
        setState(549);
        quantumGateName();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOperatorContext ------------------------------------------------------------------

qasm3Parser::UnaryOperatorContext::UnaryOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::UnaryOperatorContext::getRuleIndex() const {
  return qasm3Parser::RuleUnaryOperator;
}


antlrcpp::Any qasm3Parser::UnaryOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitUnaryOperator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::UnaryOperatorContext* qasm3Parser::unaryOperator() {
  UnaryOperatorContext *_localctx = _tracker.createInstance<UnaryOperatorContext>(_ctx, getState());
  enterRule(_localctx, 104, qasm3Parser::RuleUnaryOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(553);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__26

    || _la == qasm3Parser::T__27)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationalOperatorContext ------------------------------------------------------------------

qasm3Parser::RelationalOperatorContext::RelationalOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::RelationalOperatorContext::getRuleIndex() const {
  return qasm3Parser::RuleRelationalOperator;
}


antlrcpp::Any qasm3Parser::RelationalOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitRelationalOperator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::RelationalOperatorContext* qasm3Parser::relationalOperator() {
  RelationalOperatorContext *_localctx = _tracker.createInstance<RelationalOperatorContext>(_ctx, getState());
  enterRule(_localctx, 106, qasm3Parser::RuleRelationalOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(555);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__28)
      | (1ULL << qasm3Parser::T__29)
      | (1ULL << qasm3Parser::T__30)
      | (1ULL << qasm3Parser::T__31)
      | (1ULL << qasm3Parser::T__32)
      | (1ULL << qasm3Parser::T__33))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalOperatorContext ------------------------------------------------------------------

qasm3Parser::LogicalOperatorContext::LogicalOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::LogicalOperatorContext::getRuleIndex() const {
  return qasm3Parser::RuleLogicalOperator;
}


antlrcpp::Any qasm3Parser::LogicalOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitLogicalOperator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::LogicalOperatorContext* qasm3Parser::logicalOperator() {
  LogicalOperatorContext *_localctx = _tracker.createInstance<LogicalOperatorContext>(_ctx, getState());
  enterRule(_localctx, 108, qasm3Parser::RuleLogicalOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(557);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__14

    || _la == qasm3Parser::T__34)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

qasm3Parser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ExpressionContext* qasm3Parser::ExpressionStatementContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::ExpressionStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::ExpressionStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleExpressionStatement;
}


antlrcpp::Any qasm3Parser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExpressionStatementContext* qasm3Parser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 110, qasm3Parser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(559);
    expression(0);
    setState(560);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

qasm3Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ExpressionTerminatorContext* qasm3Parser::ExpressionContext::expressionTerminator() {
  return getRuleContext<qasm3Parser::ExpressionTerminatorContext>(0);
}

qasm3Parser::UnaryExpressionContext* qasm3Parser::ExpressionContext::unaryExpression() {
  return getRuleContext<qasm3Parser::UnaryExpressionContext>(0);
}

qasm3Parser::XOrExpressionContext* qasm3Parser::ExpressionContext::xOrExpression() {
  return getRuleContext<qasm3Parser::XOrExpressionContext>(0);
}

qasm3Parser::ExpressionContext* qasm3Parser::ExpressionContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}


size_t qasm3Parser::ExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleExpression;
}


antlrcpp::Any qasm3Parser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::ExpressionContext* qasm3Parser::expression() {
   return expression(0);
}

qasm3Parser::ExpressionContext* qasm3Parser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  qasm3Parser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 112;
  enterRecursionRule(_localctx, 112, qasm3Parser::RuleExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(566);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      setState(563);
      expressionTerminator(0);
      break;
    }

    case 2: {
      setState(564);
      unaryExpression();
      break;
    }

    case 3: {
      setState(565);
      xOrExpression(0);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(573);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(568);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(569);
        match(qasm3Parser::T__35);
        setState(570);
        xOrExpression(0); 
      }
      setState(575);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- XOrExpressionContext ------------------------------------------------------------------

qasm3Parser::XOrExpressionContext::XOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::BitAndExpressionContext* qasm3Parser::XOrExpressionContext::bitAndExpression() {
  return getRuleContext<qasm3Parser::BitAndExpressionContext>(0);
}

qasm3Parser::XOrExpressionContext* qasm3Parser::XOrExpressionContext::xOrExpression() {
  return getRuleContext<qasm3Parser::XOrExpressionContext>(0);
}


size_t qasm3Parser::XOrExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleXOrExpression;
}


antlrcpp::Any qasm3Parser::XOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitXOrExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::XOrExpressionContext* qasm3Parser::xOrExpression() {
   return xOrExpression(0);
}

qasm3Parser::XOrExpressionContext* qasm3Parser::xOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::XOrExpressionContext *_localctx = _tracker.createInstance<XOrExpressionContext>(_ctx, parentState);
  qasm3Parser::XOrExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 114;
  enterRecursionRule(_localctx, 114, qasm3Parser::RuleXOrExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(577);
    bitAndExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(584);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<XOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleXOrExpression);
        setState(579);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(580);
        match(qasm3Parser::T__36);
        setState(581);
        bitAndExpression(0); 
      }
      setState(586);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BitAndExpressionContext ------------------------------------------------------------------

qasm3Parser::BitAndExpressionContext::BitAndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::BitShiftExpressionContext* qasm3Parser::BitAndExpressionContext::bitShiftExpression() {
  return getRuleContext<qasm3Parser::BitShiftExpressionContext>(0);
}

qasm3Parser::BitAndExpressionContext* qasm3Parser::BitAndExpressionContext::bitAndExpression() {
  return getRuleContext<qasm3Parser::BitAndExpressionContext>(0);
}


size_t qasm3Parser::BitAndExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleBitAndExpression;
}


antlrcpp::Any qasm3Parser::BitAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitBitAndExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::BitAndExpressionContext* qasm3Parser::bitAndExpression() {
   return bitAndExpression(0);
}

qasm3Parser::BitAndExpressionContext* qasm3Parser::bitAndExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::BitAndExpressionContext *_localctx = _tracker.createInstance<BitAndExpressionContext>(_ctx, parentState);
  qasm3Parser::BitAndExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 116;
  enterRecursionRule(_localctx, 116, qasm3Parser::RuleBitAndExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(588);
    bitShiftExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(595);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BitAndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBitAndExpression);
        setState(590);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(591);
        match(qasm3Parser::T__37);
        setState(592);
        bitShiftExpression(0); 
      }
      setState(597);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BitShiftExpressionContext ------------------------------------------------------------------

qasm3Parser::BitShiftExpressionContext::BitShiftExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::AdditiveExpressionContext* qasm3Parser::BitShiftExpressionContext::additiveExpression() {
  return getRuleContext<qasm3Parser::AdditiveExpressionContext>(0);
}

qasm3Parser::BitShiftExpressionContext* qasm3Parser::BitShiftExpressionContext::bitShiftExpression() {
  return getRuleContext<qasm3Parser::BitShiftExpressionContext>(0);
}


size_t qasm3Parser::BitShiftExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleBitShiftExpression;
}


antlrcpp::Any qasm3Parser::BitShiftExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitBitShiftExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::BitShiftExpressionContext* qasm3Parser::bitShiftExpression() {
   return bitShiftExpression(0);
}

qasm3Parser::BitShiftExpressionContext* qasm3Parser::bitShiftExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::BitShiftExpressionContext *_localctx = _tracker.createInstance<BitShiftExpressionContext>(_ctx, parentState);
  qasm3Parser::BitShiftExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 118;
  enterRecursionRule(_localctx, 118, qasm3Parser::RuleBitShiftExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(599);
    additiveExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(606);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BitShiftExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBitShiftExpression);
        setState(601);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(602);
        _la = _input->LA(1);
        if (!(_la == qasm3Parser::T__38

        || _la == qasm3Parser::T__39)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(603);
        additiveExpression(0); 
      }
      setState(608);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AdditiveExpressionContext ------------------------------------------------------------------

qasm3Parser::AdditiveExpressionContext::AdditiveExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::MultiplicativeExpressionContext* qasm3Parser::AdditiveExpressionContext::multiplicativeExpression() {
  return getRuleContext<qasm3Parser::MultiplicativeExpressionContext>(0);
}

qasm3Parser::AdditiveExpressionContext* qasm3Parser::AdditiveExpressionContext::additiveExpression() {
  return getRuleContext<qasm3Parser::AdditiveExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::AdditiveExpressionContext::PLUS() {
  return getToken(qasm3Parser::PLUS, 0);
}

tree::TerminalNode* qasm3Parser::AdditiveExpressionContext::MINUS() {
  return getToken(qasm3Parser::MINUS, 0);
}


size_t qasm3Parser::AdditiveExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleAdditiveExpression;
}


antlrcpp::Any qasm3Parser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::AdditiveExpressionContext* qasm3Parser::additiveExpression() {
   return additiveExpression(0);
}

qasm3Parser::AdditiveExpressionContext* qasm3Parser::additiveExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::AdditiveExpressionContext *_localctx = _tracker.createInstance<AdditiveExpressionContext>(_ctx, parentState);
  qasm3Parser::AdditiveExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 120;
  enterRecursionRule(_localctx, 120, qasm3Parser::RuleAdditiveExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(610);
    multiplicativeExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(617);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
        setState(612);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(613);
        _la = _input->LA(1);
        if (!(_la == qasm3Parser::PLUS

        || _la == qasm3Parser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(614);
        multiplicativeExpression(0); 
      }
      setState(619);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

qasm3Parser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ExpressionTerminatorContext* qasm3Parser::MultiplicativeExpressionContext::expressionTerminator() {
  return getRuleContext<qasm3Parser::ExpressionTerminatorContext>(0);
}

qasm3Parser::UnaryExpressionContext* qasm3Parser::MultiplicativeExpressionContext::unaryExpression() {
  return getRuleContext<qasm3Parser::UnaryExpressionContext>(0);
}

qasm3Parser::MultiplicativeExpressionContext* qasm3Parser::MultiplicativeExpressionContext::multiplicativeExpression() {
  return getRuleContext<qasm3Parser::MultiplicativeExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::MultiplicativeExpressionContext::MUL() {
  return getToken(qasm3Parser::MUL, 0);
}

tree::TerminalNode* qasm3Parser::MultiplicativeExpressionContext::DIV() {
  return getToken(qasm3Parser::DIV, 0);
}

tree::TerminalNode* qasm3Parser::MultiplicativeExpressionContext::MOD() {
  return getToken(qasm3Parser::MOD, 0);
}


size_t qasm3Parser::MultiplicativeExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleMultiplicativeExpression;
}


antlrcpp::Any qasm3Parser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::MultiplicativeExpressionContext* qasm3Parser::multiplicativeExpression() {
   return multiplicativeExpression(0);
}

qasm3Parser::MultiplicativeExpressionContext* qasm3Parser::multiplicativeExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::MultiplicativeExpressionContext *_localctx = _tracker.createInstance<MultiplicativeExpressionContext>(_ctx, parentState);
  qasm3Parser::MultiplicativeExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 122;
  enterRecursionRule(_localctx, 122, qasm3Parser::RuleMultiplicativeExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(623);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__4:
      case qasm3Parser::T__5:
      case qasm3Parser::T__6:
      case qasm3Parser::T__7:
      case qasm3Parser::T__8:
      case qasm3Parser::T__9:
      case qasm3Parser::T__10:
      case qasm3Parser::T__11:
      case qasm3Parser::T__42:
      case qasm3Parser::T__43:
      case qasm3Parser::T__44:
      case qasm3Parser::T__45:
      case qasm3Parser::T__46:
      case qasm3Parser::T__47:
      case qasm3Parser::T__48:
      case qasm3Parser::T__49:
      case qasm3Parser::T__50:
      case qasm3Parser::T__51:
      case qasm3Parser::T__74:
      case qasm3Parser::T__75:
      case qasm3Parser::T__78:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::Constant:
      case qasm3Parser::Integer:
      case qasm3Parser::Identifier:
      case qasm3Parser::RealNumber:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::StringLiteral: {
        setState(621);
        expressionTerminator(0);
        break;
      }

      case qasm3Parser::T__26:
      case qasm3Parser::T__27: {
        setState(622);
        unaryExpression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(633);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
        setState(625);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(626);
        _la = _input->LA(1);
        if (!(((((_la - 99) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 99)) & ((1ULL << (qasm3Parser::MUL - 99))
          | (1ULL << (qasm3Parser::DIV - 99))
          | (1ULL << (qasm3Parser::MOD - 99)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(629);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case qasm3Parser::T__4:
          case qasm3Parser::T__5:
          case qasm3Parser::T__6:
          case qasm3Parser::T__7:
          case qasm3Parser::T__8:
          case qasm3Parser::T__9:
          case qasm3Parser::T__10:
          case qasm3Parser::T__11:
          case qasm3Parser::T__42:
          case qasm3Parser::T__43:
          case qasm3Parser::T__44:
          case qasm3Parser::T__45:
          case qasm3Parser::T__46:
          case qasm3Parser::T__47:
          case qasm3Parser::T__48:
          case qasm3Parser::T__49:
          case qasm3Parser::T__50:
          case qasm3Parser::T__51:
          case qasm3Parser::T__74:
          case qasm3Parser::T__75:
          case qasm3Parser::T__78:
          case qasm3Parser::LPAREN:
          case qasm3Parser::MINUS:
          case qasm3Parser::Constant:
          case qasm3Parser::Integer:
          case qasm3Parser::Identifier:
          case qasm3Parser::RealNumber:
          case qasm3Parser::TimingLiteral:
          case qasm3Parser::StringLiteral: {
            setState(627);
            expressionTerminator(0);
            break;
          }

          case qasm3Parser::T__26:
          case qasm3Parser::T__27: {
            setState(628);
            unaryExpression();
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(635);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryExpressionContext ------------------------------------------------------------------

qasm3Parser::UnaryExpressionContext::UnaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::UnaryOperatorContext* qasm3Parser::UnaryExpressionContext::unaryOperator() {
  return getRuleContext<qasm3Parser::UnaryOperatorContext>(0);
}

qasm3Parser::ExpressionTerminatorContext* qasm3Parser::UnaryExpressionContext::expressionTerminator() {
  return getRuleContext<qasm3Parser::ExpressionTerminatorContext>(0);
}


size_t qasm3Parser::UnaryExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleUnaryExpression;
}


antlrcpp::Any qasm3Parser::UnaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitUnaryExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::UnaryExpressionContext* qasm3Parser::unaryExpression() {
  UnaryExpressionContext *_localctx = _tracker.createInstance<UnaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 124, qasm3Parser::RuleUnaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(636);
    unaryOperator();
    setState(637);
    expressionTerminator(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionTerminatorContext ------------------------------------------------------------------

qasm3Parser::ExpressionTerminatorContext::ExpressionTerminatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::Constant() {
  return getToken(qasm3Parser::Constant, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::Integer() {
  return getToken(qasm3Parser::Integer, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::RealNumber() {
  return getToken(qasm3Parser::RealNumber, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::StringLiteral() {
  return getToken(qasm3Parser::StringLiteral, 0);
}

qasm3Parser::BuiltInCallContext* qasm3Parser::ExpressionTerminatorContext::builtInCall() {
  return getRuleContext<qasm3Parser::BuiltInCallContext>(0);
}

qasm3Parser::KernelCallContext* qasm3Parser::ExpressionTerminatorContext::kernelCall() {
  return getRuleContext<qasm3Parser::KernelCallContext>(0);
}

qasm3Parser::SubroutineCallContext* qasm3Parser::ExpressionTerminatorContext::subroutineCall() {
  return getRuleContext<qasm3Parser::SubroutineCallContext>(0);
}

qasm3Parser::TimingTerminatorContext* qasm3Parser::ExpressionTerminatorContext::timingTerminator() {
  return getRuleContext<qasm3Parser::TimingTerminatorContext>(0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::MINUS() {
  return getToken(qasm3Parser::MINUS, 0);
}

qasm3Parser::ExpressionTerminatorContext* qasm3Parser::ExpressionTerminatorContext::expressionTerminator() {
  return getRuleContext<qasm3Parser::ExpressionTerminatorContext>(0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::ExpressionTerminatorContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}

qasm3Parser::IncrementorContext* qasm3Parser::ExpressionTerminatorContext::incrementor() {
  return getRuleContext<qasm3Parser::IncrementorContext>(0);
}


size_t qasm3Parser::ExpressionTerminatorContext::getRuleIndex() const {
  return qasm3Parser::RuleExpressionTerminator;
}


antlrcpp::Any qasm3Parser::ExpressionTerminatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitExpressionTerminator(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::ExpressionTerminatorContext* qasm3Parser::expressionTerminator() {
   return expressionTerminator(0);
}

qasm3Parser::ExpressionTerminatorContext* qasm3Parser::expressionTerminator(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::ExpressionTerminatorContext *_localctx = _tracker.createInstance<ExpressionTerminatorContext>(_ctx, parentState);
  qasm3Parser::ExpressionTerminatorContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 126;
  enterRecursionRule(_localctx, 126, qasm3Parser::RuleExpressionTerminator, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(655);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      setState(640);
      match(qasm3Parser::Constant);
      break;
    }

    case 2: {
      setState(641);
      match(qasm3Parser::Integer);
      break;
    }

    case 3: {
      setState(642);
      match(qasm3Parser::RealNumber);
      break;
    }

    case 4: {
      setState(643);
      match(qasm3Parser::Identifier);
      break;
    }

    case 5: {
      setState(644);
      match(qasm3Parser::StringLiteral);
      break;
    }

    case 6: {
      setState(645);
      builtInCall();
      break;
    }

    case 7: {
      setState(646);
      kernelCall();
      break;
    }

    case 8: {
      setState(647);
      subroutineCall();
      break;
    }

    case 9: {
      setState(648);
      timingTerminator();
      break;
    }

    case 10: {
      setState(649);
      match(qasm3Parser::MINUS);
      setState(650);
      expressionTerminator(4);
      break;
    }

    case 11: {
      setState(651);
      match(qasm3Parser::LPAREN);
      setState(652);
      expression(0);
      setState(653);
      match(qasm3Parser::RPAREN);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(666);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(664);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionTerminatorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpressionTerminator);
          setState(657);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(658);
          match(qasm3Parser::LBRACKET);
          setState(659);
          expression(0);
          setState(660);
          match(qasm3Parser::RBRACKET);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionTerminatorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpressionTerminator);
          setState(662);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(663);
          incrementor();
          break;
        }

        default:
          break;
        } 
      }
      setState(668);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IncrementorContext ------------------------------------------------------------------

qasm3Parser::IncrementorContext::IncrementorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::IncrementorContext::getRuleIndex() const {
  return qasm3Parser::RuleIncrementor;
}


antlrcpp::Any qasm3Parser::IncrementorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitIncrementor(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IncrementorContext* qasm3Parser::incrementor() {
  IncrementorContext *_localctx = _tracker.createInstance<IncrementorContext>(_ctx, getState());
  enterRule(_localctx, 128, qasm3Parser::RuleIncrementor);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(669);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__40

    || _la == qasm3Parser::T__41)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BuiltInCallContext ------------------------------------------------------------------

qasm3Parser::BuiltInCallContext::BuiltInCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::BuiltInCallContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::BuiltInCallContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

tree::TerminalNode* qasm3Parser::BuiltInCallContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::BuiltInMathContext* qasm3Parser::BuiltInCallContext::builtInMath() {
  return getRuleContext<qasm3Parser::BuiltInMathContext>(0);
}

qasm3Parser::CastOperatorContext* qasm3Parser::BuiltInCallContext::castOperator() {
  return getRuleContext<qasm3Parser::CastOperatorContext>(0);
}


size_t qasm3Parser::BuiltInCallContext::getRuleIndex() const {
  return qasm3Parser::RuleBuiltInCall;
}


antlrcpp::Any qasm3Parser::BuiltInCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitBuiltInCall(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BuiltInCallContext* qasm3Parser::builtInCall() {
  BuiltInCallContext *_localctx = _tracker.createInstance<BuiltInCallContext>(_ctx, getState());
  enterRule(_localctx, 130, qasm3Parser::RuleBuiltInCall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(673);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__42:
      case qasm3Parser::T__43:
      case qasm3Parser::T__44:
      case qasm3Parser::T__45:
      case qasm3Parser::T__46:
      case qasm3Parser::T__47:
      case qasm3Parser::T__48:
      case qasm3Parser::T__49:
      case qasm3Parser::T__50:
      case qasm3Parser::T__51: {
        setState(671);
        builtInMath();
        break;
      }

      case qasm3Parser::T__4:
      case qasm3Parser::T__5:
      case qasm3Parser::T__6:
      case qasm3Parser::T__7:
      case qasm3Parser::T__8:
      case qasm3Parser::T__9:
      case qasm3Parser::T__10:
      case qasm3Parser::T__11:
      case qasm3Parser::T__74:
      case qasm3Parser::T__75: {
        setState(672);
        castOperator();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(675);
    match(qasm3Parser::LPAREN);
    setState(676);
    expressionList();
    setState(677);
    match(qasm3Parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BuiltInMathContext ------------------------------------------------------------------

qasm3Parser::BuiltInMathContext::BuiltInMathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::BuiltInMathContext::getRuleIndex() const {
  return qasm3Parser::RuleBuiltInMath;
}


antlrcpp::Any qasm3Parser::BuiltInMathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitBuiltInMath(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BuiltInMathContext* qasm3Parser::builtInMath() {
  BuiltInMathContext *_localctx = _tracker.createInstance<BuiltInMathContext>(_ctx, getState());
  enterRule(_localctx, 132, qasm3Parser::RuleBuiltInMath);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(679);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__42)
      | (1ULL << qasm3Parser::T__43)
      | (1ULL << qasm3Parser::T__44)
      | (1ULL << qasm3Parser::T__45)
      | (1ULL << qasm3Parser::T__46)
      | (1ULL << qasm3Parser::T__47)
      | (1ULL << qasm3Parser::T__48)
      | (1ULL << qasm3Parser::T__49)
      | (1ULL << qasm3Parser::T__50)
      | (1ULL << qasm3Parser::T__51))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CastOperatorContext ------------------------------------------------------------------

qasm3Parser::CastOperatorContext::CastOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ClassicalTypeContext* qasm3Parser::CastOperatorContext::classicalType() {
  return getRuleContext<qasm3Parser::ClassicalTypeContext>(0);
}


size_t qasm3Parser::CastOperatorContext::getRuleIndex() const {
  return qasm3Parser::RuleCastOperator;
}


antlrcpp::Any qasm3Parser::CastOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitCastOperator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CastOperatorContext* qasm3Parser::castOperator() {
  CastOperatorContext *_localctx = _tracker.createInstance<CastOperatorContext>(_ctx, getState());
  enterRule(_localctx, 134, qasm3Parser::RuleCastOperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(681);
    classicalType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionListContext ------------------------------------------------------------------

qasm3Parser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::ExpressionListContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::ExpressionListContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::ExpressionListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::ExpressionListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::ExpressionListContext::getRuleIndex() const {
  return qasm3Parser::RuleExpressionList;
}


antlrcpp::Any qasm3Parser::ExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitExpressionList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExpressionListContext* qasm3Parser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 136, qasm3Parser::RuleExpressionList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(688);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(683);
        expression(0);
        setState(684);
        match(qasm3Parser::COMMA); 
      }
      setState(690);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
    }
    setState(691);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanExpressionContext ------------------------------------------------------------------

qasm3Parser::BooleanExpressionContext::BooleanExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::MembershipTestContext* qasm3Parser::BooleanExpressionContext::membershipTest() {
  return getRuleContext<qasm3Parser::MembershipTestContext>(0);
}

qasm3Parser::ComparsionExpressionContext* qasm3Parser::BooleanExpressionContext::comparsionExpression() {
  return getRuleContext<qasm3Parser::ComparsionExpressionContext>(0);
}

qasm3Parser::BooleanExpressionContext* qasm3Parser::BooleanExpressionContext::booleanExpression() {
  return getRuleContext<qasm3Parser::BooleanExpressionContext>(0);
}

qasm3Parser::LogicalOperatorContext* qasm3Parser::BooleanExpressionContext::logicalOperator() {
  return getRuleContext<qasm3Parser::LogicalOperatorContext>(0);
}


size_t qasm3Parser::BooleanExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleBooleanExpression;
}


antlrcpp::Any qasm3Parser::BooleanExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitBooleanExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::BooleanExpressionContext* qasm3Parser::booleanExpression() {
   return booleanExpression(0);
}

qasm3Parser::BooleanExpressionContext* qasm3Parser::booleanExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::BooleanExpressionContext *_localctx = _tracker.createInstance<BooleanExpressionContext>(_ctx, parentState);
  qasm3Parser::BooleanExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 138;
  enterRecursionRule(_localctx, 138, qasm3Parser::RuleBooleanExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(696);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
    case 1: {
      setState(694);
      membershipTest();
      break;
    }

    case 2: {
      setState(695);
      comparsionExpression();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(704);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BooleanExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBooleanExpression);
        setState(698);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(699);
        logicalOperator();
        setState(700);
        comparsionExpression(); 
      }
      setState(706);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ComparsionExpressionContext ------------------------------------------------------------------

qasm3Parser::ComparsionExpressionContext::ComparsionExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::ComparsionExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::ComparsionExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

qasm3Parser::RelationalOperatorContext* qasm3Parser::ComparsionExpressionContext::relationalOperator() {
  return getRuleContext<qasm3Parser::RelationalOperatorContext>(0);
}


size_t qasm3Parser::ComparsionExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleComparsionExpression;
}


antlrcpp::Any qasm3Parser::ComparsionExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitComparsionExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ComparsionExpressionContext* qasm3Parser::comparsionExpression() {
  ComparsionExpressionContext *_localctx = _tracker.createInstance<ComparsionExpressionContext>(_ctx, getState());
  enterRule(_localctx, 140, qasm3Parser::RuleComparsionExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(712);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(707);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(708);
      expression(0);
      setState(709);
      relationalOperator();
      setState(710);
      expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqualsExpressionContext ------------------------------------------------------------------

qasm3Parser::EqualsExpressionContext::EqualsExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::EqualsExpressionContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::EqualsExpressionContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}


size_t qasm3Parser::EqualsExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleEqualsExpression;
}


antlrcpp::Any qasm3Parser::EqualsExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitEqualsExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::EqualsExpressionContext* qasm3Parser::equalsExpression() {
  EqualsExpressionContext *_localctx = _tracker.createInstance<EqualsExpressionContext>(_ctx, getState());
  enterRule(_localctx, 142, qasm3Parser::RuleEqualsExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(714);
    match(qasm3Parser::EQUALS);
    setState(715);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

qasm3Parser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::AssignmentOperatorContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}


size_t qasm3Parser::AssignmentOperatorContext::getRuleIndex() const {
  return qasm3Parser::RuleAssignmentOperator;
}


antlrcpp::Any qasm3Parser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AssignmentOperatorContext* qasm3Parser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 144, qasm3Parser::RuleAssignmentOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(717);
    _la = _input->LA(1);
    if (!(((((_la - 53) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 53)) & ((1ULL << (qasm3Parser::T__52 - 53))
      | (1ULL << (qasm3Parser::T__53 - 53))
      | (1ULL << (qasm3Parser::T__54 - 53))
      | (1ULL << (qasm3Parser::T__55 - 53))
      | (1ULL << (qasm3Parser::T__56 - 53))
      | (1ULL << (qasm3Parser::T__57 - 53))
      | (1ULL << (qasm3Parser::T__58 - 53))
      | (1ULL << (qasm3Parser::T__59 - 53))
      | (1ULL << (qasm3Parser::T__60 - 53))
      | (1ULL << (qasm3Parser::T__61 - 53))
      | (1ULL << (qasm3Parser::EQUALS - 53)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqualsAssignmentListContext ------------------------------------------------------------------

qasm3Parser::EqualsAssignmentListContext::EqualsAssignmentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> qasm3Parser::EqualsAssignmentListContext::Identifier() {
  return getTokens(qasm3Parser::Identifier);
}

tree::TerminalNode* qasm3Parser::EqualsAssignmentListContext::Identifier(size_t i) {
  return getToken(qasm3Parser::Identifier, i);
}

std::vector<qasm3Parser::EqualsExpressionContext *> qasm3Parser::EqualsAssignmentListContext::equalsExpression() {
  return getRuleContexts<qasm3Parser::EqualsExpressionContext>();
}

qasm3Parser::EqualsExpressionContext* qasm3Parser::EqualsAssignmentListContext::equalsExpression(size_t i) {
  return getRuleContext<qasm3Parser::EqualsExpressionContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::EqualsAssignmentListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::EqualsAssignmentListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::EqualsAssignmentListContext::getRuleIndex() const {
  return qasm3Parser::RuleEqualsAssignmentList;
}


antlrcpp::Any qasm3Parser::EqualsAssignmentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitEqualsAssignmentList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::EqualsAssignmentListContext* qasm3Parser::equalsAssignmentList() {
  EqualsAssignmentListContext *_localctx = _tracker.createInstance<EqualsAssignmentListContext>(_ctx, getState());
  enterRule(_localctx, 146, qasm3Parser::RuleEqualsAssignmentList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(725);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(719);
        match(qasm3Parser::Identifier);
        setState(720);
        equalsExpression();
        setState(721);
        match(qasm3Parser::COMMA); 
      }
      setState(727);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    }
    setState(728);
    match(qasm3Parser::Identifier);
    setState(729);
    equalsExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MembershipTestContext ------------------------------------------------------------------

qasm3Parser::MembershipTestContext::MembershipTestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::MembershipTestContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::SetDeclarationContext* qasm3Parser::MembershipTestContext::setDeclaration() {
  return getRuleContext<qasm3Parser::SetDeclarationContext>(0);
}


size_t qasm3Parser::MembershipTestContext::getRuleIndex() const {
  return qasm3Parser::RuleMembershipTest;
}


antlrcpp::Any qasm3Parser::MembershipTestContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitMembershipTest(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::MembershipTestContext* qasm3Parser::membershipTest() {
  MembershipTestContext *_localctx = _tracker.createInstance<MembershipTestContext>(_ctx, getState());
  enterRule(_localctx, 148, qasm3Parser::RuleMembershipTest);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(731);
    match(qasm3Parser::Identifier);
    setState(732);
    match(qasm3Parser::T__62);
    setState(733);
    setDeclaration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetDeclarationContext ------------------------------------------------------------------

qasm3Parser::SetDeclarationContext::SetDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::SetDeclarationContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::SetDeclarationContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

tree::TerminalNode* qasm3Parser::SetDeclarationContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

qasm3Parser::RangeDefinitionContext* qasm3Parser::SetDeclarationContext::rangeDefinition() {
  return getRuleContext<qasm3Parser::RangeDefinitionContext>(0);
}

tree::TerminalNode* qasm3Parser::SetDeclarationContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}


size_t qasm3Parser::SetDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleSetDeclaration;
}


antlrcpp::Any qasm3Parser::SetDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitSetDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SetDeclarationContext* qasm3Parser::setDeclaration() {
  SetDeclarationContext *_localctx = _tracker.createInstance<SetDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 150, qasm3Parser::RuleSetDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(741);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::LBRACE: {
        enterOuterAlt(_localctx, 1);
        setState(735);
        match(qasm3Parser::LBRACE);
        setState(736);
        expressionList();
        setState(737);
        match(qasm3Parser::RBRACE);
        break;
      }

      case qasm3Parser::LBRACKET: {
        enterOuterAlt(_localctx, 2);
        setState(739);
        rangeDefinition();
        break;
      }

      case qasm3Parser::Identifier: {
        enterOuterAlt(_localctx, 3);
        setState(740);
        match(qasm3Parser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramBlockContext ------------------------------------------------------------------

qasm3Parser::ProgramBlockContext::ProgramBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::StatementContext *> qasm3Parser::ProgramBlockContext::statement() {
  return getRuleContexts<qasm3Parser::StatementContext>();
}

qasm3Parser::StatementContext* qasm3Parser::ProgramBlockContext::statement(size_t i) {
  return getRuleContext<qasm3Parser::StatementContext>(i);
}

tree::TerminalNode* qasm3Parser::ProgramBlockContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::ProgramBlockContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}


size_t qasm3Parser::ProgramBlockContext::getRuleIndex() const {
  return qasm3Parser::RuleProgramBlock;
}


antlrcpp::Any qasm3Parser::ProgramBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitProgramBlock(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ProgramBlockContext* qasm3Parser::programBlock() {
  ProgramBlockContext *_localctx = _tracker.createInstance<ProgramBlockContext>(_ctx, getState());
  enterRule(_localctx, 152, qasm3Parser::RuleProgramBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(752);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__4:
      case qasm3Parser::T__5:
      case qasm3Parser::T__6:
      case qasm3Parser::T__7:
      case qasm3Parser::T__8:
      case qasm3Parser::T__9:
      case qasm3Parser::T__10:
      case qasm3Parser::T__11:
      case qasm3Parser::T__12:
      case qasm3Parser::T__13:
      case qasm3Parser::T__16:
      case qasm3Parser::T__17:
      case qasm3Parser::T__18:
      case qasm3Parser::T__19:
      case qasm3Parser::T__20:
      case qasm3Parser::T__21:
      case qasm3Parser::T__22:
      case qasm3Parser::T__23:
      case qasm3Parser::T__25:
      case qasm3Parser::T__26:
      case qasm3Parser::T__27:
      case qasm3Parser::T__42:
      case qasm3Parser::T__43:
      case qasm3Parser::T__44:
      case qasm3Parser::T__45:
      case qasm3Parser::T__46:
      case qasm3Parser::T__47:
      case qasm3Parser::T__48:
      case qasm3Parser::T__49:
      case qasm3Parser::T__50:
      case qasm3Parser::T__51:
      case qasm3Parser::T__63:
      case qasm3Parser::T__65:
      case qasm3Parser::T__66:
      case qasm3Parser::T__67:
      case qasm3Parser::T__68:
      case qasm3Parser::T__69:
      case qasm3Parser::T__74:
      case qasm3Parser::T__75:
      case qasm3Parser::T__76:
      case qasm3Parser::T__77:
      case qasm3Parser::T__78:
      case qasm3Parser::T__79:
      case qasm3Parser::T__80:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::Constant:
      case qasm3Parser::Integer:
      case qasm3Parser::Identifier:
      case qasm3Parser::RealNumber:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::StringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(743);
        statement();
        break;
      }

      case qasm3Parser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(744);
        match(qasm3Parser::LBRACE);
        setState(748);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << qasm3Parser::T__4)
          | (1ULL << qasm3Parser::T__5)
          | (1ULL << qasm3Parser::T__6)
          | (1ULL << qasm3Parser::T__7)
          | (1ULL << qasm3Parser::T__8)
          | (1ULL << qasm3Parser::T__9)
          | (1ULL << qasm3Parser::T__10)
          | (1ULL << qasm3Parser::T__11)
          | (1ULL << qasm3Parser::T__12)
          | (1ULL << qasm3Parser::T__13)
          | (1ULL << qasm3Parser::T__16)
          | (1ULL << qasm3Parser::T__17)
          | (1ULL << qasm3Parser::T__18)
          | (1ULL << qasm3Parser::T__19)
          | (1ULL << qasm3Parser::T__20)
          | (1ULL << qasm3Parser::T__21)
          | (1ULL << qasm3Parser::T__22)
          | (1ULL << qasm3Parser::T__23)
          | (1ULL << qasm3Parser::T__25)
          | (1ULL << qasm3Parser::T__26)
          | (1ULL << qasm3Parser::T__27)
          | (1ULL << qasm3Parser::T__42)
          | (1ULL << qasm3Parser::T__43)
          | (1ULL << qasm3Parser::T__44)
          | (1ULL << qasm3Parser::T__45)
          | (1ULL << qasm3Parser::T__46)
          | (1ULL << qasm3Parser::T__47)
          | (1ULL << qasm3Parser::T__48)
          | (1ULL << qasm3Parser::T__49)
          | (1ULL << qasm3Parser::T__50)
          | (1ULL << qasm3Parser::T__51))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (qasm3Parser::T__63 - 64))
          | (1ULL << (qasm3Parser::T__65 - 64))
          | (1ULL << (qasm3Parser::T__66 - 64))
          | (1ULL << (qasm3Parser::T__67 - 64))
          | (1ULL << (qasm3Parser::T__68 - 64))
          | (1ULL << (qasm3Parser::T__69 - 64))
          | (1ULL << (qasm3Parser::T__74 - 64))
          | (1ULL << (qasm3Parser::T__75 - 64))
          | (1ULL << (qasm3Parser::T__76 - 64))
          | (1ULL << (qasm3Parser::T__77 - 64))
          | (1ULL << (qasm3Parser::T__78 - 64))
          | (1ULL << (qasm3Parser::T__79 - 64))
          | (1ULL << (qasm3Parser::T__80 - 64))
          | (1ULL << (qasm3Parser::LPAREN - 64))
          | (1ULL << (qasm3Parser::MINUS - 64))
          | (1ULL << (qasm3Parser::Constant - 64))
          | (1ULL << (qasm3Parser::Integer - 64))
          | (1ULL << (qasm3Parser::Identifier - 64))
          | (1ULL << (qasm3Parser::RealNumber - 64))
          | (1ULL << (qasm3Parser::TimingLiteral - 64))
          | (1ULL << (qasm3Parser::StringLiteral - 64)))) != 0)) {
          setState(745);
          statement();
          setState(750);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(751);
        match(qasm3Parser::RBRACE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BranchingStatementContext ------------------------------------------------------------------

qasm3Parser::BranchingStatementContext::BranchingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::BranchingStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::BooleanExpressionContext* qasm3Parser::BranchingStatementContext::booleanExpression() {
  return getRuleContext<qasm3Parser::BooleanExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::BranchingStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

std::vector<qasm3Parser::ProgramBlockContext *> qasm3Parser::BranchingStatementContext::programBlock() {
  return getRuleContexts<qasm3Parser::ProgramBlockContext>();
}

qasm3Parser::ProgramBlockContext* qasm3Parser::BranchingStatementContext::programBlock(size_t i) {
  return getRuleContext<qasm3Parser::ProgramBlockContext>(i);
}


size_t qasm3Parser::BranchingStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleBranchingStatement;
}


antlrcpp::Any qasm3Parser::BranchingStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitBranchingStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BranchingStatementContext* qasm3Parser::branchingStatement() {
  BranchingStatementContext *_localctx = _tracker.createInstance<BranchingStatementContext>(_ctx, getState());
  enterRule(_localctx, 154, qasm3Parser::RuleBranchingStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(754);
    match(qasm3Parser::T__63);
    setState(755);
    match(qasm3Parser::LPAREN);
    setState(756);
    booleanExpression(0);
    setState(757);
    match(qasm3Parser::RPAREN);
    setState(758);
    programBlock();
    setState(761);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
    case 1: {
      setState(759);
      match(qasm3Parser::T__64);
      setState(760);
      programBlock();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopSignatureContext ------------------------------------------------------------------

qasm3Parser::LoopSignatureContext::LoopSignatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::MembershipTestContext* qasm3Parser::LoopSignatureContext::membershipTest() {
  return getRuleContext<qasm3Parser::MembershipTestContext>(0);
}

tree::TerminalNode* qasm3Parser::LoopSignatureContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::BooleanExpressionContext* qasm3Parser::LoopSignatureContext::booleanExpression() {
  return getRuleContext<qasm3Parser::BooleanExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::LoopSignatureContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}


size_t qasm3Parser::LoopSignatureContext::getRuleIndex() const {
  return qasm3Parser::RuleLoopSignature;
}


antlrcpp::Any qasm3Parser::LoopSignatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitLoopSignature(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::LoopSignatureContext* qasm3Parser::loopSignature() {
  LoopSignatureContext *_localctx = _tracker.createInstance<LoopSignatureContext>(_ctx, getState());
  enterRule(_localctx, 156, qasm3Parser::RuleLoopSignature);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(770);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__65: {
        enterOuterAlt(_localctx, 1);
        setState(763);
        match(qasm3Parser::T__65);
        setState(764);
        membershipTest();
        break;
      }

      case qasm3Parser::T__66: {
        enterOuterAlt(_localctx, 2);
        setState(765);
        match(qasm3Parser::T__66);
        setState(766);
        match(qasm3Parser::LPAREN);
        setState(767);
        booleanExpression(0);
        setState(768);
        match(qasm3Parser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopStatementContext ------------------------------------------------------------------

qasm3Parser::LoopStatementContext::LoopStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::LoopSignatureContext* qasm3Parser::LoopStatementContext::loopSignature() {
  return getRuleContext<qasm3Parser::LoopSignatureContext>(0);
}

qasm3Parser::ProgramBlockContext* qasm3Parser::LoopStatementContext::programBlock() {
  return getRuleContext<qasm3Parser::ProgramBlockContext>(0);
}


size_t qasm3Parser::LoopStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleLoopStatement;
}


antlrcpp::Any qasm3Parser::LoopStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitLoopStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::LoopStatementContext* qasm3Parser::loopStatement() {
  LoopStatementContext *_localctx = _tracker.createInstance<LoopStatementContext>(_ctx, getState());
  enterRule(_localctx, 158, qasm3Parser::RuleLoopStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(772);
    loopSignature();
    setState(773);
    programBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ControlDirectiveStatementContext ------------------------------------------------------------------

qasm3Parser::ControlDirectiveStatementContext::ControlDirectiveStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ControlDirectiveContext* qasm3Parser::ControlDirectiveStatementContext::controlDirective() {
  return getRuleContext<qasm3Parser::ControlDirectiveContext>(0);
}

tree::TerminalNode* qasm3Parser::ControlDirectiveStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::ControlDirectiveStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleControlDirectiveStatement;
}


antlrcpp::Any qasm3Parser::ControlDirectiveStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitControlDirectiveStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ControlDirectiveStatementContext* qasm3Parser::controlDirectiveStatement() {
  ControlDirectiveStatementContext *_localctx = _tracker.createInstance<ControlDirectiveStatementContext>(_ctx, getState());
  enterRule(_localctx, 160, qasm3Parser::RuleControlDirectiveStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(775);
    controlDirective();
    setState(776);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ControlDirectiveContext ------------------------------------------------------------------

qasm3Parser::ControlDirectiveContext::ControlDirectiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::ControlDirectiveContext::getRuleIndex() const {
  return qasm3Parser::RuleControlDirective;
}


antlrcpp::Any qasm3Parser::ControlDirectiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitControlDirective(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ControlDirectiveContext* qasm3Parser::controlDirective() {
  ControlDirectiveContext *_localctx = _tracker.createInstance<ControlDirectiveContext>(_ctx, getState());
  enterRule(_localctx, 162, qasm3Parser::RuleControlDirective);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(778);
    _la = _input->LA(1);
    if (!(((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (qasm3Parser::T__67 - 68))
      | (1ULL << (qasm3Parser::T__68 - 68))
      | (1ULL << (qasm3Parser::T__69 - 68)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KernelDeclarationContext ------------------------------------------------------------------

qasm3Parser::KernelDeclarationContext::KernelDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::KernelDeclarationContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::KernelDeclarationContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

tree::TerminalNode* qasm3Parser::KernelDeclarationContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::KernelDeclarationContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ReturnSignatureContext* qasm3Parser::KernelDeclarationContext::returnSignature() {
  return getRuleContext<qasm3Parser::ReturnSignatureContext>(0);
}

qasm3Parser::ClassicalTypeContext* qasm3Parser::KernelDeclarationContext::classicalType() {
  return getRuleContext<qasm3Parser::ClassicalTypeContext>(0);
}

qasm3Parser::ClassicalTypeListContext* qasm3Parser::KernelDeclarationContext::classicalTypeList() {
  return getRuleContext<qasm3Parser::ClassicalTypeListContext>(0);
}


size_t qasm3Parser::KernelDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleKernelDeclaration;
}


antlrcpp::Any qasm3Parser::KernelDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitKernelDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::KernelDeclarationContext* qasm3Parser::kernelDeclaration() {
  KernelDeclarationContext *_localctx = _tracker.createInstance<KernelDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 164, qasm3Parser::RuleKernelDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(780);
    match(qasm3Parser::T__70);
    setState(781);
    match(qasm3Parser::Identifier);
    setState(787);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(782);
      match(qasm3Parser::LPAREN);
      setState(784);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasm3Parser::T__4)
        | (1ULL << qasm3Parser::T__5)
        | (1ULL << qasm3Parser::T__6)
        | (1ULL << qasm3Parser::T__7)
        | (1ULL << qasm3Parser::T__8)
        | (1ULL << qasm3Parser::T__9)
        | (1ULL << qasm3Parser::T__10)
        | (1ULL << qasm3Parser::T__11))) != 0) || _la == qasm3Parser::T__74

      || _la == qasm3Parser::T__75) {
        setState(783);
        classicalTypeList();
      }
      setState(786);
      match(qasm3Parser::RPAREN);
    }
    setState(790);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(789);
      returnSignature();
    }
    setState(793);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__4)
      | (1ULL << qasm3Parser::T__5)
      | (1ULL << qasm3Parser::T__6)
      | (1ULL << qasm3Parser::T__7)
      | (1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9)
      | (1ULL << qasm3Parser::T__10)
      | (1ULL << qasm3Parser::T__11))) != 0) || _la == qasm3Parser::T__74

    || _la == qasm3Parser::T__75) {
      setState(792);
      classicalType();
    }
    setState(795);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KernelCallContext ------------------------------------------------------------------

qasm3Parser::KernelCallContext::KernelCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::KernelCallContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::KernelCallContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::KernelCallContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::KernelCallContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}


size_t qasm3Parser::KernelCallContext::getRuleIndex() const {
  return qasm3Parser::RuleKernelCall;
}


antlrcpp::Any qasm3Parser::KernelCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitKernelCall(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::KernelCallContext* qasm3Parser::kernelCall() {
  KernelCallContext *_localctx = _tracker.createInstance<KernelCallContext>(_ctx, getState());
  enterRule(_localctx, 166, qasm3Parser::RuleKernelCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(797);
    match(qasm3Parser::Identifier);
    setState(798);
    match(qasm3Parser::LPAREN);
    setState(800);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__4)
      | (1ULL << qasm3Parser::T__5)
      | (1ULL << qasm3Parser::T__6)
      | (1ULL << qasm3Parser::T__7)
      | (1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9)
      | (1ULL << qasm3Parser::T__10)
      | (1ULL << qasm3Parser::T__11)
      | (1ULL << qasm3Parser::T__26)
      | (1ULL << qasm3Parser::T__27)
      | (1ULL << qasm3Parser::T__42)
      | (1ULL << qasm3Parser::T__43)
      | (1ULL << qasm3Parser::T__44)
      | (1ULL << qasm3Parser::T__45)
      | (1ULL << qasm3Parser::T__46)
      | (1ULL << qasm3Parser::T__47)
      | (1ULL << qasm3Parser::T__48)
      | (1ULL << qasm3Parser::T__49)
      | (1ULL << qasm3Parser::T__50)
      | (1ULL << qasm3Parser::T__51))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 75)) & ((1ULL << (qasm3Parser::T__74 - 75))
      | (1ULL << (qasm3Parser::T__75 - 75))
      | (1ULL << (qasm3Parser::T__78 - 75))
      | (1ULL << (qasm3Parser::LPAREN - 75))
      | (1ULL << (qasm3Parser::MINUS - 75))
      | (1ULL << (qasm3Parser::Constant - 75))
      | (1ULL << (qasm3Parser::Integer - 75))
      | (1ULL << (qasm3Parser::Identifier - 75))
      | (1ULL << (qasm3Parser::RealNumber - 75))
      | (1ULL << (qasm3Parser::TimingLiteral - 75))
      | (1ULL << (qasm3Parser::StringLiteral - 75)))) != 0)) {
      setState(799);
      expressionList();
    }
    setState(802);
    match(qasm3Parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubroutineDefinitionContext ------------------------------------------------------------------

qasm3Parser::SubroutineDefinitionContext::SubroutineDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::SubroutineDefinitionContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::SubroutineBlockContext* qasm3Parser::SubroutineDefinitionContext::subroutineBlock() {
  return getRuleContext<qasm3Parser::SubroutineBlockContext>(0);
}

tree::TerminalNode* qasm3Parser::SubroutineDefinitionContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::SubroutineDefinitionContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::QuantumArgumentListContext* qasm3Parser::SubroutineDefinitionContext::quantumArgumentList() {
  return getRuleContext<qasm3Parser::QuantumArgumentListContext>(0);
}

qasm3Parser::ReturnSignatureContext* qasm3Parser::SubroutineDefinitionContext::returnSignature() {
  return getRuleContext<qasm3Parser::ReturnSignatureContext>(0);
}

qasm3Parser::ClassicalArgumentListContext* qasm3Parser::SubroutineDefinitionContext::classicalArgumentList() {
  return getRuleContext<qasm3Parser::ClassicalArgumentListContext>(0);
}


size_t qasm3Parser::SubroutineDefinitionContext::getRuleIndex() const {
  return qasm3Parser::RuleSubroutineDefinition;
}


antlrcpp::Any qasm3Parser::SubroutineDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitSubroutineDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SubroutineDefinitionContext* qasm3Parser::subroutineDefinition() {
  SubroutineDefinitionContext *_localctx = _tracker.createInstance<SubroutineDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 168, qasm3Parser::RuleSubroutineDefinition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(804);
    match(qasm3Parser::T__71);
    setState(805);
    match(qasm3Parser::Identifier);
    setState(811);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(806);
      match(qasm3Parser::LPAREN);
      setState(808);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasm3Parser::T__4)
        | (1ULL << qasm3Parser::T__5)
        | (1ULL << qasm3Parser::T__6)
        | (1ULL << qasm3Parser::T__7)
        | (1ULL << qasm3Parser::T__8)
        | (1ULL << qasm3Parser::T__9)
        | (1ULL << qasm3Parser::T__10)
        | (1ULL << qasm3Parser::T__11))) != 0) || _la == qasm3Parser::T__74

      || _la == qasm3Parser::T__75) {
        setState(807);
        classicalArgumentList();
      }
      setState(810);
      match(qasm3Parser::RPAREN);
    }
    setState(814);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::T__2

    || _la == qasm3Parser::T__3) {
      setState(813);
      quantumArgumentList();
    }
    setState(817);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(816);
      returnSignature();
    }
    setState(819);
    subroutineBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

qasm3Parser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::StatementContext* qasm3Parser::ReturnStatementContext::statement() {
  return getRuleContext<qasm3Parser::StatementContext>(0);
}


size_t qasm3Parser::ReturnStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleReturnStatement;
}


antlrcpp::Any qasm3Parser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ReturnStatementContext* qasm3Parser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 170, qasm3Parser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(821);
    match(qasm3Parser::T__72);
    setState(822);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubroutineBlockContext ------------------------------------------------------------------

qasm3Parser::SubroutineBlockContext::SubroutineBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::SubroutineBlockContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::SubroutineBlockContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

std::vector<qasm3Parser::StatementContext *> qasm3Parser::SubroutineBlockContext::statement() {
  return getRuleContexts<qasm3Parser::StatementContext>();
}

qasm3Parser::StatementContext* qasm3Parser::SubroutineBlockContext::statement(size_t i) {
  return getRuleContext<qasm3Parser::StatementContext>(i);
}

qasm3Parser::ReturnStatementContext* qasm3Parser::SubroutineBlockContext::returnStatement() {
  return getRuleContext<qasm3Parser::ReturnStatementContext>(0);
}


size_t qasm3Parser::SubroutineBlockContext::getRuleIndex() const {
  return qasm3Parser::RuleSubroutineBlock;
}


antlrcpp::Any qasm3Parser::SubroutineBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitSubroutineBlock(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SubroutineBlockContext* qasm3Parser::subroutineBlock() {
  SubroutineBlockContext *_localctx = _tracker.createInstance<SubroutineBlockContext>(_ctx, getState());
  enterRule(_localctx, 172, qasm3Parser::RuleSubroutineBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(824);
    match(qasm3Parser::LBRACE);
    setState(828);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__4)
      | (1ULL << qasm3Parser::T__5)
      | (1ULL << qasm3Parser::T__6)
      | (1ULL << qasm3Parser::T__7)
      | (1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9)
      | (1ULL << qasm3Parser::T__10)
      | (1ULL << qasm3Parser::T__11)
      | (1ULL << qasm3Parser::T__12)
      | (1ULL << qasm3Parser::T__13)
      | (1ULL << qasm3Parser::T__16)
      | (1ULL << qasm3Parser::T__17)
      | (1ULL << qasm3Parser::T__18)
      | (1ULL << qasm3Parser::T__19)
      | (1ULL << qasm3Parser::T__20)
      | (1ULL << qasm3Parser::T__21)
      | (1ULL << qasm3Parser::T__22)
      | (1ULL << qasm3Parser::T__23)
      | (1ULL << qasm3Parser::T__25)
      | (1ULL << qasm3Parser::T__26)
      | (1ULL << qasm3Parser::T__27)
      | (1ULL << qasm3Parser::T__42)
      | (1ULL << qasm3Parser::T__43)
      | (1ULL << qasm3Parser::T__44)
      | (1ULL << qasm3Parser::T__45)
      | (1ULL << qasm3Parser::T__46)
      | (1ULL << qasm3Parser::T__47)
      | (1ULL << qasm3Parser::T__48)
      | (1ULL << qasm3Parser::T__49)
      | (1ULL << qasm3Parser::T__50)
      | (1ULL << qasm3Parser::T__51))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (qasm3Parser::T__63 - 64))
      | (1ULL << (qasm3Parser::T__65 - 64))
      | (1ULL << (qasm3Parser::T__66 - 64))
      | (1ULL << (qasm3Parser::T__67 - 64))
      | (1ULL << (qasm3Parser::T__68 - 64))
      | (1ULL << (qasm3Parser::T__69 - 64))
      | (1ULL << (qasm3Parser::T__74 - 64))
      | (1ULL << (qasm3Parser::T__75 - 64))
      | (1ULL << (qasm3Parser::T__76 - 64))
      | (1ULL << (qasm3Parser::T__77 - 64))
      | (1ULL << (qasm3Parser::T__78 - 64))
      | (1ULL << (qasm3Parser::T__79 - 64))
      | (1ULL << (qasm3Parser::T__80 - 64))
      | (1ULL << (qasm3Parser::LPAREN - 64))
      | (1ULL << (qasm3Parser::MINUS - 64))
      | (1ULL << (qasm3Parser::Constant - 64))
      | (1ULL << (qasm3Parser::Integer - 64))
      | (1ULL << (qasm3Parser::Identifier - 64))
      | (1ULL << (qasm3Parser::RealNumber - 64))
      | (1ULL << (qasm3Parser::TimingLiteral - 64))
      | (1ULL << (qasm3Parser::StringLiteral - 64)))) != 0)) {
      setState(825);
      statement();
      setState(830);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(832);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::T__72) {
      setState(831);
      returnStatement();
    }
    setState(834);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubroutineCallContext ------------------------------------------------------------------

qasm3Parser::SubroutineCallContext::SubroutineCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::SubroutineCallContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

std::vector<qasm3Parser::ExpressionListContext *> qasm3Parser::SubroutineCallContext::expressionList() {
  return getRuleContexts<qasm3Parser::ExpressionListContext>();
}

qasm3Parser::ExpressionListContext* qasm3Parser::SubroutineCallContext::expressionList(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionListContext>(i);
}

tree::TerminalNode* qasm3Parser::SubroutineCallContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::SubroutineCallContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}


size_t qasm3Parser::SubroutineCallContext::getRuleIndex() const {
  return qasm3Parser::RuleSubroutineCall;
}


antlrcpp::Any qasm3Parser::SubroutineCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitSubroutineCall(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SubroutineCallContext* qasm3Parser::subroutineCall() {
  SubroutineCallContext *_localctx = _tracker.createInstance<SubroutineCallContext>(_ctx, getState());
  enterRule(_localctx, 174, qasm3Parser::RuleSubroutineCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(836);
    match(qasm3Parser::Identifier);
    setState(842);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx)) {
    case 1: {
      setState(837);
      match(qasm3Parser::LPAREN);
      setState(839);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasm3Parser::T__4)
        | (1ULL << qasm3Parser::T__5)
        | (1ULL << qasm3Parser::T__6)
        | (1ULL << qasm3Parser::T__7)
        | (1ULL << qasm3Parser::T__8)
        | (1ULL << qasm3Parser::T__9)
        | (1ULL << qasm3Parser::T__10)
        | (1ULL << qasm3Parser::T__11)
        | (1ULL << qasm3Parser::T__26)
        | (1ULL << qasm3Parser::T__27)
        | (1ULL << qasm3Parser::T__42)
        | (1ULL << qasm3Parser::T__43)
        | (1ULL << qasm3Parser::T__44)
        | (1ULL << qasm3Parser::T__45)
        | (1ULL << qasm3Parser::T__46)
        | (1ULL << qasm3Parser::T__47)
        | (1ULL << qasm3Parser::T__48)
        | (1ULL << qasm3Parser::T__49)
        | (1ULL << qasm3Parser::T__50)
        | (1ULL << qasm3Parser::T__51))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 75)) & ((1ULL << (qasm3Parser::T__74 - 75))
        | (1ULL << (qasm3Parser::T__75 - 75))
        | (1ULL << (qasm3Parser::T__78 - 75))
        | (1ULL << (qasm3Parser::LPAREN - 75))
        | (1ULL << (qasm3Parser::MINUS - 75))
        | (1ULL << (qasm3Parser::Constant - 75))
        | (1ULL << (qasm3Parser::Integer - 75))
        | (1ULL << (qasm3Parser::Identifier - 75))
        | (1ULL << (qasm3Parser::RealNumber - 75))
        | (1ULL << (qasm3Parser::TimingLiteral - 75))
        | (1ULL << (qasm3Parser::StringLiteral - 75)))) != 0)) {
        setState(838);
        expressionList();
      }
      setState(841);
      match(qasm3Parser::RPAREN);
      break;
    }

    default:
      break;
    }
    setState(844);
    expressionList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PragmaContext ------------------------------------------------------------------

qasm3Parser::PragmaContext::PragmaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::PragmaContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::PragmaContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

std::vector<qasm3Parser::StatementContext *> qasm3Parser::PragmaContext::statement() {
  return getRuleContexts<qasm3Parser::StatementContext>();
}

qasm3Parser::StatementContext* qasm3Parser::PragmaContext::statement(size_t i) {
  return getRuleContext<qasm3Parser::StatementContext>(i);
}


size_t qasm3Parser::PragmaContext::getRuleIndex() const {
  return qasm3Parser::RulePragma;
}


antlrcpp::Any qasm3Parser::PragmaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitPragma(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::PragmaContext* qasm3Parser::pragma() {
  PragmaContext *_localctx = _tracker.createInstance<PragmaContext>(_ctx, getState());
  enterRule(_localctx, 176, qasm3Parser::RulePragma);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(846);
    match(qasm3Parser::T__73);
    setState(847);
    match(qasm3Parser::LBRACE);
    setState(851);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__4)
      | (1ULL << qasm3Parser::T__5)
      | (1ULL << qasm3Parser::T__6)
      | (1ULL << qasm3Parser::T__7)
      | (1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9)
      | (1ULL << qasm3Parser::T__10)
      | (1ULL << qasm3Parser::T__11)
      | (1ULL << qasm3Parser::T__12)
      | (1ULL << qasm3Parser::T__13)
      | (1ULL << qasm3Parser::T__16)
      | (1ULL << qasm3Parser::T__17)
      | (1ULL << qasm3Parser::T__18)
      | (1ULL << qasm3Parser::T__19)
      | (1ULL << qasm3Parser::T__20)
      | (1ULL << qasm3Parser::T__21)
      | (1ULL << qasm3Parser::T__22)
      | (1ULL << qasm3Parser::T__23)
      | (1ULL << qasm3Parser::T__25)
      | (1ULL << qasm3Parser::T__26)
      | (1ULL << qasm3Parser::T__27)
      | (1ULL << qasm3Parser::T__42)
      | (1ULL << qasm3Parser::T__43)
      | (1ULL << qasm3Parser::T__44)
      | (1ULL << qasm3Parser::T__45)
      | (1ULL << qasm3Parser::T__46)
      | (1ULL << qasm3Parser::T__47)
      | (1ULL << qasm3Parser::T__48)
      | (1ULL << qasm3Parser::T__49)
      | (1ULL << qasm3Parser::T__50)
      | (1ULL << qasm3Parser::T__51))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (qasm3Parser::T__63 - 64))
      | (1ULL << (qasm3Parser::T__65 - 64))
      | (1ULL << (qasm3Parser::T__66 - 64))
      | (1ULL << (qasm3Parser::T__67 - 64))
      | (1ULL << (qasm3Parser::T__68 - 64))
      | (1ULL << (qasm3Parser::T__69 - 64))
      | (1ULL << (qasm3Parser::T__74 - 64))
      | (1ULL << (qasm3Parser::T__75 - 64))
      | (1ULL << (qasm3Parser::T__76 - 64))
      | (1ULL << (qasm3Parser::T__77 - 64))
      | (1ULL << (qasm3Parser::T__78 - 64))
      | (1ULL << (qasm3Parser::T__79 - 64))
      | (1ULL << (qasm3Parser::T__80 - 64))
      | (1ULL << (qasm3Parser::LPAREN - 64))
      | (1ULL << (qasm3Parser::MINUS - 64))
      | (1ULL << (qasm3Parser::Constant - 64))
      | (1ULL << (qasm3Parser::Integer - 64))
      | (1ULL << (qasm3Parser::Identifier - 64))
      | (1ULL << (qasm3Parser::RealNumber - 64))
      | (1ULL << (qasm3Parser::TimingLiteral - 64))
      | (1ULL << (qasm3Parser::StringLiteral - 64)))) != 0)) {
      setState(848);
      statement();
      setState(853);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(854);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimingTypeContext ------------------------------------------------------------------

qasm3Parser::TimingTypeContext::TimingTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::TimingTypeContext::Integer() {
  return getToken(qasm3Parser::Integer, 0);
}


size_t qasm3Parser::TimingTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleTimingType;
}


antlrcpp::Any qasm3Parser::TimingTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitTimingType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingTypeContext* qasm3Parser::timingType() {
  TimingTypeContext *_localctx = _tracker.createInstance<TimingTypeContext>(_ctx, getState());
  enterRule(_localctx, 178, qasm3Parser::RuleTimingType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(861);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__74: {
        enterOuterAlt(_localctx, 1);
        setState(856);
        match(qasm3Parser::T__74);
        break;
      }

      case qasm3Parser::T__75: {
        enterOuterAlt(_localctx, 2);
        setState(857);
        match(qasm3Parser::T__75);
        setState(859);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::Integer) {
          setState(858);
          match(qasm3Parser::Integer);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimingBoxContext ------------------------------------------------------------------

qasm3Parser::TimingBoxContext::TimingBoxContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::TimingBoxContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::QuantumBlockContext* qasm3Parser::TimingBoxContext::quantumBlock() {
  return getRuleContext<qasm3Parser::QuantumBlockContext>(0);
}

tree::TerminalNode* qasm3Parser::TimingBoxContext::TimingLiteral() {
  return getToken(qasm3Parser::TimingLiteral, 0);
}


size_t qasm3Parser::TimingBoxContext::getRuleIndex() const {
  return qasm3Parser::RuleTimingBox;
}


antlrcpp::Any qasm3Parser::TimingBoxContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitTimingBox(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingBoxContext* qasm3Parser::timingBox() {
  TimingBoxContext *_localctx = _tracker.createInstance<TimingBoxContext>(_ctx, getState());
  enterRule(_localctx, 180, qasm3Parser::RuleTimingBox);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(869);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__76: {
        enterOuterAlt(_localctx, 1);
        setState(863);
        match(qasm3Parser::T__76);
        setState(864);
        match(qasm3Parser::Identifier);
        setState(865);
        quantumBlock();
        break;
      }

      case qasm3Parser::T__77: {
        enterOuterAlt(_localctx, 2);
        setState(866);
        match(qasm3Parser::T__77);
        setState(867);
        match(qasm3Parser::TimingLiteral);
        setState(868);
        quantumBlock();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimingTerminatorContext ------------------------------------------------------------------

qasm3Parser::TimingTerminatorContext::TimingTerminatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::TimingIdentifierContext* qasm3Parser::TimingTerminatorContext::timingIdentifier() {
  return getRuleContext<qasm3Parser::TimingIdentifierContext>(0);
}


size_t qasm3Parser::TimingTerminatorContext::getRuleIndex() const {
  return qasm3Parser::RuleTimingTerminator;
}


antlrcpp::Any qasm3Parser::TimingTerminatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitTimingTerminator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingTerminatorContext* qasm3Parser::timingTerminator() {
  TimingTerminatorContext *_localctx = _tracker.createInstance<TimingTerminatorContext>(_ctx, getState());
  enterRule(_localctx, 182, qasm3Parser::RuleTimingTerminator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(873);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__51:
      case qasm3Parser::TimingLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(871);
        timingIdentifier();
        break;
      }

      case qasm3Parser::T__78: {
        enterOuterAlt(_localctx, 2);
        setState(872);
        match(qasm3Parser::T__78);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimingIdentifierContext ------------------------------------------------------------------

qasm3Parser::TimingIdentifierContext::TimingIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::TimingIdentifierContext::TimingLiteral() {
  return getToken(qasm3Parser::TimingLiteral, 0);
}

tree::TerminalNode* qasm3Parser::TimingIdentifierContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::TimingIdentifierContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

tree::TerminalNode* qasm3Parser::TimingIdentifierContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::QuantumBlockContext* qasm3Parser::TimingIdentifierContext::quantumBlock() {
  return getRuleContext<qasm3Parser::QuantumBlockContext>(0);
}


size_t qasm3Parser::TimingIdentifierContext::getRuleIndex() const {
  return qasm3Parser::RuleTimingIdentifier;
}


antlrcpp::Any qasm3Parser::TimingIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitTimingIdentifier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingIdentifierContext* qasm3Parser::timingIdentifier() {
  TimingIdentifierContext *_localctx = _tracker.createInstance<TimingIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 184, qasm3Parser::RuleTimingIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(883);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::TimingLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(875);
        match(qasm3Parser::TimingLiteral);
        break;
      }

      case qasm3Parser::T__51: {
        enterOuterAlt(_localctx, 2);
        setState(876);
        match(qasm3Parser::T__51);
        setState(877);
        match(qasm3Parser::LPAREN);
        setState(880);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case qasm3Parser::Identifier: {
            setState(878);
            match(qasm3Parser::Identifier);
            break;
          }

          case qasm3Parser::LBRACE: {
            setState(879);
            quantumBlock();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(882);
        match(qasm3Parser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimingInstructionNameContext ------------------------------------------------------------------

qasm3Parser::TimingInstructionNameContext::TimingInstructionNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::TimingInstructionNameContext::getRuleIndex() const {
  return qasm3Parser::RuleTimingInstructionName;
}


antlrcpp::Any qasm3Parser::TimingInstructionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitTimingInstructionName(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingInstructionNameContext* qasm3Parser::timingInstructionName() {
  TimingInstructionNameContext *_localctx = _tracker.createInstance<TimingInstructionNameContext>(_ctx, getState());
  enterRule(_localctx, 186, qasm3Parser::RuleTimingInstructionName);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(885);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__79

    || _la == qasm3Parser::T__80)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimingInstructionContext ------------------------------------------------------------------

qasm3Parser::TimingInstructionContext::TimingInstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::TimingInstructionNameContext* qasm3Parser::TimingInstructionContext::timingInstructionName() {
  return getRuleContext<qasm3Parser::TimingInstructionNameContext>(0);
}

qasm3Parser::DesignatorContext* qasm3Parser::TimingInstructionContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

qasm3Parser::IndexIdentifierListContext* qasm3Parser::TimingInstructionContext::indexIdentifierList() {
  return getRuleContext<qasm3Parser::IndexIdentifierListContext>(0);
}

tree::TerminalNode* qasm3Parser::TimingInstructionContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::TimingInstructionContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::TimingInstructionContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}


size_t qasm3Parser::TimingInstructionContext::getRuleIndex() const {
  return qasm3Parser::RuleTimingInstruction;
}


antlrcpp::Any qasm3Parser::TimingInstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitTimingInstruction(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingInstructionContext* qasm3Parser::timingInstruction() {
  TimingInstructionContext *_localctx = _tracker.createInstance<TimingInstructionContext>(_ctx, getState());
  enterRule(_localctx, 188, qasm3Parser::RuleTimingInstruction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(887);
    timingInstructionName();
    setState(893);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(888);
      match(qasm3Parser::LPAREN);
      setState(890);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasm3Parser::T__4)
        | (1ULL << qasm3Parser::T__5)
        | (1ULL << qasm3Parser::T__6)
        | (1ULL << qasm3Parser::T__7)
        | (1ULL << qasm3Parser::T__8)
        | (1ULL << qasm3Parser::T__9)
        | (1ULL << qasm3Parser::T__10)
        | (1ULL << qasm3Parser::T__11)
        | (1ULL << qasm3Parser::T__26)
        | (1ULL << qasm3Parser::T__27)
        | (1ULL << qasm3Parser::T__42)
        | (1ULL << qasm3Parser::T__43)
        | (1ULL << qasm3Parser::T__44)
        | (1ULL << qasm3Parser::T__45)
        | (1ULL << qasm3Parser::T__46)
        | (1ULL << qasm3Parser::T__47)
        | (1ULL << qasm3Parser::T__48)
        | (1ULL << qasm3Parser::T__49)
        | (1ULL << qasm3Parser::T__50)
        | (1ULL << qasm3Parser::T__51))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 75)) & ((1ULL << (qasm3Parser::T__74 - 75))
        | (1ULL << (qasm3Parser::T__75 - 75))
        | (1ULL << (qasm3Parser::T__78 - 75))
        | (1ULL << (qasm3Parser::LPAREN - 75))
        | (1ULL << (qasm3Parser::MINUS - 75))
        | (1ULL << (qasm3Parser::Constant - 75))
        | (1ULL << (qasm3Parser::Integer - 75))
        | (1ULL << (qasm3Parser::Identifier - 75))
        | (1ULL << (qasm3Parser::RealNumber - 75))
        | (1ULL << (qasm3Parser::TimingLiteral - 75))
        | (1ULL << (qasm3Parser::StringLiteral - 75)))) != 0)) {
        setState(889);
        expressionList();
      }
      setState(892);
      match(qasm3Parser::RPAREN);
    }
    setState(895);
    designator();
    setState(896);
    indexIdentifierList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimingStatementContext ------------------------------------------------------------------

qasm3Parser::TimingStatementContext::TimingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::TimingInstructionContext* qasm3Parser::TimingStatementContext::timingInstruction() {
  return getRuleContext<qasm3Parser::TimingInstructionContext>(0);
}

tree::TerminalNode* qasm3Parser::TimingStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::TimingBoxContext* qasm3Parser::TimingStatementContext::timingBox() {
  return getRuleContext<qasm3Parser::TimingBoxContext>(0);
}


size_t qasm3Parser::TimingStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleTimingStatement;
}


antlrcpp::Any qasm3Parser::TimingStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitTimingStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingStatementContext* qasm3Parser::timingStatement() {
  TimingStatementContext *_localctx = _tracker.createInstance<TimingStatementContext>(_ctx, getState());
  enterRule(_localctx, 190, qasm3Parser::RuleTimingStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(902);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__79:
      case qasm3Parser::T__80: {
        enterOuterAlt(_localctx, 1);
        setState(898);
        timingInstruction();
        setState(899);
        match(qasm3Parser::SEMICOLON);
        break;
      }

      case qasm3Parser::T__76:
      case qasm3Parser::T__77: {
        enterOuterAlt(_localctx, 2);
        setState(901);
        timingBox();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalibrationContext ------------------------------------------------------------------

qasm3Parser::CalibrationContext::CalibrationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::CalibrationGrammarDeclarationContext* qasm3Parser::CalibrationContext::calibrationGrammarDeclaration() {
  return getRuleContext<qasm3Parser::CalibrationGrammarDeclarationContext>(0);
}

qasm3Parser::CalibrationDefinitionContext* qasm3Parser::CalibrationContext::calibrationDefinition() {
  return getRuleContext<qasm3Parser::CalibrationDefinitionContext>(0);
}


size_t qasm3Parser::CalibrationContext::getRuleIndex() const {
  return qasm3Parser::RuleCalibration;
}


antlrcpp::Any qasm3Parser::CalibrationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitCalibration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalibrationContext* qasm3Parser::calibration() {
  CalibrationContext *_localctx = _tracker.createInstance<CalibrationContext>(_ctx, getState());
  enterRule(_localctx, 192, qasm3Parser::RuleCalibration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(906);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__81: {
        enterOuterAlt(_localctx, 1);
        setState(904);
        calibrationGrammarDeclaration();
        break;
      }

      case qasm3Parser::T__82: {
        enterOuterAlt(_localctx, 2);
        setState(905);
        calibrationDefinition();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalibrationGrammarDeclarationContext ------------------------------------------------------------------

qasm3Parser::CalibrationGrammarDeclarationContext::CalibrationGrammarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::CalibrationGrammarContext* qasm3Parser::CalibrationGrammarDeclarationContext::calibrationGrammar() {
  return getRuleContext<qasm3Parser::CalibrationGrammarContext>(0);
}

tree::TerminalNode* qasm3Parser::CalibrationGrammarDeclarationContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::CalibrationGrammarDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleCalibrationGrammarDeclaration;
}


antlrcpp::Any qasm3Parser::CalibrationGrammarDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitCalibrationGrammarDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalibrationGrammarDeclarationContext* qasm3Parser::calibrationGrammarDeclaration() {
  CalibrationGrammarDeclarationContext *_localctx = _tracker.createInstance<CalibrationGrammarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 194, qasm3Parser::RuleCalibrationGrammarDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(908);
    match(qasm3Parser::T__81);
    setState(909);
    calibrationGrammar();
    setState(910);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalibrationDefinitionContext ------------------------------------------------------------------

qasm3Parser::CalibrationDefinitionContext::CalibrationDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::CalibrationDefinitionContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::IdentifierListContext* qasm3Parser::CalibrationDefinitionContext::identifierList() {
  return getRuleContext<qasm3Parser::IdentifierListContext>(0);
}

tree::TerminalNode* qasm3Parser::CalibrationDefinitionContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::CalibrationDefinitionContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

tree::TerminalNode* qasm3Parser::CalibrationDefinitionContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::CalibrationDefinitionContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ReturnSignatureContext* qasm3Parser::CalibrationDefinitionContext::returnSignature() {
  return getRuleContext<qasm3Parser::ReturnSignatureContext>(0);
}

qasm3Parser::CalibrationArgumentListContext* qasm3Parser::CalibrationDefinitionContext::calibrationArgumentList() {
  return getRuleContext<qasm3Parser::CalibrationArgumentListContext>(0);
}


size_t qasm3Parser::CalibrationDefinitionContext::getRuleIndex() const {
  return qasm3Parser::RuleCalibrationDefinition;
}


antlrcpp::Any qasm3Parser::CalibrationDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitCalibrationDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalibrationDefinitionContext* qasm3Parser::calibrationDefinition() {
  CalibrationDefinitionContext *_localctx = _tracker.createInstance<CalibrationDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 196, qasm3Parser::RuleCalibrationDefinition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(912);
    match(qasm3Parser::T__82);
    setState(913);
    match(qasm3Parser::Identifier);
    setState(919);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(914);
      match(qasm3Parser::LPAREN);
      setState(916);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasm3Parser::T__4)
        | (1ULL << qasm3Parser::T__5)
        | (1ULL << qasm3Parser::T__6)
        | (1ULL << qasm3Parser::T__7)
        | (1ULL << qasm3Parser::T__8)
        | (1ULL << qasm3Parser::T__9)
        | (1ULL << qasm3Parser::T__10)
        | (1ULL << qasm3Parser::T__11)
        | (1ULL << qasm3Parser::T__26)
        | (1ULL << qasm3Parser::T__27)
        | (1ULL << qasm3Parser::T__42)
        | (1ULL << qasm3Parser::T__43)
        | (1ULL << qasm3Parser::T__44)
        | (1ULL << qasm3Parser::T__45)
        | (1ULL << qasm3Parser::T__46)
        | (1ULL << qasm3Parser::T__47)
        | (1ULL << qasm3Parser::T__48)
        | (1ULL << qasm3Parser::T__49)
        | (1ULL << qasm3Parser::T__50)
        | (1ULL << qasm3Parser::T__51))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 75)) & ((1ULL << (qasm3Parser::T__74 - 75))
        | (1ULL << (qasm3Parser::T__75 - 75))
        | (1ULL << (qasm3Parser::T__78 - 75))
        | (1ULL << (qasm3Parser::LPAREN - 75))
        | (1ULL << (qasm3Parser::MINUS - 75))
        | (1ULL << (qasm3Parser::Constant - 75))
        | (1ULL << (qasm3Parser::Integer - 75))
        | (1ULL << (qasm3Parser::Identifier - 75))
        | (1ULL << (qasm3Parser::RealNumber - 75))
        | (1ULL << (qasm3Parser::TimingLiteral - 75))
        | (1ULL << (qasm3Parser::StringLiteral - 75)))) != 0)) {
        setState(915);
        calibrationArgumentList();
      }
      setState(918);
      match(qasm3Parser::RPAREN);
    }
    setState(921);
    identifierList();
    setState(923);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(922);
      returnSignature();
    }
    setState(925);
    match(qasm3Parser::LBRACE);
    setState(929);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(926);
        matchWildcard(); 
      }
      setState(931);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx);
    }
    setState(932);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalibrationGrammarContext ------------------------------------------------------------------

qasm3Parser::CalibrationGrammarContext::CalibrationGrammarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::CalibrationGrammarContext::StringLiteral() {
  return getToken(qasm3Parser::StringLiteral, 0);
}


size_t qasm3Parser::CalibrationGrammarContext::getRuleIndex() const {
  return qasm3Parser::RuleCalibrationGrammar;
}


antlrcpp::Any qasm3Parser::CalibrationGrammarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitCalibrationGrammar(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalibrationGrammarContext* qasm3Parser::calibrationGrammar() {
  CalibrationGrammarContext *_localctx = _tracker.createInstance<CalibrationGrammarContext>(_ctx, getState());
  enterRule(_localctx, 198, qasm3Parser::RuleCalibrationGrammar);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(934);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__83

    || _la == qasm3Parser::StringLiteral)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalibrationArgumentListContext ------------------------------------------------------------------

qasm3Parser::CalibrationArgumentListContext::CalibrationArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ClassicalArgumentListContext* qasm3Parser::CalibrationArgumentListContext::classicalArgumentList() {
  return getRuleContext<qasm3Parser::ClassicalArgumentListContext>(0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::CalibrationArgumentListContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}


size_t qasm3Parser::CalibrationArgumentListContext::getRuleIndex() const {
  return qasm3Parser::RuleCalibrationArgumentList;
}


antlrcpp::Any qasm3Parser::CalibrationArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitCalibrationArgumentList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalibrationArgumentListContext* qasm3Parser::calibrationArgumentList() {
  CalibrationArgumentListContext *_localctx = _tracker.createInstance<CalibrationArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 200, qasm3Parser::RuleCalibrationArgumentList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(938);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(936);
      classicalArgumentList();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(937);
      expressionList();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool qasm3Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 34: return indexIdentifierSempred(dynamic_cast<IndexIdentifierContext *>(context), predicateIndex);
    case 56: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 57: return xOrExpressionSempred(dynamic_cast<XOrExpressionContext *>(context), predicateIndex);
    case 58: return bitAndExpressionSempred(dynamic_cast<BitAndExpressionContext *>(context), predicateIndex);
    case 59: return bitShiftExpressionSempred(dynamic_cast<BitShiftExpressionContext *>(context), predicateIndex);
    case 60: return additiveExpressionSempred(dynamic_cast<AdditiveExpressionContext *>(context), predicateIndex);
    case 61: return multiplicativeExpressionSempred(dynamic_cast<MultiplicativeExpressionContext *>(context), predicateIndex);
    case 63: return expressionTerminatorSempred(dynamic_cast<ExpressionTerminatorContext *>(context), predicateIndex);
    case 69: return booleanExpressionSempred(dynamic_cast<BooleanExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::indexIdentifierSempred(IndexIdentifierContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::xOrExpressionSempred(XOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::bitAndExpressionSempred(BitAndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::bitShiftExpressionSempred(BitShiftExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::additiveExpressionSempred(AdditiveExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::multiplicativeExpressionSempred(MultiplicativeExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::expressionTerminatorSempred(ExpressionTerminatorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 2);
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::booleanExpressionSempred(BooleanExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> qasm3Parser::_decisionToDFA;
atn::PredictionContextCache qasm3Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN qasm3Parser::_atn;
std::vector<uint16_t> qasm3Parser::_serializedATN;

std::vector<std::string> qasm3Parser::_ruleNames = {
  "program", "header", "version", "include", "globalStatement", "statement", 
  "quantumDeclarationStatement", "classicalDeclarationStatement", "classicalAssignment", 
  "assignmentStatement", "returnSignature", "designator", "doubleDesignator", 
  "identifierList", "association", "quantumType", "quantumDeclaration", 
  "quantumArgument", "quantumArgumentList", "bitType", "singleDesignatorType", 
  "doubleDesignatorType", "noDesignatorType", "classicalType", "constantDeclaration", 
  "singleDesignatorDeclaration", "doubleDesignatorDeclaration", "noDesignatorDeclaration", 
  "bitDeclaration", "classicalDeclaration", "classicalTypeList", "classicalArgument", 
  "classicalArgumentList", "aliasStatement", "indexIdentifier", "indexIdentifierList", 
  "indexEqualsAssignmentList", "rangeDefinition", "quantumGateDefinition", 
  "quantumGateSignature", "quantumBlock", "quantumLoop", "quantumLoopBlock", 
  "quantumStatement", "quantumInstruction", "quantumPhase", "quantumMeasurement", 
  "quantumMeasurementAssignment", "quantumBarrier", "quantumGateModifier", 
  "quantumGateCall", "quantumGateName", "unaryOperator", "relationalOperator", 
  "logicalOperator", "expressionStatement", "expression", "xOrExpression", 
  "bitAndExpression", "bitShiftExpression", "additiveExpression", "multiplicativeExpression", 
  "unaryExpression", "expressionTerminator", "incrementor", "builtInCall", 
  "builtInMath", "castOperator", "expressionList", "booleanExpression", 
  "comparsionExpression", "equalsExpression", "assignmentOperator", "equalsAssignmentList", 
  "membershipTest", "setDeclaration", "programBlock", "branchingStatement", 
  "loopSignature", "loopStatement", "controlDirectiveStatement", "controlDirective", 
  "kernelDeclaration", "kernelCall", "subroutineDefinition", "returnStatement", 
  "subroutineBlock", "subroutineCall", "pragma", "timingType", "timingBox", 
  "timingTerminator", "timingIdentifier", "timingInstructionName", "timingInstruction", 
  "timingStatement", "calibration", "calibrationGrammarDeclaration", "calibrationDefinition", 
  "calibrationGrammar", "calibrationArgumentList"
};

std::vector<std::string> qasm3Parser::_literalNames = {
  "", "'OPENQASM'", "'include'", "'qubit'", "'qreg'", "'bit'", "'creg'", 
  "'int'", "'uint'", "'float'", "'angle'", "'fixed'", "'bool'", "'const'", 
  "'let'", "'||'", "'gate'", "'CX'", "'U'", "'gphase'", "'measure'", "'barrier'", 
  "'inv'", "'pow'", "'ctrl'", "'@'", "'reset'", "'~'", "'!'", "'>'", "'<'", 
  "'>='", "'<='", "'=='", "'!='", "'&&'", "'|'", "'^'", "'&'", "'<<'", "'>>'", 
  "'++'", "'--'", "'sin'", "'cos'", "'tan'", "'exp'", "'ln'", "'sqrt'", 
  "'rotl'", "'rotr'", "'popcount'", "'lengthof'", "'+='", "'-='", "'*='", 
  "'/='", "'&='", "'|='", "'~='", "'^='", "'<<='", "'>>='", "'in'", "'if'", 
  "'else'", "'for'", "'while'", "'break'", "'continue'", "'end'", "'kernel'", 
  "'def'", "'return'", "'#pragma'", "'length'", "'stretch'", "'boxas'", 
  "'boxto'", "'stretchinf'", "'delay'", "'rotary'", "'defcalgrammar'", "'defcal'", 
  "'\"openpulse\"'", "'['", "']'", "'{'", "'}'", "'('", "')'", "':'", "';'", 
  "'.'", "','", "'='", "'->'", "'+'", "'-'", "'*'", "'/'", "'%'"
};

std::vector<std::string> qasm3Parser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "LBRACKET", "RBRACKET", 
  "LBRACE", "RBRACE", "LPAREN", "RPAREN", "COLON", "SEMICOLON", "DOT", "COMMA", 
  "EQUALS", "ARROW", "PLUS", "MINUS", "MUL", "DIV", "MOD", "Constant", "Whitespace", 
  "Newline", "Integer", "Identifier", "RealNumber", "TimingLiteral", "StringLiteral", 
  "LineComment", "BlockComment"
};

dfa::Vocabulary qasm3Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> qasm3Parser::_tokenNames;

qasm3Parser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x71, 0x3af, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 
       0x9, 0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 
       0x9, 0x35, 0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 
       0x9, 0x38, 0x4, 0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 
       0x9, 0x3b, 0x4, 0x3c, 0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 
       0x9, 0x3e, 0x4, 0x3f, 0x9, 0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 
       0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 
       0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 0x46, 0x9, 0x46, 0x4, 0x47, 
       0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 0x9, 0x49, 0x4, 0x4a, 
       0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 0x4c, 0x4, 0x4d, 
       0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 0x4, 0x50, 
       0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 0x53, 
       0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
       0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 
       0x9, 0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 
       0x9, 0x5c, 0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 
       0x9, 0x5f, 0x4, 0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 
       0x9, 0x62, 0x4, 0x63, 0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 
       0x9, 0x65, 0x4, 0x66, 0x9, 0x66, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 
       0x2, 0xd0, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xd3, 0xb, 0x2, 0x3, 0x3, 
       0x5, 0x3, 0xd6, 0xa, 0x3, 0x3, 0x3, 0x7, 0x3, 0xd9, 0xa, 0x3, 0xc, 
       0x3, 0xe, 0x3, 0xdc, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0xec, 0xa, 0x6, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x5, 0x7, 0xf6, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xfd, 0xa, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x105, 0xa, 
       0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x109, 0xa, 0xb, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
       0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
       0xe, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x11c, 0xa, 0xf, 0xc, 0xf, 0xe, 
       0xf, 0x11f, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
       0x13, 0x3, 0x13, 0x5, 0x13, 0x12d, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 
       0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x134, 0xa, 0x14, 0xc, 
       0x14, 0xe, 0x14, 0x137, 0xb, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 
       0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 
       0x3, 0x18, 0x5, 0x18, 0x143, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
       0x19, 0x5, 0x19, 0x14e, 0xa, 0x19, 0x5, 0x19, 0x150, 0xa, 0x19, 0x3, 
       0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
       0x1b, 0x5, 0x1b, 0x159, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
       0x3, 0x1c, 0x5, 0x1c, 0x15f, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
       0x1d, 0x5, 0x1d, 0x164, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
       0x5, 0x1e, 0x169, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
       0x1f, 0x5, 0x1f, 0x16f, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x7, 0x20, 0x174, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x177, 0xb, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 
       0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x181, 0xa, 0x22, 0xc, 0x22, 0xe, 
       0x22, 0x184, 0xb, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 
       0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 
       0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
       0x5, 0x24, 0x196, 0xa, 0x24, 0x5, 0x24, 0x198, 0xa, 0x24, 0x3, 0x24, 
       0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x19d, 0xa, 0x24, 0xc, 0x24, 0xe, 
       0x24, 0x1a0, 0xb, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 
       0x1a5, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x1a8, 0xb, 0x25, 0x3, 0x25, 
       0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 
       0x1b0, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x1b3, 0xb, 0x26, 0x3, 0x26, 
       0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x1ba, 0xa, 
       0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x1be, 0xa, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x5, 0x27, 0x1c2, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
       0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 
       0x29, 0x5, 0x29, 0x1cd, 0xa, 0x29, 0x3, 0x29, 0x5, 0x29, 0x1d0, 0xa, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x7, 
       0x2a, 0x1d7, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x1da, 0xb, 0x2a, 0x3, 
       0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 
       0x2c, 0x3, 0x2c, 0x7, 0x2c, 0x1e4, 0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 
       0x1e7, 0xb, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x1ea, 0xa, 0x2c, 0x3, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x1f0, 0xa, 0x2d, 0x3, 
       0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x1f6, 0xa, 0x2e, 
       0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 
       0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 
       0x203, 0xa, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 
       0x31, 0x209, 0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 
       0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
       0x5, 0x33, 0x215, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 
       0x34, 0x3, 0x34, 0x5, 0x34, 0x21c, 0xa, 0x34, 0x3, 0x34, 0x5, 0x34, 
       0x21f, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 
       0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x22a, 
       0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 
       0x3, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 
       0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x239, 0xa, 0x3a, 0x3, 0x3a, 0x3, 
       0x3a, 0x3, 0x3a, 0x7, 0x3a, 0x23e, 0xa, 0x3a, 0xc, 0x3a, 0xe, 0x3a, 
       0x241, 0xb, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 
       0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x249, 0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 
       0x24c, 0xb, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
       0x3c, 0x3, 0x3c, 0x7, 0x3c, 0x254, 0xa, 0x3c, 0xc, 0x3c, 0xe, 0x3c, 
       0x257, 0xb, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 
       0x3d, 0x3, 0x3d, 0x7, 0x3d, 0x25f, 0xa, 0x3d, 0xc, 0x3d, 0xe, 0x3d, 
       0x262, 0xb, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 
       0x3e, 0x3, 0x3e, 0x7, 0x3e, 0x26a, 0xa, 0x3e, 0xc, 0x3e, 0xe, 0x3e, 
       0x26d, 0xb, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x272, 
       0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 
       0x278, 0xa, 0x3f, 0x7, 0x3f, 0x27a, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 
       0x27d, 0xb, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 
       0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
       0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
       0x41, 0x3, 0x41, 0x3, 0x41, 0x5, 0x41, 0x292, 0xa, 0x41, 0x3, 0x41, 
       0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
       0x7, 0x41, 0x29b, 0xa, 0x41, 0xc, 0x41, 0xe, 0x41, 0x29e, 0xb, 0x41, 
       0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x2a4, 0xa, 
       0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x44, 0x3, 
       0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x7, 
       0x46, 0x2b1, 0xa, 0x46, 0xc, 0x46, 0xe, 0x46, 0x2b4, 0xb, 0x46, 0x3, 
       0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x5, 0x47, 0x2bb, 
       0xa, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x7, 0x47, 
       0x2c1, 0xa, 0x47, 0xc, 0x47, 0xe, 0x47, 0x2c4, 0xb, 0x47, 0x3, 0x48, 
       0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 0x2cb, 0xa, 
       0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x3, 
       0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x7, 0x4b, 0x2d6, 0xa, 0x4b, 
       0xc, 0x4b, 0xe, 0x4b, 0x2d9, 0xb, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 
       0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4d, 0x3, 
       0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x5, 0x4d, 0x2e8, 
       0xa, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x7, 0x4e, 0x2ed, 0xa, 
       0x4e, 0xc, 0x4e, 0xe, 0x4e, 0x2f0, 0xb, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 
       0x2f3, 0xa, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 
       0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x2fc, 0xa, 0x4f, 0x3, 0x50, 
       0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 
       0x5, 0x50, 0x305, 0xa, 0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 
       0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 0x54, 0x3, 
       0x54, 0x3, 0x54, 0x3, 0x54, 0x5, 0x54, 0x313, 0xa, 0x54, 0x3, 0x54, 
       0x5, 0x54, 0x316, 0xa, 0x54, 0x3, 0x54, 0x5, 0x54, 0x319, 0xa, 0x54, 
       0x3, 0x54, 0x5, 0x54, 0x31c, 0xa, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 
       0x55, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x323, 0xa, 0x55, 0x3, 0x55, 
       0x3, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x5, 0x56, 
       0x32b, 0xa, 0x56, 0x3, 0x56, 0x5, 0x56, 0x32e, 0xa, 0x56, 0x3, 0x56, 
       0x5, 0x56, 0x331, 0xa, 0x56, 0x3, 0x56, 0x5, 0x56, 0x334, 0xa, 0x56, 
       0x3, 0x56, 0x3, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x58, 
       0x3, 0x58, 0x7, 0x58, 0x33d, 0xa, 0x58, 0xc, 0x58, 0xe, 0x58, 0x340, 
       0xb, 0x58, 0x3, 0x58, 0x5, 0x58, 0x343, 0xa, 0x58, 0x3, 0x58, 0x3, 
       0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x5, 0x59, 0x34a, 0xa, 0x59, 
       0x3, 0x59, 0x5, 0x59, 0x34d, 0xa, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 
       0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x7, 0x5a, 0x354, 0xa, 0x5a, 0xc, 0x5a, 
       0xe, 0x5a, 0x357, 0xb, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5b, 0x3, 
       0x5b, 0x3, 0x5b, 0x5, 0x5b, 0x35e, 0xa, 0x5b, 0x5, 0x5b, 0x360, 0xa, 
       0x5b, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 
       0x5c, 0x5, 0x5c, 0x368, 0xa, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 0x5, 0x5d, 
       0x36c, 0xa, 0x5d, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 
       0x5e, 0x5, 0x5e, 0x373, 0xa, 0x5e, 0x3, 0x5e, 0x5, 0x5e, 0x376, 0xa, 
       0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x5, 
       0x60, 0x37d, 0xa, 0x60, 0x3, 0x60, 0x5, 0x60, 0x380, 0xa, 0x60, 0x3, 
       0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 
       0x61, 0x5, 0x61, 0x389, 0xa, 0x61, 0x3, 0x62, 0x3, 0x62, 0x5, 0x62, 
       0x38d, 0xa, 0x62, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 
       0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 0x5, 0x64, 0x397, 0xa, 0x64, 
       0x3, 0x64, 0x5, 0x64, 0x39a, 0xa, 0x64, 0x3, 0x64, 0x3, 0x64, 0x5, 
       0x64, 0x39e, 0xa, 0x64, 0x3, 0x64, 0x3, 0x64, 0x7, 0x64, 0x3a2, 0xa, 
       0x64, 0xc, 0x64, 0xe, 0x64, 0x3a5, 0xb, 0x64, 0x3, 0x64, 0x3, 0x64, 
       0x3, 0x65, 0x3, 0x65, 0x3, 0x66, 0x3, 0x66, 0x5, 0x66, 0x3ad, 0xa, 
       0x66, 0x3, 0x66, 0x3, 0x3a3, 0xb, 0x46, 0x72, 0x74, 0x76, 0x78, 0x7a, 
       0x7c, 0x80, 0x8c, 0x67, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
       0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 
       0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 
       0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 
       0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 
       0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 
       0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 
       0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 
       0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0xc0, 
       0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0x2, 0x13, 0x4, 0x2, 0x6b, 0x6b, 0x6d, 
       0x6d, 0x3, 0x2, 0x5, 0x6, 0x3, 0x2, 0x7, 0x8, 0x3, 0x2, 0x9, 0xc, 
       0x4, 0x2, 0x13, 0x14, 0x6c, 0x6c, 0x3, 0x2, 0x1d, 0x1e, 0x3, 0x2, 
       0x1f, 0x24, 0x4, 0x2, 0x11, 0x11, 0x25, 0x25, 0x3, 0x2, 0x29, 0x2a, 
       0x3, 0x2, 0x63, 0x64, 0x3, 0x2, 0x65, 0x67, 0x3, 0x2, 0x2b, 0x2c, 
       0x3, 0x2, 0x2d, 0x36, 0x4, 0x2, 0x37, 0x40, 0x61, 0x61, 0x3, 0x2, 
       0x46, 0x48, 0x3, 0x2, 0x52, 0x53, 0x4, 0x2, 0x56, 0x56, 0x6f, 0x6f, 
       0x2, 0x3c8, 0x2, 0xcc, 0x3, 0x2, 0x2, 0x2, 0x4, 0xd5, 0x3, 0x2, 0x2, 
       0x2, 0x6, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x8, 0xe1, 0x3, 0x2, 0x2, 0x2, 
       0xa, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xc, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xe, 
       0xf7, 0x3, 0x2, 0x2, 0x2, 0x10, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x12, 0x100, 
       0x3, 0x2, 0x2, 0x2, 0x14, 0x108, 0x3, 0x2, 0x2, 0x2, 0x16, 0x10c, 
       0x3, 0x2, 0x2, 0x2, 0x18, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x113, 
       0x3, 0x2, 0x2, 0x2, 0x1c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x122, 
       0x3, 0x2, 0x2, 0x2, 0x20, 0x125, 0x3, 0x2, 0x2, 0x2, 0x22, 0x127, 
       0x3, 0x2, 0x2, 0x2, 0x24, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x26, 0x135, 
       0x3, 0x2, 0x2, 0x2, 0x28, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x13c, 
       0x3, 0x2, 0x2, 0x2, 0x2c, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x142, 
       0x3, 0x2, 0x2, 0x2, 0x30, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x32, 0x151, 
       0x3, 0x2, 0x2, 0x2, 0x34, 0x154, 0x3, 0x2, 0x2, 0x2, 0x36, 0x15a, 
       0x3, 0x2, 0x2, 0x2, 0x38, 0x160, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x165, 
       0x3, 0x2, 0x2, 0x2, 0x3c, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x175, 
       0x3, 0x2, 0x2, 0x2, 0x40, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x42, 0x182, 
       0x3, 0x2, 0x2, 0x2, 0x44, 0x187, 0x3, 0x2, 0x2, 0x2, 0x46, 0x197, 
       0x3, 0x2, 0x2, 0x2, 0x48, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x1b1, 
       0x3, 0x2, 0x2, 0x2, 0x4c, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x1c5, 
       0x3, 0x2, 0x2, 0x2, 0x50, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1d3, 
       0x3, 0x2, 0x2, 0x2, 0x54, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1e9, 
       0x3, 0x2, 0x2, 0x2, 0x58, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1f5, 
       0x3, 0x2, 0x2, 0x2, 0x5c, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1fc, 
       0x3, 0x2, 0x2, 0x2, 0x60, 0x208, 0x3, 0x2, 0x2, 0x2, 0x62, 0x20a, 
       0x3, 0x2, 0x2, 0x2, 0x64, 0x214, 0x3, 0x2, 0x2, 0x2, 0x66, 0x218, 
       0x3, 0x2, 0x2, 0x2, 0x68, 0x229, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x22b, 
       0x3, 0x2, 0x2, 0x2, 0x6c, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x22f, 
       0x3, 0x2, 0x2, 0x2, 0x70, 0x231, 0x3, 0x2, 0x2, 0x2, 0x72, 0x238, 
       0x3, 0x2, 0x2, 0x2, 0x74, 0x242, 0x3, 0x2, 0x2, 0x2, 0x76, 0x24d, 
       0x3, 0x2, 0x2, 0x2, 0x78, 0x258, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x263, 
       0x3, 0x2, 0x2, 0x2, 0x7c, 0x271, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x27e, 
       0x3, 0x2, 0x2, 0x2, 0x80, 0x291, 0x3, 0x2, 0x2, 0x2, 0x82, 0x29f, 
       0x3, 0x2, 0x2, 0x2, 0x84, 0x2a3, 0x3, 0x2, 0x2, 0x2, 0x86, 0x2a9, 
       0x3, 0x2, 0x2, 0x2, 0x88, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x2b2, 
       0x3, 0x2, 0x2, 0x2, 0x8c, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x2ca, 
       0x3, 0x2, 0x2, 0x2, 0x90, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x92, 0x2cf, 
       0x3, 0x2, 0x2, 0x2, 0x94, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x96, 0x2dd, 
       0x3, 0x2, 0x2, 0x2, 0x98, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x2f2, 
       0x3, 0x2, 0x2, 0x2, 0x9c, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x304, 
       0x3, 0x2, 0x2, 0x2, 0xa0, 0x306, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x309, 
       0x3, 0x2, 0x2, 0x2, 0xa4, 0x30c, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x30e, 
       0x3, 0x2, 0x2, 0x2, 0xa8, 0x31f, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x326, 
       0x3, 0x2, 0x2, 0x2, 0xac, 0x337, 0x3, 0x2, 0x2, 0x2, 0xae, 0x33a, 
       0x3, 0x2, 0x2, 0x2, 0xb0, 0x346, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x350, 
       0x3, 0x2, 0x2, 0x2, 0xb4, 0x35f, 0x3, 0x2, 0x2, 0x2, 0xb6, 0x367, 
       0x3, 0x2, 0x2, 0x2, 0xb8, 0x36b, 0x3, 0x2, 0x2, 0x2, 0xba, 0x375, 
       0x3, 0x2, 0x2, 0x2, 0xbc, 0x377, 0x3, 0x2, 0x2, 0x2, 0xbe, 0x379, 
       0x3, 0x2, 0x2, 0x2, 0xc0, 0x388, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x38c, 
       0x3, 0x2, 0x2, 0x2, 0xc4, 0x38e, 0x3, 0x2, 0x2, 0x2, 0xc6, 0x392, 
       0x3, 0x2, 0x2, 0x2, 0xc8, 0x3a8, 0x3, 0x2, 0x2, 0x2, 0xca, 0x3ac, 
       0x3, 0x2, 0x2, 0x2, 0xcc, 0xd1, 0x5, 0x4, 0x3, 0x2, 0xcd, 0xd0, 0x5, 
       0xa, 0x6, 0x2, 0xce, 0xd0, 0x5, 0xc, 0x7, 0x2, 0xcf, 0xcd, 0x3, 0x2, 
       0x2, 0x2, 0xcf, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd3, 0x3, 0x2, 0x2, 
       0x2, 0xd1, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 
       0xd2, 0x3, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd4, 
       0xd6, 0x5, 0x6, 0x4, 0x2, 0xd5, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 
       0x3, 0x2, 0x2, 0x2, 0xd6, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd9, 0x5, 
       0x8, 0x5, 0x2, 0xd8, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xdc, 0x3, 0x2, 
       0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x3, 0x2, 0x2, 
       0x2, 0xdb, 0x5, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xda, 0x3, 0x2, 0x2, 0x2, 
       0xdd, 0xde, 0x7, 0x3, 0x2, 0x2, 0xde, 0xdf, 0x9, 0x2, 0x2, 0x2, 0xdf, 
       0xe0, 0x7, 0x5e, 0x2, 0x2, 0xe0, 0x7, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 
       0x7, 0x4, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x6f, 0x2, 0x2, 0xe3, 0xe4, 
       0x7, 0x5e, 0x2, 0x2, 0xe4, 0x9, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xec, 0x5, 
       0xaa, 0x56, 0x2, 0xe6, 0xec, 0x5, 0xa6, 0x54, 0x2, 0xe7, 0xec, 0x5, 
       0x4e, 0x28, 0x2, 0xe8, 0xec, 0x5, 0xc2, 0x62, 0x2, 0xe9, 0xec, 0x5, 
       0xe, 0x8, 0x2, 0xea, 0xec, 0x5, 0xb2, 0x5a, 0x2, 0xeb, 0xe5, 0x3, 
       0x2, 0x2, 0x2, 0xeb, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xe7, 0x3, 0x2, 
       0x2, 0x2, 0xeb, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xe9, 0x3, 0x2, 0x2, 
       0x2, 0xeb, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xb, 0x3, 0x2, 0x2, 0x2, 
       0xed, 0xf6, 0x5, 0x70, 0x39, 0x2, 0xee, 0xf6, 0x5, 0x14, 0xb, 0x2, 
       0xef, 0xf6, 0x5, 0x10, 0x9, 0x2, 0xf0, 0xf6, 0x5, 0x9c, 0x4f, 0x2, 
       0xf1, 0xf6, 0x5, 0xa0, 0x51, 0x2, 0xf2, 0xf6, 0x5, 0xa2, 0x52, 0x2, 
       0xf3, 0xf6, 0x5, 0x44, 0x23, 0x2, 0xf4, 0xf6, 0x5, 0x58, 0x2d, 0x2, 
       0xf5, 0xed, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf5, 
       0xef, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf1, 
       0x3, 0x2, 0x2, 0x2, 0xf5, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 
       0x2, 0x2, 0x2, 0xf5, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xd, 0x3, 0x2, 
       0x2, 0x2, 0xf7, 0xf8, 0x5, 0x22, 0x12, 0x2, 0xf8, 0xf9, 0x7, 0x5e, 
       0x2, 0x2, 0xf9, 0xf, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfd, 0x5, 0x3c, 0x1f, 
       0x2, 0xfb, 0xfd, 0x5, 0x32, 0x1a, 0x2, 0xfc, 0xfa, 0x3, 0x2, 0x2, 
       0x2, 0xfc, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x3, 0x2, 0x2, 0x2, 
       0xfe, 0xff, 0x7, 0x5e, 0x2, 0x2, 0xff, 0x11, 0x3, 0x2, 0x2, 0x2, 
       0x100, 0x101, 0x5, 0x46, 0x24, 0x2, 0x101, 0x104, 0x5, 0x92, 0x4a, 
       0x2, 0x102, 0x105, 0x5, 0x72, 0x3a, 0x2, 0x103, 0x105, 0x5, 0x46, 
       0x24, 0x2, 0x104, 0x102, 0x3, 0x2, 0x2, 0x2, 0x104, 0x103, 0x3, 0x2, 
       0x2, 0x2, 0x105, 0x13, 0x3, 0x2, 0x2, 0x2, 0x106, 0x109, 0x5, 0x12, 
       0xa, 0x2, 0x107, 0x109, 0x5, 0x60, 0x31, 0x2, 0x108, 0x106, 0x3, 
       0x2, 0x2, 0x2, 0x108, 0x107, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x3, 
       0x2, 0x2, 0x2, 0x10a, 0x10b, 0x7, 0x5e, 0x2, 0x2, 0x10b, 0x15, 0x3, 
       0x2, 0x2, 0x2, 0x10c, 0x10d, 0x7, 0x62, 0x2, 0x2, 0x10d, 0x10e, 0x5, 
       0x30, 0x19, 0x2, 0x10e, 0x17, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x7, 
       0x57, 0x2, 0x2, 0x110, 0x111, 0x5, 0x72, 0x3a, 0x2, 0x111, 0x112, 
       0x7, 0x58, 0x2, 0x2, 0x112, 0x19, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 
       0x7, 0x57, 0x2, 0x2, 0x114, 0x115, 0x5, 0x72, 0x3a, 0x2, 0x115, 0x116, 
       0x7, 0x60, 0x2, 0x2, 0x116, 0x117, 0x5, 0x72, 0x3a, 0x2, 0x117, 0x118, 
       0x7, 0x58, 0x2, 0x2, 0x118, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 
       0x7, 0x6c, 0x2, 0x2, 0x11a, 0x11c, 0x7, 0x60, 0x2, 0x2, 0x11b, 0x119, 
       0x3, 0x2, 0x2, 0x2, 0x11c, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11b, 
       0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x120, 
       0x3, 0x2, 0x2, 0x2, 0x11f, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 
       0x7, 0x6c, 0x2, 0x2, 0x121, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 
       0x7, 0x5d, 0x2, 0x2, 0x123, 0x124, 0x7, 0x6c, 0x2, 0x2, 0x124, 0x1f, 
       0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x9, 0x3, 0x2, 0x2, 0x126, 0x21, 
       0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x5, 0x20, 0x11, 0x2, 0x128, 0x129, 
       0x5, 0x48, 0x25, 0x2, 0x129, 0x23, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12c, 
       0x5, 0x20, 0x11, 0x2, 0x12b, 0x12d, 0x5, 0x18, 0xd, 0x2, 0x12c, 0x12b, 
       0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 
       0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 0x5, 0x1e, 0x10, 0x2, 0x12f, 0x25, 
       0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x5, 0x24, 0x13, 0x2, 0x131, 0x132, 
       0x7, 0x60, 0x2, 0x2, 0x132, 0x134, 0x3, 0x2, 0x2, 0x2, 0x133, 0x130, 
       0x3, 0x2, 0x2, 0x2, 0x134, 0x137, 0x3, 0x2, 0x2, 0x2, 0x135, 0x133, 
       0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 0x3, 0x2, 0x2, 0x2, 0x136, 0x138, 
       0x3, 0x2, 0x2, 0x2, 0x137, 0x135, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 
       0x5, 0x24, 0x13, 0x2, 0x139, 0x27, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 
       0x9, 0x4, 0x2, 0x2, 0x13b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 
       0x9, 0x5, 0x2, 0x2, 0x13d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 
       0x7, 0xd, 0x2, 0x2, 0x13f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x140, 0x143, 
       0x7, 0xe, 0x2, 0x2, 0x141, 0x143, 0x5, 0xb4, 0x5b, 0x2, 0x142, 0x140, 
       0x3, 0x2, 0x2, 0x2, 0x142, 0x141, 0x3, 0x2, 0x2, 0x2, 0x143, 0x2f, 
       0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x5, 0x2a, 0x16, 0x2, 0x145, 0x146, 
       0x5, 0x18, 0xd, 0x2, 0x146, 0x150, 0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 
       0x5, 0x2c, 0x17, 0x2, 0x148, 0x149, 0x5, 0x1a, 0xe, 0x2, 0x149, 0x150, 
       0x3, 0x2, 0x2, 0x2, 0x14a, 0x150, 0x5, 0x2e, 0x18, 0x2, 0x14b, 0x14d, 
       0x5, 0x28, 0x15, 0x2, 0x14c, 0x14e, 0x5, 0x18, 0xd, 0x2, 0x14d, 0x14c, 
       0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x150, 
       0x3, 0x2, 0x2, 0x2, 0x14f, 0x144, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x147, 
       0x3, 0x2, 0x2, 0x2, 0x14f, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x14b, 
       0x3, 0x2, 0x2, 0x2, 0x150, 0x31, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 
       0x7, 0xf, 0x2, 0x2, 0x152, 0x153, 0x5, 0x94, 0x4b, 0x2, 0x153, 0x33, 
       0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x5, 0x2a, 0x16, 0x2, 0x155, 0x158, 
       0x5, 0x18, 0xd, 0x2, 0x156, 0x159, 0x5, 0x1c, 0xf, 0x2, 0x157, 0x159, 
       0x5, 0x94, 0x4b, 0x2, 0x158, 0x156, 0x3, 0x2, 0x2, 0x2, 0x158, 0x157, 
       0x3, 0x2, 0x2, 0x2, 0x159, 0x35, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15b, 
       0x5, 0x2c, 0x17, 0x2, 0x15b, 0x15e, 0x5, 0x1a, 0xe, 0x2, 0x15c, 0x15f, 
       0x5, 0x1c, 0xf, 0x2, 0x15d, 0x15f, 0x5, 0x94, 0x4b, 0x2, 0x15e, 0x15c, 
       0x3, 0x2, 0x2, 0x2, 0x15e, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x37, 
       0x3, 0x2, 0x2, 0x2, 0x160, 0x163, 0x5, 0x2e, 0x18, 0x2, 0x161, 0x164, 
       0x5, 0x1c, 0xf, 0x2, 0x162, 0x164, 0x5, 0x94, 0x4b, 0x2, 0x163, 0x161, 
       0x3, 0x2, 0x2, 0x2, 0x163, 0x162, 0x3, 0x2, 0x2, 0x2, 0x164, 0x39, 
       0x3, 0x2, 0x2, 0x2, 0x165, 0x168, 0x5, 0x28, 0x15, 0x2, 0x166, 0x169, 
       0x5, 0x48, 0x25, 0x2, 0x167, 0x169, 0x5, 0x4a, 0x26, 0x2, 0x168, 
       0x166, 0x3, 0x2, 0x2, 0x2, 0x168, 0x167, 0x3, 0x2, 0x2, 0x2, 0x169, 
       0x3b, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16f, 0x5, 0x34, 0x1b, 0x2, 0x16b, 
       0x16f, 0x5, 0x36, 0x1c, 0x2, 0x16c, 0x16f, 0x5, 0x38, 0x1d, 0x2, 
       0x16d, 0x16f, 0x5, 0x3a, 0x1e, 0x2, 0x16e, 0x16a, 0x3, 0x2, 0x2, 
       0x2, 0x16e, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16c, 0x3, 0x2, 0x2, 
       0x2, 0x16e, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x3d, 0x3, 0x2, 0x2, 
       0x2, 0x170, 0x171, 0x5, 0x30, 0x19, 0x2, 0x171, 0x172, 0x7, 0x60, 
       0x2, 0x2, 0x172, 0x174, 0x3, 0x2, 0x2, 0x2, 0x173, 0x170, 0x3, 0x2, 
       0x2, 0x2, 0x174, 0x177, 0x3, 0x2, 0x2, 0x2, 0x175, 0x173, 0x3, 0x2, 
       0x2, 0x2, 0x175, 0x176, 0x3, 0x2, 0x2, 0x2, 0x176, 0x178, 0x3, 0x2, 
       0x2, 0x2, 0x177, 0x175, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x5, 0x30, 
       0x19, 0x2, 0x179, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x5, 0x30, 
       0x19, 0x2, 0x17b, 0x17c, 0x5, 0x1e, 0x10, 0x2, 0x17c, 0x41, 0x3, 
       0x2, 0x2, 0x2, 0x17d, 0x17e, 0x5, 0x40, 0x21, 0x2, 0x17e, 0x17f, 
       0x7, 0x60, 0x2, 0x2, 0x17f, 0x181, 0x3, 0x2, 0x2, 0x2, 0x180, 0x17d, 
       0x3, 0x2, 0x2, 0x2, 0x181, 0x184, 0x3, 0x2, 0x2, 0x2, 0x182, 0x180, 
       0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 0x3, 0x2, 0x2, 0x2, 0x183, 0x185, 
       0x3, 0x2, 0x2, 0x2, 0x184, 0x182, 0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 
       0x5, 0x40, 0x21, 0x2, 0x186, 0x43, 0x3, 0x2, 0x2, 0x2, 0x187, 0x188, 
       0x7, 0x10, 0x2, 0x2, 0x188, 0x189, 0x7, 0x6c, 0x2, 0x2, 0x189, 0x18a, 
       0x7, 0x61, 0x2, 0x2, 0x18a, 0x18b, 0x5, 0x46, 0x24, 0x2, 0x18b, 0x18c, 
       0x7, 0x5e, 0x2, 0x2, 0x18c, 0x45, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 
       0x8, 0x24, 0x1, 0x2, 0x18e, 0x18f, 0x7, 0x6c, 0x2, 0x2, 0x18f, 0x198, 
       0x5, 0x4c, 0x27, 0x2, 0x190, 0x195, 0x7, 0x6c, 0x2, 0x2, 0x191, 0x192, 
       0x7, 0x57, 0x2, 0x2, 0x192, 0x193, 0x5, 0x8a, 0x46, 0x2, 0x193, 0x194, 
       0x7, 0x58, 0x2, 0x2, 0x194, 0x196, 0x3, 0x2, 0x2, 0x2, 0x195, 0x191, 
       0x3, 0x2, 0x2, 0x2, 0x195, 0x196, 0x3, 0x2, 0x2, 0x2, 0x196, 0x198, 
       0x3, 0x2, 0x2, 0x2, 0x197, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x197, 0x190, 
       0x3, 0x2, 0x2, 0x2, 0x198, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19a, 
       0xc, 0x3, 0x2, 0x2, 0x19a, 0x19b, 0x7, 0x11, 0x2, 0x2, 0x19b, 0x19d, 
       0x5, 0x46, 0x24, 0x4, 0x19c, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x1a0, 
       0x3, 0x2, 0x2, 0x2, 0x19e, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 
       0x3, 0x2, 0x2, 0x2, 0x19f, 0x47, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x19e, 
       0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 0x5, 0x46, 0x24, 0x2, 0x1a2, 0x1a3, 
       0x7, 0x60, 0x2, 0x2, 0x1a3, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a1, 
       0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a4, 
       0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a9, 
       0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1aa, 
       0x5, 0x46, 0x24, 0x2, 0x1aa, 0x49, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1ac, 
       0x5, 0x46, 0x24, 0x2, 0x1ac, 0x1ad, 0x5, 0x90, 0x49, 0x2, 0x1ad, 
       0x1ae, 0x7, 0x60, 0x2, 0x2, 0x1ae, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1af, 
       0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b1, 
       0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b2, 
       0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b4, 
       0x1b5, 0x5, 0x46, 0x24, 0x2, 0x1b5, 0x1b6, 0x5, 0x90, 0x49, 0x2, 
       0x1b6, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b9, 0x7, 0x57, 0x2, 0x2, 
       0x1b8, 0x1ba, 0x5, 0x72, 0x3a, 0x2, 0x1b9, 0x1b8, 0x3, 0x2, 0x2, 
       0x2, 0x1b9, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bb, 0x3, 0x2, 0x2, 
       0x2, 0x1bb, 0x1bd, 0x7, 0x5d, 0x2, 0x2, 0x1bc, 0x1be, 0x5, 0x72, 
       0x3a, 0x2, 0x1bd, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1be, 0x3, 0x2, 
       0x2, 0x2, 0x1be, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c0, 0x7, 0x5d, 
       0x2, 0x2, 0x1c0, 0x1c2, 0x5, 0x72, 0x3a, 0x2, 0x1c1, 0x1bf, 0x3, 
       0x2, 0x2, 0x2, 0x1c1, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 0x3, 
       0x2, 0x2, 0x2, 0x1c3, 0x1c4, 0x7, 0x58, 0x2, 0x2, 0x1c4, 0x4d, 0x3, 
       0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x7, 0x12, 0x2, 0x2, 0x1c6, 0x1c7, 0x5, 
       0x50, 0x29, 0x2, 0x1c7, 0x1c8, 0x5, 0x52, 0x2a, 0x2, 0x1c8, 0x4f, 
       0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1cf, 0x9, 0x6, 0x2, 0x2, 0x1ca, 0x1cc, 
       0x7, 0x5b, 0x2, 0x2, 0x1cb, 0x1cd, 0x5, 0x1c, 0xf, 0x2, 0x1cc, 0x1cb, 
       0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1ce, 
       0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1d0, 0x7, 0x5c, 0x2, 0x2, 0x1cf, 0x1ca, 
       0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d1, 
       0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d2, 0x5, 0x1c, 0xf, 0x2, 0x1d2, 0x51, 
       0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d8, 0x7, 0x59, 0x2, 0x2, 0x1d4, 0x1d7, 
       0x5, 0x58, 0x2d, 0x2, 0x1d5, 0x1d7, 0x5, 0x54, 0x2b, 0x2, 0x1d6, 
       0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d7, 
       0x1da, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d8, 
       0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x1da, 
       0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1dc, 0x7, 0x5a, 0x2, 0x2, 0x1dc, 
       0x53, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1de, 0x5, 0x9e, 0x50, 0x2, 0x1de, 
       0x1df, 0x5, 0x56, 0x2c, 0x2, 0x1df, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1e0, 
       0x1ea, 0x5, 0x58, 0x2d, 0x2, 0x1e1, 0x1e5, 0x7, 0x59, 0x2, 0x2, 0x1e2, 
       0x1e4, 0x5, 0x58, 0x2d, 0x2, 0x1e3, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e4, 
       0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e5, 
       0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1e7, 
       0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1ea, 0x7, 0x5a, 0x2, 0x2, 0x1e9, 
       0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1ea, 
       0x57, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1ec, 0x5, 0x5a, 0x2e, 0x2, 0x1ec, 
       0x1ed, 0x7, 0x5e, 0x2, 0x2, 0x1ed, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1ee, 
       0x1f0, 0x5, 0xc0, 0x61, 0x2, 0x1ef, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1ef, 
       0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1f1, 
       0x1f6, 0x5, 0x66, 0x34, 0x2, 0x1f2, 0x1f6, 0x5, 0x5c, 0x2f, 0x2, 
       0x1f3, 0x1f6, 0x5, 0x5e, 0x30, 0x2, 0x1f4, 0x1f6, 0x5, 0x62, 0x32, 
       0x2, 0x1f5, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f2, 0x3, 0x2, 0x2, 
       0x2, 0x1f5, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f4, 0x3, 0x2, 0x2, 
       0x2, 0x1f6, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f8, 0x7, 0x15, 0x2, 
       0x2, 0x1f8, 0x1f9, 0x7, 0x5b, 0x2, 0x2, 0x1f9, 0x1fa, 0x7, 0x6c, 
       0x2, 0x2, 0x1fa, 0x1fb, 0x7, 0x5c, 0x2, 0x2, 0x1fb, 0x5d, 0x3, 0x2, 
       0x2, 0x2, 0x1fc, 0x1fd, 0x7, 0x16, 0x2, 0x2, 0x1fd, 0x1fe, 0x5, 0x48, 
       0x25, 0x2, 0x1fe, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x202, 0x5, 0x5e, 
       0x30, 0x2, 0x200, 0x201, 0x7, 0x62, 0x2, 0x2, 0x201, 0x203, 0x5, 
       0x48, 0x25, 0x2, 0x202, 0x200, 0x3, 0x2, 0x2, 0x2, 0x202, 0x203, 
       0x3, 0x2, 0x2, 0x2, 0x203, 0x209, 0x3, 0x2, 0x2, 0x2, 0x204, 0x205, 
       0x5, 0x48, 0x25, 0x2, 0x205, 0x206, 0x7, 0x61, 0x2, 0x2, 0x206, 0x207, 
       0x5, 0x5e, 0x30, 0x2, 0x207, 0x209, 0x3, 0x2, 0x2, 0x2, 0x208, 0x1ff, 
       0x3, 0x2, 0x2, 0x2, 0x208, 0x204, 0x3, 0x2, 0x2, 0x2, 0x209, 0x61, 
       0x3, 0x2, 0x2, 0x2, 0x20a, 0x20b, 0x7, 0x17, 0x2, 0x2, 0x20b, 0x20c, 
       0x5, 0x48, 0x25, 0x2, 0x20c, 0x63, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x215, 
       0x7, 0x18, 0x2, 0x2, 0x20e, 0x20f, 0x7, 0x19, 0x2, 0x2, 0x20f, 0x210, 
       0x7, 0x5b, 0x2, 0x2, 0x210, 0x211, 0x5, 0x72, 0x3a, 0x2, 0x211, 0x212, 
       0x7, 0x5c, 0x2, 0x2, 0x212, 0x215, 0x3, 0x2, 0x2, 0x2, 0x213, 0x215, 
       0x7, 0x1a, 0x2, 0x2, 0x214, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x214, 0x20e, 
       0x3, 0x2, 0x2, 0x2, 0x214, 0x213, 0x3, 0x2, 0x2, 0x2, 0x215, 0x216, 
       0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x7, 0x1b, 0x2, 0x2, 0x217, 0x65, 
       0x3, 0x2, 0x2, 0x2, 0x218, 0x21e, 0x5, 0x68, 0x35, 0x2, 0x219, 0x21b, 
       0x7, 0x5b, 0x2, 0x2, 0x21a, 0x21c, 0x5, 0x8a, 0x46, 0x2, 0x21b, 0x21a, 
       0x3, 0x2, 0x2, 0x2, 0x21b, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x21d, 
       0x3, 0x2, 0x2, 0x2, 0x21d, 0x21f, 0x7, 0x5c, 0x2, 0x2, 0x21e, 0x219, 
       0x3, 0x2, 0x2, 0x2, 0x21e, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x220, 
       0x3, 0x2, 0x2, 0x2, 0x220, 0x221, 0x5, 0x48, 0x25, 0x2, 0x221, 0x67, 
       0x3, 0x2, 0x2, 0x2, 0x222, 0x22a, 0x7, 0x13, 0x2, 0x2, 0x223, 0x22a, 
       0x7, 0x14, 0x2, 0x2, 0x224, 0x22a, 0x7, 0x1c, 0x2, 0x2, 0x225, 0x22a, 
       0x7, 0x6c, 0x2, 0x2, 0x226, 0x227, 0x5, 0x64, 0x33, 0x2, 0x227, 0x228, 
       0x5, 0x68, 0x35, 0x2, 0x228, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x229, 0x222, 
       0x3, 0x2, 0x2, 0x2, 0x229, 0x223, 0x3, 0x2, 0x2, 0x2, 0x229, 0x224, 
       0x3, 0x2, 0x2, 0x2, 0x229, 0x225, 0x3, 0x2, 0x2, 0x2, 0x229, 0x226, 
       0x3, 0x2, 0x2, 0x2, 0x22a, 0x69, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22c, 
       0x9, 0x7, 0x2, 0x2, 0x22c, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22e, 
       0x9, 0x8, 0x2, 0x2, 0x22e, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x230, 
       0x9, 0x9, 0x2, 0x2, 0x230, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x231, 0x232, 
       0x5, 0x72, 0x3a, 0x2, 0x232, 0x233, 0x7, 0x5e, 0x2, 0x2, 0x233, 0x71, 
       0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 0x8, 0x3a, 0x1, 0x2, 0x235, 0x239, 
       0x5, 0x80, 0x41, 0x2, 0x236, 0x239, 0x5, 0x7e, 0x40, 0x2, 0x237, 
       0x239, 0x5, 0x74, 0x3b, 0x2, 0x238, 0x234, 0x3, 0x2, 0x2, 0x2, 0x238, 
       0x236, 0x3, 0x2, 0x2, 0x2, 0x238, 0x237, 0x3, 0x2, 0x2, 0x2, 0x239, 
       0x23f, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x23b, 0xc, 0x3, 0x2, 0x2, 0x23b, 
       0x23c, 0x7, 0x26, 0x2, 0x2, 0x23c, 0x23e, 0x5, 0x74, 0x3b, 0x2, 0x23d, 
       0x23a, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x241, 0x3, 0x2, 0x2, 0x2, 0x23f, 
       0x23d, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x240, 0x3, 0x2, 0x2, 0x2, 0x240, 
       0x73, 0x3, 0x2, 0x2, 0x2, 0x241, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x242, 
       0x243, 0x8, 0x3b, 0x1, 0x2, 0x243, 0x244, 0x5, 0x76, 0x3c, 0x2, 0x244, 
       0x24a, 0x3, 0x2, 0x2, 0x2, 0x245, 0x246, 0xc, 0x3, 0x2, 0x2, 0x246, 
       0x247, 0x7, 0x27, 0x2, 0x2, 0x247, 0x249, 0x5, 0x76, 0x3c, 0x2, 0x248, 
       0x245, 0x3, 0x2, 0x2, 0x2, 0x249, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24a, 
       0x248, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x24b, 
       0x75, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24d, 
       0x24e, 0x8, 0x3c, 0x1, 0x2, 0x24e, 0x24f, 0x5, 0x78, 0x3d, 0x2, 0x24f, 
       0x255, 0x3, 0x2, 0x2, 0x2, 0x250, 0x251, 0xc, 0x3, 0x2, 0x2, 0x251, 
       0x252, 0x7, 0x28, 0x2, 0x2, 0x252, 0x254, 0x5, 0x78, 0x3d, 0x2, 0x253, 
       0x250, 0x3, 0x2, 0x2, 0x2, 0x254, 0x257, 0x3, 0x2, 0x2, 0x2, 0x255, 
       0x253, 0x3, 0x2, 0x2, 0x2, 0x255, 0x256, 0x3, 0x2, 0x2, 0x2, 0x256, 
       0x77, 0x3, 0x2, 0x2, 0x2, 0x257, 0x255, 0x3, 0x2, 0x2, 0x2, 0x258, 
       0x259, 0x8, 0x3d, 0x1, 0x2, 0x259, 0x25a, 0x5, 0x7a, 0x3e, 0x2, 0x25a, 
       0x260, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25c, 0xc, 0x3, 0x2, 0x2, 0x25c, 
       0x25d, 0x9, 0xa, 0x2, 0x2, 0x25d, 0x25f, 0x5, 0x7a, 0x3e, 0x2, 0x25e, 
       0x25b, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x262, 0x3, 0x2, 0x2, 0x2, 0x260, 
       0x25e, 0x3, 0x2, 0x2, 0x2, 0x260, 0x261, 0x3, 0x2, 0x2, 0x2, 0x261, 
       0x79, 0x3, 0x2, 0x2, 0x2, 0x262, 0x260, 0x3, 0x2, 0x2, 0x2, 0x263, 
       0x264, 0x8, 0x3e, 0x1, 0x2, 0x264, 0x265, 0x5, 0x7c, 0x3f, 0x2, 0x265, 
       0x26b, 0x3, 0x2, 0x2, 0x2, 0x266, 0x267, 0xc, 0x3, 0x2, 0x2, 0x267, 
       0x268, 0x9, 0xb, 0x2, 0x2, 0x268, 0x26a, 0x5, 0x7c, 0x3f, 0x2, 0x269, 
       0x266, 0x3, 0x2, 0x2, 0x2, 0x26a, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26b, 
       0x269, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x26c, 
       0x7b, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x26e, 
       0x26f, 0x8, 0x3f, 0x1, 0x2, 0x26f, 0x272, 0x5, 0x80, 0x41, 0x2, 0x270, 
       0x272, 0x5, 0x7e, 0x40, 0x2, 0x271, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x271, 
       0x270, 0x3, 0x2, 0x2, 0x2, 0x272, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x273, 
       0x274, 0xc, 0x3, 0x2, 0x2, 0x274, 0x277, 0x9, 0xc, 0x2, 0x2, 0x275, 
       0x278, 0x5, 0x80, 0x41, 0x2, 0x276, 0x278, 0x5, 0x7e, 0x40, 0x2, 
       0x277, 0x275, 0x3, 0x2, 0x2, 0x2, 0x277, 0x276, 0x3, 0x2, 0x2, 0x2, 
       0x278, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x279, 0x273, 0x3, 0x2, 0x2, 0x2, 
       0x27a, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x27b, 0x279, 0x3, 0x2, 0x2, 0x2, 
       0x27b, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x7d, 0x3, 0x2, 0x2, 0x2, 
       0x27d, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x27f, 0x5, 0x6a, 0x36, 
       0x2, 0x27f, 0x280, 0x5, 0x80, 0x41, 0x2, 0x280, 0x7f, 0x3, 0x2, 0x2, 
       0x2, 0x281, 0x282, 0x8, 0x41, 0x1, 0x2, 0x282, 0x292, 0x7, 0x68, 
       0x2, 0x2, 0x283, 0x292, 0x7, 0x6b, 0x2, 0x2, 0x284, 0x292, 0x7, 0x6d, 
       0x2, 0x2, 0x285, 0x292, 0x7, 0x6c, 0x2, 0x2, 0x286, 0x292, 0x7, 0x6f, 
       0x2, 0x2, 0x287, 0x292, 0x5, 0x84, 0x43, 0x2, 0x288, 0x292, 0x5, 
       0xa8, 0x55, 0x2, 0x289, 0x292, 0x5, 0xb0, 0x59, 0x2, 0x28a, 0x292, 
       0x5, 0xb8, 0x5d, 0x2, 0x28b, 0x28c, 0x7, 0x64, 0x2, 0x2, 0x28c, 0x292, 
       0x5, 0x80, 0x41, 0x6, 0x28d, 0x28e, 0x7, 0x5b, 0x2, 0x2, 0x28e, 0x28f, 
       0x5, 0x72, 0x3a, 0x2, 0x28f, 0x290, 0x7, 0x5c, 0x2, 0x2, 0x290, 0x292, 
       0x3, 0x2, 0x2, 0x2, 0x291, 0x281, 0x3, 0x2, 0x2, 0x2, 0x291, 0x283, 
       0x3, 0x2, 0x2, 0x2, 0x291, 0x284, 0x3, 0x2, 0x2, 0x2, 0x291, 0x285, 
       0x3, 0x2, 0x2, 0x2, 0x291, 0x286, 0x3, 0x2, 0x2, 0x2, 0x291, 0x287, 
       0x3, 0x2, 0x2, 0x2, 0x291, 0x288, 0x3, 0x2, 0x2, 0x2, 0x291, 0x289, 
       0x3, 0x2, 0x2, 0x2, 0x291, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x291, 0x28b, 
       0x3, 0x2, 0x2, 0x2, 0x291, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x292, 0x29c, 
       0x3, 0x2, 0x2, 0x2, 0x293, 0x294, 0xc, 0x4, 0x2, 0x2, 0x294, 0x295, 
       0x7, 0x57, 0x2, 0x2, 0x295, 0x296, 0x5, 0x72, 0x3a, 0x2, 0x296, 0x297, 
       0x7, 0x58, 0x2, 0x2, 0x297, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x298, 0x299, 
       0xc, 0x3, 0x2, 0x2, 0x299, 0x29b, 0x5, 0x82, 0x42, 0x2, 0x29a, 0x293, 
       0x3, 0x2, 0x2, 0x2, 0x29a, 0x298, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x29e, 
       0x3, 0x2, 0x2, 0x2, 0x29c, 0x29a, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 
       0x3, 0x2, 0x2, 0x2, 0x29d, 0x81, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x29c, 
       0x3, 0x2, 0x2, 0x2, 0x29f, 0x2a0, 0x9, 0xd, 0x2, 0x2, 0x2a0, 0x83, 
       0x3, 0x2, 0x2, 0x2, 0x2a1, 0x2a4, 0x5, 0x86, 0x44, 0x2, 0x2a2, 0x2a4, 
       0x5, 0x88, 0x45, 0x2, 0x2a3, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a2, 
       0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0x2a6, 
       0x7, 0x5b, 0x2, 0x2, 0x2a6, 0x2a7, 0x5, 0x8a, 0x46, 0x2, 0x2a7, 0x2a8, 
       0x7, 0x5c, 0x2, 0x2, 0x2a8, 0x85, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2aa, 
       0x9, 0xe, 0x2, 0x2, 0x2aa, 0x87, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2ac, 
       0x5, 0x30, 0x19, 0x2, 0x2ac, 0x89, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2ae, 
       0x5, 0x72, 0x3a, 0x2, 0x2ae, 0x2af, 0x7, 0x60, 0x2, 0x2, 0x2af, 0x2b1, 
       0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b4, 
       0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b3, 
       0x3, 0x2, 0x2, 0x2, 0x2b3, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b2, 
       0x3, 0x2, 0x2, 0x2, 0x2b5, 0x2b6, 0x5, 0x72, 0x3a, 0x2, 0x2b6, 0x8b, 
       0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b8, 0x8, 0x47, 0x1, 0x2, 0x2b8, 0x2bb, 
       0x5, 0x96, 0x4c, 0x2, 0x2b9, 0x2bb, 0x5, 0x8e, 0x48, 0x2, 0x2ba, 
       0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2bb, 
       0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bd, 0xc, 0x3, 0x2, 0x2, 0x2bd, 
       0x2be, 0x5, 0x6e, 0x38, 0x2, 0x2be, 0x2bf, 0x5, 0x8e, 0x48, 0x2, 
       0x2bf, 0x2c1, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2bc, 0x3, 0x2, 0x2, 0x2, 
       0x2c1, 0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c0, 0x3, 0x2, 0x2, 0x2, 
       0x2c2, 0x2c3, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x8d, 0x3, 0x2, 0x2, 0x2, 
       0x2c4, 0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2cb, 0x5, 0x72, 0x3a, 
       0x2, 0x2c6, 0x2c7, 0x5, 0x72, 0x3a, 0x2, 0x2c7, 0x2c8, 0x5, 0x6c, 
       0x37, 0x2, 0x2c8, 0x2c9, 0x5, 0x72, 0x3a, 0x2, 0x2c9, 0x2cb, 0x3, 
       0x2, 0x2, 0x2, 0x2ca, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2c6, 0x3, 
       0x2, 0x2, 0x2, 0x2cb, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2cd, 0x7, 
       0x61, 0x2, 0x2, 0x2cd, 0x2ce, 0x5, 0x72, 0x3a, 0x2, 0x2ce, 0x91, 
       0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2d0, 0x9, 0xf, 0x2, 0x2, 0x2d0, 0x93, 
       0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d2, 0x7, 0x6c, 0x2, 0x2, 0x2d2, 0x2d3, 
       0x5, 0x90, 0x49, 0x2, 0x2d3, 0x2d4, 0x7, 0x60, 0x2, 0x2, 0x2d4, 0x2d6, 
       0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d9, 
       0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d8, 
       0x3, 0x2, 0x2, 0x2, 0x2d8, 0x2da, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2d7, 
       0x3, 0x2, 0x2, 0x2, 0x2da, 0x2db, 0x7, 0x6c, 0x2, 0x2, 0x2db, 0x2dc, 
       0x5, 0x90, 0x49, 0x2, 0x2dc, 0x95, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2de, 
       0x7, 0x6c, 0x2, 0x2, 0x2de, 0x2df, 0x7, 0x41, 0x2, 0x2, 0x2df, 0x2e0, 
       0x5, 0x98, 0x4d, 0x2, 0x2e0, 0x97, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e2, 
       0x7, 0x59, 0x2, 0x2, 0x2e2, 0x2e3, 0x5, 0x8a, 0x46, 0x2, 0x2e3, 0x2e4, 
       0x7, 0x5a, 0x2, 0x2, 0x2e4, 0x2e8, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e8, 
       0x5, 0x4c, 0x27, 0x2, 0x2e6, 0x2e8, 0x7, 0x6c, 0x2, 0x2, 0x2e7, 0x2e1, 
       0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e5, 0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e6, 
       0x3, 0x2, 0x2, 0x2, 0x2e8, 0x99, 0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2f3, 
       0x5, 0xc, 0x7, 0x2, 0x2ea, 0x2ee, 0x7, 0x59, 0x2, 0x2, 0x2eb, 0x2ed, 
       0x5, 0xc, 0x7, 0x2, 0x2ec, 0x2eb, 0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2f0, 
       0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ef, 
       0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2f1, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2ee, 
       0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2f3, 0x7, 0x5a, 0x2, 0x2, 0x2f2, 0x2e9, 
       0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x9b, 
       0x3, 0x2, 0x2, 0x2, 0x2f4, 0x2f5, 0x7, 0x42, 0x2, 0x2, 0x2f5, 0x2f6, 
       0x7, 0x5b, 0x2, 0x2, 0x2f6, 0x2f7, 0x5, 0x8c, 0x47, 0x2, 0x2f7, 0x2f8, 
       0x7, 0x5c, 0x2, 0x2, 0x2f8, 0x2fb, 0x5, 0x9a, 0x4e, 0x2, 0x2f9, 0x2fa, 
       0x7, 0x43, 0x2, 0x2, 0x2fa, 0x2fc, 0x5, 0x9a, 0x4e, 0x2, 0x2fb, 0x2f9, 
       0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x9d, 
       0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2fe, 0x7, 0x44, 0x2, 0x2, 0x2fe, 0x305, 
       0x5, 0x96, 0x4c, 0x2, 0x2ff, 0x300, 0x7, 0x45, 0x2, 0x2, 0x300, 0x301, 
       0x7, 0x5b, 0x2, 0x2, 0x301, 0x302, 0x5, 0x8c, 0x47, 0x2, 0x302, 0x303, 
       0x7, 0x5c, 0x2, 0x2, 0x303, 0x305, 0x3, 0x2, 0x2, 0x2, 0x304, 0x2fd, 
       0x3, 0x2, 0x2, 0x2, 0x304, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x305, 0x9f, 
       0x3, 0x2, 0x2, 0x2, 0x306, 0x307, 0x5, 0x9e, 0x50, 0x2, 0x307, 0x308, 
       0x5, 0x9a, 0x4e, 0x2, 0x308, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x309, 0x30a, 
       0x5, 0xa4, 0x53, 0x2, 0x30a, 0x30b, 0x7, 0x5e, 0x2, 0x2, 0x30b, 0xa3, 
       0x3, 0x2, 0x2, 0x2, 0x30c, 0x30d, 0x9, 0x10, 0x2, 0x2, 0x30d, 0xa5, 
       0x3, 0x2, 0x2, 0x2, 0x30e, 0x30f, 0x7, 0x49, 0x2, 0x2, 0x30f, 0x315, 
       0x7, 0x6c, 0x2, 0x2, 0x310, 0x312, 0x7, 0x5b, 0x2, 0x2, 0x311, 0x313, 
       0x5, 0x3e, 0x20, 0x2, 0x312, 0x311, 0x3, 0x2, 0x2, 0x2, 0x312, 0x313, 
       0x3, 0x2, 0x2, 0x2, 0x313, 0x314, 0x3, 0x2, 0x2, 0x2, 0x314, 0x316, 
       0x7, 0x5c, 0x2, 0x2, 0x315, 0x310, 0x3, 0x2, 0x2, 0x2, 0x315, 0x316, 
       0x3, 0x2, 0x2, 0x2, 0x316, 0x318, 0x3, 0x2, 0x2, 0x2, 0x317, 0x319, 
       0x5, 0x16, 0xc, 0x2, 0x318, 0x317, 0x3, 0x2, 0x2, 0x2, 0x318, 0x319, 
       0x3, 0x2, 0x2, 0x2, 0x319, 0x31b, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x31c, 
       0x5, 0x30, 0x19, 0x2, 0x31b, 0x31a, 0x3, 0x2, 0x2, 0x2, 0x31b, 0x31c, 
       0x3, 0x2, 0x2, 0x2, 0x31c, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x31d, 0x31e, 
       0x7, 0x5e, 0x2, 0x2, 0x31e, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x31f, 0x320, 
       0x7, 0x6c, 0x2, 0x2, 0x320, 0x322, 0x7, 0x5b, 0x2, 0x2, 0x321, 0x323, 
       0x5, 0x8a, 0x46, 0x2, 0x322, 0x321, 0x3, 0x2, 0x2, 0x2, 0x322, 0x323, 
       0x3, 0x2, 0x2, 0x2, 0x323, 0x324, 0x3, 0x2, 0x2, 0x2, 0x324, 0x325, 
       0x7, 0x5c, 0x2, 0x2, 0x325, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x326, 0x327, 
       0x7, 0x4a, 0x2, 0x2, 0x327, 0x32d, 0x7, 0x6c, 0x2, 0x2, 0x328, 0x32a, 
       0x7, 0x5b, 0x2, 0x2, 0x329, 0x32b, 0x5, 0x42, 0x22, 0x2, 0x32a, 0x329, 
       0x3, 0x2, 0x2, 0x2, 0x32a, 0x32b, 0x3, 0x2, 0x2, 0x2, 0x32b, 0x32c, 
       0x3, 0x2, 0x2, 0x2, 0x32c, 0x32e, 0x7, 0x5c, 0x2, 0x2, 0x32d, 0x328, 
       0x3, 0x2, 0x2, 0x2, 0x32d, 0x32e, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x330, 
       0x3, 0x2, 0x2, 0x2, 0x32f, 0x331, 0x5, 0x26, 0x14, 0x2, 0x330, 0x32f, 
       0x3, 0x2, 0x2, 0x2, 0x330, 0x331, 0x3, 0x2, 0x2, 0x2, 0x331, 0x333, 
       0x3, 0x2, 0x2, 0x2, 0x332, 0x334, 0x5, 0x16, 0xc, 0x2, 0x333, 0x332, 
       0x3, 0x2, 0x2, 0x2, 0x333, 0x334, 0x3, 0x2, 0x2, 0x2, 0x334, 0x335, 
       0x3, 0x2, 0x2, 0x2, 0x335, 0x336, 0x5, 0xae, 0x58, 0x2, 0x336, 0xab, 
       0x3, 0x2, 0x2, 0x2, 0x337, 0x338, 0x7, 0x4b, 0x2, 0x2, 0x338, 0x339, 
       0x5, 0xc, 0x7, 0x2, 0x339, 0xad, 0x3, 0x2, 0x2, 0x2, 0x33a, 0x33e, 
       0x7, 0x59, 0x2, 0x2, 0x33b, 0x33d, 0x5, 0xc, 0x7, 0x2, 0x33c, 0x33b, 
       0x3, 0x2, 0x2, 0x2, 0x33d, 0x340, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x33c, 
       0x3, 0x2, 0x2, 0x2, 0x33e, 0x33f, 0x3, 0x2, 0x2, 0x2, 0x33f, 0x342, 
       0x3, 0x2, 0x2, 0x2, 0x340, 0x33e, 0x3, 0x2, 0x2, 0x2, 0x341, 0x343, 
       0x5, 0xac, 0x57, 0x2, 0x342, 0x341, 0x3, 0x2, 0x2, 0x2, 0x342, 0x343, 
       0x3, 0x2, 0x2, 0x2, 0x343, 0x344, 0x3, 0x2, 0x2, 0x2, 0x344, 0x345, 
       0x7, 0x5a, 0x2, 0x2, 0x345, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x346, 0x34c, 
       0x7, 0x6c, 0x2, 0x2, 0x347, 0x349, 0x7, 0x5b, 0x2, 0x2, 0x348, 0x34a, 
       0x5, 0x8a, 0x46, 0x2, 0x349, 0x348, 0x3, 0x2, 0x2, 0x2, 0x349, 0x34a, 
       0x3, 0x2, 0x2, 0x2, 0x34a, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x34d, 
       0x7, 0x5c, 0x2, 0x2, 0x34c, 0x347, 0x3, 0x2, 0x2, 0x2, 0x34c, 0x34d, 
       0x3, 0x2, 0x2, 0x2, 0x34d, 0x34e, 0x3, 0x2, 0x2, 0x2, 0x34e, 0x34f, 
       0x5, 0x8a, 0x46, 0x2, 0x34f, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x350, 0x351, 
       0x7, 0x4c, 0x2, 0x2, 0x351, 0x355, 0x7, 0x59, 0x2, 0x2, 0x352, 0x354, 
       0x5, 0xc, 0x7, 0x2, 0x353, 0x352, 0x3, 0x2, 0x2, 0x2, 0x354, 0x357, 
       0x3, 0x2, 0x2, 0x2, 0x355, 0x353, 0x3, 0x2, 0x2, 0x2, 0x355, 0x356, 
       0x3, 0x2, 0x2, 0x2, 0x356, 0x358, 0x3, 0x2, 0x2, 0x2, 0x357, 0x355, 
       0x3, 0x2, 0x2, 0x2, 0x358, 0x359, 0x7, 0x5a, 0x2, 0x2, 0x359, 0xb3, 
       0x3, 0x2, 0x2, 0x2, 0x35a, 0x360, 0x7, 0x4d, 0x2, 0x2, 0x35b, 0x35d, 
       0x7, 0x4e, 0x2, 0x2, 0x35c, 0x35e, 0x7, 0x6b, 0x2, 0x2, 0x35d, 0x35c, 
       0x3, 0x2, 0x2, 0x2, 0x35d, 0x35e, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x360, 
       0x3, 0x2, 0x2, 0x2, 0x35f, 0x35a, 0x3, 0x2, 0x2, 0x2, 0x35f, 0x35b, 
       0x3, 0x2, 0x2, 0x2, 0x360, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x361, 0x362, 
       0x7, 0x4f, 0x2, 0x2, 0x362, 0x363, 0x7, 0x6c, 0x2, 0x2, 0x363, 0x368, 
       0x5, 0x52, 0x2a, 0x2, 0x364, 0x365, 0x7, 0x50, 0x2, 0x2, 0x365, 0x366, 
       0x7, 0x6e, 0x2, 0x2, 0x366, 0x368, 0x5, 0x52, 0x2a, 0x2, 0x367, 0x361, 
       0x3, 0x2, 0x2, 0x2, 0x367, 0x364, 0x3, 0x2, 0x2, 0x2, 0x368, 0xb7, 
       0x3, 0x2, 0x2, 0x2, 0x369, 0x36c, 0x5, 0xba, 0x5e, 0x2, 0x36a, 0x36c, 
       0x7, 0x51, 0x2, 0x2, 0x36b, 0x369, 0x3, 0x2, 0x2, 0x2, 0x36b, 0x36a, 
       0x3, 0x2, 0x2, 0x2, 0x36c, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x36d, 0x376, 
       0x7, 0x6e, 0x2, 0x2, 0x36e, 0x36f, 0x7, 0x36, 0x2, 0x2, 0x36f, 0x372, 
       0x7, 0x5b, 0x2, 0x2, 0x370, 0x373, 0x7, 0x6c, 0x2, 0x2, 0x371, 0x373, 
       0x5, 0x52, 0x2a, 0x2, 0x372, 0x370, 0x3, 0x2, 0x2, 0x2, 0x372, 0x371, 
       0x3, 0x2, 0x2, 0x2, 0x373, 0x374, 0x3, 0x2, 0x2, 0x2, 0x374, 0x376, 
       0x7, 0x5c, 0x2, 0x2, 0x375, 0x36d, 0x3, 0x2, 0x2, 0x2, 0x375, 0x36e, 
       0x3, 0x2, 0x2, 0x2, 0x376, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x377, 0x378, 
       0x9, 0x11, 0x2, 0x2, 0x378, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x379, 0x37f, 
       0x5, 0xbc, 0x5f, 0x2, 0x37a, 0x37c, 0x7, 0x5b, 0x2, 0x2, 0x37b, 0x37d, 
       0x5, 0x8a, 0x46, 0x2, 0x37c, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x37c, 0x37d, 
       0x3, 0x2, 0x2, 0x2, 0x37d, 0x37e, 0x3, 0x2, 0x2, 0x2, 0x37e, 0x380, 
       0x7, 0x5c, 0x2, 0x2, 0x37f, 0x37a, 0x3, 0x2, 0x2, 0x2, 0x37f, 0x380, 
       0x3, 0x2, 0x2, 0x2, 0x380, 0x381, 0x3, 0x2, 0x2, 0x2, 0x381, 0x382, 
       0x5, 0x18, 0xd, 0x2, 0x382, 0x383, 0x5, 0x48, 0x25, 0x2, 0x383, 0xbf, 
       0x3, 0x2, 0x2, 0x2, 0x384, 0x385, 0x5, 0xbe, 0x60, 0x2, 0x385, 0x386, 
       0x7, 0x5e, 0x2, 0x2, 0x386, 0x389, 0x3, 0x2, 0x2, 0x2, 0x387, 0x389, 
       0x5, 0xb6, 0x5c, 0x2, 0x388, 0x384, 0x3, 0x2, 0x2, 0x2, 0x388, 0x387, 
       0x3, 0x2, 0x2, 0x2, 0x389, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x38d, 
       0x5, 0xc4, 0x63, 0x2, 0x38b, 0x38d, 0x5, 0xc6, 0x64, 0x2, 0x38c, 
       0x38a, 0x3, 0x2, 0x2, 0x2, 0x38c, 0x38b, 0x3, 0x2, 0x2, 0x2, 0x38d, 
       0xc3, 0x3, 0x2, 0x2, 0x2, 0x38e, 0x38f, 0x7, 0x54, 0x2, 0x2, 0x38f, 
       0x390, 0x5, 0xc8, 0x65, 0x2, 0x390, 0x391, 0x7, 0x5e, 0x2, 0x2, 0x391, 
       0xc5, 0x3, 0x2, 0x2, 0x2, 0x392, 0x393, 0x7, 0x55, 0x2, 0x2, 0x393, 
       0x399, 0x7, 0x6c, 0x2, 0x2, 0x394, 0x396, 0x7, 0x5b, 0x2, 0x2, 0x395, 
       0x397, 0x5, 0xca, 0x66, 0x2, 0x396, 0x395, 0x3, 0x2, 0x2, 0x2, 0x396, 
       0x397, 0x3, 0x2, 0x2, 0x2, 0x397, 0x398, 0x3, 0x2, 0x2, 0x2, 0x398, 
       0x39a, 0x7, 0x5c, 0x2, 0x2, 0x399, 0x394, 0x3, 0x2, 0x2, 0x2, 0x399, 
       0x39a, 0x3, 0x2, 0x2, 0x2, 0x39a, 0x39b, 0x3, 0x2, 0x2, 0x2, 0x39b, 
       0x39d, 0x5, 0x1c, 0xf, 0x2, 0x39c, 0x39e, 0x5, 0x16, 0xc, 0x2, 0x39d, 
       0x39c, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x39e, 0x3, 0x2, 0x2, 0x2, 0x39e, 
       0x39f, 0x3, 0x2, 0x2, 0x2, 0x39f, 0x3a3, 0x7, 0x59, 0x2, 0x2, 0x3a0, 
       0x3a2, 0xb, 0x2, 0x2, 0x2, 0x3a1, 0x3a0, 0x3, 0x2, 0x2, 0x2, 0x3a2, 
       0x3a5, 0x3, 0x2, 0x2, 0x2, 0x3a3, 0x3a4, 0x3, 0x2, 0x2, 0x2, 0x3a3, 
       0x3a1, 0x3, 0x2, 0x2, 0x2, 0x3a4, 0x3a6, 0x3, 0x2, 0x2, 0x2, 0x3a5, 
       0x3a3, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x3a7, 0x7, 0x5a, 0x2, 0x2, 0x3a7, 
       0xc7, 0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3a9, 0x9, 0x12, 0x2, 0x2, 0x3a9, 
       0xc9, 0x3, 0x2, 0x2, 0x2, 0x3aa, 0x3ad, 0x5, 0x42, 0x22, 0x2, 0x3ab, 
       0x3ad, 0x5, 0x8a, 0x46, 0x2, 0x3ac, 0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3ac, 
       0x3ab, 0x3, 0x2, 0x2, 0x2, 0x3ad, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x62, 
       0xcf, 0xd1, 0xd5, 0xda, 0xeb, 0xf5, 0xfc, 0x104, 0x108, 0x11d, 0x12c, 
       0x135, 0x142, 0x14d, 0x14f, 0x158, 0x15e, 0x163, 0x168, 0x16e, 0x175, 
       0x182, 0x195, 0x197, 0x19e, 0x1a6, 0x1b1, 0x1b9, 0x1bd, 0x1c1, 0x1cc, 
       0x1cf, 0x1d6, 0x1d8, 0x1e5, 0x1e9, 0x1ef, 0x1f5, 0x202, 0x208, 0x214, 
       0x21b, 0x21e, 0x229, 0x238, 0x23f, 0x24a, 0x255, 0x260, 0x26b, 0x271, 
       0x277, 0x27b, 0x291, 0x29a, 0x29c, 0x2a3, 0x2b2, 0x2ba, 0x2c2, 0x2ca, 
       0x2d7, 0x2e7, 0x2ee, 0x2f2, 0x2fb, 0x304, 0x312, 0x315, 0x318, 0x31b, 
       0x322, 0x32a, 0x32d, 0x330, 0x333, 0x33e, 0x342, 0x349, 0x34c, 0x355, 
       0x35d, 0x35f, 0x367, 0x36b, 0x372, 0x375, 0x37c, 0x37f, 0x388, 0x38c, 
       0x396, 0x399, 0x39d, 0x3a3, 0x3ac, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

qasm3Parser::Initializer qasm3Parser::_init;
