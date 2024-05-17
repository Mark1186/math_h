#include <check.h>

#include "s21_test.h"

START_TEST(s21_pow_test_is_normal) {
  double testValue = 454.45;
  double testExp = 2.5;
  ck_assert_double_eq_tol(s21_pow(testValue, testExp), pow(testValue, testExp),
                          TOL);
}
END_TEST

START_TEST(s21_pow_test_is_zero) {
  double testValue1 = 0.0;
  double testExp1 = 0.0;

  double testValue2 = 0.0;
  double testExp2 = 1.0;
  ck_assert_double_eq_tol(s21_pow(testValue1, testExp1),
                          pow(testValue1, testExp1), TOL);
  ck_assert_double_eq_tol(s21_pow(testValue2, testExp2),
                          pow(testValue2, testExp2), TOL);
}
END_TEST

START_TEST(s21_pow_test_is_negative) {
  double testValue = -2.3;
  double testExp = -2.5;
  ck_assert_double_nan(s21_pow(testValue, testExp));
}
END_TEST

START_TEST(s21_pow_test_nan_inf) {
  double testValue1 = -5.4;
  double testExp1 = 3.0;

  double testValue2 = 5.4;
  double testExp2 = POS_INF;

  double testValue3 = 1.0;
  double testExp3 = POS_INF;

  double testValue4 = 5.4;
  double testExp4 = 0.0;

  double testValue5 = 0.0;
  double testExp5 = 1.0;

  ck_assert_double_nan(s21_pow(testValue1, testExp1));
  ck_assert_double_infinite(s21_pow(testValue2, testExp2));

  ck_assert_double_eq_tol(s21_pow(testValue3, testExp3),
                          pow(testValue3, testExp3), TOL);
  ck_assert_double_eq_tol(s21_pow(testValue4, testExp4),
                          pow(testValue4, testExp4), TOL);
  ck_assert_double_eq_tol(s21_pow(testValue5, testExp5),
                          pow(testValue5, testExp5), TOL);
}
END_TEST

Suite *s21_pow_suite(void) {
  Suite *suite;
  TCase *tc_pow_test_is_zero, *tc_pow_test_is_normal, *tc_pow_test_is_negative,
      *tc_pow_test_nan_inf;

  suite = suite_create("s21_pow");

  tc_pow_test_is_zero = tcase_create("s21_pow_test_is_zero");
  tcase_add_test(tc_pow_test_is_zero, s21_pow_test_is_zero);
  suite_add_tcase(suite, tc_pow_test_is_zero);

  tc_pow_test_is_normal = tcase_create("s21_pow_test_is_normal");
  tcase_add_test(tc_pow_test_is_normal, s21_pow_test_is_normal);
  suite_add_tcase(suite, tc_pow_test_is_normal);

  tc_pow_test_is_negative = tcase_create("s21_pow_test_is_negative");
  tcase_add_test(tc_pow_test_is_negative, s21_pow_test_is_negative);
  suite_add_tcase(suite, tc_pow_test_is_negative);

  tc_pow_test_nan_inf = tcase_create("s21_pow_test_nan_inf");
  tcase_add_test(tc_pow_test_nan_inf, s21_pow_test_nan_inf);
  suite_add_tcase(suite, tc_pow_test_nan_inf);

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
  case_test(s21_pow_suite(), &fail);

  return fail;
}