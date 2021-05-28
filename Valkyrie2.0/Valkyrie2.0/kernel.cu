
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "antlr4-runtime.h"
#include "libs/qasm2Lexer.h"
#include "libs/qasm2Parser.h"
#include "libs/qasm2Visitor.h"
#include "libs/qasm2BaseVisitor.h"
#include "libs/staging.h"
#include "libs/CPUDevice.h"
#include "libs/GPUDevice.cuh"
#include "libs/Measurement.h"
#include "libs/JSONify.h"
#include <Windows.h>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>

#include <stdio.h>

#include "test/ValkyrieTests.h"

using namespace antlr4;

// getexepath allows vakyrie to resolve the directory it is operating in
std::string getexepath()
{
    char result[MAX_PATH];
    return std::string(result, GetModuleFileName(NULL, result, MAX_PATH));
}
// DisplayHeader is used during info print command to display GPU devices connected
void DisplayHeader();
// printHelp will print help if the user enters an invalid set of command line options
void printHelp();
// resolveDeviceType resolves what type of device the user wants to rpocess on
DeviceType resolveDeviceType(std::vector<std::string> arguments);
// fetchFileName finds the file name specified by the user
std::string fetchFileName(std::vector<std::string> arguments);
// CPURun performs CPU execution of the target QASM code
void CPURun(std::string filename, bool SV, bool jsonMode);
// GPURun performs GPU execution of the target QASM code
void GPURun(std::string filename, bool SV, bool jsonMode);
// handleInfoRequest prints the info requested by user in command line options
void handleInfoRequest(std::vector<std::string> arguments);
// resolveComputeMode resolves whether the user wants fast or statevector compute modes
bool resolveComputeMode(std::vector<std::string> arguments);
// resolveJSONPrint resolves whether this is a VisualQ call which requires json output
bool resolveJsonPrint(std::vector<std::string> arguments);

enum timingPoint
{
    NONE_,
    FULL,
    PARSE,
    STAGE,
    EXECUTION
};

// resolveTimingRequest
timingPoint resolveTimingRequest(std::vector<std::string> arguments);

