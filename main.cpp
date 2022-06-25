#include <iostream>

#include "Base/matrix.h"
#include "Parallel/gpu_vector.h"

int main() {
  CoolMath::Matrix<double> a(4, 3);
  for (int i = 0; i < a.rows(); ++i) {
    for (int j = 0; j < a.cols(); ++j) {
      a[i][j] = i * a.cols() + j;
    }
  }

  CoolMath::Matrix<double> b(3, 5);
  for (int i = 0; i < b.rows(); ++i) {
    for (int j = 0; j < b.cols(); ++j) {
      b[i][j] = i * b.cols() + j;
    }
  }

  CoolMath::Vector<double> d(100, 2);
  CoolMath::Vector<double> e(100, 3);
  CoolMath::GpuVector<double>f(d);
  CoolMath::GpuVector<double>g(e);

  CoolMath::GpuVector<double>h = f + g;

  CoolMath::Vector<double> i = h.release();
  std::cout << d << std::endl;
  std::cout << e << std::endl;
  std::cout << i << std::endl;

  return 0;
}