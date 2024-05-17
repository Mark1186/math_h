#include <check.h>

#include "../s21_math.h"

START_TEST(s21_fabs_test1) {
  double testValue1 = -5.0;
  double testValue2 = 5.0;
  double testValue3 = 0.0;
  ck_assert_int_eq(s21_fabs(testValue1), fabs(testValue1));
  ck_assert_int_eq(s21_fabs(testValue2), fabs(testValue2));
  ck_assert_int_eq(s21_fabs(testValue3), fabs(testValue3));
}
END_TEST

START_TEST(s21_fabs_test2) {
  double testValue1 = -10.0;
  double testValue2 = 10.0;
  double testValue3 = 0.0;
  ck_assert_int_eq(s21_fabs(testValue1), fabs(testValue1));
  ck_assert_int_eq(s21_fabs(testValue2), fabs(testValue2));
  ck_assert_int_eq(s21_fabs(testValue3), fabs(testValue3));
}
END_TEST

START_TEST(s21_fabs_test3) {
  ck_assert_double_eq_tol(s21_fabs(568.36), fabs(568.36), TOL);
}
END_TEST

START_TEST(s21_fabs_test4) {
  ck_assert_double_eq_tol(s21_fabs(-14720.5689), fabs(-14720.5689), TOL);
}
END_TEST

START_TEST(s21_fabs_test5) {
  ck_assert_double_eq(s21_fabs(INFINITY), fabs(INFINITY));
}
END_TEST

START_TEST(s21_fabs_test6) {
  ck_assert_double_nan(s21_fabs(NAN));
  ck_assert_double_nan(fabs(NAN));
}
END_TEST

START_TEST(s21_fabs_test7) {
  ck_assert_double_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
}
END_TEST

Suite *s21_fabs_suite(void) {
  Suite *suite;
  TCase *tc_fabs_test1, *tc_fabs_test2, *tc_fabs_test3,
  *tc_fabs_test4, *tc_fabs_test5, *tc_fabs_test6, *tc_fabs_test7;

  suite = suite_create("s21_fabs");

  tc_fabs_test1 = tcase_create("s21_fabs_test1");
  tcase_add_test(tc_fabs_test1, s21_fabs_test1);
  suite_add_tcase(suite, tc_fabs_test1);

  tc_fabs_test2 = tcase_create("s21_fabs_test2");
  tcase_add_test(tc_fabs_test2, s21_fabs_test2);
  suite_add_tcase(suite, tc_fabs_test2);
  
  tc_fabs_test3 = tcase_create("s21_fabs_test3");
  tcase_add_test(tc_fabs_test3, s21_fabs_test3);
  suite_add_tcase(suite, tc_fabs_test3);
  
  tc_fabs_test4 = tcase_create("s21_fabs_test4");
  tcase_add_test(tc_fabs_test4, s21_fabs_test4);
  suite_add_tcase(suite, tc_fabs_test4);
  
  tc_fabs_test5 = tcase_create("s21_fabs_test5");
  tcase_add_test(tc_fabs_test5, s21_fabs_test5);
  suite_add_tcase(suite, tc_fabs_test5);
  
  tc_fabs_test6 = tcase_create("s21_fabs_test6");
  tcase_add_test(tc_fabs_test6, s21_fabs_test6);
  suite_add_tcase(suite, tc_fabs_test6);
  
  tc_fabs_test7 = tcase_create("s21_fabs_test7");
  tcase_add_test(tc_fabs_test7, s21_fabs_test7);
  suite_add_tcase(suite, tc_fabs_test7);

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
  case_test(s21_fabs_suite(), &fail);

  return fail;
}
