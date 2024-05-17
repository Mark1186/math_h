#include "../s21_math.h"

long double s21_log(double x) {
  long double result = 0.0;
  long double value = 0.0;
  long double term = (x - 1.0) / (x + 1.0);
  long double term_squared = term * term;
  long double numerator = term;
  long double denominator = 1.0;

  if (x != x || (x < 0.0 && x != NEG_INF)) {
    result = -NaN;
  } else if (x == POS_INF) {
    result = POS_INF;
  } else if (x == NEG_INF) {
    result = -NaN;
  } else if (x == 0) {
    result = NEG_INF;
  } else {
    for (int i = 1; i <= x * 10; i++) {
      value += numerator / denominator;
      numerator *= term_squared;
      denominator += 2.0;
    }
    value *= 2.0;
    result = value;
  }
  return result;
}
