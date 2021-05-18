#include "ParsingGateUtilities.h"
#include <functional>

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

std::vector<GateRequest> compileCSwapGate(idLocationPairs idLoc) {
    if (idLoc.getSize() != 3) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairC = fetchIDLoc(idLoc, 2);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);
    std::vector<GateRequest> req = compileCXGate(zipIDLoc(pairC, pairB));
    req = attachGateRequests(req, compileCCXGate(idLoc));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairC, pairB)));
    return req;
}

std::vector<GateRequest> compileCRXGate(double lambda, idLocationPairs idLoc) {
    if (idLoc.getSize() != 2) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairA = fetchIDLoc(idLoc, 0);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);

    std::vector<GateRequest> req = compileU1Gate(PI / 2, pairB);
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compileU3Gate(-lambda / 2, 0, 0, pairB));
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compileU3Gate(lambda / 2, -PI / 2, 0, pairB));
    return req;
}

std::vector<GateRequest> compileCRYGate(double lambda, idLocationPairs idLoc) {
    if (idLoc.getSize() != 2) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairA = fetchIDLoc(idLoc, 0);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);

    std::vector<GateRequest> req = compileRYGate(lambda / 2, pairB);
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compileRYGate(-lambda / 2, pairB));
    req = attachGateRequests(req, compileCXGate(idLoc));
    return req;
}

std::vector<GateRequest> compileCRZGate(double lambda, idLocationPairs idLoc) {
    if (idLoc.getSize() != 2) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairA = fetchIDLoc(idLoc, 0);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);
    std::vector<GateRequest> req = compileRZGate(lambda / 2, pairB);
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compileRZGate(-lambda / 2, pairB));
    req = attachGateRequests(req, compileCXGate(idLoc));
    return req;
}

std::vector<GateRequest> compileCU1Gate(double lambda, idLocationPairs idLoc) {
    if (idLoc.getSize() != 2) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairA = fetchIDLoc(idLoc, 0);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);

    std::vector<GateRequest> req = compileU1Gate(lambda / 2, pairA);
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compileU1Gate(-lambda / 2, pairB));
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compileU1Gate(lambda / 2, pairB));

    return req;
}

std::vector<GateRequest> compileCPGate(double lambda, idLocationPairs idLoc) {
    if (idLoc.getSize() != 2) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairA = fetchIDLoc(idLoc, 0);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);

    std::vector<GateRequest> req = compilePGate(lambda / 2, pairA);
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compilePGate(-lambda / 2, pairB));
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compilePGate(lambda / 2, pairB));
    return req;
}

std::vector<GateRequest> compileCU3Gate(double theta, double phi, double lambda, idLocationPairs idLoc) {
    if (idLoc.getSize() != 2) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairA = fetchIDLoc(idLoc, 0);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);

    std::vector<GateRequest> req = compileU1Gate((lambda + phi) / 2, pairA);
    req = attachGateRequests(req, compileU1Gate((lambda - phi) / 2, pairB));
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compileU3Gate(-theta / 2, 0, -(phi + lambda) / 2, pairB));
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compileU3Gate(theta / 2, phi, 0, pairB));
    return req;
}

std::vector<GateRequest> compileCSXGate(idLocationPairs idLoc) {
    if (idLoc.getSize() != 2) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairA = fetchIDLoc(idLoc, 0);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);

    std::vector<GateRequest> req = compileHGate(pairB);
    req = attachGateRequests(req, compileCU1Gate(PI / 2, idLoc));
    req = attachGateRequests(req, compileHGate(pairB));
    return req;
}

std::vector<GateRequest> compileCUGate(double theta, double phi, double lambda, double gamma, idLocationPairs idLoc) {
    if (idLoc.getSize() != 2) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairA = fetchIDLoc(idLoc, 0);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);
    std::vector<GateRequest> req = compilePGate(gamma, pairA);
    req = attachGateRequests(req, compilePGate((lambda + phi) / 2, pairA));
    req = attachGateRequests(req, compilePGate((lambda - phi) / 2, pairB));
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compileUGate(-theta / 2, 0, -(phi + lambda) / 2, pairB));
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compileUGate(theta / 2, phi, 0, pairB));
    return req;
}

