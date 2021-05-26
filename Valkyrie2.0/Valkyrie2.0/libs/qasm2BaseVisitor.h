
// Generated from qasm2.g4 by ANTLR 4.9.2
// Completed by Neelesh Ravichandran

#pragma once


#include "antlr4-runtime.h"
#include "qasm2Visitor.h"
#include "BaseTypes.h"
#include <cmath>
#include "ParsingGateUtilities.h"
#include <map>

/*
    qasm2BaseVisitor.h
    Description: File provides implementation for QASM2 visitation

*/


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
    std::vector<MeasureCommand> commands_;
    std::map<std::string, std::function <std::vector<GateRequest>(std::vector<double> params, idLocationPairs idLoc)>> customGates_;
    bool gateDeclMode = false;

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

    int findReg(std::string identifier) {
        for (int i = 0; i < registers_.size(); i++) {
            if (registers_[i].getName() == identifier) {
                return i;
            }
        }
        return -1;
    }

    void attachGates(std::vector<GateRequest> gates) {
        for (int i = 0; i < gates.size(); i++) {
            gates_.push_back(gates[i]);
        }
    }

    idLocationPairs makePair(idLocationPairs p1, int i1) {
        idLocationPairs newPair;
        newPair.identifiers.push_back(p1.identifiers[i1]);
        newPair.locations.push_back(p1.locations[i1]);
        return newPair;
    }

