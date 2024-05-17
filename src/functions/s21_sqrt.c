#include "../s21_math.h"

long double s21_log2(double x) { return s21_log(x) / s21_log(2.0); }

long double s21_sqrt(double x) {
  long double result = 0.0;
  if (x == 0.0) {
    result = 0.0;
  } else if (x == NaN) {
    result = NaN;
  } else if (x == POS_INF) {
    result = POS_INF;
  } else if (x == NEG_INF) {
    result = NAN;
  } else if (x < 0.0) {
    result = NaN;
  } else {
    result = s21_pow(2.0, 0.5 * s21_log2(x));
  }

  return result;
}
