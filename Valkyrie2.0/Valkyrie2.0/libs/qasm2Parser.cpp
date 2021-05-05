
// Generated from qasm2.g4 by ANTLR 4.9.2


#include "qasm2Visitor.h"

#include "qasm2Parser.h"


using namespace antlrcpp;
using namespace antlr4;

qasm2Parser::qasm2Parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

qasm2Parser::~qasm2Parser() {
  delete _interpreter;
}

std::string qasm2Parser::getGrammarFileName() const {
  return "qasm2.g4";
}

const std::vector<std::string>& qasm2Parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& qasm2Parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- MainprogContext ------------------------------------------------------------------

qasm2Parser::MainprogContext::MainprogContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm2Parser::VersionContext* qasm2Parser::MainprogContext::version() {
  return getRuleContext<qasm2Parser::VersionContext>(0);
}

std::vector<qasm2Parser::StatementContext *> qasm2Parser::MainprogContext::statement() {
  return getRuleContexts<qasm2Parser::StatementContext>();
}

qasm2Parser::StatementContext* qasm2Parser::MainprogContext::statement(size_t i) {
  return getRuleContext<qasm2Parser::StatementContext>(i);
}


size_t qasm2Parser::MainprogContext::getRuleIndex() const {
  return qasm2Parser::RuleMainprog;
}


antlrcpp::Any qasm2Parser::MainprogContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm2Visitor*>(visitor))
    return parserVisitor->visitMainprog(this);
  else
    return visitor->visitChildren(this);
}

qasm2Parser::MainprogContext* qasm2Parser::mainprog() {
  MainprogContext *_localctx = _tracker.createInstance<MainprogContext>(_ctx, getState());
  enterRule(_localctx, 0, qasm2Parser::RuleMainprog);
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
    setState(30);
    version();
    setState(34);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm2Parser::T__1)
      | (1ULL << qasm2Parser::T__5)
      | (1ULL << qasm2Parser::T__7)
      | (1ULL << qasm2Parser::T__9)
      | (1ULL << qasm2Parser::T__12)
      | (1ULL << qasm2Parser::T__13)
      | (1ULL << qasm2Parser::T__15)
      | (1ULL << qasm2Parser::T__17)
      | (1ULL << qasm2Parser::T__18)
      | (1ULL << qasm2Parser::T__19)
      | (1ULL << qasm2Parser::ID))) != 0)) {
      setState(31);
      statement();
      setState(36);
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

//----------------- StatementContext ------------------------------------------------------------------

qasm2Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm2Parser::DeclContext* qasm2Parser::StatementContext::decl() {
  return getRuleContext<qasm2Parser::DeclContext>(0);
}

qasm2Parser::GatedeclContext* qasm2Parser::StatementContext::gatedecl() {
  return getRuleContext<qasm2Parser::GatedeclContext>(0);
}

qasm2Parser::GoplistContext* qasm2Parser::StatementContext::goplist() {
  return getRuleContext<qasm2Parser::GoplistContext>(0);
}

tree::TerminalNode* qasm2Parser::StatementContext::ID() {
  return getToken(qasm2Parser::ID, 0);
}

std::vector<qasm2Parser::IdlistContext *> qasm2Parser::StatementContext::idlist() {
  return getRuleContexts<qasm2Parser::IdlistContext>();
}

qasm2Parser::IdlistContext* qasm2Parser::StatementContext::idlist(size_t i) {
  return getRuleContext<qasm2Parser::IdlistContext>(i);
}

qasm2Parser::QopContext* qasm2Parser::StatementContext::qop() {
  return getRuleContext<qasm2Parser::QopContext>(0);
}

tree::TerminalNode* qasm2Parser::StatementContext::INT() {
  return getToken(qasm2Parser::INT, 0);
}

qasm2Parser::AnylistContext* qasm2Parser::StatementContext::anylist() {
  return getRuleContext<qasm2Parser::AnylistContext>(0);
}


size_t qasm2Parser::StatementContext::getRuleIndex() const {
  return qasm2Parser::RuleStatement;
}


antlrcpp::Any qasm2Parser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm2Visitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm2Parser::StatementContext* qasm2Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, qasm2Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(77);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(37);
      decl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(38);
      gatedecl();
      setState(39);
      goplist();
      setState(40);
      match(qasm2Parser::T__0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(42);
      gatedecl();
      setState(43);
      match(qasm2Parser::T__0);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(45);
      match(qasm2Parser::T__1);
      setState(46);
      match(qasm2Parser::ID);
      setState(47);
      idlist();
      setState(48);
      match(qasm2Parser::T__2);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(50);
      match(qasm2Parser::T__1);
      setState(51);
      match(qasm2Parser::ID);
      setState(52);
      match(qasm2Parser::T__3);
      setState(53);
      match(qasm2Parser::T__4);
      setState(54);
      idlist();
      setState(55);
      match(qasm2Parser::T__2);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(57);
      match(qasm2Parser::T__1);
      setState(58);
      match(qasm2Parser::ID);
      setState(59);
      match(qasm2Parser::T__3);
      setState(60);
      idlist();
      setState(61);
      match(qasm2Parser::T__4);
      setState(62);
      idlist();
      setState(63);
      match(qasm2Parser::T__2);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(65);
      qop();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(66);
      match(qasm2Parser::T__5);
      setState(67);
      match(qasm2Parser::T__3);
      setState(68);
      match(qasm2Parser::ID);
      setState(69);
      match(qasm2Parser::T__6);
      setState(70);
      match(qasm2Parser::INT);
      setState(71);
      match(qasm2Parser::T__4);
      setState(72);
      qop();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(73);
      match(qasm2Parser::T__7);
      setState(74);
      anylist();
      setState(75);
      match(qasm2Parser::T__2);
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

//----------------- VersionContext ------------------------------------------------------------------

qasm2Parser::VersionContext::VersionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm2Parser::VersionContext::REAL() {
  return getToken(qasm2Parser::REAL, 0);
}


size_t qasm2Parser::VersionContext::getRuleIndex() const {
  return qasm2Parser::RuleVersion;
}


antlrcpp::Any qasm2Parser::VersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm2Visitor*>(visitor))
    return parserVisitor->visitVersion(this);
  else
    return visitor->visitChildren(this);
}

