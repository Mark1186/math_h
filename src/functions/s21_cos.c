#include "../s21_math.h"

long double s21_cos(double x) {
  long double result = 0.0;
  if (x == NEG_INF || x == POS_INF) {
    result = POS_INF;
  } else if (x != x) {
    result = NaN;
  } else {
    result = s21_sin(x + PI / 2.0);
  }

  return result;
}