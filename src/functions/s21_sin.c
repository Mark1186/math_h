#include "../s21_math.h"

long double s21_sin(double x) {
  long double result = 0.0;
  if (x == NEG_INF || x == POS_INF) {
    result = POS_INF;
  } else if (x != x) {
    result = NaN;
  } else {
    x = s21_fmod(x, 2 * PI);
    if (x < 0.0) {
      x += 2 * PI;
    }
    long double term = x;
    for (int i = 1; i <= 100; ++i) {
      result += term;

      term = -term * x * x / ((2 * i) * (2 * i + 1));
    }
  }

  return result;
}