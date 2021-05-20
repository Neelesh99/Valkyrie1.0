#pragma once
#include "BaseTypes.h"

/*
	GateUtilitiesGPU.h
	Description: defines utilities for gate matrix generation

*/

const std::complex<double> IMAGGPU(0, 1);

// buildU3GateGPU uses trigonometric functions to generate U gate
std::vector<std::vector<std::complex<double>>> buildU3GateGPU(GateRequest gate) {
	double theta = gate.getParameters()[0];
	double phi = gate.getParameters()[1];
	double lambda_ = gate.getParameters()[2];
	double cosHalfTheta = std::cos(theta / 2);
	double sinHalfTheta = std::sin(theta / 2);
	std::complex<double> elem1 = cosHalfTheta;
	std::complex<double> elem2 = sinHalfTheta * -1 * std::exp(lambda_ * IMAGGPU);
	std::complex<double> elem3 = sinHalfTheta * std::exp(phi * IMAGGPU);
	std::complex<double> elem4 = cosHalfTheta * std::exp(lambda_ * IMAGGPU + phi * IMAGGPU);
	return std::vector<std::vector<std::complex<double>>> { {elem1, elem2}, { elem3, elem4 }};
}