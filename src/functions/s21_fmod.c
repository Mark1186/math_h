#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double result = 0.0;
  if (y == POS_INF) {
    result = x;
  } else if ((x == POS_INF || x == NEG_INF) && (y != 0)) {
    result = x;
  } else {
    long double quotient = x / y;
    int integer_part = (int)quotient;

    long double fractional_part = quotient - integer_part;
    result = fractional_part * y;
  }

  return result;
}