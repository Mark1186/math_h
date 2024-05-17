#include "../s21_math.h"

long double s21_asin(double x) {
  long double result = 0.0;
  if (x <= -1.0 || x >= 1.0) {
    result = NaN;
  } else {
    result = PI / 2 - s21_acos(x);
  }

  return result;
}