qasm2Parser::VersionContext* qasm2Parser::version() {
  VersionContext *_localctx = _tracker.createInstance<VersionContext>(_ctx, getState());
  enterRule(_localctx, 4, qasm2Parser::RuleVersion);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    match(qasm2Parser::T__8);
    setState(80);
    match(qasm2Parser::REAL);
    setState(81);
    match(qasm2Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

qasm2Parser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm2Parser::DeclContext::ID() {
  return getToken(qasm2Parser::ID, 0);
}

tree::TerminalNode* qasm2Parser::DeclContext::INT() {
  return getToken(qasm2Parser::INT, 0);
}


size_t qasm2Parser::DeclContext::getRuleIndex() const {
  return qasm2Parser::RuleDecl;
}


antlrcpp::Any qasm2Parser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm2Visitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

qasm2Parser::DeclContext* qasm2Parser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 6, qasm2Parser::RuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(95);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm2Parser::T__9: {
        enterOuterAlt(_localctx, 1);
        setState(83);
        match(qasm2Parser::T__9);
        setState(84);
        match(qasm2Parser::ID);
        setState(85);
        match(qasm2Parser::T__10);
        setState(86);
        match(qasm2Parser::INT);
        setState(87);
        match(qasm2Parser::T__11);
        setState(88);
        match(qasm2Parser::T__2);
        break;
      }

      case qasm2Parser::T__12: {
        enterOuterAlt(_localctx, 2);
        setState(89);
        match(qasm2Parser::T__12);
        setState(90);
        match(qasm2Parser::ID);
        setState(91);
        match(qasm2Parser::T__10);
        setState(92);
        match(qasm2Parser::INT);
        setState(93);
        match(qasm2Parser::T__11);
        setState(94);
        match(qasm2Parser::T__2);
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

//----------------- GatedeclContext ------------------------------------------------------------------

qasm2Parser::GatedeclContext::GatedeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm2Parser::GatedeclContext::ID() {
  return getToken(qasm2Parser::ID, 0);
}

std::vector<qasm2Parser::IdlistContext *> qasm2Parser::GatedeclContext::idlist() {
  return getRuleContexts<qasm2Parser::IdlistContext>();
}

qasm2Parser::IdlistContext* qasm2Parser::GatedeclContext::idlist(size_t i) {
  return getRuleContext<qasm2Parser::IdlistContext>(i);
}


size_t qasm2Parser::GatedeclContext::getRuleIndex() const {
  return qasm2Parser::RuleGatedecl;
}


antlrcpp::Any qasm2Parser::GatedeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm2Visitor*>(visitor))
    return parserVisitor->visitGatedecl(this);
  else
    return visitor->visitChildren(this);
}

qasm2Parser::GatedeclContext* qasm2Parser::gatedecl() {
  GatedeclContext *_localctx = _tracker.createInstance<GatedeclContext>(_ctx, getState());
  enterRule(_localctx, 8, qasm2Parser::RuleGatedecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(117);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(97);
      match(qasm2Parser::T__13);
      setState(98);
      match(qasm2Parser::ID);
      setState(99);
      idlist();
      setState(100);
      match(qasm2Parser::T__14);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(102);
      match(qasm2Parser::T__13);
      setState(103);
      match(qasm2Parser::ID);
      setState(104);
      match(qasm2Parser::T__3);
      setState(105);
      match(qasm2Parser::T__4);
      setState(106);
      idlist();
      setState(107);
      match(qasm2Parser::T__14);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(109);
      match(qasm2Parser::T__13);
      setState(110);
      match(qasm2Parser::ID);
      setState(111);
      match(qasm2Parser::T__3);
      setState(112);
      idlist();
      setState(113);
      match(qasm2Parser::T__4);
      setState(114);
      idlist();
      setState(115);
      match(qasm2Parser::T__14);
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

//----------------- GoplistContext ------------------------------------------------------------------

qasm2Parser::GoplistContext::GoplistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm2Parser::UopContext *> qasm2Parser::GoplistContext::uop() {
  return getRuleContexts<qasm2Parser::UopContext>();
}

qasm2Parser::UopContext* qasm2Parser::GoplistContext::uop(size_t i) {
  return getRuleContext<qasm2Parser::UopContext>(i);
}

std::vector<qasm2Parser::IdlistContext *> qasm2Parser::GoplistContext::idlist() {
  return getRuleContexts<qasm2Parser::IdlistContext>();
}

qasm2Parser::IdlistContext* qasm2Parser::GoplistContext::idlist(size_t i) {
  return getRuleContext<qasm2Parser::IdlistContext>(i);
}


size_t qasm2Parser::GoplistContext::getRuleIndex() const {
  return qasm2Parser::RuleGoplist;
}


antlrcpp::Any qasm2Parser::GoplistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm2Visitor*>(visitor))
    return parserVisitor->visitGoplist(this);
  else
    return visitor->visitChildren(this);
}

qasm2Parser::GoplistContext* qasm2Parser::goplist() {
  GoplistContext *_localctx = _tracker.createInstance<GoplistContext>(_ctx, getState());
  enterRule(_localctx, 10, qasm2Parser::RuleGoplist);
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
    setState(124); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(124);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case qasm2Parser::T__18:
        case qasm2Parser::T__19:
        case qasm2Parser::ID: {
          setState(119);
          uop();
          break;
        }

        case qasm2Parser::T__7: {
          setState(120);
          match(qasm2Parser::T__7);
          setState(121);
          idlist();
          setState(122);
          match(qasm2Parser::T__2);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(126); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm2Parser::T__7)
      | (1ULL << qasm2Parser::T__18)
      | (1ULL << qasm2Parser::T__19)
      | (1ULL << qasm2Parser::ID))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QopContext ------------------------------------------------------------------

qasm2Parser::QopContext::QopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm2Parser::UopContext* qasm2Parser::QopContext::uop() {
  return getRuleContext<qasm2Parser::UopContext>(0);
}

std::vector<qasm2Parser::ArgumentContext *> qasm2Parser::QopContext::argument() {
  return getRuleContexts<qasm2Parser::ArgumentContext>();
}

qasm2Parser::ArgumentContext* qasm2Parser::QopContext::argument(size_t i) {
  return getRuleContext<qasm2Parser::ArgumentContext>(i);
}


size_t qasm2Parser::QopContext::getRuleIndex() const {
  return qasm2Parser::RuleQop;
}


antlrcpp::Any qasm2Parser::QopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm2Visitor*>(visitor))
    return parserVisitor->visitQop(this);
  else
    return visitor->visitChildren(this);
}

