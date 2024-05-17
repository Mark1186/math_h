#include <check.h>

#include "s21_test.h"

START_TEST(s21_fmod_test_is_nomal) {
  double testValue = 43.4;
  double testStepen = 2.5;
  ck_assert_double_eq_tol(s21_fmod(testValue, testStepen),
                          fmod(testValue, testStepen), TOL);
}
END_TEST

START_TEST(s21_fmod_test_is_zero) {
  double testValue = 0.0;
  double testStepen = 4.2;
  ck_assert_double_eq_tol(s21_fmod(testValue, testStepen),
                          fmod(testValue, testStepen), TOL);
}
END_TEST

START_TEST(s21_fmod_test_is_negative) {
  double testValue = -43.4;
  double testStepen = 1.9;
  ck_assert_double_eq_tol(s21_fmod(testValue, testStepen),
                          fmod(testValue, testStepen), TOL);
}
END_TEST

START_TEST(s21_fmod_test_nan_inf) {
  double testValue1 = NaN;
  double testStepen1 = POS_INF;

  double testValue2 = 5.0;
  double testStepen2 = 0.0;

  double testValue3 = 5.0;
  double testStepen3 = POS_INF;

  double testValue4 = POS_INF;
  double testStepen4 = 2.0;

  double testValue5 = NEG_INF;
  double testStepen5 = 2.0;

  ck_assert_double_nan(s21_fmod(testValue1, testStepen1));
  ck_assert_double_nan(s21_fmod(testValue2, testStepen2));
  ck_assert_double_eq_tol(s21_fmod(testValue3, testStepen3),
                          fmod(testValue3, testStepen3), TOL);
  ck_assert_double_infinite(s21_fmod(testValue4, testStepen4));
  ck_assert_double_infinite(s21_fmod(testValue5, testStepen5));
}
END_TEST

Suite *s21_fmod_suite(void) {
  Suite *suite;
  TCase *tc_fmod_is_normal, *tc_fmod_is_zero, *tc_fmod_is_negative,
      *tc_fmod_test_nan_inf;

  suite = suite_create("s21_fmod");

  tc_fmod_is_normal = tcase_create("s21_fmod_test_is_normal");
  tcase_add_test(tc_fmod_is_normal, s21_fmod_test_is_nomal);
  suite_add_tcase(suite, tc_fmod_is_normal);

  tc_fmod_is_zero = tcase_create("s21_fmod_test_is_zero");
  tcase_add_test(tc_fmod_is_zero, s21_fmod_test_is_zero);
  suite_add_tcase(suite, tc_fmod_is_zero);

  tc_fmod_is_negative = tcase_create("s21_fmod_test_is_negative");
  tcase_add_test(tc_fmod_is_negative, s21_fmod_test_is_negative);
  suite_add_tcase(suite, tc_fmod_is_negative);

  tc_fmod_test_nan_inf = tcase_create("s21_fmod_test_nan_inf");
  tcase_add_test(tc_fmod_test_nan_inf, s21_fmod_test_nan_inf);
  suite_add_tcase(suite, tc_fmod_test_nan_inf);

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
  case_test(s21_fmod_suite(), &fail);

  return fail;
}