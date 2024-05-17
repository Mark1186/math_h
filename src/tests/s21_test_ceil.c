#include <check.h>

#include "../s21_math.h"

START_TEST(s21_ceil_test1) {
  ck_assert_double_eq_tol(s21_ceil(-0.1), ceil(-0.1), TOL);
}
END_TEST

START_TEST(s21_ceil_test2) {
  ck_assert_double_eq_tol(s21_ceil(-213.3), ceil(-213.3), TOL);
}
END_TEST

START_TEST(s21_ceil_test3) {
  ck_assert_double_eq(s21_ceil(INFINITY), ceil(INFINITY));
}
END_TEST

START_TEST(s21_ceil_test4) {
  ck_assert_double_nan(s21_ceil(NAN));
  ck_assert_double_nan(ceil(NAN));
}
END_TEST

START_TEST(s21_ceil_test5) {
  ck_assert_double_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
}
END_TEST

START_TEST(s21_ceil_test6) {
  ck_assert_double_eq_tol(s21_ceil(50), ceil(50), TOL);
}
END_TEST

Suite *s21_ceil_suite(void) {
  Suite *suite;
  TCase *tc_ceil_test1, *tc_ceil_test2, *tc_ceil_test3,
  *tc_ceil_test4, *tc_ceil_test5, *tc_ceil_test6;

  suite = suite_create("s21_ceil");

  tc_ceil_test1 = tcase_create("s21_ceil_test1");
  tcase_add_test(tc_ceil_test1, s21_ceil_test1);
  suite_add_tcase(suite, tc_ceil_test1);

  tc_ceil_test2 = tcase_create("s21_ceil_test2");
  tcase_add_test(tc_ceil_test2, s21_ceil_test2);
  suite_add_tcase(suite, tc_ceil_test2);
  
  tc_ceil_test3 = tcase_create("s21_ceil_test3");
  tcase_add_test(tc_ceil_test3, s21_ceil_test3);
  suite_add_tcase(suite, tc_ceil_test3);
  
  tc_ceil_test4 = tcase_create("s21_ceil_test4");
  tcase_add_test(tc_ceil_test4, s21_ceil_test4);
  suite_add_tcase(suite, tc_ceil_test4);
  
  tc_ceil_test5 = tcase_create("s21_ceil_test5");
  tcase_add_test(tc_ceil_test5, s21_ceil_test5);
  suite_add_tcase(suite, tc_ceil_test5);
  
  tc_ceil_test6 = tcase_create("s21_ceil_test6");
  tcase_add_test(tc_ceil_test6, s21_ceil_test6);
  suite_add_tcase(suite, tc_ceil_test6);

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
  case_test(s21_ceil_suite(), &fail);

  return fail;
}
