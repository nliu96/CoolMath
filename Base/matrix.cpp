#include "matrix.h"

#include <stdexcept>

namespace CoolMath {

template <typename scalar>
Matrix<scalar>::Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  data_ = std::vector<std::vector<scalar>>(rows, std::vector<scalar>(cols, 0));
}

template <typename scalar> scalar Matrix<scalar>::at(int row, int col) const {
  return data_[row][col];
}

template <typename scalar> int Matrix<scalar>::rows() const { return rows_; }
template <typename scalar> int Matrix<scalar>::cols() const { return cols_; }

template <typename scalar> Matrix<scalar> Matrix<scalar>::transpose() {
  Matrix<scalar> ret(this->cols(), this->rows());
  for (int i = 0; i < this->rows(); ++i) {
    for (int j = 0; j < this->cols(); ++j) {
      ret[j][i] = this->at(i, j);
    }
  }
  return ret;
}

template <typename scalar>
std::vector<scalar> &Matrix<scalar>::operator[](int i) {
  return data_[i];
}

template <typename scalar>
Matrix<scalar> Matrix<scalar>::operator+(const Matrix<scalar> &rhs) {
  Matrix ret(rhs.rows(), rhs.cols());
  for (int i = 0; i < rhs.rows(); ++i) {
    for (int j = 0; j < rhs.cols(); ++j) {
      ret[i][j] = this->at(i, j) + rhs.at(i, j);
    }
  }
  return ret;
}

template <typename scalar>
Matrix<scalar> Matrix<scalar>::operator-(const Matrix<scalar> &rhs) {
  Matrix ret(rhs.rows(), rhs.cols());
  for (int i = 0; i < rhs.rows(); ++i) {
    for (int j = 0; j < rhs.cols(); ++j) {
      ret[i][j] = this->at(i, j) - rhs.at(i, j);
    }
  }
  return ret;
}

template <typename scalar>
Matrix<scalar> Matrix<scalar>::operator*(const Matrix<scalar> &rhs) {
  if (this->cols() != rhs.rows()) {
    throw std::runtime_error("Mismatched dimensions for matrix multiplication");
  }

  Matrix ret(this->rows(), rhs.cols());
  for (int i = 0; i < (*this).rows(); ++i) {
    for (int j = 0; j < rhs.cols(); ++j) {
      for (int k = 0; k < rhs.rows(); ++k) {
        ret[i][j] += this->at(i, k) * rhs.at(k, j);
      }
    }
  }

  return ret;
}

template <typename scalar>
bool Matrix<scalar>::operator==(const Matrix<scalar> &rhs) {
  if (this->rows() != rhs.rows() || this->cols() != rhs.cols()) {
    return false;
  }

  for (int i = 0; i < (*this).rows(); ++i) {
    for (int j = 0; j < (*this).rows(); ++j) {
      if (this->at(i, j) != rhs.at(i, j))
        return false;
    }
  }

  return true;
}

template <typename scalar>
std::ostream &operator<<(std::ostream &os, const Matrix<scalar> &m) {
  for (int i = 0; i < m.rows(); ++i) {
    for (int j = 0; j < m.cols(); ++j) {
      os << m.at(i, j) << " ";
    }
    os << std::endl;
  }
  return os;
}

} // namespace CoolMath