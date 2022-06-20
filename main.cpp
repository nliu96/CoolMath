#include <iostream>

#include "matrix.cpp"

int main() {
  CoolMath::Matrix<double> m(4, 3);
  for (int i = 0; i < m.rows(); ++i) {
    for (int j = 0; j < m.cols(); ++j) {
      m[i][j] = i * m.cols() + j;
    }
  }

  CoolMath::Matrix<double> n(3, 5);
  for (int i = 0; i < n.rows(); ++i) {
    for (int j = 0; j < n.cols(); ++j) {
      n[i][j] = i * n.cols() + j;
    }
  }

  CoolMath::Matrix<double> o = m.transpose();
  std::cout << o << std::endl;
  return 0;
}