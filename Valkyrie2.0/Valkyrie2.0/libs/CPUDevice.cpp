#include "CPUDevice.h"
#include <cmath>

using namespace std::complex_literals;
const double ROOT2INV = 1.0 / std::pow(2, 0.5);

std::vector<std::vector<std::complex<double>>> getGateMatrix(GateRequestType gateType) {
	switch (gateType) {
	case h:
		return std::vector<std::vector<std::complex<double>>> { {ROOT2INV, ROOT2INV}, {ROOT2INV, -1.0 * ROOT2INV} };
		break;
	case cx:
		return std::vector<std::vector<std::complex<double>>> { {1, 0, 0, 0}, { 0, 1, 0, 0 }, { 0, 0, 0, 1 }, { 0, 0, 1, 0 } };
		break;
	}
}

Qubit* CPUQubitFactory::generateQubit()
{
	// Allocate heap memory for Qubit values
	std::complex<double>* s0 = new std::complex<double>;
	std::complex<double>* s1 = new std::complex<double>;
	*s0 = 1.0;
	*s1 = 0.0;
	// Allocate heap memory for Qubit and store values
	Qubit* generatedQubit = new Qubit(s0, s1);
	// Push into qubit tracker for deletion
	qubits_.push_back(generatedQubit);

	return generatedQubit;
}

CPUQubitFactory::~CPUQubitFactory()
{
	for (auto qubit : qubits_) {
		delete qubit;
	}
}

Gate* CPUGateFactory::generateGate(GateRequest request)
{
	std::vector<std::vector<std::complex<double>>> gateMatrix = getGateMatrix(request.getGateType());
	int gateM = gateMatrix.size();
	int gateN = gateMatrix[0].size();

	Gate* generatedGate = new Gate(gateM, gateN, gateMatrix);
	gates_.push_back(generatedGate);
	return generatedGate;
}

CPUGateFactory::~CPUGateFactory()
{
	for (auto gate : gates_) {
		delete gate;
	}
}
