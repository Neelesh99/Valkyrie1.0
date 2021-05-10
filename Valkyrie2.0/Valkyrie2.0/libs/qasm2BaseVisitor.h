
// Generated from qasm2.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "qasm2Visitor.h"
#include "BaseTypes.h"
#include <cmath>


struct idLocationPairs {
    std::vector<std::string> identifiers;
    std::vector<int> locations;
};

const double PI = 3.1415926535;

enum unaryOp {
    SIN_,
    COS_,
    TAN_,
    EXP_,
    LN_,
    SQRT_
};


/**
 * This class provides an empty implementation of qasm2Visitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  qasm2BaseVisitor : public qasm2Visitor {
private:
    int debugLevel = 1;
    std::vector<Register> registers_;
    std::vector<GateRequest> gates_;
    GateRequestType getGateTypeS(std::string gateType) {
        GateRequestType gtType;
        if (gateType == "U") {
            gtType = U;
        }
        else if (gateType == "CX") {
            gtType = CX;
        }
        else if (gateType == "h") {
            gtType = h;
        }
        else if (gateType == "cx") {
            gtType = cx;
        }
        else {
            gtType = CUSTOM;
        }
        return gtType;
    }

    GateRequest compileGateRequest(std::string gateType, idLocationPairs idLoc) {
        GateRequestType gtType = getGateTypeS(gateType);
        GateRequest gate(gtType);
        for (int i = 0; i < idLoc.identifiers.size(); i++) {
            gate.addressQubit(idLoc.identifiers[i], idLoc.locations[i]);
        }
        return gate;
    }

    GateRequest compileGateRequest(std::string gateType, std::vector<double> params, idLocationPairs idLoc) {
        GateRequestType gtType = getGateTypeS(gateType);
        GateRequest gate(gtType);
        for (int i = 0; i < idLoc.identifiers.size(); i++) {
            gate.addressQubit(idLoc.identifiers[i], idLoc.locations[i]);
        }
        gate.setParameters(params);
        return gate;
    }

    int findRegWidth(std::string identifier) {
        for (auto register_ : registers_) {
            if (register_.getName() == identifier) {
                if (register_.isQuantum()) {
                    return register_.getQuantumRegister().getWidth();
                }
                else {
                    return register_.getClassicalRegister().getWidth();
                }
            }
        }
        return -1;
    }

public:
    
    std::vector<Register> getRegisters() {
        return registers_;
    }

    std::vector<GateRequest> getGates() {
        return gates_;
    }

  virtual antlrcpp::Any visitMainprog(qasm2Parser::MainprogContext *ctx) override {
      if (ctx->version()) {
          HeaderData headerD = visitVersion(ctx->version()).as<HeaderData>();
          std::vector<qasm2Parser::StatementContext*> statements = ctx->statement();
          for (auto statement : statements) {
              visitStatement(statement);
          }
      }
      return 1;
  }

  virtual antlrcpp::Any visitStatement(qasm2Parser::StatementContext *ctx) override {
      if (ctx->decl()) {
          /*Register newRegister = visitDecl(ctx->decl()).as<Register>();
          registers_.push_back(newRegister);*/
      }
      else if (ctx->qop()) {
          
      }
      else {
          return 1;
      }
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVersion(qasm2Parser::VersionContext *ctx) override {
      if (ctx->REAL()) {
          std::vector<std::string> includes;
          HeaderData header(ctx->REAL()->toString(), includes);
          return header;
      }
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecl(qasm2Parser::DeclContext *ctx) override {
        antlr4::tree::TerminalNode* id = ctx->ID();
        std::string identifier = id->getText();
        antlr4::tree::TerminalNode* intVal = ctx->INT();
        std::string widthString = intVal->getText();
      if (ctx->getStart()->getText() == "qreg") {
          QuantumRegister qReg = QuantumRegister(identifier, std::stoi(widthString));
          Register reg(quantum_, qReg);
          registers_.push_back(reg);
          return 0;
      }
      else {
          ClassicalRegister cReg = ClassicalRegister(identifier, std::stoi(widthString));
          Register reg(classical_, cReg);
          registers_.push_back(reg);
          return 0;
      }
      return 1;
  }

  virtual antlrcpp::Any visitGatedecl(qasm2Parser::GatedeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGoplist(qasm2Parser::GoplistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQop(qasm2Parser::QopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUop(qasm2Parser::UopContext *ctx) override {
      if (ctx->getStart()->getText() == "U") {
          if (ctx->explist()) {
              std::vector<double> gateArguments = visitExplist(ctx->explist()).as<std::vector<double>>();
              if (gateArguments.size() == 3) {
                  idLocationPairs pairs = visitArgument(ctx->argument()[0]);
                  if (pairs.identifiers.size() == 1) {
                      GateRequest gate = compileGateRequest("U", gateArguments, pairs);
                      gates_.push_back(gate);
                  }
              }
          }
      }
      if (ctx->getStart()->getText() == "CX") {
        idLocationPairs pairs1 = visitArgument(ctx->argument()[0]).as<idLocationPairs>();
        idLocationPairs pairs2 = visitArgument(ctx->argument()[1]).as<idLocationPairs>();
        idLocationPairs combinedPairs;
        for (int i = 0; pairs1.identifiers.size(); i++) {
            combinedPairs.identifiers.push_back(pairs1.identifiers[i]);
            combinedPairs.locations.push_back(pairs1.locations[i]);
        }
        for (int i = 0; pairs2.identifiers.size(); i++) {
            combinedPairs.identifiers.push_back(pairs2.identifiers[i]);
            combinedPairs.locations.push_back(pairs2.locations[i]);
        }
        if (combinedPairs.identifiers.size() == 2) {
            GateRequest gate = compileGateRequest("CX", combinedPairs);
            gates_.push_back(gate);
        }
      }
      if (ctx->ID()) {
          std::string uopGate = ctx->ID()->getText();
          if (ctx->anylist()) {              
              if (ctx->anylist()->mixedlist()) {
                  idLocationPairs idLoc = visitMixedlist(ctx->anylist()->mixedlist()).as<idLocationPairs>();
                  GateRequest gate = compileGateRequest(uopGate, idLoc);
                  gates_.push_back(gate);
              }
          }
      }

    return 0;
  }

  virtual antlrcpp::Any visitAnylist(qasm2Parser::AnylistContext *ctx) override {
      return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdlist(qasm2Parser::IdlistContext *ctx) override {
      std::vector<antlr4::tree::TerminalNode*> ids = ctx->ID();
      std::vector<std::string> idStrings;
      for (auto id : ids) {
          idStrings.push_back(id->getText());
      }
      return idStrings;
  }

  virtual antlrcpp::Any visitMixedlist(qasm2Parser::MixedlistContext *ctx) override {
      int countID = ctx->ID().size();
      int countINT = ctx->INT().size();
      if (countID == countINT) {
          std::vector<std::string> identifiers;
          for (auto id : ctx->ID()) {
              identifiers.push_back(id->getText());
          }
          std::vector<int> locations;
          for (auto val : ctx->INT()) {
              locations.push_back(std::stoi(val->getText()));
          }
          idLocationPairs idLoc;
          idLoc.identifiers = identifiers;
          idLoc.locations = locations;
          return idLoc;
      }
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgument(qasm2Parser::ArgumentContext *ctx) override {
      idLocationPairs pairs;
      if (ctx->INT()) {
          pairs.identifiers.push_back(ctx->ID()->getText());
          pairs.locations.push_back(std::stoi(ctx->INT()->getText()));
      }
      else {
          std::string register_ = ctx->ID()->getText();
          int width = findRegWidth(register_);
          for (int i = 0; i < width; i++) {
              pairs.identifiers.push_back(register_);
              pairs.locations.push_back(i);
          }
      }
      return pairs;
  }

  virtual antlrcpp::Any visitExplist(qasm2Parser::ExplistContext *ctx) override {
      std::vector<double> values;
      for (auto exp : ctx->exp()) {
          double value = visitExp(exp);
          values.push_back(value);
      }
      return values;
  }

  virtual antlrcpp::Any visitExp(qasm2Parser::ExpContext *ctx) override {
      if (!ctx->unaryop()) {
          if (!ctx->ID()) {
              std::vector<qasm2Parser::ExpContext*> subexpressions = ctx->exp();
              if (subexpressions.size() == 0) {
                  if (ctx->getStart()->getText() == "pi") {
                      return PI;
                  }
                  double value = 0;
                  if (ctx->REAL()) {
                      std::string unparsed = ctx->REAL()->getText();
                      value = std::stod(unparsed);
                  }
                  else if (ctx->INT()) {
                      std::string unparsed = ctx->INT()->getText();
                      value = std::stod(unparsed);
                  }
                  return value;
              }
              if (subexpressions.size() == 1) {
                  if (ctx->getStart()->getText() == "-") {
                      return -1 * visitExp(subexpressions[0]).as<double>();
                  }
                  else {
                      return visitExp(subexpressions[0]);
                  }
              }
              if (subexpressions.size() == 2) {
                  std::string operator_ = ctx->getToken(sizeof(antlr4::Token), 1)->getText();
                  if (operator_ == "+") {
                      return visitExp(subexpressions[0]).as<double>() + visitExp(subexpressions[1]).as<double>();
                  }
                  if (operator_ == "-") {
                      return visitExp(subexpressions[0]).as<double>() - visitExp(subexpressions[1]).as<double>();
                  }
                  if (operator_ == "*") {
                      return visitExp(subexpressions[0]).as<double>() * visitExp(subexpressions[1]).as<double>();
                  }
                  if (operator_ == "/") {
                      return visitExp(subexpressions[0]).as<double>() / visitExp(subexpressions[1]).as<double>();
                  }
              }
          }
      }
      if (ctx->ID()) {
          double k = 0;
          return k;
      }
      if (ctx->unaryop()) {
          double expressionVal = visitExp(ctx->exp()[0]);
          unaryOp operation_ = visitUnaryop(ctx->unaryop()).as<unaryOp>();
          switch (operation_) {
          case SIN_:
              return std::sin(expressionVal);
              break;
          case COS_:
              return std::cos(expressionVal);
              break;
          case TAN_:
              return std::tan(expressionVal);
              break;
          case EXP_:
              return std::exp(expressionVal);
              break;
          case LN_:
              return std::log(expressionVal);
              break;
          case SQRT_:
              return std::pow(expressionVal, 0.5);
              break;
          }
      }
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryop(qasm2Parser::UnaryopContext *ctx) override {
      std::string operation_ = ctx->getText();
      if (operation_ == "sin") {
          return SIN_;
      }
      if (operation_ == "cos") {
          return COS_;
      }
      if (operation_ == "tan") {
          return TAN_;
      }
      if (operation_ == "exp") {
          return EXP_;
      }
      if (operation_ == "ln") {
          return LN_;
      }
      if (operation_ == "sqrt") {
          return SQRT_;
      }
      return SIN_;
  }


};

