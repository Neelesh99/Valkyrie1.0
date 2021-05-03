
// Generated from qasm2.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "qasm2Parser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by qasm2Parser.
 */
class  qasm2Visitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by qasm2Parser.
   */
    virtual antlrcpp::Any visitMainprog(qasm2Parser::MainprogContext *context) = 0;

    virtual antlrcpp::Any visitStatement(qasm2Parser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitVersion(qasm2Parser::VersionContext *context) = 0;

    virtual antlrcpp::Any visitDecl(qasm2Parser::DeclContext *context) = 0;

    virtual antlrcpp::Any visitGatedecl(qasm2Parser::GatedeclContext *context) = 0;

    virtual antlrcpp::Any visitGoplist(qasm2Parser::GoplistContext *context) = 0;

    virtual antlrcpp::Any visitQop(qasm2Parser::QopContext *context) = 0;

    virtual antlrcpp::Any visitUop(qasm2Parser::UopContext *context) = 0;

    virtual antlrcpp::Any visitAnylist(qasm2Parser::AnylistContext *context) = 0;

    virtual antlrcpp::Any visitIdlist(qasm2Parser::IdlistContext *context) = 0;

    virtual antlrcpp::Any visitMixedlist(qasm2Parser::MixedlistContext *context) = 0;

    virtual antlrcpp::Any visitArgument(qasm2Parser::ArgumentContext *context) = 0;

    virtual antlrcpp::Any visitExplist(qasm2Parser::ExplistContext *context) = 0;

    virtual antlrcpp::Any visitExp(qasm2Parser::ExpContext *context) = 0;

    virtual antlrcpp::Any visitUnaryop(qasm2Parser::UnaryopContext *context) = 0;


};

