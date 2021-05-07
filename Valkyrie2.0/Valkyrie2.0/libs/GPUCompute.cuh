#include "cuda_runtime.h"
#include <stdio.h>
#include "cuComplex.h"

namespace ValkGPULib {
	__global__ void matrixMul(cuDoubleComplex* output, const cuDoubleComplex* input, const cuDoubleComplex* gate, const int m) {
		int loc = threadIdx.x;
		output[loc] = make_cuDoubleComplex(0, 0);
		for (int i = 0; i < m; i++) {
			output[loc] = cuCadd(cuCmul(input[i], gate[m * loc + i]), output[loc]);
			//printf("Thread: %d, i = %d, value of multiplication: %f current value of output[loc]: %f \n", loc, i, cuCmul(input[i], gate[m * loc + i]).x, output[loc].x);
		}
	}
}