qasm2Parser::QopContext* qasm2Parser::qop() {
  QopContext *_localctx = _tracker.createInstance<QopContext>(_ctx, getState());
  enterRule(_localctx, 12, qasm2Parser::RuleQop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(139);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm2Parser::T__18:
      case qasm2Parser::T__19:
      case qasm2Parser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(128);
        uop();
        break;
      }

      case qasm2Parser::T__15: {
        enterOuterAlt(_localctx, 2);
        setState(129);
        match(qasm2Parser::T__15);
        setState(130);
        argument();
        setState(131);
        match(qasm2Parser::T__16);
        setState(132);
        argument();
        setState(133);
        match(qasm2Parser::T__2);
        break;
      }

      case qasm2Parser::T__17: {
        enterOuterAlt(_localctx, 3);
        setState(135);
        match(qasm2Parser::T__17);
        setState(136);
        argument();
        setState(137);
        match(qasm2Parser::T__2);
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

//----------------- UopContext ------------------------------------------------------------------

qasm2Parser::UopContext::UopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm2Parser::ExplistContext* qasm2Parser::UopContext::explist() {
  return getRuleContext<qasm2Parser::ExplistContext>(0);
}

std::vector<qasm2Parser::ArgumentContext *> qasm2Parser::UopContext::argument() {
  return getRuleContexts<qasm2Parser::ArgumentContext>();
}

qasm2Parser::ArgumentContext* qasm2Parser::UopContext::argument(size_t i) {
  return getRuleContext<qasm2Parser::ArgumentContext>(i);
}

tree::TerminalNode* qasm2Parser::UopContext::ID() {
  return getToken(qasm2Parser::ID, 0);
}

qasm2Parser::AnylistContext* qasm2Parser::UopContext::anylist() {
  return getRuleContext<qasm2Parser::AnylistContext>(0);
}


size_t qasm2Parser::UopContext::getRuleIndex() const {
  return qasm2Parser::RuleUop;
}


antlrcpp::Any qasm2Parser::UopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm2Visitor*>(visitor))
    return parserVisitor->visitUop(this);
  else
    return visitor->visitChildren(this);
}

qasm2Parser::UopContext* qasm2Parser::uop() {
  UopContext *_localctx = _tracker.createInstance<UopContext>(_ctx, getState());
  enterRule(_localctx, 14, qasm2Parser::RuleUop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(171);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(141);
      match(qasm2Parser::T__18);
      setState(142);
      match(qasm2Parser::T__3);
      setState(143);
      explist();
      setState(144);
      match(qasm2Parser::T__4);
      setState(145);
      argument();
      setState(146);
      match(qasm2Parser::T__2);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(148);
      match(qasm2Parser::T__19);
      setState(149);
      argument();
      setState(150);
      match(qasm2Parser::T__20);
      setState(151);
      argument();
      setState(152);
      match(qasm2Parser::T__2);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(154);
      match(qasm2Parser::ID);
      setState(155);
      anylist();
      setState(156);
      match(qasm2Parser::T__2);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(158);
      match(qasm2Parser::ID);
      setState(159);
      match(qasm2Parser::T__3);
      setState(160);
      match(qasm2Parser::T__4);
      setState(161);
      anylist();
      setState(162);
      match(qasm2Parser::T__2);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(164);
      match(qasm2Parser::ID);
      setState(165);
      match(qasm2Parser::T__3);
      setState(166);
      explist();
      setState(167);
      match(qasm2Parser::T__4);
      setState(168);
      anylist();
      setState(169);
      match(qasm2Parser::T__2);
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

//----------------- AnylistContext ------------------------------------------------------------------

qasm2Parser::AnylistContext::AnylistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm2Parser::IdlistContext* qasm2Parser::AnylistContext::idlist() {
  return getRuleContext<qasm2Parser::IdlistContext>(0);
}

qasm2Parser::MixedlistContext* qasm2Parser::AnylistContext::mixedlist() {
  return getRuleContext<qasm2Parser::MixedlistContext>(0);
}


size_t qasm2Parser::AnylistContext::getRuleIndex() const {
  return qasm2Parser::RuleAnylist;
}


antlrcpp::Any qasm2Parser::AnylistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm2Visitor*>(visitor))
    return parserVisitor->visitAnylist(this);
  else
    return visitor->visitChildren(this);
}

qasm2Parser::AnylistContext* qasm2Parser::anylist() {
  AnylistContext *_localctx = _tracker.createInstance<AnylistContext>(_ctx, getState());
  enterRule(_localctx, 16, qasm2Parser::RuleAnylist);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(175);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(173);
      idlist();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(174);
      mixedlist();
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

//----------------- IdlistContext ------------------------------------------------------------------

qasm2Parser::IdlistContext::IdlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> qasm2Parser::IdlistContext::ID() {
  return getTokens(qasm2Parser::ID);
}

tree::TerminalNode* qasm2Parser::IdlistContext::ID(size_t i) {
  return getToken(qasm2Parser::ID, i);
}


size_t qasm2Parser::IdlistContext::getRuleIndex() const {
  return qasm2Parser::RuleIdlist;
}


antlrcpp::Any qasm2Parser::IdlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm2Visitor*>(visitor))
    return parserVisitor->visitIdlist(this);
  else
    return visitor->visitChildren(this);
}

