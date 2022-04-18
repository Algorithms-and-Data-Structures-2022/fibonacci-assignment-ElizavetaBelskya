#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {
    if (n <= 1) {
      return n;
    }
    double gold = std::pow((1+std::sqrt(5))/2, n);
    double gold2 = std::pow((1-std::sqrt(5))/2, n);
    double f = ((gold-gold2)/std::sqrt(5));
    return f;
  }

  int64_t fib_iterative(int n) {
    if (n <= 1) {
      return n;
    }
    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;

    int result;
    for (int i = 1; i < n; i++) {
      result = fib_prev + fib_curr;
      fib_prev = fib_curr;
      fib_curr= result;
    }
    return result;
  }

  int64_t fib_recursive(int n) {
    if (n <= 1) {
      return n;
    } else {
      return fib_recursive(n-1) + fib_recursive(n-2);
    }
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n < 0) {
      return n;
    }
    if (cache[n] != -1) {
      return cache[n];
    } else {
      cache[n] = fib_recursive_memoization(n-1, cache) + fib_recursive_memoization(n-2, cache);
      return cache[n];
    }
  }

  int64_t fib_matrix(int n) {
    if (n <= 1) {
      return n;
    }
    Matrix2x2 matrix = matrix_power(FibMatrix, n);
    // Tip: используйте реализованную функцию matrix_pow
    return matrix[0][1];
  }

}  // namespace assignment