// timeCPUExecution is used for experimentation and metric gathering
void timeCPUExecution(std::string filename, bool SV, bool jsonMode, timingPoint point) {
    // Start clock
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;
    if (point == FULL || point == PARSE) {
        begin = std::chrono::high_resolution_clock::now();
    }
    std::ifstream stream;
    stream.open(filename);          // Open File requested
    if (!stream.is_open()) {
        std::cout << "Couldn't find file specified" << std::endl;
        printHelp();
        return;
    }
    ANTLRInputStream input(stream);                 // Convert filestream to ANTLR stream
    qasm2Lexer lexer(&input);                       // Lex file
    CommonTokenStream tokens(&lexer);               // get the tokens
    qasm2Parser parser(&tokens);                    // send to antlr parser
    qasm2Parser::MainprogContext* tree = parser.mainprog();             // Fetch AST tree
    qasm2BaseVisitor visitor;
    visitor.visitMainprog(tree);                                        // Use custom visitor to process information
    std::vector<Register> registers = visitor.getRegisters();           // Get registers defined by user
    std::vector<GateRequest> gateRequests = visitor.getGates();         // Get gates defined by user   
    if (point == PARSE) {
        end = std::chrono::high_resolution_clock::now();
    }
    if (point == STAGE) {
        begin = std::chrono::high_resolution_clock::now();
    }
    Stager stage = Stager();
    std::vector<ConcurrentBlock> blocks = stage.stageInformation(registers, gateRequests);          // User stager to convert parsed information into calculation commands       
    if (point == STAGE) {
        end = std::chrono::high_resolution_clock::now();
    }
    if (point == EXECUTION) {
        begin = std::chrono::high_resolution_clock::now();
    }
    CPUDevice device = CPUDevice();
    if (!SV) {                                                          // If we are in statevector compute mode, run in statevector mode
        device.run(stage.getRegisters(), blocks);
    }
    else {
        device.runSV(stage.getRegisters(), blocks);
    }
    if (point == EXECUTION) {
        end = std::chrono::high_resolution_clock::now();
    }
    StateVectorMeasurement measure = StateVectorMeasurement(device.getStateVector(), registers);        // Initialise statevector measurement
    measure.measure();
    if (point == FULL) {
        end = std::chrono::high_resolution_clock::now();
    }
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << std::endl;   
}
// timeGPUExecution is used for experimentation and metric gathering
void timeGPUExecution(std::string filename, bool SV, bool jsonMode, timingPoint point) {
    // Start clock
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;
    if (point == FULL || point == PARSE) {
        begin = std::chrono::high_resolution_clock::now();
    }
    std::ifstream stream;
    stream.open(filename);          // Open File requested
    if (!stream.is_open()) {
        std::cout << "Couldn't find file specified" << std::endl;
        printHelp();
        return;
    }
    ANTLRInputStream input(stream);                 // Convert filestream to ANTLR stream
    qasm2Lexer lexer(&input);                       // Lex file
    CommonTokenStream tokens(&lexer);               // get the tokens
    qasm2Parser parser(&tokens);                    // send to antlr parser
    qasm2Parser::MainprogContext* tree = parser.mainprog();             // Fetch AST tree
    qasm2BaseVisitor visitor;
    visitor.visitMainprog(tree);                                        // Use custom visitor to process information
    std::vector<Register> registers = visitor.getRegisters();           // Get registers defined by user
    std::vector<GateRequest> gateRequests = visitor.getGates();         // Get gates defined by user   
    if (point == PARSE) {
        end = std::chrono::high_resolution_clock::now();
    }
    if (point == STAGE) {
        begin = std::chrono::high_resolution_clock::now();
    }
    Stager stage = Stager();
    std::vector<ConcurrentBlock> blocks = stage.stageInformation(registers, gateRequests);          // User stager to convert parsed information into calculation commands       
    if (point == STAGE) {
        end = std::chrono::high_resolution_clock::now();
    }
    if (point == EXECUTION) {
        begin = std::chrono::high_resolution_clock::now();
    }
    GPUDevice device = GPUDevice();
    if (!SV) {                                                          // If we are in statevector compute mode, run in statevector mode
        device.run(stage.getRegisters(), blocks);
    }
    else {
        device.runSV(stage.getRegisters(), blocks);
    }
    if (point == EXECUTION) {
        end = std::chrono::high_resolution_clock::now();
    }
    StateVectorMeasurement measure = StateVectorMeasurement(device.getStateVector(), registers);        // Initialise statevector measurement
    measure.measure();
    if (point == FULL) {
        end = std::chrono::high_resolution_clock::now();
    }
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << std::endl;
}


// main is the entrypoint of the program
int main(int argc, char *argv[])
{
    std::vector<std::string> arguments;
    for (int i = 1; i < argc; i++) {
        arguments.push_back(argv[i]);           // collect command line arguments
    }
    handleInfoRequest(arguments);               // check if information was requested by user and print

    DeviceType type = resolveDeviceType(arguments);         // calculate whether the user wants to use the CPU or GPU
    if (type == INVALID) {
        std::cout << "Invalid or No execution mode provided, specify -c or -g" << std::endl;
        printHelp();
        return 1;
    }

    std::string fileName = fetchFileName(arguments);        // resolve the qasm file the user wants to process
    if (fileName == "INVALID") {
        std::cout << "File not specified, please use -o <filename> to indicate which file Valkyrie should process" << std::endl;
        printHelp();
        return 1;
    }
    bool svMode = resolveComputeMode(arguments);            // resolve whether the user wanted to user statevector or fast compute mode
    bool jsonMode = resolveJsonPrint(arguments);            // reolve whether the user wants a JSON print at the end or normal print
    timingPoint timing = resolveTimingRequest(arguments);
    if (timing != NONE_) {
        if (type == CPU_) {                                     // depending on requested devicetype run on CPU or GPU
            for (int i = 0; i < 121; i++) {
                timeCPUExecution(fileName, svMode, jsonMode, timing);
            }
        }
        else {
            for (int i = 0; i < 121; i++) {
                timeGPUExecution(fileName, svMode, jsonMode, timing);
            }
        }
        return 0;
    }
    if (type == CPU_) {                                     // depending on requested devicetype run on CPU or GPU
        CPURun(fileName, svMode, jsonMode);
    }
    else {
        GPURun(fileName, svMode, jsonMode);      
    }
    return 0;
}

