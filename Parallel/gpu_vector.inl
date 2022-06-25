#include "add.cu"

#include <cstring>
#include <cuda_runtime.h>

namespace CoolMath {

template <typename scalar>
GpuVector<scalar>::GpuVector(int size) : size_(size) {
  scalar *data = NULL;
  cudaMalloc((void **)&data, size_ * sizeof(scalar));
  data_ = data;
}

template <typename scalar>
GpuVector<scalar>::GpuVector(Vector<scalar> v) : size_(v.size()) {
  scalar *data;
  cudaMalloc((void **)&data, size_ * sizeof(scalar));
  cudaMemcpy(data, v.data().data(), size_ *sizeof(scalar), cudaMemcpyHostToDevice);
  data_ = data;
}

template <typename scalar>
GpuVector<scalar>::GpuVector(scalar *data, int size) : data_(data), size_(size) {
}

template <typename scalar> scalar &GpuVector<scalar>::operator[](int i) {
  return data_[i];
}

template <typename scalar>
GpuVector<scalar> GpuVector<scalar>::operator+(const GpuVector<scalar> &rhs) {
  scalar *data = NULL;
  cudaMalloc((void **)&data, size_ * sizeof(scalar));
  vector_add(this->data(), rhs.data(), data, size_);
  GpuVector<scalar> res(data, size_);

  return res;
}

template <typename scalar> scalar GpuVector<scalar>::at(int ind) const {
  return data_[ind];
}

template <typename scalar> int GpuVector<scalar>::size() const { return size_; }

template <typename scalar> scalar *GpuVector<scalar>::data() const {
  return data_;
}

template <typename scalar> Vector<scalar> GpuVector<scalar>::release() const {
  scalar *data = (scalar *)malloc(size_ * sizeof(scalar));
  cudaMemcpy(data, data_, size_ * sizeof(scalar), cudaMemcpyDeviceToHost);
  Vector<scalar> res(data, size_);
  return res;
}

} // namespace CoolMath
