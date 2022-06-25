#pragma once

#include <cuda_runtime.h>
#include <iostream>
#include <vector>

#include "../Base/vector.h"

namespace CoolMath {

template <typename scalar> class GpuVector {
public:
  __host__ GpuVector<scalar>(int size);
  __host__ GpuVector<scalar>(Vector<scalar> v);
  __host__ GpuVector<scalar>(scalar *data, int size);

  scalar &operator[](int i);

  scalar at(int ind) const;

  int size() const;

  scalar *data() const;

  Vector<scalar> release() const;

  __host__ GpuVector<scalar> operator+(const GpuVector<scalar> &rhs);

private:
  scalar *data_;
  int size_;
};

} // namespace CoolMath

#include "gpu_vector.inl"