std::vector<GateRequest> compileRXXGate(double theta, idLocationPairs idLoc) {
    if (idLoc.getSize() != 2) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairA = fetchIDLoc(idLoc, 0);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);

    std::vector<GateRequest> req = compileU3Gate(PI / 2, theta, 0, pairA);
    req = attachGateRequests(req, compileHGate(pairB));
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compileU1Gate(-theta, pairB));
    req = attachGateRequests(req, compileCXGate(idLoc));
    req = attachGateRequests(req, compileHGate(pairB));
    req = attachGateRequests(req, compileU2Gate(-PI,PI - theta, pairA));
    return req;
}

std::vector<GateRequest> compileRZZGate(double theta, idLocationPairs idLoc) {
    if (idLoc.getSize() != 2) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairA = fetchIDLoc(idLoc, 0);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);

    std::vector<GateRequest> req = compileCXGate(idLoc);
    req = attachGateRequests(req, compileU1Gate(theta, pairB));
    req = attachGateRequests(req, compileCXGate(idLoc));
    return req;
}

std::vector<GateRequest> compileRCCXGate(idLocationPairs idLoc) {
    if (idLoc.getSize() != 3) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairA = fetchIDLoc(idLoc, 0);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);
    idLocationPairs pairC = fetchIDLoc(idLoc, 2);

    std::vector<GateRequest> req = compileU2Gate(0, PI, pairC);
    req = attachGateRequests(req, compileU1Gate(PI / 4, pairC));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairB, pairC)));
    req = attachGateRequests(req, compileU1Gate(-PI / 4, pairC));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairC)));
    req = attachGateRequests(req, compileU1Gate(PI / 4, pairC));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairB, pairC)));
    req = attachGateRequests(req, compileU1Gate(-PI / 4, pairC));
    req = attachGateRequests(req, compileU2Gate(0, PI, pairC));
    return req;
}

std::vector<GateRequest> compileRC3XGate(idLocationPairs idLoc) {
    if (idLoc.getSize() != 4) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairA = fetchIDLoc(idLoc, 0);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);
    idLocationPairs pairC = fetchIDLoc(idLoc, 2);
    idLocationPairs pairD = fetchIDLoc(idLoc, 3);

    std::vector<GateRequest> req = compileU2Gate(0, PI, pairD);
    req = attachGateRequests(req, compileU1Gate(PI / 4, pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairC, pairD)));
    req = attachGateRequests(req, compileU1Gate(-PI / 4, pairD));
    req = attachGateRequests(req, compileU2Gate(0, PI, pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairD)));
    req = attachGateRequests(req, compileU1Gate(PI / 4, pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairB, pairD)));
    req = attachGateRequests(req, compileU1Gate(-PI / 4, pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairD)));
    req = attachGateRequests(req, compileU1Gate(PI / 4, pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairB, pairD)));
    req = attachGateRequests(req, compileU1Gate(-PI / 4, pairD));
    req = attachGateRequests(req, compileU2Gate(0, PI, pairD));
    req = attachGateRequests(req, compileU1Gate(PI / 4, pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairC, pairD)));
    req = attachGateRequests(req, compileU1Gate(-PI / 4, pairD));
    req = attachGateRequests(req, compileU2Gate(0, PI, pairD));
    return req;
}

std::vector<GateRequest> compileC3XGate(idLocationPairs idLoc) {
    if (idLoc.getSize() != 4) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairA = fetchIDLoc(idLoc, 0);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);
    idLocationPairs pairC = fetchIDLoc(idLoc, 2);
    idLocationPairs pairD = fetchIDLoc(idLoc, 3);

    std::vector<GateRequest> req = compileHGate(pairD);
    req = attachGateRequests(req, compilePGate(PI / 8, pairA));
    req = attachGateRequests(req, compilePGate(PI / 8, pairB));
    req = attachGateRequests(req, compilePGate(PI / 8, pairC));
    req = attachGateRequests(req, compilePGate(PI / 8, pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairB)));
    req = attachGateRequests(req, compilePGate(-PI / 8, pairB));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairB)));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairB, pairC)));
    req = attachGateRequests(req, compilePGate(-PI / 8, pairC));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairC)));
    req = attachGateRequests(req, compilePGate(PI / 8, pairC));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairB, pairC)));
    req = attachGateRequests(req, compilePGate(-PI / 8, pairC));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairC)));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairC, pairD)));
    req = attachGateRequests(req, compilePGate(-PI / 8, pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairB, pairD)));
    req = attachGateRequests(req, compilePGate(PI / 8, pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairC, pairD)));
    req = attachGateRequests(req, compilePGate(-PI / 8, pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairD)));
    req = attachGateRequests(req, compilePGate(PI / 8, pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairC, pairD)));
    req = attachGateRequests(req, compilePGate(-PI / 8, pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairB, pairD)));
    req = attachGateRequests(req, compilePGate(PI / 8, pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairC, pairD)));
    req = attachGateRequests(req, compilePGate(-PI / 8, pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairD)));
    req = attachGateRequests(req, compileHGate(pairD));
    return req;
}