qasm2Parser::IdlistContext* qasm2Parser::idlist() {
  IdlistContext *_localctx = _tracker.createInstance<IdlistContext>(_ctx, getState());
  enterRule(_localctx, 18, qasm2Parser::RuleIdlist);

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
    setState(181);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(177);
        match(qasm2Parser::ID);
        setState(178);
        match(qasm2Parser::T__20); 
      }
      setState(183);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
    setState(184);
    match(qasm2Parser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MixedlistContext ------------------------------------------------------------------

qasm2Parser::MixedlistContext::MixedlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> qasm2Parser::MixedlistContext::ID() {
  return getTokens(qasm2Parser::ID);
}

tree::TerminalNode* qasm2Parser::MixedlistContext::ID(size_t i) {
  return getToken(qasm2Parser::ID, i);
}

std::vector<tree::TerminalNode *> qasm2Parser::MixedlistContext::INT() {
  return getTokens(qasm2Parser::INT);
}

tree::TerminalNode* qasm2Parser::MixedlistContext::INT(size_t i) {
  return getToken(qasm2Parser::INT, i);
}


size_t qasm2Parser::MixedlistContext::getRuleIndex() const {
  return qasm2Parser::RuleMixedlist;
}


antlrcpp::Any qasm2Parser::MixedlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm2Visitor*>(visitor))
    return parserVisitor->visitMixedlist(this);
  else
    return visitor->visitChildren(this);
}

qasm2Parser::MixedlistContext* qasm2Parser::mixedlist() {
  MixedlistContext *_localctx = _tracker.createInstance<MixedlistContext>(_ctx, getState());
  enterRule(_localctx, 20, qasm2Parser::RuleMixedlist);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(229);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(193);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(186);
          match(qasm2Parser::ID);
          setState(187);
          match(qasm2Parser::T__10);
          setState(188);
          match(qasm2Parser::INT);
          setState(189);
          match(qasm2Parser::T__11);
          setState(190);
          match(qasm2Parser::T__20); 
        }
        setState(195);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
      }
      setState(196);
      match(qasm2Parser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(204);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(197);
          match(qasm2Parser::ID);
          setState(198);
          match(qasm2Parser::T__10);
          setState(199);
          match(qasm2Parser::INT);
          setState(200);
          match(qasm2Parser::T__11);
          setState(201);
          match(qasm2Parser::T__20); 
        }
        setState(206);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
      }
      setState(207);
      match(qasm2Parser::ID);
      setState(208);
      match(qasm2Parser::T__10);
      setState(209);
      match(qasm2Parser::INT);
      setState(210);
      match(qasm2Parser::T__11);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(222);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(215);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(211);
              match(qasm2Parser::ID);
              setState(212);
              match(qasm2Parser::T__20); 
            }
            setState(217);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
          }
          setState(218);
          match(qasm2Parser::ID);
          setState(219);
          match(qasm2Parser::T__20); 
        }
        setState(224);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      }
      setState(225);
      match(qasm2Parser::ID);
      setState(226);
      match(qasm2Parser::T__10);
      setState(227);
      match(qasm2Parser::INT);
      setState(228);
      match(qasm2Parser::T__11);
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

//----------------- ArgumentContext ------------------------------------------------------------------

qasm2Parser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm2Parser::ArgumentContext::ID() {
  return getToken(qasm2Parser::ID, 0);
}

tree::TerminalNode* qasm2Parser::ArgumentContext::INT() {
  return getToken(qasm2Parser::INT, 0);
}


size_t qasm2Parser::ArgumentContext::getRuleIndex() const {
  return qasm2Parser::RuleArgument;
}


antlrcpp::Any qasm2Parser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm2Visitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

qasm2Parser::ArgumentContext* qasm2Parser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 22, qasm2Parser::RuleArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(236);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(231);
      match(qasm2Parser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(232);
      match(qasm2Parser::ID);
      setState(233);
      match(qasm2Parser::T__10);
      setState(234);
      match(qasm2Parser::INT);
      setState(235);
      match(qasm2Parser::T__11);
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

//----------------- ExplistContext ------------------------------------------------------------------

qasm2Parser::ExplistContext::ExplistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm2Parser::ExpContext *> qasm2Parser::ExplistContext::exp() {
  return getRuleContexts<qasm2Parser::ExpContext>();
}

qasm2Parser::ExpContext* qasm2Parser::ExplistContext::exp(size_t i) {
  return getRuleContext<qasm2Parser::ExpContext>(i);
}


size_t qasm2Parser::ExplistContext::getRuleIndex() const {
  return qasm2Parser::RuleExplist;
}


antlrcpp::Any qasm2Parser::ExplistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm2Visitor*>(visitor))
    return parserVisitor->visitExplist(this);
  else
    return visitor->visitChildren(this);
}

qasm2Parser::ExplistContext* qasm2Parser::explist() {
  ExplistContext *_localctx = _tracker.createInstance<ExplistContext>(_ctx, getState());
  enterRule(_localctx, 24, qasm2Parser::RuleExplist);

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
    setState(243);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(238);
        exp(0);
        setState(239);
        match(qasm2Parser::T__20); 
      }
      setState(245);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
    setState(246);
    exp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

qasm2Parser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm2Parser::ExpContext::REAL() {
  return getToken(qasm2Parser::REAL, 0);
}

tree::TerminalNode* qasm2Parser::ExpContext::INT() {
  return getToken(qasm2Parser::INT, 0);
}

tree::TerminalNode* qasm2Parser::ExpContext::ID() {
  return getToken(qasm2Parser::ID, 0);
}

std::vector<qasm2Parser::ExpContext *> qasm2Parser::ExpContext::exp() {
  return getRuleContexts<qasm2Parser::ExpContext>();
}

qasm2Parser::ExpContext* qasm2Parser::ExpContext::exp(size_t i) {
  return getRuleContext<qasm2Parser::ExpContext>(i);
}

qasm2Parser::UnaryopContext* qasm2Parser::ExpContext::unaryop() {
  return getRuleContext<qasm2Parser::UnaryopContext>(0);
}


size_t qasm2Parser::ExpContext::getRuleIndex() const {
  return qasm2Parser::RuleExp;
}


antlrcpp::Any qasm2Parser::ExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm2Visitor*>(visitor))
    return parserVisitor->visitExp(this);
  else
    return visitor->visitChildren(this);
}


qasm2Parser::ExpContext* qasm2Parser::exp() {
   return exp(0);
}

