#include <check.h>

#include "s21_test.h"

START_TEST(s21_cos_test_is_zero) {
  double testValue = 0.0;
  ck_assert_double_eq_tol(s21_cos(testValue), cos(testValue), TOL);
}
END_TEST

START_TEST(s21_cos_test_is_normal) {
  double testValue = 50.0;
  ck_assert_double_eq_tol(s21_cos(testValue), cos(testValue), TOL);
}
END_TEST

START_TEST(s21_cos_test_is_negative) {
  double testValue = -45.6;
  ck_assert_double_eq_tol(s21_cos(testValue), cos(testValue), TOL);
}
END_TEST

START_TEST(s21_cos_test_nan_inf) {
  double testValue1 = NaN;
  double testValue2 = POS_INF;
  ck_assert_double_nan(s21_cos(testValue1));
  ck_assert_double_infinite(s21_cos(testValue2));
}
END_TEST

Suite *s21_cos_suite(void) {
  Suite *suite;
  TCase *tc_cos_is_zero, *tc_cos_is_normal, *tc_cos_is_negative,
      *tc_cos_nan_inf;

  suite = suite_create("s21_cos");

  tc_cos_is_zero = tcase_create("s21_cos_test_is_zero");
  tcase_add_test(tc_cos_is_zero, s21_cos_test_is_zero);
  suite_add_tcase(suite, tc_cos_is_zero);

  tc_cos_is_normal = tcase_create("s21_cos_test_is_normal");
  tcase_add_test(tc_cos_is_normal, s21_cos_test_is_normal);
  suite_add_tcase(suite, tc_cos_is_normal);

  tc_cos_is_negative = tcase_create("s21_cos_is_negative");
  tcase_add_test(tc_cos_is_negative, s21_cos_test_is_negative);
  suite_add_tcase(suite, tc_cos_is_negative);

  tc_cos_nan_inf = tcase_create("s21_cos_nan_inf");
  tcase_add_test(tc_cos_nan_inf, s21_cos_test_nan_inf);
  suite_add_tcase(suite, tc_cos_nan_inf);

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
  case_test(s21_cos_suite(), &fail);

  return fail;
}