std::vector<GateRequest> compileC3SQRTGate(idLocationPairs idLoc) {
    if (idLoc.getSize() != 4) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairA = fetchIDLoc(idLoc, 0);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);
    idLocationPairs pairC = fetchIDLoc(idLoc, 2);
    idLocationPairs pairD = fetchIDLoc(idLoc, 3);

    std::vector<GateRequest> req = compileHGate(pairD);
    req = attachGateRequests(req, compileCU1Gate(-PI / 8, zipIDLoc(pairA, pairD)));
    req = attachGateRequests(req, compileHGate(pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairB)));
    req = attachGateRequests(req, compileHGate(pairD));
    req = attachGateRequests(req, compileCU1Gate(PI / 8, zipIDLoc(pairB, pairD)));
    req = attachGateRequests(req, compileHGate(pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairB)));
    req = attachGateRequests(req, compileHGate(pairD));
    req = attachGateRequests(req, compileCU1Gate(-PI / 8, zipIDLoc(pairB, pairD)));
    req = attachGateRequests(req, compileHGate(pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairB, pairC)));
    req = attachGateRequests(req, compileHGate(pairD));
    req = attachGateRequests(req, compileCU1Gate(PI / 8, zipIDLoc(pairC, pairD)));
    req = attachGateRequests(req, compileHGate(pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairC)));
    req = attachGateRequests(req, compileHGate(pairD));
    req = attachGateRequests(req, compileCU1Gate(-PI / 8, zipIDLoc(pairC, pairD)));
    req = attachGateRequests(req, compileHGate(pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairB, pairC)));
    req = attachGateRequests(req, compileHGate(pairD));
    req = attachGateRequests(req, compileCU1Gate(PI / 8, zipIDLoc(pairC, pairD)));
    req = attachGateRequests(req, compileHGate(pairD));
    req = attachGateRequests(req, compileCXGate(zipIDLoc(pairA, pairC)));
    req = attachGateRequests(req, compileHGate(pairD));
    req = attachGateRequests(req, compileCU1Gate(-PI / 8, zipIDLoc(pairC, pairD)));
    req = attachGateRequests(req, compileHGate(pairD));
    return req;
}

