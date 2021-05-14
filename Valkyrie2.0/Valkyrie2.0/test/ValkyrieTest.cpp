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
#include "../libs/ParsingGateUtilities.h"
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

bool parserTest5() {
    std::ifstream stream;
    stream.open("test/parserTest5.qasm");
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

    // Testing gate registrations
    if (!(gateRequests.size() == 3)) {
        return false;
    }

    for (auto gate : gateRequests) {
        if (!(gate.getGateType() == U)) {
            return false;
        }
    }

    GateRequest sdg1 = gateRequests[0];
    GateRequest h1 = gateRequests[1];
    GateRequest sdg2 = gateRequests[2];
    const double PIc = 3.1415926535;
    if (!(sdg1.getParameters()[2] == -PIc / 2) || !(sdg2.getParameters()[2] == -PIc / 2)) {
        return false;
    }
    return true;
}

// Staging Tests
bool stagingTest1(std::vector<Register> mockReg1, std::vector<GateRequest> mockGateRequest1) {
    Stager stager = Stager(mockReg1, mockGateRequest1);
    std::vector<ConcurrentBlock> blocks = stager.getConcurrencyBlocks();
    if (blocks.size() != 2) {
        return false;
    }
    std::vector<GateRequest> req1 = blocks[0].getGates();
    std::vector<GateRequest> req2 = blocks[1].getGates();
    if (!(req1.size() == 1) || !(req2.size() == 1)) {
        return false;
    }
    if (!(req1[0].getGateType() == CX) || !(req2[0].getGateType() == U)) {
        return false;
    }
    return true;
}

bool stagingTest2(std::vector<Register> mockReg1, std::vector<GateRequest> mockGateRequest1) {
    Stager stager = Stager(mockReg1, mockGateRequest1);
    std::vector<ConcurrentBlock> blocks = stager.getConcurrencyBlocks();
    if (blocks.size() != 2) {
        return false;
    }
    std::vector<GateRequest> req1 = blocks[0].getGates();
    std::vector<GateRequest> req2 = blocks[1].getGates();
    if (!(req1.size() == 1) || !(req2.size() == 2)) {
        return false;
    }
    if (!(req1[0].getGateType() == CX) || !(req2[0].getGateType() == U) || !(req2[1].getGateType() == U)) {
        return false;
    }
    return true;
}

bool stagingTest3(std::vector<Register> mockReg1, std::vector<GateRequest> mockGateRequest1) {
    Stager stager = Stager(mockReg1, mockGateRequest1);
    std::vector<ConcurrentBlock> blocks = stager.getConcurrencyBlocks();
    if (blocks.size() != 3) {
        return false;
    }
    std::vector<GateRequest> req1 = blocks[0].getGates();
    std::vector<GateRequest> req2 = blocks[1].getGates();
    std::vector<GateRequest> req3 = blocks[2].getGates();
    if (!(req1.size() == 1) || !(req2.size() == 2) || !(req3.size() == 1)) {
        return false;
    }
    if (!(req1[0].getGateType() == CX) || !(req2[0].getGateType() == U) || !(req2[1].getGateType() == U)) {
        return false;
    }
    if (!(req3[0].getGateType() == CX)) {
        return false;
    }
    return true;
}

// CPU Device Tests
bool cpuQubitFactoryTest() {
    CPUQubitFactory cpuQubitFactory = CPUQubitFactory();
    Qubit* newQubit = cpuQubitFactory.generateQubit();
    if (!newQubit) {
        return false;
    }
    return true;
}

bool cpuGateFactoryTest() {
    CPUGateFactory gateFactory = CPUGateFactory();
    idLocationPairs pair;
    pair.identifiers.push_back("q");
    pair.locations.push_back(0);
    GateRequest hadamardGate = compileCompoundGateRequest("h", pair)[0];
    Gate* gate = gateFactory.generateGate(hadamardGate);
    if (!gate) {
        return false;
    }
    double oneOverSQRT2 = (1 / std::pow(2, 0.5));
    double diff1 = gate->fetchValue(0, 0).real() - oneOverSQRT2;
    double diff2 = gate->fetchValue(0, 1).real() - oneOverSQRT2;
    double diff3 = gate->fetchValue(1, 0).real() - oneOverSQRT2;
    double diff4 = gate->fetchValue(1, 1).real() + oneOverSQRT2;
    if (!(diff1 + diff2 + diff3 + diff4 < std::pow(10, -9))) {          // Some numerical differences expexcted since we have fixed precisiona nd PI to 10 dp
        return false;
    }
    return true;
}

