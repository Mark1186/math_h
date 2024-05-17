#include "../s21_math.h"

long double s21_atan(double x) {
  double long result = 0.0;
  if (x == POS_INF) {
    result = PI / 2.0;
  } else if (x == NEG_INF) {
    result = -PI / 2.0;
  } else if (x > 0) {
    result = s21_asin(x / s21_sqrt(1 + x * x));
  } else {
    x = s21_fabs(x);
    result = -(s21_asin(x / s21_sqrt(1 + x * x)));
  }
  return result;
}