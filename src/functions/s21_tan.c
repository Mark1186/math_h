#include "../s21_math.h"

long double s21_tan(double x) {
  long double sin_x = s21_sin(x);
  long double cos_x = s21_cos(x);
  long double result = 0.0;

  if (s21_fabs(cos_x) < TOL) {
    result = NaN;
  } else {
    result = sin_x / cos_x;
  }

  return result;
}