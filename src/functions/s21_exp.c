#include "../s21_math.h"

long double s21_exp(double x) {
  long double result = 1.0;
  long double term = 1.0;

  if (x != x) {
    result = NaN;
  } else if (x == POS_INF) {
    result = POS_INF;
  } else if (x == NEG_INF || x < -14.5) {
    result = 0.0;
  } else {
    for (long double i = 1.0; s21_fabs(term) > EPS; ++i) {
      term *= x / i;
      result += term;

      if (result > 1e100) {
        result = POS_INF;
      }
    }
  }

  return result;
}