bool cpuQuantumCircuitTest() {

    CPUQubitFactory cpuQubitFactory = CPUQubitFactory();
    Qubit* newQubit = cpuQubitFactory.generateQubit();
    Qubit* newQubit2 = cpuQubitFactory.generateQubit();

    // Set up required gate factory
    CPUGateFactory* gateFactory = &CPUGateFactory();
    CPUQuantumCircuit circuit = CPUQuantumCircuit(gateFactory);
    
    // Set up required qubit map
    std::map<std::string, std::vector<Qubit*>> qubitMap{
        {"q", {newQubit, newQubit2}}
    };

    // Set up required concurrency blocks
    std::vector<Register> mockReg1;
    std::vector<GateRequest> mockGateRequest1;
    idLocationPairs mockPair;
    mockPair.identifiers.push_back("q");
    mockPair.locations.push_back(0);
    idLocationPairs mockPair2 = mockPair;
    mockPair.identifiers.push_back("q");
    mockPair.locations.push_back(1);

    mockGateRequest1 = compileCompoundGateRequest("cx", mockPair);
    mockGateRequest1.push_back(compileCompoundGateRequest("h", mockPair2)[0]);
    Stager stager = Stager(mockReg1, mockGateRequest1);
    std::vector<ConcurrentBlock> blocks = stager.getConcurrencyBlocks();
    
    // Load qubitMap
    circuit.loadQubitMap(qubitMap);
    // Load first concurrency block
    circuit.loadBlock(blocks[0]);
    std::vector<Calculation> calculations = circuit.getNextCalculation();
    if (!(calculations.size() == 1)) {
        return false;
    }
    Calculation firstCalc = calculations[0];
    if (!(firstCalc.getQubit(0) == newQubit) || !(firstCalc.getQubit(1) == newQubit2)) {
        return false;
    }
    return true;
}

bool cpuDeviceAllUpTest() {
    // Setting up all required info
    std::vector<Register> mockReg1;
    QuantumRegister qReg = QuantumRegister("q", 3);
    ClassicalRegister cReg = ClassicalRegister("c", 3);
    Register qRegWrapped = Register(quantum_, qReg);
    Register cRegWrapped = Register(classical_, cReg);
    mockReg1.push_back(qRegWrapped);
    mockReg1.push_back(cRegWrapped);
    std::vector<GateRequest> mockGateRequest1;
    idLocationPairs mockPair;
    mockPair.identifiers.push_back("q");
    mockPair.locations.push_back(0);
    idLocationPairs mockPair2 = mockPair;
    mockPair.identifiers.push_back("q");
    mockPair.locations.push_back(1);

    mockGateRequest1 = compileCompoundGateRequest("cx", mockPair);
    mockGateRequest1.push_back(compileCompoundGateRequest("h", mockPair2)[0]);
    mockGateRequest1.push_back(compileCompoundGateRequest("h", mockPair2)[0]);
    mockGateRequest1.push_back(compileCompoundGateRequest("cx", mockPair)[0]);
    Stager stager = Stager(mockReg1, mockGateRequest1);

    std::vector<ConcurrentBlock> blocks = stager.getConcurrencyBlocks();

    CPUDevice device = CPUDevice();
    device.run(mockReg1, blocks);
    std::map<std::string, std::vector<Qubit*>> results = device.revealQuantumState();
    if (!(results["q"][0]->fetch(0)->real() == 1) || !(results["q"][1]->fetch(0)->real() == 1)) {
        return false;
    }
    return true;
}

// GPU Device Tests
bool gpuQubitFactoryTest() {
    GPUQubitFactory cpuQubitFactory = GPUQubitFactory();
    Qubit* newQubit = cpuQubitFactory.generateQubit();
    if (!newQubit) {
        return false;
    }
    return true;
}

