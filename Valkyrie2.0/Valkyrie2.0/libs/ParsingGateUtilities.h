#pragma once
#include "BaseTypes.h"
#include <map>

GateRequestType getGateTypeS(std::string gateType);
GateRequestType getGateTypeM(std::string gateType);
GateRequest compileGateRequest(std::string gateType, idLocationPairs idLoc);
GateRequest compileGateRequest(std::string gateType, std::vector<double> params, idLocationPairs idLoc);
std::vector<GateRequest> compileCompoundGateRequest(std::string gateType, idLocationPairs idLoc);
std::vector<GateRequest> compileCompoundGateRequest(std::string gateType, std::vector<double> params, idLocationPairs idLoc);