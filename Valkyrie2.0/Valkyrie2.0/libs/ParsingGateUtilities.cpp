#include "ParsingGateUtilities.h"

const double PI = 3.1415926535;

std::vector<GateRequest> attachGateRequests(std::vector<GateRequest> initial, std::vector<GateRequest> addition) {
    for (int i = 0; i < addition.size(); i++) {
        initial.push_back(addition[i]);
    }
    return initial;
}

idLocationPairs fetchIDLoc(idLocationPairs input, int i) {
    if (i >= input.getSize()) {
        return input;
    }
    idLocationPairs x;
    x.identifiers.push_back(input.identifiers[i]);
    x.locations.push_back(input.locations[i]);
    return x;
}

idLocationPairs zipIDLoc(idLocationPairs inp1, idLocationPairs inp2) {
    idLocationPairs x;
    x.identifiers = inp1.identifiers;
    x.locations = inp1.locations;

    for (int i = 0; i < inp2.getSize(); i++) {
        x.identifiers.push_back(inp2.identifiers[i]);
        x.locations.push_back(inp2.locations[i]);
    }
    return x;
}

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

GateRequest attachIDLocPairs(GateRequest input, idLocationPairs pairs) {
    for (int i = 0; i < pairs.identifiers.size(); i++) {
        input.addressQubit(pairs.identifiers[i], pairs.locations[i]);
    }
    return input;
}

// Hardware Primitive gates //

std::vector<GateRequest> compileU3Gate(double theta, double phi, double lambda, idLocationPairs idLoc) {
    GateRequest gate(U);
    gate.addParameter(theta);
    gate.addParameter(phi);
    gate.addParameter(lambda);
    if (idLoc.getSize() != 1) {
        return std::vector<GateRequest>();
    }
    gate = attachIDLocPairs(gate, idLoc);
    std::vector<GateRequest> output {gate};
    return output;
}

std::vector<GateRequest> compileU2Gate(double phi, double lambda, idLocationPairs idLoc) {
    return compileU3Gate(PI / 2.0, phi, lambda, idLoc);
}

std::vector<GateRequest> compileU1Gate(double lambda, idLocationPairs idLoc) {
    return compileU3Gate(0, 0, lambda, idLoc);
}

std::vector<GateRequest> compileCXGate(idLocationPairs idLoc) {
    GateRequest gate(CX);
    if (idLoc.getSize() != 2) {
        return std::vector<GateRequest>();
    }
    gate = attachIDLocPairs(gate, idLoc);
    std::vector<GateRequest> output{ gate };
    return output;
}

std::vector<GateRequest> compileIDGate(idLocationPairs idLoc) {
    return compileU3Gate(0, 0, 0, idLoc);
}

std::vector<GateRequest> compileU0Gate(double gamma, idLocationPairs idLoc) {
    return compileU3Gate(0, 0, 0, idLoc);
}

// Standard Gates //

std::vector<GateRequest> compileUGate(double theta, double phi, double lambda, idLocationPairs idLoc) {
    return compileU3Gate(theta, phi, lambda, idLoc);
}

std::vector<GateRequest> compilePGate(double lambda, idLocationPairs idLoc) {
    return compileU3Gate(0, 0, lambda, idLoc);
}

std::vector<GateRequest> compileXGate(idLocationPairs idLoc) {
    return compileU3Gate(PI, 0, PI, idLoc);
}

std::vector<GateRequest> compileYGate(idLocationPairs idLoc) {
    return compileU3Gate(PI, PI / 2, PI / 2, idLoc);
}

std::vector<GateRequest> compileZGate(idLocationPairs idLoc) {
    return compileU1Gate(PI, idLoc);
}

std::vector<GateRequest> compileHGate(idLocationPairs idLoc) {
    return compileU2Gate(0, PI, idLoc);
}

std::vector<GateRequest> compileSGate(idLocationPairs idLoc) {
    return compileU1Gate(PI / 2, idLoc);
}

std::vector<GateRequest> compileSDGGate(idLocationPairs idLoc) {
    return compileU1Gate(-PI / 2, idLoc);
}

std::vector<GateRequest> compileTGate(idLocationPairs idLoc) {
    return compileU1Gate(PI / 4, idLoc);
}

std::vector<GateRequest> compileTDGGate(idLocationPairs idLoc) {
    return compileU1Gate(-PI / 4, idLoc);
}

// Standard Rotations //
std::vector<GateRequest> compileRXGate(double theta, idLocationPairs idLoc) {
    return compileU3Gate(theta, -PI / 2, PI / 2, idLoc);
}

std::vector<GateRequest> compileRYGate(double theta, idLocationPairs idLoc) {
    return compileU3Gate(theta, 0, 0, idLoc);
}

