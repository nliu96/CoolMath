#pragma once

#include <iostream>
#include <vector>

namespace CoolMath {

template <typename scalar> class Vector {
public:
  Vector<scalar>(int size);

  scalar at(int ind) const;

private:
  std::vector<scalar> data_;
  int size_;
};

} // namespace CoolMath
