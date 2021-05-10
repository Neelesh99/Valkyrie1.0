#pragma once
#include "BaseTypes.h"

const double IMAGCPU = std::sqrt(-1);

std::vector<std::vector<std::complex<double>>> buildU3GateCPU(GateRequest gate) {
	double theta = gate.getParameters()[0];
	double phi = gate.getParameters()[1];
	double lambda_ = gate.getParameters()[2];
	double cosHalfTheta = std::cos(theta / 2);
	double sinHalfTheta = std::sin(theta / 2);
	std::complex<double> elem1 = cosHalfTheta;
	std::complex<double> elem2 = sinHalfTheta * -1 * std::exp(lambda_ * IMAGCPU);
	std::complex<double> elem3 = sinHalfTheta * std::exp(phi * IMAGCPU);
	std::complex<double> elem4 = cosHalfTheta * std::exp(lambda_ * IMAGCPU + phi * IMAGCPU);
	return std::vector<std::vector<std::complex<double>>> { {elem1, elem2}, { elem3, elem4 }};
}
