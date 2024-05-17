#include "../s21_math.h"

long double s21_pow(double x, double y) {
  long double result = 0.0;
  if (x < 0.0 || y < 0.0) {
    result = NaN;
  } else if (x < 0.0 && y != s21_fabs(y)) {
    result = NaN;
  } else if (x > 0.0 && y == POS_INF) {
    if (x == 1.0) {
      result = x;
    } else {
      result = y;
    }
  } else if (x == 0.0 && y == NEG_INF) {
    result = POS_INF;
  } else if (y == 0.0) {
    result = 1.0;
  } else if (x == 0.0 && y > 0.0) {
    result = 0.0;
  } else {
    result = s21_exp(y * s21_log(x));
  }

  return result;
}