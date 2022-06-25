#include "vector.h"

namespace CoolMath {

template <typename scalar>
Vector<scalar>::Vector(int size) : Vector<scalar>(size, 0) {}

template <typename scalar>
Vector<scalar>::Vector(int size, scalar default_value) : size_(size) {
  data_ = std::vector<scalar>(size, default_value);
}

template <typename scalar>
Vector<scalar>::Vector(scalar *data, int size) : size_(size) {
  data_ = std::vector<scalar>(data, data + size);
}

template <typename scalar> scalar &Vector<scalar>::operator[](int i) {
  return data_[i];
}

template <typename scalar> scalar Vector<scalar>::at(int ind) const {
  return data_[ind];
}

template <typename scalar> int Vector<scalar>::size() const { return size_; }

template <typename scalar> std::vector<scalar> Vector<scalar>::data() const { return data_; }

template <typename scalar>
std::ostream &operator<<(std::ostream &os, const Vector<scalar> &v) {
  for (int i = 0; i < v.size(); ++i) {
    os << v.at(i) << " ";
  }
  return os;
}

} // namespace CoolMath
