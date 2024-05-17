#include <check.h>

#include "s21_test.h"

START_TEST(s21_atan_test_is_zero) {
  double testValue = 0.0;
  ck_assert_double_eq_tol(s21_atan(testValue), atan(testValue), TOL);
}
END_TEST

START_TEST(s21_atan_test_is_normal) {
  double testValue1 = 50.0;
  double testValue2 = 1000.0;
  double testValue3 = 3.4;
  double testValue4 = 0.45;
  ck_assert_double_eq_tol(s21_atan(testValue1), atan(testValue1), TOL);
  ck_assert_double_eq_tol(s21_atan(testValue2), atan(testValue2), TOL);
  ck_assert_double_eq_tol(s21_atan(testValue3), atan(testValue3), TOL);
  ck_assert_double_eq_tol(s21_atan(testValue4), atan(testValue4), TOL);
}
END_TEST

START_TEST(s21_atan_test_is_negative) {
  double testValue1 = -50.0;
  double testValue2 = -1000.0;
  double testValue3 = -3.4;
  double testValue4 = -0.45;
  ck_assert_double_eq_tol(s21_atan(testValue1), atan(testValue1), TOL);
  ck_assert_double_eq_tol(s21_atan(testValue2), atan(testValue2), TOL);
  ck_assert_double_eq_tol(s21_atan(testValue3), atan(testValue3), TOL);
  ck_assert_double_eq_tol(s21_atan(testValue4), atan(testValue4), TOL);

  ck_assert_double_eq_tol(s21_atan(POS_INF), atan(POS_INF), TOL);
}
END_TEST

Suite *s21_atan_suite(void) {
  Suite *suite;
  TCase *tc_atan_test_is_zero, *tc_atan_test_is_normal,
      *tc_atan_test_is_negative;

  suite = suite_create("s21_atan");

  tc_atan_test_is_zero = tcase_create("s21_atan_test_is_normal");
  tcase_add_test(tc_atan_test_is_zero, s21_atan_test_is_zero);
  suite_add_tcase(suite, tc_atan_test_is_zero);

  tc_atan_test_is_normal = tcase_create("s21_atan_test_is_normal");
  tcase_add_test(tc_atan_test_is_normal, s21_atan_test_is_normal);
  suite_add_tcase(suite, tc_atan_test_is_normal);

  tc_atan_test_is_negative = tcase_create("s21_atan_test_is_negative");
  tcase_add_test(tc_atan_test_is_negative, s21_atan_test_is_negative);
  suite_add_tcase(suite, tc_atan_test_is_negative);

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
  case_test(s21_atan_suite(), &fail);

  return fail;
}