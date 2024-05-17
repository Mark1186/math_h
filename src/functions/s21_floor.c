#include "../s21_math.h"

long double s21_floor(double x) {
  long double number = 0.0;
  if (x != x) {
    number = NaN;
  } else if (x == POS_INF) {
    number = POS_INF;
  } else if (x == NEG_INF) {
    number = NEG_INF; 
  } else {
    number = (int)x;
    if (x < 0 && number != x) {
        number--;
    }
  }
  return number;
}
