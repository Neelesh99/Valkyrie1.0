
// Generated from qasm2.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "qasm2Visitor.h"
#include "BaseTypes.h"


struct idLocationPairs {
    std::vector<std::string> identifiers;
    std::vector<int> locations;
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

    return visitChildren(ctx);
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
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExplist(qasm2Parser::ExplistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExp(qasm2Parser::ExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryop(qasm2Parser::UnaryopContext *ctx) override {
    return visitChildren(ctx);
  }


};

