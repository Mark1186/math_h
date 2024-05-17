#include <check.h>

#include "s21_test.h"

START_TEST(s21_log_test_is_number) {
  double testVl1 = 32.3;
  double testVl2 = 50.0;
  double testVl3 = 5.4;
  ck_assert_double_eq_tol(s21_log(testVl1), log(testVl1), TOL);
  ck_assert_double_eq_tol(s21_log(testVl2), log(testVl2), TOL);
  ck_assert_double_eq_tol(s21_log(testVl3), log(testVl3), TOL);
}
END_TEST

START_TEST(s21_log_test_is_nan) {
  double testVl1 = -32.3;
  double testVl2 = -50.0;
  double testVl3 = -5.4;
  ck_assert_double_nan(s21_log(testVl1));
  ck_assert_double_nan(s21_log(testVl2));
  ck_assert_double_nan(s21_log(testVl3));
}
END_TEST

START_TEST(s21_log_test_is_zero) {
  double testVl = 0.0;
  ck_assert_double_infinite(s21_log(testVl));
}
END_TEST

START_TEST(s21_log_test_nan_inf) {
  double testVl1 = NaN;
  double testVl2 = POS_INF;
  double testVl3 = NEG_INF;
  ck_assert_double_nan(s21_log(testVl1));
  ck_assert_double_infinite(s21_log(testVl2));
  ck_assert_double_nan(s21_log(testVl3));
}
END_TEST

START_TEST(s21_log_test1) {
  ck_assert_double_eq_tol(s21_log(26941.289), log(26941.289), TOL);
}
END_TEST

START_TEST(s21_log_test2) {
  ck_assert_double_nan(s21_log(-12.36));
  ck_assert_double_nan(log(-12.36));
}
END_TEST

START_TEST(s21_log_test3) {
  ck_assert_double_eq(s21_log(INFINITY), log(INFINITY));
}
END_TEST

START_TEST(s21_log_test4) {
  ck_assert_double_nan(s21_log(NAN));
  ck_assert_double_nan(log(NAN));
}
END_TEST

START_TEST(s21_log_test5) {
  ck_assert_double_nan(s21_log(-INFINITY));
  ck_assert_double_nan(log(-INFINITY));
}
END_TEST

START_TEST(s21_log_test6) { ck_assert_double_eq(s21_log(0), log(0)); }
END_TEST

START_TEST(s21_log_test7) { ck_assert_double_eq(s21_log(1), log(1)); }
END_TEST

Suite *s21_log_suite(void) {
  Suite *suite;
  TCase *tc_log_test_is_number, *tc_log_test_is_nan, *tc_log_test_is_zero,
      *tc_log_test_nan_inf, *tc_log_test1, *tc_log_test2, *tc_log_test3,
      *tc_log_test4, *tc_log_test5, *tc_log_test6, *tc_log_test7;

  suite = suite_create("s21_log");

  tc_log_test_is_number = tcase_create("s21_log_test");
  tcase_add_test(tc_log_test_is_number, s21_log_test_is_number);
  suite_add_tcase(suite, tc_log_test_is_number);

  tc_log_test_is_nan = tcase_create("s21_log_test_is_nan");
  tcase_add_test(tc_log_test_is_nan, s21_log_test_is_nan);
  suite_add_tcase(suite, tc_log_test_is_nan);

  tc_log_test_is_zero = tcase_create("s21_log_test_is_zero");
  tcase_add_test(tc_log_test_is_zero, s21_log_test_is_zero);
  suite_add_tcase(suite, tc_log_test_is_zero);

  tc_log_test_nan_inf = tcase_create("s21_log_test_nan_inf");
  tcase_add_test(tc_log_test_nan_inf, s21_log_test_nan_inf);
  suite_add_tcase(suite, tc_log_test_nan_inf);
  
  tc_log_test1 = tcase_create("s21_log_test1");
  tcase_add_test(tc_log_test1, s21_log_test1);
  suite_add_tcase(suite, tc_log_test1);
  
  tc_log_test2 = tcase_create("s21_log_test2");
  tcase_add_test(tc_log_test2, s21_log_test2);
  suite_add_tcase(suite, tc_log_test2);
  
  tc_log_test3 = tcase_create("s21_log_test3");
  tcase_add_test(tc_log_test3, s21_log_test3);
  suite_add_tcase(suite, tc_log_test3);
  
  tc_log_test4 = tcase_create("s21_log_test4");
  tcase_add_test(tc_log_test4, s21_log_test4);
  suite_add_tcase(suite, tc_log_test4);
  
  tc_log_test5 = tcase_create("s21_log_test5");
  tcase_add_test(tc_log_test5, s21_log_test5);
  suite_add_tcase(suite, tc_log_test5);
  
  tc_log_test6 = tcase_create("s21_log_test6");
  tcase_add_test(tc_log_test6, s21_log_test6);
  suite_add_tcase(suite, tc_log_test6);
  
  tc_log_test7 = tcase_create("s21_log_test7");
  tcase_add_test(tc_log_test7, s21_log_test7);
  suite_add_tcase(suite, tc_log_test7);

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
  case_test(s21_log_suite(), &fail);

  return fail;
}