bool gpuGateFactoryTest() {
    GPUGateFactory gateFactory = GPUGateFactory();
    idLocationPairs pair;
    pair.identifiers.push_back("q");
    pair.locations.push_back(0);
    GateRequest hadamardGate = compileCompoundGateRequest("h", pair)[0];
    Gate* gate = gateFactory.generateGate(hadamardGate);
    if (!gate) {
        return false;
    }
    double oneOverSQRT2 = (1 / std::pow(2, 0.5));
    double diff1 = gate->fetchValue(0, 0).real() - oneOverSQRT2;
    double diff2 = gate->fetchValue(0, 1).real() - oneOverSQRT2;
    double diff3 = gate->fetchValue(1, 0).real() - oneOverSQRT2;
    double diff4 = gate->fetchValue(1, 1).real() + oneOverSQRT2;
    if (!(diff1 + diff2 + diff3 + diff4 < std::pow(10, -9))) {          // Some numerical differences expexcted since we have fixed precisiona nd PI to 10 dp
        return false;
    }
    return true;
}

bool gpuQuantumCircuitTest() {

    GPUQubitFactory cpuQubitFactory = GPUQubitFactory();
    Qubit* newQubit = cpuQubitFactory.generateQubit();
    Qubit* newQubit2 = cpuQubitFactory.generateQubit();

    // Set up required gate factory
    GPUGateFactory* gateFactory = &GPUGateFactory();
    GPUQuantumCircuit circuit = GPUQuantumCircuit(gateFactory);

    // Set up required qubit map
    std::map<std::string, std::vector<Qubit*>> qubitMap{
        {"q", {newQubit, newQubit2}}
    };

    // Set up required concurrency blocks
    std::vector<Register> mockReg1;
    std::vector<GateRequest> mockGateRequest1;
    idLocationPairs mockPair;
    mockPair.identifiers.push_back("q");
    mockPair.locations.push_back(0);
    idLocationPairs mockPair2 = mockPair;
    mockPair.identifiers.push_back("q");
    mockPair.locations.push_back(1);

    mockGateRequest1 = compileCompoundGateRequest("cx", mockPair);
    mockGateRequest1.push_back(compileCompoundGateRequest("h", mockPair2)[0]);
    Stager stager = Stager(mockReg1, mockGateRequest1);
    std::vector<ConcurrentBlock> blocks = stager.getConcurrencyBlocks();

    // Load qubitMap
    circuit.loadQubitMap(qubitMap);
    // Load first concurrency block
    circuit.loadBlock(blocks[0]);
    std::vector<Calculation> calculations = circuit.getNextCalculation();
    if (!(calculations.size() == 1)) {
        return false;
    }
    Calculation firstCalc = calculations[0];
    if (!(firstCalc.getQubit(0) == newQubit) || !(firstCalc.getQubit(1) == newQubit2)) {
        return false;
    }
    return true;
}

bool gpuDeviceAllUpTest() {
    // Setting up all required info
    std::vector<Register> mockReg1;
    QuantumRegister qReg = QuantumRegister("q", 3);
    ClassicalRegister cReg = ClassicalRegister("c", 3);
    Register qRegWrapped = Register(quantum_, qReg);
    Register cRegWrapped = Register(classical_, cReg);
    mockReg1.push_back(qRegWrapped);
    mockReg1.push_back(cRegWrapped);
    std::vector<GateRequest> mockGateRequest1;
    idLocationPairs mockPair;
    mockPair.identifiers.push_back("q");
    mockPair.locations.push_back(0);
    idLocationPairs mockPair2 = mockPair;
    mockPair.identifiers.push_back("q");
    mockPair.locations.push_back(1);

    mockGateRequest1 = compileCompoundGateRequest("cx", mockPair);
    mockGateRequest1.push_back(compileCompoundGateRequest("h", mockPair2)[0]);
    mockGateRequest1.push_back(compileCompoundGateRequest("h", mockPair2)[0]);
    mockGateRequest1.push_back(compileCompoundGateRequest("cx", mockPair)[0]);
    Stager stager = Stager(mockReg1, mockGateRequest1);

    std::vector<ConcurrentBlock> blocks = stager.getConcurrencyBlocks();

    GPUDevice device = GPUDevice();
    device.run(mockReg1, blocks);
    std::map<std::string, std::vector<Qubit*>> results = device.revealQuantumState();
    if (!(results["q"][0]->fetch(0)->real() == 1) || !(results["q"][1]->fetch(0)->real() == 1)) {
        return false;
    }
    return true;
}

