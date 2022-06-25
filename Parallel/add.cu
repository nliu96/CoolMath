#pragma once

#include <iostream>

template <typename scalar>
__global__ void vector_add_kernel(const scalar *a, const scalar *b, scalar *c, int numElements) {
    int i = blockDim.x * blockIdx.x + threadIdx.x;

    if (i < numElements) {
        c[i] = a[i] + b[i];
    }
}

template <typename scalar>
inline void vector_add(const scalar *a, const scalar *b, scalar *c, int numElements) {
  int threadsPerBlock = 256;
  int blocksPerGrid = (numElements + threadsPerBlock - 1) / threadsPerBlock;
  vector_add_kernel<<<blocksPerGrid, threadsPerBlock>>>(a, b, c, numElements);
}