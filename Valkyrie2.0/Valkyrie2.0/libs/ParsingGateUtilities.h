#pragma once
#include "BaseTypes.h"
#include <map>
#include <functional>

GateRequestType getGateTypeS(std::string gateType);
GateRequestType getGateTypeM(std::string gateType);
GateRequest compileGateRequest(std::string gateType, idLocationPairs idLoc);
GateRequest compileGateRequest(std::string gateType, std::vector<double> params, idLocationPairs idLoc);
std::vector<GateRequest> compileCompoundGateRequest(std::string gateType, idLocationPairs idLoc);
std::vector<GateRequest> compileCompoundGateRequest(std::string gateType, std::vector<double> params, idLocationPairs idLoc);
std::function <std::vector<GateRequest>(std::vector<double> params, idLocationPairs idLoc)> compileCustomGateInternal(std::vector<std::string> gates, std::vector<std::vector<doubleOrArg>> paramsForGate, std::vector<std::vector<int>> locationsPerGate);
std::function <std::vector<GateRequest>(std::vector<double> params, idLocationPairs idLoc)> compileCustomGate(gateDeclaration decl, std::vector<gateOp> gateOperations);