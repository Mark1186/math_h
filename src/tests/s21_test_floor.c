#include <check.h>

#include "s21_test.h"

START_TEST(s21_floor_test1) {
  ck_assert_double_eq_tol(s21_floor(-0.8), floor(-0.8), TOL);
}
END_TEST

START_TEST(s21_floor_test2) {
  ck_assert_double_eq_tol(s21_floor(0.8), floor(0.8), TOL);
}
END_TEST

START_TEST(s21_floor_test3) {
  ck_assert_double_eq_tol(s21_floor(-10.23), floor(-10.23), TOL);
}
END_TEST

START_TEST(s21_floor_test4) {
  ck_assert_double_eq(s21_floor(INFINITY), floor(INFINITY));
}
END_TEST

START_TEST(s21_floor_test5) {
  ck_assert_double_nan(s21_floor(NAN));
  ck_assert_double_nan(floor(NAN));
}
END_TEST

START_TEST(s21_floor_test6) {
  ck_assert_double_eq(s21_floor(-INFINITY), floor(-INFINITY));
}
END_TEST

START_TEST(s21_floor_test7) {
  ck_assert_double_eq_tol(s21_floor(-1200), floor(-1200), TOL);
}
END_TEST

Suite *s21_floor_suite(void) {
  Suite *suite;
  TCase *tc_floor_test1, *tc_floor_test2, *tc_floor_test3,
  *tc_floor_test4, *tc_floor_test5, *tc_floor_test6, *tc_floor_test7;

  suite = suite_create("s21_floor");

  tc_floor_test1 = tcase_create("s21_floor_test1");
  tcase_add_test(tc_floor_test1, s21_floor_test1);
  suite_add_tcase(suite, tc_floor_test1);

  tc_floor_test2 = tcase_create("s21_floor_test2");
  tcase_add_test(tc_floor_test2, s21_floor_test2);
  suite_add_tcase(suite, tc_floor_test2);

  tc_floor_test3 = tcase_create("s21_floor_test3");
  tcase_add_test(tc_floor_test3, s21_floor_test3);
  suite_add_tcase(suite, tc_floor_test3);
  
  tc_floor_test4 = tcase_create("s21_floor_test4");
  tcase_add_test(tc_floor_test4, s21_floor_test4);
  suite_add_tcase(suite, tc_floor_test4);
  
  tc_floor_test5 = tcase_create("s21_floor_test5");
  tcase_add_test(tc_floor_test5, s21_floor_test5);
  suite_add_tcase(suite, tc_floor_test5);
  
  tc_floor_test6 = tcase_create("s21_floor_test6");
  tcase_add_test(tc_floor_test6, s21_floor_test6);
  suite_add_tcase(suite, tc_floor_test6);
  
  tc_floor_test7 = tcase_create("s21_floor_test7");
  tcase_add_test(tc_floor_test7, s21_floor_test7);
  suite_add_tcase(suite, tc_floor_test7);

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
  case_test(s21_floor_suite(), &fail);

  return fail;
}
