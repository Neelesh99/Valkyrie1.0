#include "ValkyrieTests.h"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "antlr4-runtime.h"
#include "../libs/qasm2Lexer.h"
#include "../libs/qasm2Parser.h"
#include "../libs/qasm2Visitor.h"
#include "../libs/qasm2BaseVisitor.h"
#include "../libs/staging.h"
#include "../libs/CPUDevice.h"
#include "../libs/GPUDevice.cuh"
#include "../libs/Measurement.h"
#include <Windows.h>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>

using namespace antlr4;

// Parser Tests
bool parserTest1() {
	std::ifstream stream;
    stream.open("test/parserTest1.qasm");
    if (!stream.is_open()) {
        std::cout << "Couldn't find file specified" << std::endl;
        return false;
    }
    ANTLRInputStream input(stream);

    qasm2Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    qasm2Parser parser(&tokens);

    qasm2Parser::MainprogContext* tree = parser.mainprog();

    qasm2BaseVisitor visitor;
    visitor.visitMainprog(tree);
    std::vector<Register> registers = visitor.getRegisters();
    std::vector<GateRequest> gateRequests = visitor.getGates();
    std::vector<MeasureCommand> commands = visitor.getMeasureCommands();

    // Testing registers
    if (registers.size() != 2) {
        return false;
    }
    Register qReg = registers[0];
    Register cReg = registers[1];

    // Checking Quantum register parameters
    if (!(qReg.getName() == "q") || !(qReg.getQuantumRegister().getWidth() == 3)) {
        return false;
    }

    // Checking Classical register parameters
    if (!(cReg.getName() == "c") || !(cReg.getClassicalRegister().getWidth() == 3)) {
        return false;
    }
    return true;
}

bool parserTest2() {
    std::ifstream stream;
    stream.open("test/parserTest2.qasm");
    if (!stream.is_open()) {
        std::cout << "Couldn't find file specified" << std::endl;
        return false;
    }
    ANTLRInputStream input(stream);

    qasm2Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    qasm2Parser parser(&tokens);

    qasm2Parser::MainprogContext* tree = parser.mainprog();

    qasm2BaseVisitor visitor;
    visitor.visitMainprog(tree);
    std::vector<Register> registers = visitor.getRegisters();
    std::vector<GateRequest> gateRequests = visitor.getGates();
    std::vector<MeasureCommand> commands = visitor.getMeasureCommands();

    // Testing registers
    if (registers.size() != 2) {
        return false;
    }
    Register qReg = registers[0];
    Register cReg = registers[1];

    // Checking Quantum register parameters
    if (!(qReg.getName() == "q") || !(qReg.getQuantumRegister().getWidth() == 3)) {
        return false;
    }

    // Checking Classical register parameters
    if (!(cReg.getName() == "c") || !(cReg.getClassicalRegister().getWidth() == 3)) {
        return false;
    }

    // Checking Hadamard gate operation
    if (!(gateRequests.size() == 1)) {
        return false;
    }
    GateRequest gate = gateRequests[0];
    if (!(gate.getGateType() == U)) {
        return false;
    }
    std::vector<double> params = gate.getParameters();
    if (params.size() != 3) {
        return false;
    }
    const double PIc = 3.1415926535;
    if (!(params[0] == PIc / 2) || !(params[1] == 0) || !(params[2] == PIc)) {
        return false;
    }
    return true;
}

bool parserTest3() {
    std::ifstream stream;
    stream.open("test/parserTest3.qasm");
    if (!stream.is_open()) {
        std::cout << "Couldn't find file specified" << std::endl;
        return false;
    }
    ANTLRInputStream input(stream);

    qasm2Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    qasm2Parser parser(&tokens);

    qasm2Parser::MainprogContext* tree = parser.mainprog();

    qasm2BaseVisitor visitor;
    visitor.visitMainprog(tree);
    std::vector<Register> registers = visitor.getRegisters();
    std::vector<GateRequest> gateRequests = visitor.getGates();
    std::vector<MeasureCommand> commands = visitor.getMeasureCommands();

    // Testing registers
    if (registers.size() != 2) {
        return false;
    }
    Register qReg = registers[0];
    Register cReg = registers[1];

    // Checking Hadamard gate operation
    if (!(gateRequests.size() == 2)) {
        return false;
    }
    GateRequest gate = gateRequests[1];
    if (!(gate.getGateType() == CX)) {
        return false;
    }
    std::vector<std::string> identifiers = gate.getRegisters();
    std::vector<int> locations = gate.getLocations();
    const double PIc = 3.1415926535;
    if (!(identifiers[0] == "q") || !(identifiers[1] == "q")) {
        return false;
    }
    if (!(locations[0] == 0) || !(locations[1] == 1)) {
        return false;
    }
    return true;
}

bool parserTest4() {
    std::ifstream stream;
    stream.open("test/parserTest4.qasm");
    if (!stream.is_open()) {
        std::cout << "Couldn't find file specified" << std::endl;
        return false;
    }
    ANTLRInputStream input(stream);

    qasm2Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    qasm2Parser parser(&tokens);

    qasm2Parser::MainprogContext* tree = parser.mainprog();

    qasm2BaseVisitor visitor;
    visitor.visitMainprog(tree);
    std::vector<Register> registers = visitor.getRegisters();
    std::vector<GateRequest> gateRequests = visitor.getGates();
    std::vector<MeasureCommand> commands = visitor.getMeasureCommands();

    // Testing registers
    if (registers.size() != 2) {
        return false;
    }
    Register qReg = registers[0];
    Register cReg = registers[1];

    // Checking Hadamard gate operation
    if (commands.size() != 1) {
        return false;
    }
    MeasureCommand command = commands[0];
    if (!(command.getFrom().identifiers[0] == "q") || !(command.getTo().identifiers[0] == "c")) {
        return false;
    }
    if (!(command.getFrom().locations[0] == 0) || !(command.getTo().locations[0] == 0)) {
        return false;
    }
    return true;
}


void ValkyrieTests::runParserTests() {

    // Basic Register set-up test
    handleTestResult(parserTest1(), "Parser Test: Basic Register set up");
    // Register setup and simple gate applications
    handleTestResult(parserTest2(), "Parser Test: Simple Gate application");
    // Register setup and CX multi qubit gate application
    handleTestResult(parserTest3(), "Parser Test: CX multi-qubit gate application");
    // Measure command setup check
    handleTestResult(parserTest4(), "Parser Test: Checking Measure command operation");
}


ValkyrieTests::ValkyrieTests()
{
	total_ = 1;
	passed_ = 1;
}

void ValkyrieTests::runTests()
{
	// Valkyrie Test Suite
    // Parser Tests
    runParserTests();
}

void ValkyrieTests::handleTestResult(bool res, std::string testDescription)
{
    total_++;
    if (res) {
        passed_++;
        passedTests.push_back(testDescription);
    }
    else {
        failedTests.push_back(testDescription);
    }
}

double ValkyrieTests::getPercentagePassed()
{
	return 100 * (double) passed_ / (double) total_;
}

std::vector<std::string> ValkyrieTests::testsFailed()
{
	return failedTests;
}
