#pragma once

#include <iostream>
#include <complex>

namespace valk {

	enum executionType {
		CPU = 0,
		GPU,
	};

	typedef std::complex<double> ComplexNumber;
	
	struct GateDimension {
		int rows;
		int columns;
		GateDimension(int rows, int cols) {
			this->rows = rows;
			this->columns = cols;
		}
	};

	enum gateType {
		SingleQubit = 0,
		CNot,
	};


}