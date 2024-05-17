#include <check.h>

#include "../s21_math.h"

START_TEST(s21_abs_test1) {
  int testValue1 = -5;
  int testValue2 = 5;
  int testValue3 = 0;
  ck_assert_int_eq(s21_abs(testValue1), abs(testValue1));
  ck_assert_int_eq(s21_abs(testValue2), abs(testValue2));
  ck_assert_int_eq(s21_abs(testValue3), abs(testValue3));
}END_TEST

START_TEST(s21_abs_test2) {
  int testValue1 = -10;
  int testValue2 = 10;
  int testValue3 = 0;
  ck_assert_int_eq(s21_abs(testValue1), abs(testValue1));
  ck_assert_int_eq(s21_abs(testValue2), abs(testValue2));
  ck_assert_int_eq(s21_abs(testValue3), abs(testValue3));
}END_TEST

START_TEST(s21_abs_test3) { 
  ck_assert_int_eq(s21_abs(5), abs(5));
}END_TEST

START_TEST(s21_abs_test4) { 
  ck_assert_int_eq(s21_abs(-5), abs(-5));
}
END_TEST

START_TEST(s21_abs_test5) {
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
}END_TEST

START_TEST(s21_abs_test6) {
  ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN));
}END_TEST

START_TEST(s21_abs_test7) {
  ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
}END_TEST

Suite *s21_abs_suite(void) {
  Suite *suite;
  TCase *tc_abs_test1, *tc_abs_test2, *tc_abs_test3,
  *tc_abs_test4, *tc_abs_test5, *tc_abs_test6, *tc_abs_test7;

  suite = suite_create("s21_abs");

  tc_abs_test1 = tcase_create("s21_abs_test1");
  tcase_add_test(tc_abs_test1, s21_abs_test1);
  suite_add_tcase(suite, tc_abs_test1);

  tc_abs_test2 = tcase_create("s21_abs_test2");
  tcase_add_test(tc_abs_test2, s21_abs_test2);
  suite_add_tcase(suite, tc_abs_test2);
  
  tc_abs_test3 = tcase_create("s21_abs_test3");
  tcase_add_test(tc_abs_test3, s21_abs_test3);
  suite_add_tcase(suite, tc_abs_test3);
  
  tc_abs_test4 = tcase_create("s21_abs_test4");
  tcase_add_test(tc_abs_test4, s21_abs_test4);
  suite_add_tcase(suite, tc_abs_test4);
  
  tc_abs_test5 = tcase_create("s21_abs_test5");
  tcase_add_test(tc_abs_test5, s21_abs_test5);
  suite_add_tcase(suite, tc_abs_test5);
  
  tc_abs_test6 = tcase_create("s21_abs_test6");
  tcase_add_test(tc_abs_test6, s21_abs_test6);
  suite_add_tcase(suite, tc_abs_test6);
  
  tc_abs_test7 = tcase_create("s21_abs_test7");
  tcase_add_test(tc_abs_test7, s21_abs_test7);
  suite_add_tcase(suite, tc_abs_test7);

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
  case_test(s21_abs_suite(), &fail);

  return fail;
}