public:
    
    std::vector<Register> getRegisters() {
        return registers_;
    }

    std::vector<GateRequest> getGates() {
        return gates_;
    }

    std::vector<MeasureCommand> getMeasureCommands() {
        return commands_;
    }

  // visitMainprog provides parsing logic for program as a whole
  virtual antlrcpp::Any visitMainprog(qasm2Parser::MainprogContext *ctx) override {                 //Complete
      if (ctx->version()) {
          HeaderData headerD = visitVersion(ctx->version()).as<HeaderData>();
          std::vector<qasm2Parser::StatementContext*> statements = ctx->statement();
          for (auto statement : statements) {
              visitStatement(statement);
          }
      }
      return 1;
  }

  // visitStatement provides parsing logic for visiting a single statement as a whole  
  virtual antlrcpp::Any visitStatement(qasm2Parser::StatementContext *ctx) override {               //Incomplete -gatedecl 
      if (ctx->decl()) {
          /*Register newRegister = visitDecl(ctx->decl()).as<Register>();
          registers_.push_back(newRegister);*/
      }
      else if (ctx->qop()) {
          
      }
      else if (ctx->gatedecl() && ctx->goplist()) {
          gateDeclMode = true;
          gateDeclaration gDecl = visitGatedecl(ctx->gatedecl()).as<gateDeclaration>();
          std::vector<gateOp> gateOps = visitGoplist(ctx->goplist()).as<std::vector<gateOp>>();
          gateDeclMode = false;
          customGates_[gDecl.gateName] = compileCustomGate(gDecl, gateOps);
          return 1;
      }
      else {
          return 1;
      }
    return visitChildren(ctx);
  }

  // visitVersion provides parsing logic for the qasm version
  virtual antlrcpp::Any visitVersion(qasm2Parser::VersionContext *ctx) override {       // Complete
      if (ctx->REAL()) {
          std::vector<std::string> includes;
          HeaderData header(ctx->REAL()->toString(), includes);
          return header;
      }
    return visitChildren(ctx);
  }

  // visitVersion provides parsing logic for a single declaration such as qreg or creg
  virtual antlrcpp::Any visitDecl(qasm2Parser::DeclContext *ctx) override {     // Complete
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

  // visitVersion provides parsing logic for a custom gate declaration
  virtual antlrcpp::Any visitGatedecl(qasm2Parser::GatedeclContext *ctx) override {
      if (ctx->idlist().size() == 1) {          
          std::vector<std::string> idLocNames = visitIdlist(ctx->idlist()[0]);
          gateDeclaration gDecl;
          gDecl.gateName = ctx->ID()->getText();
          gDecl.idLocList = idLocNames;
          return gDecl;
      }
      else {
          std::vector<std::string> idLocNames = visitIdlist(ctx->idlist()[1]);
          std::vector<std::string> paramNames = visitIdlist(ctx->idlist()[0]);
          gateDeclaration gDecl;
          gDecl.gateName = ctx->ID()->getText();
          gDecl.idLocList = idLocNames;
          gDecl.paramList = paramNames;
          return gDecl;
      }
    return visitChildren(ctx);
  }

  // visitVersion provides parsing logic for a custom gate operation declaration
  virtual antlrcpp::Any visitGoplist(qasm2Parser::GoplistContext *ctx) override {           
      if (ctx->uop().size() > 0) {
          std::vector<gateOp> gateOperations;
          for (auto uop : ctx->uop()) {
              gateOp gop = visitUop(uop).as<gateOp>();
              gateOperations.push_back(gop);
          }
          return gateOperations;
      }
      return 1;
  }

  // visitQop provides parsing logic for a quantum operation
  virtual antlrcpp::Any visitQop(qasm2Parser::QopContext *ctx) override {   
    // Incomplete -measure
    if (ctx->getStart()->getText() == "measure") {
        if (ctx->argument().size() == 2) {
            idLocationPairs pairs1 = visitArgument(ctx->argument()[0]);
            idLocationPairs pairs2 = visitArgument(ctx->argument()[1]);
            if (pairs1.getSize() == pairs2.getSize()) {
                for (int i = 0; i < pairs1.getSize(); i++) {
                    idLocationPairs p1 = makePair(pairs1, i);
                    idLocationPairs p2 = makePair(pairs2, i);
                    MeasureCommand command = MeasureCommand(p1, p2);
                    commands_.push_back(command);
                }
            }            
        }
    }
    return visitChildren(ctx);
  }

  // visitUop provides parsing logic for a unitary gate operation
  virtual antlrcpp::Any visitUop(qasm2Parser::UopContext *ctx) override {
      if (!gateDeclMode) {
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
              for (int i = 0; i < pairs1.identifiers.size(); i++) {
                  combinedPairs.identifiers.push_back(pairs1.identifiers[i]);
                  combinedPairs.locations.push_back(pairs1.locations[i]);
              }
              for (int i = 0; i < pairs2.identifiers.size(); i++) {
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
              bool customGate = customGates_.find(uopGate) != customGates_.end();
              if (ctx->explist()) {
                  std::vector<double> gateArguments = visitExplist(ctx->explist()).as<std::vector<double>>();
                  if (ctx->anylist()) {
                      if (ctx->anylist()->mixedlist()) {
                          idLocationPairs idLoc = visitMixedlist(ctx->anylist()->mixedlist()).as<idLocationPairs>();
                          std::vector<GateRequest> gates;
                          if (customGate) {
                              gates = customGates_[uopGate](gateArguments, idLoc);
                          }
                          else {
                              gates = compileCompoundGateRequest(uopGate, gateArguments, idLoc);
                          }                          
                          attachGates(gates);
                      }
                      else {
                          std::vector<std::string> identifiers = visitIdlist(ctx->anylist()->idlist()).as<std::vector<std::string>>();
                          for (auto identifier : identifiers) {
                              int width = findRegWidth(identifier);
                              idLocationPairs pairs;
                              for (int i = 0; i < width; i++) {
                                  pairs.identifiers.push_back(identifier);
                                  pairs.locations.push_back(i);
                              }
                              std::vector<GateRequest> gates;
                              if (customGate) {
                                  gates = customGates_[uopGate](gateArguments, pairs);
                              }
                              else {
                                  gates = compileCompoundGateRequest(uopGate, gateArguments, pairs);
                              }
                              attachGates(gates);
                          }
                      }
                  }
              }
              else {
                  bool customGate = customGates_.find(uopGate) != customGates_.end();
                  if (ctx->anylist()) {
                      if (ctx->anylist()->mixedlist()) {
                          idLocationPairs idLoc = visitMixedlist(ctx->anylist()->mixedlist()).as<idLocationPairs>();
                          std::vector<GateRequest> gates;
                          if (customGate) {
                              gates = customGates_[uopGate](std::vector<double>(), idLoc);
                          }
                          else {
                              gates = compileCompoundGateRequest(uopGate, idLoc);
                          }                 
                          attachGates(gates);
                      }
                  }
                  else {
                      std::vector<std::string> identifiers = visitIdlist(ctx->anylist()->idlist()).as<std::vector<std::string>>();
                      for (auto identifier : identifiers) {
                          int width = findRegWidth(identifier);
                          idLocationPairs pairs;
                          for (int i = 0; i < width; i++) {
                              pairs.identifiers.push_back(identifier);
                              pairs.locations.push_back(i);
                          }
                          std::vector<GateRequest> gates;
                          if (customGate) {
                              gates = customGates_[uopGate](std::vector<double>(), pairs);
                          }
                          else {
                              gates = compileCompoundGateRequest(uopGate, pairs);
                          }
                          attachGates(gates);
                      }
                  }
              }
          }
      }
      else {
          gateOp gOP;
          if (ctx->getStart()->getText() == "U") {
              gOP.gateName = "U";
          }
          else if (ctx->getStart()->getText() == "CX") {
              gOP.gateName = "CX";
          }
          else {
              gOP.gateName = ctx->ID()->getText();
          }
          std::vector<expEval> paramList;
          if (ctx->explist()) {
              paramList = visitExplist(ctx->explist()).as<std::vector<expEval>>();
          }
          gOP.params = paramList;
          if (ctx->argument().size() > 0) {
              idLocationPairs pairs = visitArgument(ctx->argument()[0]);
              if (ctx->argument().size() == 2) {
                  idLocationPairs pairs2 = visitArgument(ctx->argument()[1]);
                  for (int i = 0; i < pairs2.identifiers.size(); i++) {
                      pairs.identifiers.push_back(pairs2.identifiers[i]);
                  }
              }
              gOP.idLocs = pairs.identifiers;
          }
          else {
              if (ctx->anylist()->idlist()) {
                  gOP.idLocs = visitIdlist(ctx->anylist()->idlist()).as<std::vector<std::string>>();
              }              
          }
          return gOP;
      }    

    return 0;
  }

  // visitAnyList provides parsing logic for a AnyList parsing
  virtual antlrcpp::Any visitAnylist(qasm2Parser::AnylistContext *ctx) override {               // Complete
      return visitChildren(ctx);
  }
  
  // visitIdList provides parsing logic for an IdList
  virtual antlrcpp::Any visitIdlist(qasm2Parser::IdlistContext *ctx) override {                 // Complete
      std::vector<antlr4::tree::TerminalNode*> ids = ctx->ID();
      std::vector<std::string> idStrings;
      for (auto id : ids) {
          idStrings.push_back(id->getText());
      }
      return idStrings;
  }

  // visitMixedList provides parsing logic for a MixedList
  virtual antlrcpp::Any visitMixedlist(qasm2Parser::MixedlistContext *ctx) override {           // Complete
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
      else {
          std::string decider = ctx->getToken(sizeof(antlr4::Token), 1)->getText();
          if (decider == "[") {
              std::vector<std::string> identifiers;
              for (int i = 0; i < countINT; i++) {
                  identifiers.push_back(ctx->ID()[i]->getText());
              }
              std::string finalID = ctx->ID()[countINT]->getText();
              std::vector<int> locations;
              for (auto val : ctx->INT()) {
                  locations.push_back(std::stoi(val->getText()));
              }
              int width = findRegWidth(finalID);
              identifiers.push_back(finalID);
              for (int i = 0; i < width; i++) {
                  locations.push_back(i);
              }
              idLocationPairs idLoc;
              idLoc.identifiers = identifiers;
              idLoc.locations = locations;
              return idLoc;
          }
          if (decider == ",") {
              std::vector<std::string> identifiers;
              std::vector<int> locations;
              for (int i = 0; i < countID - 1; i++) {
                  for (int j = 0; j < findRegWidth(ctx->ID()[j]->getText()); j++) {
                      identifiers.push_back(ctx->ID()[i]->getText());
                      locations.push_back(j);
                  }                  
              }
              std::string finalID = ctx->ID()[countID - 1]->getText();
              identifiers.push_back(finalID);
              locations.push_back(std::stoi(ctx->INT()[0]->getText()));
              idLocationPairs idLoc;
              idLoc.identifiers = identifiers;
              idLoc.locations = locations;
              return idLoc;
          }
      }
    return visitChildren(ctx);
  }

  // visitArgument provides parsing logic for an argument for a gate
  virtual antlrcpp::Any visitArgument(qasm2Parser::ArgumentContext *ctx) override {             // Complete
      idLocationPairs pairs;
      if (ctx->INT()) {
          pairs.identifiers.push_back(ctx->ID()->getText());
          pairs.locations.push_back(std::stoi(ctx->INT()->getText()));
      }
      else {
          if (!gateDeclMode) {
              std::string register_ = ctx->ID()->getText();
              int width = findRegWidth(register_);
              for (int i = 0; i < width; i++) {
                  pairs.identifiers.push_back(register_);
                  pairs.locations.push_back(i);
              }
          }
          else {
              pairs.identifiers.push_back(ctx->ID()->getText());
          }
      }
      return pairs;
  }

  // visitExpList provides parsing logic for an expList for a gate
  virtual antlrcpp::Any visitExplist(qasm2Parser::ExplistContext *ctx) override {           // Complete
      if (!gateDeclMode) {
          std::vector<double> values;
          for (auto exp : ctx->exp()) {
              double value = visitExp(exp).as<double>();
              values.push_back(value);
          }
          return values;
      }
      else {
          std::vector<expEval> values;
          for (auto exp : ctx->exp()) {
              expEval value = visitExp(exp).as<expEval>();
              values.push_back(value);
          }
          return values;
      }
  }

  // visitExp provides parsing logic for any general expression
  virtual antlrcpp::Any visitExp(qasm2Parser::ExpContext *ctx) override {
      if (!ctx->unaryop()) {
          if (!ctx->ID()) {
              std::vector<qasm2Parser::ExpContext*> subexpressions = ctx->exp();
              if (subexpressions.size() == 0) {
                  if (ctx->getStart()->getText() == "pi") {
                      if (gateDeclMode) {
                          expEval exp;
                          exp.identNotVal = false;
                          exp.value = PI;
                          return exp;
                      }
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
                  if (gateDeclMode) {
                      expEval exp;
                      exp.identNotVal = false;
                      exp.value = value;
                      return exp;
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
          expEval val;
          val.identNotVal = true;
          val.ident = ctx->ID()->getText();
          return val;
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

  // visitUnaryOp provides parsing logic for generic unary operation
  virtual antlrcpp::Any visitUnaryop(qasm2Parser::UnaryopContext *ctx) override {               // Complete
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