void DisplayHeader()
{
    const int kb = 1024;
    const int mb = kb * kb;
    std::cout << "NBody.GPU" << std::endl << "=========" << std::endl << std::endl;

    std::cout << "CUDA version:   v" << CUDART_VERSION << std::endl;

    int devCount;
    cudaGetDeviceCount(&devCount);
    std::cout << "CUDA Devices: " << std::endl << std::endl;

    for (int i = 0; i < devCount; ++i)
    {
        cudaDeviceProp props;
        cudaGetDeviceProperties(&props, i);
        std::cout << i << ": " << props.name << ": " << props.major << "." << props.minor << std::endl;
        std::cout << "  Global memory:   " << props.totalGlobalMem / mb << "mb" << std::endl;
        std::cout << "  Shared memory:   " << props.sharedMemPerBlock / kb << "kb" << std::endl;
        std::cout << "  Constant memory: " << props.totalConstMem / kb << "kb" << std::endl;
        std::cout << "  Block registers: " << props.regsPerBlock << std::endl << std::endl;

        std::cout << "  Warp size:         " << props.warpSize << std::endl;
        std::cout << "  Threads per block: " << props.maxThreadsPerBlock << std::endl;
        std::cout << "  Max block dimensions: [ " << props.maxThreadsDim[0] << ", " << props.maxThreadsDim[1] << ", " << props.maxThreadsDim[2] << " ]" << std::endl;
        std::cout << "  Max grid dimensions:  [ " << props.maxGridSize[0] << ", " << props.maxGridSize[1] << ", " << props.maxGridSize[2] << " ]" << std::endl;
        std::cout << std::endl;
    }
}

void printHelp() {
    std::cout << "Welcome to Valkyrie Help" << std::endl;
    std::cout << "Command line options" << std::endl;
    std::cout << "CPU execution mode: \t \t \t -c" << std::endl;
    std::cout << "GPU execution mode: \t \t \t -g" << std::endl;
    std::cout << "Path to file: \t \t \t \t -o <filepath>" << std::endl;
    std::cout << "State vector computation: -sv" << std::endl;
}

DeviceType resolveDeviceType(std::vector<std::string> arguments) {
    DeviceType val = INVALID;
    for (std::string argument : arguments) {
        if (argument == "-g") {
            val = GPU_;
            break;
        }
        if (argument == "-c") {
            val = CPU_;
            break;
        }
    }
    return val;
}

bool resolveComputeMode(std::vector<std::string> arguments) {
    for (std::string argument : arguments) {
        if (argument == "-sv") {
            return true;
        }
    }
    return false;
}

bool resolveJsonPrint(std::vector<std::string> arguments) {
    for (std::string argument : arguments) {
        if (argument == "-json") {
            return true;
        }
    }
    return false;
}

timingPoint resolveTimingRequest(std::vector<std::string> arguments) {
    for (int i = 0; i < arguments.size(); i++) {
        if (arguments[i] == "-time") {
            if (i != arguments.size() - 1) {
                if (arguments[i + 1] == "parse") {
                    return PARSE;
                }
                if (arguments[i + 1] == "staging") {
                    return STAGE;
                }
                if (arguments[i + 1] == "execution") {
                    return EXECUTION;
                }
            }
            return FULL;
        }
    }
    return NONE_;
}

std::string fetchFileName(std::vector<std::string> arguments) {
    std::string returnVal = "INVALID";
    if (arguments.size() == 0) {
        return returnVal;
    }
    for (int i = 0; i < arguments.size()-1; i++) {
        if (arguments[i] == "-o") {
            return arguments[i + 1];
        }
    }
    return returnVal;
}