qasm2Parser::ExpContext* qasm2Parser::exp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm2Parser::ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, parentState);
  qasm2Parser::ExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, qasm2Parser::RuleExp, precedence);

    

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
    setState(264);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm2Parser::REAL: {
        setState(249);
        match(qasm2Parser::REAL);
        break;
      }

      case qasm2Parser::INT: {
        setState(250);
        match(qasm2Parser::INT);
        break;
      }

      case qasm2Parser::T__21: {
        setState(251);
        match(qasm2Parser::T__21);
        break;
      }

      case qasm2Parser::ID: {
        setState(252);
        match(qasm2Parser::ID);
        break;
      }

      case qasm2Parser::T__23: {
        setState(253);
        match(qasm2Parser::T__23);
        setState(254);
        exp(4);
        break;
      }

      case qasm2Parser::T__3: {
        setState(255);
        match(qasm2Parser::T__3);
        setState(256);
        exp(0);
        setState(257);
        match(qasm2Parser::T__4);
        break;
      }

      case qasm2Parser::T__27:
      case qasm2Parser::T__28:
      case qasm2Parser::T__29:
      case qasm2Parser::T__30:
      case qasm2Parser::T__31:
      case qasm2Parser::T__32: {
        setState(259);
        unaryop();
        setState(260);
        match(qasm2Parser::T__3);
        setState(261);
        exp(0);
        setState(262);
        match(qasm2Parser::T__4);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(283);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(281);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(266);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(267);
          match(qasm2Parser::T__22);
          setState(268);
          exp(9);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(269);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(270);
          match(qasm2Parser::T__23);
          setState(271);
          exp(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(272);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(273);
          match(qasm2Parser::T__24);
          setState(274);
          exp(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(275);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(276);
          match(qasm2Parser::T__25);
          setState(277);
          exp(6);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(278);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(279);
          match(qasm2Parser::T__26);
          setState(280);
          exp(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(285);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryopContext ------------------------------------------------------------------

qasm2Parser::UnaryopContext::UnaryopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm2Parser::UnaryopContext::getRuleIndex() const {
  return qasm2Parser::RuleUnaryop;
}


antlrcpp::Any qasm2Parser::UnaryopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm2Visitor*>(visitor))
    return parserVisitor->visitUnaryop(this);
  else
    return visitor->visitChildren(this);
}

qasm2Parser::UnaryopContext* qasm2Parser::unaryop() {
  UnaryopContext *_localctx = _tracker.createInstance<UnaryopContext>(_ctx, getState());
  enterRule(_localctx, 28, qasm2Parser::RuleUnaryop);
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
    setState(286);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm2Parser::T__27)
      | (1ULL << qasm2Parser::T__28)
      | (1ULL << qasm2Parser::T__29)
      | (1ULL << qasm2Parser::T__30)
      | (1ULL << qasm2Parser::T__31)
      | (1ULL << qasm2Parser::T__32))) != 0))) {
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

bool qasm2Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 13: return expSempred(dynamic_cast<ExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool qasm2Parser::expSempred(ExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> qasm2Parser::_decisionToDFA;
atn::PredictionContextCache qasm2Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN qasm2Parser::_atn;
std::vector<uint16_t> qasm2Parser::_serializedATN;

std::vector<std::string> qasm2Parser::_ruleNames = {
  "mainprog", "statement", "version", "decl", "gatedecl", "goplist", "qop", 
  "uop", "anylist", "idlist", "mixedlist", "argument", "explist", "exp", 
  "unaryop"
};

std::vector<std::string> qasm2Parser::_literalNames = {
  "", "'}'", "'opaque'", "';'", "'('", "')'", "'if'", "'=='", "'barrier'", 
  "'OPENQASM'", "'qreg'", "'['", "']'", "'creg'", "'gate'", "'{'", "'measure'", 
  "'->'", "'reset'", "'U'", "'CX'", "','", "'pi'", "'+'", "'-'", "'*'", 
  "'/'", "'^'", "'sin'", "'cos'", "'tan'", "'exp'", "'ln'", "'sqrt'"
};

std::vector<std::string> qasm2Parser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "ID", 
  "REAL", "INT", "WS", "COMMENT", "LINE_COMMENT"
};

dfa::Vocabulary qasm2Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> qasm2Parser::_tokenNames;

qasm2Parser::Initializer::Initializer() {
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
       0x3, 0x29, 0x123, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x3, 0x2, 
       0x3, 0x2, 0x7, 0x2, 0x23, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x26, 0xb, 
       0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x5, 0x3, 0x50, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x5, 0x5, 0x62, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
       0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
       0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x78, 0xa, 0x6, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x6, 0x7, 0x7f, 0xa, 
       0x7, 0xd, 0x7, 0xe, 0x7, 0x80, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x5, 0x8, 0x8e, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x5, 0x9, 0xae, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 
       0xb2, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xb6, 0xa, 0xb, 0xc, 
       0xb, 0xe, 0xb, 0xb9, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xc2, 0xa, 0xc, 0xc, 
       0xc, 0xe, 0xc, 0xc5, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xcd, 0xa, 0xc, 0xc, 0xc, 0xe, 
       0xc, 0xd0, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x7, 0xc, 0xd8, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xdb, 
       0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xdf, 0xa, 0xc, 0xc, 0xc, 
       0xe, 0xc, 0xe2, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
       0x5, 0xc, 0xe8, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
       0x3, 0xd, 0x5, 0xd, 0xef, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
       0x7, 0xe, 0xf4, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xf7, 0xb, 0xe, 0x3, 
       0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
       0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x10b, 0xa, 
       0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
       0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x11c, 0xa, 0xf, 0xc, 0xf, 0xe, 
       0xf, 0x11f, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x2, 0x3, 
       0x1c, 0x11, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
       0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x2, 0x3, 0x3, 0x2, 0x1e, 0x23, 0x2, 
       0x13c, 0x2, 0x20, 0x3, 0x2, 0x2, 0x2, 0x4, 0x4f, 0x3, 0x2, 0x2, 0x2, 
       0x6, 0x51, 0x3, 0x2, 0x2, 0x2, 0x8, 0x61, 0x3, 0x2, 0x2, 0x2, 0xa, 
       0x77, 0x3, 0x2, 0x2, 0x2, 0xc, 0x7e, 0x3, 0x2, 0x2, 0x2, 0xe, 0x8d, 
       0x3, 0x2, 0x2, 0x2, 0x10, 0xad, 0x3, 0x2, 0x2, 0x2, 0x12, 0xb1, 0x3, 
       0x2, 0x2, 0x2, 0x14, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x16, 0xe7, 0x3, 0x2, 
       0x2, 0x2, 0x18, 0xee, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xf5, 0x3, 0x2, 0x2, 
       0x2, 0x1c, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x120, 0x3, 0x2, 0x2, 
       0x2, 0x20, 0x24, 0x5, 0x6, 0x4, 0x2, 0x21, 0x23, 0x5, 0x4, 0x3, 0x2, 
       0x22, 0x21, 0x3, 0x2, 0x2, 0x2, 0x23, 0x26, 0x3, 0x2, 0x2, 0x2, 0x24, 
       0x22, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x3, 0x2, 0x2, 0x2, 0x25, 0x3, 
       0x3, 0x2, 0x2, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x27, 0x50, 0x5, 
       0x8, 0x5, 0x2, 0x28, 0x29, 0x5, 0xa, 0x6, 0x2, 0x29, 0x2a, 0x5, 0xc, 
       0x7, 0x2, 0x2a, 0x2b, 0x7, 0x3, 0x2, 0x2, 0x2b, 0x50, 0x3, 0x2, 0x2, 
       0x2, 0x2c, 0x2d, 0x5, 0xa, 0x6, 0x2, 0x2d, 0x2e, 0x7, 0x3, 0x2, 0x2, 
       0x2e, 0x50, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x4, 0x2, 0x2, 0x30, 
       0x31, 0x7, 0x24, 0x2, 0x2, 0x31, 0x32, 0x5, 0x14, 0xb, 0x2, 0x32, 
       0x33, 0x7, 0x5, 0x2, 0x2, 0x33, 0x50, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 
       0x7, 0x4, 0x2, 0x2, 0x35, 0x36, 0x7, 0x24, 0x2, 0x2, 0x36, 0x37, 
       0x7, 0x6, 0x2, 0x2, 0x37, 0x38, 0x7, 0x7, 0x2, 0x2, 0x38, 0x39, 0x5, 
       0x14, 0xb, 0x2, 0x39, 0x3a, 0x7, 0x5, 0x2, 0x2, 0x3a, 0x50, 0x3, 
       0x2, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x4, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x24, 
       0x2, 0x2, 0x3d, 0x3e, 0x7, 0x6, 0x2, 0x2, 0x3e, 0x3f, 0x5, 0x14, 
       0xb, 0x2, 0x3f, 0x40, 0x7, 0x7, 0x2, 0x2, 0x40, 0x41, 0x5, 0x14, 
       0xb, 0x2, 0x41, 0x42, 0x7, 0x5, 0x2, 0x2, 0x42, 0x50, 0x3, 0x2, 0x2, 
       0x2, 0x43, 0x50, 0x5, 0xe, 0x8, 0x2, 0x44, 0x45, 0x7, 0x8, 0x2, 0x2, 
       0x45, 0x46, 0x7, 0x6, 0x2, 0x2, 0x46, 0x47, 0x7, 0x24, 0x2, 0x2, 
       0x47, 0x48, 0x7, 0x9, 0x2, 0x2, 0x48, 0x49, 0x7, 0x26, 0x2, 0x2, 
       0x49, 0x4a, 0x7, 0x7, 0x2, 0x2, 0x4a, 0x50, 0x5, 0xe, 0x8, 0x2, 0x4b, 
       0x4c, 0x7, 0xa, 0x2, 0x2, 0x4c, 0x4d, 0x5, 0x12, 0xa, 0x2, 0x4d, 
       0x4e, 0x7, 0x5, 0x2, 0x2, 0x4e, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x27, 
       0x3, 0x2, 0x2, 0x2, 0x4f, 0x28, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x2c, 0x3, 
       0x2, 0x2, 0x2, 0x4f, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x34, 0x3, 0x2, 
       0x2, 0x2, 0x4f, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x43, 0x3, 0x2, 0x2, 
       0x2, 0x4f, 0x44, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4b, 0x3, 0x2, 0x2, 0x2, 
       0x50, 0x5, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0xb, 0x2, 0x2, 0x52, 
       0x53, 0x7, 0x25, 0x2, 0x2, 0x53, 0x54, 0x7, 0x5, 0x2, 0x2, 0x54, 
       0x7, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x7, 0xc, 0x2, 0x2, 0x56, 0x57, 
       0x7, 0x24, 0x2, 0x2, 0x57, 0x58, 0x7, 0xd, 0x2, 0x2, 0x58, 0x59, 
       0x7, 0x26, 0x2, 0x2, 0x59, 0x5a, 0x7, 0xe, 0x2, 0x2, 0x5a, 0x62, 
       0x7, 0x5, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0xf, 0x2, 0x2, 0x5c, 0x5d, 0x7, 
       0x24, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0xd, 0x2, 0x2, 0x5e, 0x5f, 0x7, 
       0x26, 0x2, 0x2, 0x5f, 0x60, 0x7, 0xe, 0x2, 0x2, 0x60, 0x62, 0x7, 
       0x5, 0x2, 0x2, 0x61, 0x55, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5b, 0x3, 0x2, 
       0x2, 0x2, 0x62, 0x9, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x7, 0x10, 0x2, 
       0x2, 0x64, 0x65, 0x7, 0x24, 0x2, 0x2, 0x65, 0x66, 0x5, 0x14, 0xb, 
       0x2, 0x66, 0x67, 0x7, 0x11, 0x2, 0x2, 0x67, 0x78, 0x3, 0x2, 0x2, 
       0x2, 0x68, 0x69, 0x7, 0x10, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x24, 0x2, 
       0x2, 0x6a, 0x6b, 0x7, 0x6, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x7, 0x2, 0x2, 
       0x6c, 0x6d, 0x5, 0x14, 0xb, 0x2, 0x6d, 0x6e, 0x7, 0x11, 0x2, 0x2, 
       0x6e, 0x78, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x10, 0x2, 0x2, 
       0x70, 0x71, 0x7, 0x24, 0x2, 0x2, 0x71, 0x72, 0x7, 0x6, 0x2, 0x2, 
       0x72, 0x73, 0x5, 0x14, 0xb, 0x2, 0x73, 0x74, 0x7, 0x7, 0x2, 0x2, 
       0x74, 0x75, 0x5, 0x14, 0xb, 0x2, 0x75, 0x76, 0x7, 0x11, 0x2, 0x2, 
       0x76, 0x78, 0x3, 0x2, 0x2, 0x2, 0x77, 0x63, 0x3, 0x2, 0x2, 0x2, 0x77, 
       0x68, 0x3, 0x2, 0x2, 0x2, 0x77, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x78, 0xb, 
       0x3, 0x2, 0x2, 0x2, 0x79, 0x7f, 0x5, 0x10, 0x9, 0x2, 0x7a, 0x7b, 
       0x7, 0xa, 0x2, 0x2, 0x7b, 0x7c, 0x5, 0x14, 0xb, 0x2, 0x7c, 0x7d, 
       0x7, 0x5, 0x2, 0x2, 0x7d, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x79, 0x3, 
       0x2, 0x2, 0x2, 0x7e, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 
       0x2, 0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 0x2, 
       0x2, 0x81, 0xd, 0x3, 0x2, 0x2, 0x2, 0x82, 0x8e, 0x5, 0x10, 0x9, 0x2, 
       0x83, 0x84, 0x7, 0x12, 0x2, 0x2, 0x84, 0x85, 0x5, 0x18, 0xd, 0x2, 
       0x85, 0x86, 0x7, 0x13, 0x2, 0x2, 0x86, 0x87, 0x5, 0x18, 0xd, 0x2, 
       0x87, 0x88, 0x7, 0x5, 0x2, 0x2, 0x88, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x89, 
       0x8a, 0x7, 0x14, 0x2, 0x2, 0x8a, 0x8b, 0x5, 0x18, 0xd, 0x2, 0x8b, 
       0x8c, 0x7, 0x5, 0x2, 0x2, 0x8c, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x82, 
       0x3, 0x2, 0x2, 0x2, 0x8d, 0x83, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x89, 0x3, 
       0x2, 0x2, 0x2, 0x8e, 0xf, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x15, 
       0x2, 0x2, 0x90, 0x91, 0x7, 0x6, 0x2, 0x2, 0x91, 0x92, 0x5, 0x1a, 
       0xe, 0x2, 0x92, 0x93, 0x7, 0x7, 0x2, 0x2, 0x93, 0x94, 0x5, 0x18, 
       0xd, 0x2, 0x94, 0x95, 0x7, 0x5, 0x2, 0x2, 0x95, 0xae, 0x3, 0x2, 0x2, 
       0x2, 0x96, 0x97, 0x7, 0x16, 0x2, 0x2, 0x97, 0x98, 0x5, 0x18, 0xd, 
       0x2, 0x98, 0x99, 0x7, 0x17, 0x2, 0x2, 0x99, 0x9a, 0x5, 0x18, 0xd, 
       0x2, 0x9a, 0x9b, 0x7, 0x5, 0x2, 0x2, 0x9b, 0xae, 0x3, 0x2, 0x2, 0x2, 
       0x9c, 0x9d, 0x7, 0x24, 0x2, 0x2, 0x9d, 0x9e, 0x5, 0x12, 0xa, 0x2, 
       0x9e, 0x9f, 0x7, 0x5, 0x2, 0x2, 0x9f, 0xae, 0x3, 0x2, 0x2, 0x2, 0xa0, 
       0xa1, 0x7, 0x24, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x6, 0x2, 0x2, 0xa2, 
       0xa3, 0x7, 0x7, 0x2, 0x2, 0xa3, 0xa4, 0x5, 0x12, 0xa, 0x2, 0xa4, 
       0xa5, 0x7, 0x5, 0x2, 0x2, 0xa5, 0xae, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 
       0x7, 0x24, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x6, 0x2, 0x2, 0xa8, 0xa9, 
       0x5, 0x1a, 0xe, 0x2, 0xa9, 0xaa, 0x7, 0x7, 0x2, 0x2, 0xaa, 0xab, 
       0x5, 0x12, 0xa, 0x2, 0xab, 0xac, 0x7, 0x5, 0x2, 0x2, 0xac, 0xae, 
       0x3, 0x2, 0x2, 0x2, 0xad, 0x8f, 0x3, 0x2, 0x2, 0x2, 0xad, 0x96, 0x3, 
       0x2, 0x2, 0x2, 0xad, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xad, 0xa0, 0x3, 0x2, 
       0x2, 0x2, 0xad, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xae, 0x11, 0x3, 0x2, 0x2, 
       0x2, 0xaf, 0xb2, 0x5, 0x14, 0xb, 0x2, 0xb0, 0xb2, 0x5, 0x16, 0xc, 
       0x2, 0xb1, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb0, 0x3, 0x2, 0x2, 0x2, 
       0xb2, 0x13, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x24, 0x2, 0x2, 
       0xb4, 0xb6, 0x7, 0x17, 0x2, 0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 
       0xb6, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 
       0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xba, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb7, 
       0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x24, 0x2, 0x2, 0xbb, 0x15, 
       0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0x24, 0x2, 0x2, 0xbd, 0xbe, 
       0x7, 0xd, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x26, 0x2, 0x2, 0xbf, 0xc0, 
       0x7, 0xe, 0x2, 0x2, 0xc0, 0xc2, 0x7, 0x17, 0x2, 0x2, 0xc1, 0xbc, 
       0x3, 0x2, 0x2, 0x2, 0xc2, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc1, 0x3, 
       0x2, 0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc6, 0x3, 0x2, 
       0x2, 0x2, 0xc5, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xe8, 0x7, 0x24, 
       0x2, 0x2, 0xc7, 0xc8, 0x7, 0x24, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0xd, 
       0x2, 0x2, 0xc9, 0xca, 0x7, 0x26, 0x2, 0x2, 0xca, 0xcb, 0x7, 0xe, 
       0x2, 0x2, 0xcb, 0xcd, 0x7, 0x17, 0x2, 0x2, 0xcc, 0xc7, 0x3, 0x2, 
       0x2, 0x2, 0xcd, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 
       0x2, 0xce, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd1, 0x3, 0x2, 0x2, 0x2, 
       0xd0, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x24, 0x2, 0x2, 
       0xd2, 0xd3, 0x7, 0xd, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x26, 0x2, 0x2, 
       0xd4, 0xe8, 0x7, 0xe, 0x2, 0x2, 0xd5, 0xd6, 0x7, 0x24, 0x2, 0x2, 
       0xd6, 0xd8, 0x7, 0x17, 0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 
       0xd8, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd9, 
       0xda, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xd9, 
       0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x24, 0x2, 0x2, 0xdd, 0xdf, 
       0x7, 0x17, 0x2, 0x2, 0xde, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe2, 
       0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x3, 
       0x2, 0x2, 0x2, 0xe1, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe0, 0x3, 0x2, 
       0x2, 0x2, 0xe3, 0xe4, 0x7, 0x24, 0x2, 0x2, 0xe4, 0xe5, 0x7, 0xd, 
       0x2, 0x2, 0xe5, 0xe6, 0x7, 0x26, 0x2, 0x2, 0xe6, 0xe8, 0x7, 0xe, 
       0x2, 0x2, 0xe7, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xce, 0x3, 0x2, 0x2, 
       0x2, 0xe7, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe8, 0x17, 0x3, 0x2, 0x2, 0x2, 
       0xe9, 0xef, 0x7, 0x24, 0x2, 0x2, 0xea, 0xeb, 0x7, 0x24, 0x2, 0x2, 
       0xeb, 0xec, 0x7, 0xd, 0x2, 0x2, 0xec, 0xed, 0x7, 0x26, 0x2, 0x2, 
       0xed, 0xef, 0x7, 0xe, 0x2, 0x2, 0xee, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xee, 
       0xea, 0x3, 0x2, 0x2, 0x2, 0xef, 0x19, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 
       0x5, 0x1c, 0xf, 0x2, 0xf1, 0xf2, 0x7, 0x17, 0x2, 0x2, 0xf2, 0xf4, 
       0x3, 0x2, 0x2, 0x2, 0xf3, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf7, 0x3, 
       0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x3, 0x2, 
       0x2, 0x2, 0xf6, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 
       0x2, 0xf8, 0xf9, 0x5, 0x1c, 0xf, 0x2, 0xf9, 0x1b, 0x3, 0x2, 0x2, 
       0x2, 0xfa, 0xfb, 0x8, 0xf, 0x1, 0x2, 0xfb, 0x10b, 0x7, 0x25, 0x2, 
       0x2, 0xfc, 0x10b, 0x7, 0x26, 0x2, 0x2, 0xfd, 0x10b, 0x7, 0x18, 0x2, 
       0x2, 0xfe, 0x10b, 0x7, 0x24, 0x2, 0x2, 0xff, 0x100, 0x7, 0x1a, 0x2, 
       0x2, 0x100, 0x10b, 0x5, 0x1c, 0xf, 0x6, 0x101, 0x102, 0x7, 0x6, 0x2, 
       0x2, 0x102, 0x103, 0x5, 0x1c, 0xf, 0x2, 0x103, 0x104, 0x7, 0x7, 0x2, 
       0x2, 0x104, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x5, 0x1e, 0x10, 
       0x2, 0x106, 0x107, 0x7, 0x6, 0x2, 0x2, 0x107, 0x108, 0x5, 0x1c, 0xf, 
       0x2, 0x108, 0x109, 0x7, 0x7, 0x2, 0x2, 0x109, 0x10b, 0x3, 0x2, 0x2, 
       0x2, 0x10a, 0xfa, 0x3, 0x2, 0x2, 0x2, 0x10a, 0xfc, 0x3, 0x2, 0x2, 
       0x2, 0x10a, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x10a, 0xfe, 0x3, 0x2, 0x2, 
       0x2, 0x10a, 0xff, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x101, 0x3, 0x2, 0x2, 
       0x2, 0x10a, 0x105, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x11d, 0x3, 0x2, 0x2, 
       0x2, 0x10c, 0x10d, 0xc, 0xa, 0x2, 0x2, 0x10d, 0x10e, 0x7, 0x19, 0x2, 
       0x2, 0x10e, 0x11c, 0x5, 0x1c, 0xf, 0xb, 0x10f, 0x110, 0xc, 0x9, 0x2, 
       0x2, 0x110, 0x111, 0x7, 0x1a, 0x2, 0x2, 0x111, 0x11c, 0x5, 0x1c, 
       0xf, 0xa, 0x112, 0x113, 0xc, 0x8, 0x2, 0x2, 0x113, 0x114, 0x7, 0x1b, 
       0x2, 0x2, 0x114, 0x11c, 0x5, 0x1c, 0xf, 0x9, 0x115, 0x116, 0xc, 0x7, 
       0x2, 0x2, 0x116, 0x117, 0x7, 0x1c, 0x2, 0x2, 0x117, 0x11c, 0x5, 0x1c, 
       0xf, 0x8, 0x118, 0x119, 0xc, 0x5, 0x2, 0x2, 0x119, 0x11a, 0x7, 0x1d, 
       0x2, 0x2, 0x11a, 0x11c, 0x5, 0x1c, 0xf, 0x6, 0x11b, 0x10c, 0x3, 0x2, 
       0x2, 0x2, 0x11b, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x112, 0x3, 0x2, 
       0x2, 0x2, 0x11b, 0x115, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x118, 0x3, 0x2, 
       0x2, 0x2, 0x11c, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11b, 0x3, 0x2, 
       0x2, 0x2, 0x11d, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x1d, 0x3, 0x2, 
       0x2, 0x2, 0x11f, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x9, 0x2, 
       0x2, 0x2, 0x121, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x16, 0x24, 0x4f, 0x61, 
       0x77, 0x7e, 0x80, 0x8d, 0xad, 0xb1, 0xb7, 0xc3, 0xce, 0xd9, 0xe0, 
       0xe7, 0xee, 0xf5, 0x10a, 0x11b, 0x11d, 
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

qasm2Parser::Initializer qasm2Parser::_init;
