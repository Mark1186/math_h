#include <check.h>

#include "s21_test.h"

START_TEST(s21_tan_test_out_diaposon) {
  double testValue = PI / 2 + PI * 1.5;
  ck_assert_double_eq_tol(s21_tan(testValue), tan(testValue), TOL);
}
END_TEST

START_TEST(s21_tan_test_in_diaposon) {
  double testValue1 = 40.5;
  double testValue2 = -430.54;
  ck_assert_double_eq_tol(s21_tan(testValue1), tan(testValue1), TOL);
  ck_assert_double_eq_tol(s21_tan(testValue2), tan(testValue2), TOL);
}
END_TEST

START_TEST(s21_tan_test_is_zero) {
  double testValue = 0.0;
  ck_assert_double_eq_tol(s21_tan(testValue), tan(testValue), TOL);
}
END_TEST

START_TEST(s21_tan_test_nan_inf) {
  double testValue1 = NaN;
  double testValue2 = POS_INF;

  ck_assert_double_nan(s21_tan(testValue1));
  ck_assert_double_nan(s21_tan(testValue2));
}
END_TEST

Suite *s21_tan_suite(void) {
  Suite *suite;
  TCase *tc_tan_test1, *tc_tan_test2, *tc_tan_test3, *tc_tan_test_nan_inf;

  suite = suite_create("s21_tan");

  tc_tan_test1 = tcase_create("s21_tan_test1");
  tcase_add_test(tc_tan_test1, s21_tan_test_out_diaposon);
  suite_add_tcase(suite, tc_tan_test1);

  tc_tan_test2 = tcase_create("s21_tan_test2");
  tcase_add_test(tc_tan_test2, s21_tan_test_in_diaposon);
  suite_add_tcase(suite, tc_tan_test2);

  tc_tan_test3 = tcase_create("s21_tan_test3");
  tcase_add_test(tc_tan_test3, s21_tan_test_is_zero);
  suite_add_tcase(suite, tc_tan_test3);

  tc_tan_test_nan_inf = tcase_create("s21_tan_test_nan_inf");
  tcase_add_test(tc_tan_test_nan_inf, s21_tan_test_nan_inf);
  suite_add_tcase(suite, tc_tan_test_nan_inf);

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
  case_test(s21_tan_suite(), &fail);

  return fail;
}