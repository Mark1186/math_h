#include <check.h>

#include "s21_test.h"

START_TEST(s21_acos_test_in_diaposon) {
  double testValue1 = 0.1;
  double testValue2 = 0.25;
  double testValue3 = -0.89;
  ck_assert_double_eq_tol(s21_acos(testValue1), acos(testValue1), TOL);
  ck_assert_double_eq_tol(s21_acos(testValue2), acos(testValue2), TOL);
  ck_assert_double_eq_tol(s21_acos(testValue3), acos(testValue3), TOL);
}
END_TEST

START_TEST(s21_acos_test_out_diaposon) {
  double testValue1 = -1.5;
  double testValue2 = 1.5;
  ck_assert_double_nan(s21_acos(testValue1));
  ck_assert_double_nan(s21_acos(testValue2));
}
END_TEST

START_TEST(s21_acos_test_is_zero) {
  double testValue = 0.0;
  ck_assert_double_eq_tol(s21_acos(testValue), acos(testValue), TOL);
}
END_TEST

Suite *s21_acos_suite(void) {
  Suite *suite;
  TCase *tc_acos_test_in_diaposon, *tc_acos_test_out_diaposon,
      *tc_acos_test_is_zero;

  suite = suite_create("s21_acos");

  tc_acos_test_in_diaposon = tcase_create("s21_acos_test_in_diaposon");
  tcase_add_test(tc_acos_test_in_diaposon, s21_acos_test_in_diaposon);
  suite_add_tcase(suite, tc_acos_test_in_diaposon);

  tc_acos_test_out_diaposon = tcase_create("s21_acos_test_out_diaposon");
  tcase_add_test(tc_acos_test_out_diaposon, s21_acos_test_out_diaposon);
  suite_add_tcase(suite, tc_acos_test_out_diaposon);

  tc_acos_test_is_zero = tcase_create("s21_acos_test_is_zero");
  tcase_add_test(tc_acos_test_is_zero, s21_acos_test_is_zero);
  suite_add_tcase(suite, tc_acos_test_is_zero);

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
  case_test(s21_acos_suite(), &fail);

  return fail;
}