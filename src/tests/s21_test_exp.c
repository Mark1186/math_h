#include <check.h>

#include "s21_test.h"

START_TEST(s21_exp_pos) {
  double testValue = 54.5;
  ck_assert_double_eq_tol(s21_exp(testValue), exp(testValue), TOL);
}
END_TEST

START_TEST(s21_exp_neg) {
  double testValue = -534.54;
  ck_assert_double_eq_tol(s21_exp(testValue), exp(testValue), TOL);
}
END_TEST

START_TEST(s21_exp_zero) {
  double testValue = 0.0;
  ck_assert_double_eq_tol(s21_exp(testValue), exp(testValue), TOL);
}
END_TEST

START_TEST(s21_exp_nan_inf) {
  ck_assert_double_nan(s21_exp(NaN));
  ck_assert_double_infinite(s21_exp(POS_INF));
}
END_TEST

Suite *s21_exp_suite(void) {
  Suite *suite;
  TCase *tc_exp_pos, *tc_exp_neg, *tc_exp_zero, *tc_exp_nan_inf;

  suite = suite_create("s21_exp");

  tc_exp_pos = tcase_create("s21_exp_pos");
  tcase_add_test(tc_exp_pos, s21_exp_pos);
  suite_add_tcase(suite, tc_exp_pos);

  tc_exp_neg = tcase_create("s21_exp_neg");
  tcase_add_test(tc_exp_neg, s21_exp_neg);
  suite_add_tcase(suite, tc_exp_neg);

  tc_exp_zero = tcase_create("s21_exp_zero");
  tcase_add_test(tc_exp_zero, s21_exp_zero);
  suite_add_tcase(suite, tc_exp_zero);

  tc_exp_nan_inf = tcase_create("s21_exp_nan_inf");
  tcase_add_test(tc_exp_nan_inf, s21_exp_nan_inf);
  suite_add_tcase(suite, tc_exp_nan_inf);

  return suite;
}

void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main(void) {
  int fail = 0;
  case_test(s21_exp_suite(), &fail);

  return fail;
}