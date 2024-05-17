#ifndef S21_MATH_H
#define S21_MATH_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define EPS 1e-100
#define TOL 1e-6
#define PI 3.14159265358979323846
#define POS_INF 1.0 / 0.0
#define NEG_INF -1.0 / 0.0
#define NaN (__builtin_nan(""))

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_sqrt(double x);
long double s21_log2(double x);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_pow(double x, double y);
long double s21_fmod(double x, double y);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_tan(double x);
long double s21_atan(double x);

#endif