void CPURun(std::string filename, bool SV, bool jsonMode) {
    std::ifstream stream;
    stream.open(filename);          // Open File requested
    if (!stream.is_open()) {
        std::cout << "Couldn't find file specified" << std::endl;
        printHelp();
        return;
    }
    ANTLRInputStream input(stream);             // Convert filestream to ANTLR stream

    qasm2Lexer lexer(&input);                   // Lex file
    CommonTokenStream tokens(&lexer);           // get the tokens
    qasm2Parser parser(&tokens);                // send to antlr parser

    qasm2Parser::MainprogContext* tree = parser.mainprog();             // Fetch AST tree

    qasm2BaseVisitor visitor;
    visitor.visitMainprog(tree);                                        // Use custom visitor to process information
    std::vector<Register> registers = visitor.getRegisters();           // Get registers defined by user
    std::vector<GateRequest> gateRequests = visitor.getGates();         // Get gates defined by user
    Stager stage = Stager();                                            
    std::vector<ConcurrentBlock> blocks = stage.stageInformation(registers, gateRequests);          // User stager to convert parsed information into calculation commands
    CPUDevice device = CPUDevice();
    if (!SV) {                                                          // If we are in statevector compute mode, run in statevector mode
        device.run(stage.getRegisters(), blocks);
    }
    else {
        device.runSV(stage.getRegisters(), blocks);
    }    
    StateVectorMeasurement measure = StateVectorMeasurement(device.getStateVector(), registers);        // Initialise statevector measurement
    measure.measure();
    std::vector<MeasureCommand> commands = visitor.getMeasureCommands();
    measure.loadMeasureCommands(commands);
    measure.passMeasurementsIntoClassicalRegisters();
    if (!jsonMode) {
        measure.printClassicalRegisters();
    }
    else {
        JSONify json = JSONify(measure.getAllRegisters(), device.getStateVector());                     // If requested print in JSON format
        json.printJSON();
    }
}

void GPURun(std::string filename, bool SV, bool jsonMode) {
    std::ifstream stream;
    stream.open(filename);          // Open File requested
    if (!stream.is_open()) {
        std::cout << "Couldn't find file specified" << std::endl;
        printHelp();
        return;
    }
    ANTLRInputStream input(stream);                 // Convert filestream to ANTLR stream

    qasm2Lexer lexer(&input);                       // Lex file
    CommonTokenStream tokens(&lexer);               // get the tokens
    qasm2Parser parser(&tokens);                    // send to antlr parser

    qasm2Parser::MainprogContext* tree = parser.mainprog();             // Fetch AST tree

    qasm2BaseVisitor visitor;
    visitor.visitMainprog(tree);                                        // Use custom visitor to process information
    std::vector<Register> registers = visitor.getRegisters();           // Get registers defined by user
    std::vector<GateRequest> gateRequests = visitor.getGates();         // Get gates defined by user
    Stager stage = Stager();
    std::vector<ConcurrentBlock> blocks = stage.stageInformation(registers, gateRequests);          // User stager to convert parsed information into calculation commands
    GPUDevice device = GPUDevice();
    if (!SV) {                                                          // If we are in statevector compute mode, run in statevector mode
        device.run(stage.getRegisters(), blocks);
    }
    else {
        device.runSV(stage.getRegisters(), blocks);
    }
    StateVectorMeasurement measure = StateVectorMeasurement(device.getStateVector(), registers);        // Initialise statevector measurement
    measure.measure();
    std::vector<MeasureCommand> commands = visitor.getMeasureCommands();
    measure.loadMeasureCommands(commands);
    measure.passMeasurementsIntoClassicalRegisters();
    if (!jsonMode) {
        measure.printClassicalRegisters();
    }
    else {
        JSONify json = JSONify(measure.getAllRegisters(), device.getStateVector());                     // If requested print in JSON format
        json.printJSON();
    }
}

void handleInfoRequest(std::vector<std::string> arguments)
{
    for (auto argument : arguments) {
        if (argument == "-gpuInfo") {
            DisplayHeader();
        }
        if (argument == "-test") {
            ValkyrieTests tester = ValkyrieTests();
            tester.runTests();
            std::cout << "Number of Tests passed: " << tester.noPassed() << std::endl;
            std::cout << "Test pass percentage: " << tester.getPercentagePassed() << std::endl;
            if (tester.getPercentagePassed() != 100.0) {
                for (auto fail : tester.testsFailed()) {
                    std::cout << "Test Failed: " << fail << std::endl;
                }
            }
        }
    }
}
