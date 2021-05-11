#include "ParsingGateUtilities.h"

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
    else if (gateType == "u3") {
        gtType = u3;
    }
    else if (gateType == "u2") {
        gtType = u2;
    }
    else if (gateType == "u1") {
        gtType = u1;
    }
    else if (gateType == "id") {
        gtType = id;
    }
    else if (gateType == "u0") {
        gtType = u0;
    }
    else {
        gtType = CUSTOM;
    }
    return gtType;
}

std::map<std::string, GateRequestType> mapOfGateRequests = {
    {"U", U},
    {"CX", CX},
    {"h", h},
    {"cx", cx},
    {"u3", u3},
    {"u2", u2},
    {"u1", u1},
    {"id", id},
    {"u0", u0},
    {"u", u},
    {"p", p},
    {"x", x},
    {"y", y},
    {"z", z},
    {"s", s},
    {"sdg", sdg},
    {"t", t},
    {"tdg", tdg},
    {"rx", rx},
    {"ry", ry},
    {"rz", rz},
    {"sx", sx},
    {"sxdg", sxdg},
    {"cz", cz},
    {"cy", cy},
    {"swap", swap},
    {"ch", ch},
    {"ccx", ccx},
    {"cswap", cswap},
    {"crx", crx},
    {"cry", cry},
    {"crz", crz},
    {"cu1", cu1},
    {"cp", cp},
    {"cu3", cu3},
    {"csx", csx},
    {"cu", cu},
    {"rxx", rxx},
    {"rzz", rzz},
    {"rccx", rccx},
    {"rc3x", rc3x},
    {"c3x", c3x},
    {"c3sqrtx", c3sqrtx},
    {"c4x", c4x}
};

GateRequestType getGateTypeM(std::string gateType) {
    std::map<std::string, GateRequestType>::iterator it = mapOfGateRequests.find(gateType);
    if (it != mapOfGateRequests.end()) {
        return it->second;
    }
    return CUSTOM;
}

GateRequest compileGateRequest(std::string gateType, idLocationPairs idLoc) {
    //GateRequestType gtType = getGateTypeS(gateType);
    GateRequestType gtType = getGateTypeM(gateType);
    GateRequest gate(gtType);
    for (int i = 0; i < idLoc.identifiers.size(); i++) {
        gate.addressQubit(idLoc.identifiers[i], idLoc.locations[i]);
    }
    return gate;
}

GateRequest compileGateRequest(std::string gateType, std::vector<double> params, idLocationPairs idLoc) {
    //GateRequestType gtType = getGateTypeS(gateType);
    GateRequestType gtType = getGateTypeM(gateType);
    GateRequest gate(gtType);
    for (int i = 0; i < idLoc.identifiers.size(); i++) {
        gate.addressQubit(idLoc.identifiers[i], idLoc.locations[i]);
    }
    gate.setParameters(params);
    return gate;
}

std::vector<GateRequest> compileCompoundGateRequest(std::string gateType, idLocationPairs idLoc)
{
    return std::vector<GateRequest>();
}
std::vector<GateRequest> compileCompoundGateRequest(std::string gateType, std::vector<double> params, idLocationPairs idLoc)
{
    return std::vector<GateRequest>();
}
