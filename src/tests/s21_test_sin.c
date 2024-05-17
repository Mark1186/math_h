#include <check.h>

#include "s21_test.h"

START_TEST(s21_sin_test_is_zero) {
  double testValue = 0.0;
  ck_assert_double_eq_tol(s21_sin(testValue), sin(testValue), TOL);
}
END_TEST

START_TEST(s21_sin_test_in_diaposon) {
  double testValue1 = 0.5;
  double testValue2 = -0.5;
  ck_assert_double_eq_tol(s21_sin(testValue1), sin(testValue1), TOL);
  ck_assert_double_eq_tol(s21_sin(testValue2), sin(testValue2), TOL);
}
END_TEST

START_TEST(s21_sin_test_out_diaposon) {
  double testValue1 = 2.3;
  double testValue2 = -60.0;
  ck_assert_double_eq_tol(s21_sin(testValue1), sin(testValue1), TOL);
  ck_assert_double_eq_tol(s21_sin(testValue2), sin(testValue2), TOL);
}

START_TEST(s21_sin_test_nan_inf) {
  double testValue1 = NaN;
  double testValue2 = POS_INF;
  ck_assert_double_nan(s21_sin(testValue1));
  ck_assert_double_infinite(s21_sin(testValue2));
}
END_TEST

Suite *s21_sin_suite(void) {
  Suite *suite;
  TCase *tc_sin_test1, *tc_sin_test2, *tc_sin_test3, *tc_sin_nan_inf;

  suite = suite_create("s21_sin");

  tc_sin_test1 = tcase_create("s21_sin_test1");
  tcase_add_test(tc_sin_test1, s21_sin_test_is_zero);
  suite_add_tcase(suite, tc_sin_test1);

  tc_sin_test2 = tcase_create("s21_sin_test2");
  tcase_add_test(tc_sin_test2, s21_sin_test_in_diaposon);
  suite_add_tcase(suite, tc_sin_test2);

  tc_sin_test3 = tcase_create("s21_sin_test3");
  tcase_add_test(tc_sin_test3, s21_sin_test_out_diaposon);
  suite_add_tcase(suite, tc_sin_test3);

  tc_sin_nan_inf = tcase_create("s21_sin_test_nan_inf");
  tcase_add_test(tc_sin_nan_inf, s21_sin_test_nan_inf);
  suite_add_tcase(suite, tc_sin_nan_inf);

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
  case_test(s21_sin_suite(), &fail);

  return fail;
}