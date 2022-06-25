#pragma once

#include <iostream>
#include <vector>

#include "vector.h"

namespace CoolMath {

template <typename scalar> class Matrix {
public:
  Matrix<scalar>(int rows, int cols);

  scalar at(int row, int col) const;
  int rows() const;
  int cols() const;

  Matrix<scalar> transpose();

  Vector<scalar> &operator[](int i);
  Matrix<scalar> operator+(const Matrix<scalar> &rhs);
  Matrix<scalar> operator-(const Matrix<scalar> &rhs);
  Matrix<scalar> operator*(const Matrix<scalar> &rhs);
  bool operator==(const Matrix<scalar> &rhs);

  template <typename scalar1>
  friend std::ostream &operator<<(std::ostream &os, const Matrix<scalar1> &m);

private:
  std::vector<Vector<scalar>> data_;
  int rows_, cols_;
};

} // namespace CoolMath

#include "matrix.inl"