// Measurement Test

bool runSimpleMeasurementTest() {
    std::ifstream stream;
    stream.open("test/measureTest1.qasm");
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
    Stager stager = Stager(registers, gateRequests);
    CPUDevice device = CPUDevice();
    device.run(registers, stager.getConcurrencyBlocks());
    MeasurementCalculator calc = MeasurementCalculator(registers);
    calc.loadMeasureCommands(commands);
    calc.registerHandover(device.revealQuantumState());
    calc.measureAll();
    calc.passMeasurementsIntoClassicalRegisters();
    Register cReg = calc.fetchRegister("c");
    if (cReg.getClassicalRegister().getWidth() != 3) {
        return false;
    }
    if (cReg.getClassicalRegister().getValue(0) != 0) {
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
    // Compound gate setup check
    handleTestResult(parserTest5(), "Parser Test: Checking compound gate setup is working");
}

void ValkyrieTests::runStagingTests()
{
    std::vector<Register> mockReg1;
    std::vector<GateRequest> mockGateRequest1;
    idLocationPairs mockPair;
    mockPair.identifiers.push_back("q");
    mockPair.locations.push_back(0);
    idLocationPairs mockPair2 = mockPair;
    mockPair.identifiers.push_back("c");
    mockPair.locations.push_back(1);

    mockGateRequest1 = compileCompoundGateRequest("cx", mockPair);
    mockGateRequest1.push_back(compileCompoundGateRequest("h", mockPair2)[0]);
    
    handleTestResult(stagingTest1(mockReg1, mockGateRequest1), "Staging test: Checking for correct concurrency resolution simple case");

    mockGateRequest1.push_back(compileCompoundGateRequest("h", mockPair2)[0]);
    handleTestResult(stagingTest2(mockReg1, mockGateRequest1), "Staging test: Checking for correct concurrency resolution in intermediate case");
    mockGateRequest1.push_back(compileCompoundGateRequest("cx", mockPair)[0]);
    handleTestResult(stagingTest3(mockReg1, mockGateRequest1), "Staging test: Checking for correct concurrency resolution in complex case");
}

void ValkyrieTests::runCPUDeviceTests()
{
    // Test CPU Qubit Factory
    handleTestResult(cpuQubitFactoryTest(), "CPU Device Test: Checking whether CPU Qubit factory is able to emit Qubits");
    // Test CPU Gate Factory
    handleTestResult(cpuGateFactoryTest(), "CPU Device Test: Checking whether CPU Gate factory is able to resolve correct gates");
    // Test CPU Quantum Circuit
    handleTestResult(cpuQuantumCircuitTest(), "CPU Device Test: Checking whether CPU Quantum Circuit is able to compile calculations");
    // Test CPU device all up
    handleTestResult(cpuDeviceAllUpTest(), "CPU Device Test: Full run all up test");
}

void ValkyrieTests::runGPUDeviceTests()
{
    // Test GPU Qubit Factory
    handleTestResult(gpuQubitFactoryTest(), "GPU Device Test: Checking whether GPU Qubit factory is able to emit Qubits");
    // Test GPU Gate Factory
    handleTestResult(gpuGateFactoryTest(), "GPU Device Test: Checking whether GPU Gate factory is able to resolve correct gates");
    // Test GPU Quantum Circuit
    handleTestResult(gpuQuantumCircuitTest(), "GPU Device Test: Checking whether GPU Quantum Circuit is able to compile calculations");
    // Test GPU device all up
    handleTestResult(gpuDeviceAllUpTest(), "GPU Device Test: Full run all up test");
}

void ValkyrieTests::runMeasurementTests()
{
    handleTestResult(runSimpleMeasurementTest(), "Measurement test: Checking whether simple emasure case is handled");
}



ValkyrieTests::ValkyrieTests()
{
    // Module initialisation passed ;)
	total_ = 1;
	passed_ = 1;
}

void ValkyrieTests::runTests()
{
	// Valkyrie Test Suite
    // Parser Tests
    runParserTests();
    // Staging Tests
    runStagingTests();
    // CPU Device Tests
    runCPUDeviceTests();
    // GPU Device Tests
    runGPUDeviceTests();
    // Measurement Test
    runMeasurementTests();
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