std::vector<GateRequest> compileRZGate(double phi, idLocationPairs idLoc) {
    return compileU1Gate(-PI / 4, idLoc);
}

// Standard User Defined Gates //
std::vector<GateRequest> compileSXGate(idLocationPairs idLoc) {
    std::vector<GateRequest> req = compileSDGGate(idLoc);
    req = attachGateRequests(req, compileHGate(idLoc));
    req = attachGateRequests(req, compileSDGGate(idLoc));
    return req;
}

std::vector<GateRequest> compileSXDGGate(idLocationPairs idLoc) {
    std::vector<GateRequest> req = compileSGate(idLoc);
    req = attachGateRequests(req, compileHGate(idLoc));
    req = attachGateRequests(req, compileSGate(idLoc));
    return req;
}

std::vector<GateRequest> compileCZGate(idLocationPairs idLoc) {
    if (idLoc.getSize() != 2) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairB;
    pairB.identifiers.push_back(idLoc.identifiers[1]);
    pairB.locations.push_back(idLoc.locations[1]);
    std::vector<GateRequest> req = compileHGate(pairB);
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compileHGate(pairB));
    return req;
}

std::vector<GateRequest> compileCYGate(idLocationPairs idLoc) {
    if (idLoc.getSize() != 2) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairB;
    pairB.identifiers.push_back(idLoc.identifiers[1]);
    pairB.locations.push_back(idLoc.locations[1]);
    std::vector<GateRequest> req = compileSDGGate(pairB);
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compileSGate(pairB));
    return req;
}

std::vector<GateRequest> compileSwapGate(idLocationPairs idLoc) {
    if (idLoc.getSize() != 2) {
        return std::vector<GateRequest>();
    }
    idLocationPairs swapped;
    swapped.identifiers.push_back(idLoc.identifiers[1]);
    swapped.identifiers.push_back(idLoc.identifiers[0]);
    swapped.locations.push_back(idLoc.locations[1]);
    swapped.locations.push_back(idLoc.locations[0]);

    std::vector<GateRequest> req = compileCXGate(idLoc);
    req = attachGateRequests(req, compileCXGate(swapped));
    req = attachGateRequests(req, compileCXGate(idLoc));
    return req;
}

std::vector<GateRequest> compileCHGate(idLocationPairs idLoc) {
    if (idLoc.getSize() != 2) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairA;
    pairA.identifiers.push_back(idLoc.identifiers[0]);
    pairA.locations.push_back(idLoc.locations[0]);
    idLocationPairs pairB;
    pairB.identifiers.push_back(idLoc.identifiers[1]);
    pairB.locations.push_back(idLoc.locations[1]);

    std::vector<GateRequest> req = compileHGate(pairB);
    req = attachGateRequests(req, compileSDGGate(pairB));
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compileHGate(pairB));
    req = attachGateRequests(req, compileTGate(pairB));
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compileTGate(pairB));
    req = attachGateRequests(req, compileHGate(pairB));
    req = attachGateRequests(req, compileSGate(pairB));
    req = attachGateRequests(req, compileXGate(pairB));
    req = attachGateRequests(req, compileSGate(pairA));
}

std::vector<GateRequest> compileCCXGate(idLocationPairs idLoc) {
    if (idLoc.getSize() != 3) {
        return std::vector<GateRequest>();
    }

    idLocationPairs pairA = fetchIDLoc(idLoc, 0);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);
    idLocationPairs pairC = fetchIDLoc(idLoc, 2);

    std::vector<GateRequest> req = compileHGate(pairC);
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairB, pairC)));
    req = attachGateRequests(req, compileTDGGate(pairC));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairC)));
    req = attachGateRequests(req, compileTGate(pairC));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairB, pairC)));
    req = attachGateRequests(req, compileTDGGate(pairC));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairC)));
    req = attachGateRequests(req, compileTGate(pairB));
    req = attachGateRequests(req, compileTGate(pairC));
    req = attachGateRequests(req, compileHGate(pairC));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairB)));
    req = attachGateRequests(req, compileTGate(pairA));
    req = attachGateRequests(req, compileTDGGate(pairB));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairB)));
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
    GateRequestType gtType = getGateTypeM(gateType);
    switch (gtType) {
    case cx:
        return compileCXGate(idLoc);
    case h:
        return compileHGate(idLoc);
    }
    return std::vector<GateRequest>();
}
std::vector<GateRequest> compileCompoundGateRequest(std::string gateType, std::vector<double> params, idLocationPairs idLoc)
{
    GateRequestType gtType = getGateTypeM(gateType);
    switch (gtType) {
    case u3:
        if (params.size() == 3) {
            return compileU3Gate(params[0], params[1], params[2], idLoc);
        }
        break;
    }
    return std::vector<GateRequest>();
}
