#include <check.h>

#include "s21_test.h"

START_TEST(s21_sqrt_test_is_normal) {
  double testValue = 50.0;
  ck_assert_double_eq_tol(s21_sqrt(testValue), sqrt(testValue), TOL);
}
END_TEST

START_TEST(s21_sqrt_test_is_zero) {
  double testValue = 0.0;
  ck_assert_double_eq_tol(s21_sqrt(testValue), sqrt(testValue), TOL);
}
END_TEST

START_TEST(s21_sqrt_test_is_negative) {
  double testValue = -54.32;
  ck_assert_double_nan(s21_sqrt(testValue));
}
END_TEST

START_TEST(s21_sqrt_test_nan_inf) {
  double testValue1 = NaN;
  double testValue2 = POS_INF;
  double testValue3 = NEG_INF;
  ck_assert_double_nan(s21_sqrt(testValue1));
  ck_assert_double_nan(sqrt(testValue1));
  ck_assert_double_infinite(s21_sqrt(testValue2));
  ck_assert_double_infinite(sqrt(testValue2));
  ck_assert_double_nan(s21_sqrt(testValue3));
  ck_assert_double_nan(sqrt(testValue3));
}
END_TEST

START_TEST(s21_sqrt_test1) {
  ck_assert_double_nan(s21_sqrt(-0.01));
  ck_assert_double_nan(sqrt(-0.01));
}
END_TEST

START_TEST(s21_sqrt_test2) {
  ck_assert_double_eq(s21_sqrt(INFINITY), sqrt(INFINITY));
}
END_TEST

START_TEST(s21_sqrt_test3) {
  ck_assert_double_nan(s21_sqrt(NAN));
  ck_assert_double_nan(sqrt(NAN));
}
END_TEST

START_TEST(s21_sqrt_test4) {
  ck_assert_double_nan(s21_sqrt(-INFINITY));
  ck_assert_double_nan(sqrt(-INFINITY));
}
END_TEST

START_TEST(s21_sqrt_test5) {
  ck_assert_double_nan(s21_sqrt(-231.41));
  ck_assert_double_nan(sqrt(-231.41));
}
END_TEST

START_TEST(s21_sqrt_test6) {
/*
  long double arr[] = {5898.467, 8427.928,  5698.0035, 1289.244, 7025.7,
                       12.1357,  4745.5,    2930.637,  8187.391, 1015.89,
                       3155.844, 3954.143,  2862.1,    2782.954, 5097.545,
                       2630.4,   1075.747,  1889.786,  1782,     1,
                       21345678, 7432,      0.3245,    12345,    13456,
                       0.03213,  324.42342, 0,         50,       0.24};
  for (int i = 0; i < 30; i++) {
    ck_assert_double_eq_tol(s21_sqrt(arr[i]), sqrt(arr[i]), TOL);
  }
  */
}

Suite *s21_sqrt_suite(void) {
  Suite *suite;
  TCase *tc_sqrt_test_is_normal, *tc_sqrt_test_is_zero,
      *tc_sqrt_test_is_negative, *tc_sqrt_test_nan_inf,
      *tc_sqrt_test1, *tc_sqrt_test2, *tc_sqrt_test3,
      *tc_sqrt_test4, *tc_sqrt_test5, *tc_sqrt_test6;

  suite = suite_create("s21_sqrt");

  tc_sqrt_test_is_normal = tcase_create("s21_sqrt_is_normal");
  tcase_add_test(tc_sqrt_test_is_normal, s21_sqrt_test_is_normal);
  suite_add_tcase(suite, tc_sqrt_test_is_normal);

  tc_sqrt_test_is_zero = tcase_create("s21_sqrt_is_zero");
  tcase_add_test(tc_sqrt_test_is_zero, s21_sqrt_test_is_zero);
  suite_add_tcase(suite, tc_sqrt_test_is_zero);

  tc_sqrt_test_is_negative = tcase_create("s21_sqrt_is_negative");
  tcase_add_test(tc_sqrt_test_is_negative, s21_sqrt_test_is_negative);
  suite_add_tcase(suite, tc_sqrt_test_is_negative);

  tc_sqrt_test_nan_inf = tcase_create("s21_sqrt_test_nan_inf");
  tcase_add_test(tc_sqrt_test_nan_inf, s21_sqrt_test_nan_inf);
  suite_add_tcase(suite, tc_sqrt_test_nan_inf);
  
  tc_sqrt_test1 = tcase_create("s21_sqrt_test1");
  tcase_add_test(tc_sqrt_test1, s21_sqrt_test1);
  suite_add_tcase(suite, tc_sqrt_test1);
  
  tc_sqrt_test2 = tcase_create("s21_sqrt_test2");
  tcase_add_test(tc_sqrt_test2, s21_sqrt_test2);
  suite_add_tcase(suite, tc_sqrt_test2);
  
  tc_sqrt_test3 = tcase_create("s21_sqrt_test3");
  tcase_add_test(tc_sqrt_test3, s21_sqrt_test3);
  suite_add_tcase(suite, tc_sqrt_test3);
  
  tc_sqrt_test4 = tcase_create("s21_sqrt_test4");
  tcase_add_test(tc_sqrt_test4, s21_sqrt_test4);
  suite_add_tcase(suite, tc_sqrt_test4);
  
  tc_sqrt_test5 = tcase_create("s21_sqrt_test5");
  tcase_add_test(tc_sqrt_test5, s21_sqrt_test5);
  suite_add_tcase(suite, tc_sqrt_test5);
  
  tc_sqrt_test6 = tcase_create("s21_sqrt_test6");
  tcase_add_test(tc_sqrt_test6, s21_sqrt_test6);
  suite_add_tcase(suite, tc_sqrt_test6);

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
  case_test(s21_sqrt_suite(), &fail);

  return fail;
}
