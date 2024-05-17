#include "../s21_math.h"

long double s21_acos(double x) {
  long double result;

  if (x == 0.0) {
    result = PI / 2.0;
  } else if (x < -1.0 || x > 1.0) {
    result = NaN;
  } else {
    long double guess = PI / 4.0;
    long double delta;
    int max_iterations = 1000;
    int iterations = 0;
    int breakpoint = 0;

    do {
      long double cos_guess = s21_cos(guess);
      long double sin_guess = s21_sin(guess);
      delta = (cos_guess - x) / (-sin_guess);
      guess -= delta;
      iterations++;

      if (iterations > max_iterations) {
        result = NaN;
        breakpoint = 1;
      }
    } while (s21_fabs(delta) > TOL && !breakpoint);

    result = guess;
  }

  return result;
}