std::vector<GateRequest> compileC4XGate(idLocationPairs idLoc) {
    if (idLoc.getSize() != 5) {
        return std::vector<GateRequest>();
    }
    idLocationPairs pairA = fetchIDLoc(idLoc, 0);
    idLocationPairs pairB = fetchIDLoc(idLoc, 1);
    idLocationPairs pairC = fetchIDLoc(idLoc, 2);
    idLocationPairs pairD = fetchIDLoc(idLoc, 3);
    idLocationPairs pairE = fetchIDLoc(idLoc, 4);

    std::vector<GateRequest> req = compileHGate(pairE);
    req = attachGateRequests(req, compileCU1Gate(-PI / 2, zipIDLoc(pairD, pairE)));
    req = attachGateRequests(req, compileHGate(pairE));
    req = attachGateRequests(req, compileC3XGate(zipIDLoc(zipIDLoc(pairA, pairB), zipIDLoc(pairC, pairD))));
    req = attachGateRequests(req, compileHGate(pairE));
    req = attachGateRequests(req, compileCU1Gate(PI / 2, zipIDLoc(pairD, pairE)));
    req = attachGateRequests(req, compileHGate(pairE));
    req = attachGateRequests(req, compileC3XGate(zipIDLoc(zipIDLoc(pairA, pairB), zipIDLoc(pairC, pairD))));
    req = attachGateRequests(req, compileC3SQRTGate(zipIDLoc(zipIDLoc(pairA, pairB), zipIDLoc(pairC, pairE))));
    return req;

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
    case id:
        return compileIDGate(idLoc);
    case x:
        return compileXGate(idLoc);
    case y:
        return compileYGate(idLoc);
    case z:
        return compileZGate(idLoc);
    case h:
        return compileHGate(idLoc);
    case s:
        return compileSGate(idLoc);
    case sdg:
        return compileSDGGate(idLoc);
    case t:
        return compileTGate(idLoc);
    case tdg:
        return compileTDGGate(idLoc);
    case sx:
        return compileSXGate(idLoc);
    case sxdg:
        return compileSXDGGate(idLoc);
    case cz:
        return compileCZGate(idLoc);
    case cy:
        return compileCYGate(idLoc);
    case swap:
        return compileSwapGate(idLoc);
    case ch:
        return compileCHGate(idLoc);
    case ccx:
        return compileCCXGate(idLoc);
    case cswap:
        return compileCSwapGate(idLoc);
    case csx:
        return compileCSXGate(idLoc);
    case rccx:
        return compileRCCXGate(idLoc);
    case rc3x:
        return compileRC3XGate(idLoc);
    case c3x:
        return compileC3XGate(idLoc);
    case c3sqrtx:
        return compileC3SQRTGate(idLoc);
    case c4x:
        return compileC4XGate(idLoc);
    default:
        return std::vector<GateRequest>();
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
    case u2:
        if (params.size() == 2) {
            return compileU2Gate(params[0], params[1], idLoc);
        }
        break;
    case u1:
        if (params.size() == 1) {
            return compileU1Gate(params[0], idLoc);
        }
        break;
    case u0:
        if (params.size() == 1) {
            return compileU0Gate(params[0], idLoc);
        }
        break;
    case u:
        if (params.size() == 3) {
            return compileUGate(params[0], params[1], params[2], idLoc);
        }
        break;
    case p:
        if (params.size() == 1) {
            return compilePGate(params[0], idLoc);
        }
        break;
    case rx:
        if (params.size() == 1) {
            return compileRXGate(params[0], idLoc);
        }
        break;
    case ry:
        if (params.size() == 1) {
            return compileRYGate(params[0], idLoc);
        }
        break;
    case rz:
        if (params.size() == 1) {
            return compileRZGate(params[0], idLoc);
        }
        break;
    case crx:
        if (params.size() == 1) {
            return compileCRXGate(params[0], idLoc);
        }
        break;
    case cry:
        if (params.size() == 1) {
            return compileCRYGate(params[0], idLoc);
        }
        break;
    case crz:
        if (params.size() == 1) {
            return compileCRZGate(params[0], idLoc);
        }
        break;
    case cu1:
        if (params.size() == 1) {
            return compileCU1Gate(params[0], idLoc);
        }
        break;
    case cp:
        if (params.size() == 1) {
            return compileCPGate(params[0], idLoc);
        }
        break;
    case cu3:
        if (params.size() == 3) {
            return compileCU3Gate(params[0], params[1], params[2], idLoc);
        }
        break;
    case cu:
        if (params.size() == 4) {
            return compileCUGate(params[0], params[1], params[2], params[3], idLoc);
        }
        break;
    case rxx:
        if (params.size() == 1) {
            return compileRXXGate(params[0], idLoc);
        }
        break;
    case rzz:
        if (params.size() == 1) {
            return compileRZZGate(params[0], idLoc);
        }
        break;
    default:
        return std::vector<GateRequest>();
    }
    return std::vector<GateRequest>();
}

int findMin(std::vector<int> values) {
    int minSoFar = INT_MAX;
    int loc = 0;
    for (int i = 0; i < values.size(); i++) {
        if (values[i] < minSoFar) {
            minSoFar = values[i];
            loc = i;
        }
    }
    return loc;
}

int findMax(std::vector<int> values) {
    int maxSoFar = 0;
    int loc = 0;
    for (int i = 0; i < values.size(); i++) {
        if (values[i] > maxSoFar) {
            maxSoFar = values[i];
            loc = i;
        }
    }
    return loc;
}

