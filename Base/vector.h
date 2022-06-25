#pragma once

#include <iostream>
#include <vector>

namespace CoolMath {

template <typename scalar> class Vector {
public:
  Vector<scalar>(int size);
  Vector<scalar>(int size, scalar default_value);
  Vector<scalar>(scalar *data, int size);

  scalar &operator[](int i);

  scalar at(int ind) const;

  int size() const;

  std::vector<scalar> data() const;

  template <typename scalar1>
  friend std::ostream &operator<<(std::ostream &os, const Vector<scalar1> &v);

private:
  std::vector<scalar> data_;
  int size_;
};

} // namespace CoolMath

#include "vector.inl"