std::vector<int> findMinMax(std::vector<std::vector<int>> paramsForGate, std::vector<std::vector<int>> locationsPerGate) {
    std::vector<int> minForParams, maxForParams, minForLocations, maxForLocations, result;
    for (int i = 0; i < paramsForGate.size(); i++) {
        minForParams.push_back(paramsForGate[i][findMin(paramsForGate[i])]);
        maxForParams.push_back(paramsForGate[i][findMax(paramsForGate[i])]);
    }
    for (int i = 0; i < locationsPerGate.size(); i++) {
        minForLocations.push_back(locationsPerGate[i][findMin(locationsPerGate[i])]);
        maxForLocations.push_back(locationsPerGate[i][findMax(locationsPerGate[i])]);
    }
    if (paramsForGate.size() == 0) {
        minForParams.push_back(0);
        maxForParams.push_back(0);
    }
    result = { minForParams[findMin(minForParams)], maxForParams[findMax(maxForParams)], minForLocations[findMin(minForLocations)], maxForLocations[findMax(maxForLocations)]};
    return result;
}

struct gateCoupling {
    std::string gateName;
    std::vector<doubleOrArg> paramLocations;
    std::vector<int> idLocations;
    gateCoupling(std::string name, std::vector<doubleOrArg> param, std::vector<int> idLoc) {
        gateName = name;
        paramLocations = param;
        idLocations = idLoc;
    }
};


std::function <std::vector<GateRequest>(std::vector<double> params, idLocationPairs idLoc)> compileCustomGateInternal(std::vector<std::string> gates, std::vector<std::vector<doubleOrArg>> paramsForGate, std::vector<std::vector<int>> locationsPerGate) {
    std::vector<gateCoupling> couplings;
    for (int i = 0; i < gates.size(); i++) {
        couplings.push_back(gateCoupling(gates[i], paramsForGate[i], locationsPerGate[i]));
    }
    std::function <std::vector<GateRequest>(std::vector<double> params, idLocationPairs idLoc)> deltaFunc = [couplings](std::vector<double> params, idLocationPairs idLoc) {
        std::vector<GateRequest> requests;
        for (auto coupling : couplings) {
            std::vector<double> localParams;
            for (int i = 0; i < coupling.paramLocations.size(); i++) {
                doubleOrArg da = coupling.paramLocations[i];
                if (da.doubleNotArg) {
                    localParams.push_back(da.valD);
                }
                else {
                    localParams.push_back(params[da.position]);
                }
            }
            idLocationPairs localPairs;
            for (int i = 0; i < coupling.idLocations.size(); i++) {
                localPairs = zipIDLoc(localPairs, fetchIDLoc(idLoc, coupling.idLocations[i]));
            }
            if (localParams.size() > 0) {
                requests = attachGateRequests(requests, compileCompoundGateRequest(coupling.gateName, localParams, localPairs));
            }
            else {
                requests = attachGateRequests(requests, compileCompoundGateRequest(coupling.gateName, localPairs));
            }
        }
        return requests;
    };
    return deltaFunc;
}

std::function<std::vector<GateRequest>(std::vector<double>params, idLocationPairs idLoc)> compileCustomGate(gateDeclaration decl, std::vector<gateOp> gateOperations)
{
    std::map<std::string, int> paramToLocation, idLocToLocation;
    std::vector<std::string> params = decl.paramList;
    for (int i = 0; i < params.size(); i++) {
        paramToLocation[params[i]] = i;
    }
    std::vector<std::string> idLocs = decl.idLocList;
    for (int i = 0; i < idLocs.size(); i++) {
        idLocToLocation[idLocs[i]] = i;
    }
    std::vector<std::string> gates;
    std::vector<std::vector<doubleOrArg>> paramLocs;
    std::vector<std::vector<int>> idLocsI;
    for (auto gop : gateOperations) {
        gates.push_back(gop.gateName);
        std::vector<doubleOrArg> parmsLocal;
        for (int i = 0; i < gop.params.size(); i++) {
            if (gop.params[i].identNotVal) {
                doubleOrArg arg;
                arg.doubleNotArg = false;
                arg.position = paramToLocation[gop.params[i].ident];
                parmsLocal.push_back(arg);
            } else{
                doubleOrArg doub;
                doub.doubleNotArg = true;
                doub.valD = gop.params[i].value;
                parmsLocal.push_back(doub);
            }
        }
        std::vector<int> idLocal;
        for (int i = 0; i < gop.idLocs.size(); i++) {
            idLocal.push_back(idLocToLocation[gop.idLocs[i]]);
        }
        paramLocs.push_back(parmsLocal);
        idLocsI.push_back(idLocal);
    }
    return compileCustomGateInternal(gates, paramLocs, idLocsI);
}
