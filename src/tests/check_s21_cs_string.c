#include "check_s21_cs_string.h"

START_TEST(test_s21_to_upper) {
  char *str1 = "bulk";
  char *str2 = "BULK";
  char *str3 = "bULk";
  char *str4 = "";
  char *str5 = "{}[]()";
  char *str6 = s21_NULL;

  char *ans1 = (char *)s21_to_upper(str1);
  char *ans2 = (char *)s21_to_upper(str3);
  char *ans3 = (char *)s21_to_upper(str4);
  char *ans4 = (char *)s21_to_upper(str5);
  char *ans5 = (char *)s21_to_upper(str6);
  char *ans6 = (char *)s21_to_upper(str1);

  ck_assert_str_eq(ans1, str2);
  ck_assert_str_eq(ans2, str2);
  ck_assert_str_eq(ans3, str4);
  ck_assert_str_eq(ans4, str5);
  ck_assert_ptr_eq(ans5, str6);
  ck_assert_int_eq(s21_strlen(ans6), strlen(str2));

  free(ans1);
  free(ans2);
  free(ans3);
  free(ans4);
  free(ans5);
  free(ans6);
}
END_TEST

START_TEST(test_s21_to_lower) {
  char *str1 = "bulk";
  char *str2 = "BULK";
  char *str3 = "bULk";
  char *str4 = "";
  char *str5 = "{}[]()";
  char *str6 = s21_NULL;

  char *ans1 = (char *)s21_to_lower(str2);
  char *ans2 = (char *)s21_to_lower(str3);
  char *ans3 = (char *)s21_to_lower(str4);
  char *ans4 = (char *)s21_to_lower(str5);
  char *ans5 = (char *)s21_to_lower(str6);
  char *ans6 = (char *)s21_to_upper(str1);

  ck_assert_str_eq(ans1, str1);
  ck_assert_str_eq(ans2, str1);
  ck_assert_str_eq(ans3, str4);
  ck_assert_str_eq(ans4, str5);
  ck_assert_ptr_eq(ans5, str6);
  ck_assert_int_eq(s21_strlen(ans6), strlen(str2));

  free(ans1);
  free(ans2);
  free(ans3);
  free(ans4);
  free(ans5);
  free(ans6);
}
END_TEST

START_TEST(test_s21_insert) {
  char *str1 = "Dopeman, please, ";
  char *str2 = "can i have another hit?";
  char *str3 = "Dopeman, please, can i have another hit?";
  char *str4 = "Dopeman,  can i have another hit?";
  char *str5 = "please,";

  char *ans1 = (char *)s21_insert(str1, str2, 17);
  char *ans2 = (char *)s21_insert(str4, str5, 9);
  char *ans3 = (char *)s21_insert(str1, str2, 18);
  char *ans4 = (char *)s21_insert(s21_NULL, str2, 2);

  ck_assert_str_eq(ans1, str3);
  ck_assert_str_eq(ans2, str3);

  ck_assert_ptr_eq(ans3, s21_NULL);
  ck_assert_ptr_eq(ans4, s21_NULL);

  free(ans1);
  free(ans2);
  free(ans3);
}
END_TEST

START_TEST(test_s21_trim) {
  char *ans1 = (char *)s21_trim("-=1--1=--=", "-=");
  char *ans2 = (char *)s21_trim("1--1=--=", "-=");
  char *ans3 = (char *)s21_trim("1--1-----------------------------", "-=");
  char *ans4 = (char *)s21_trim("", "-=");
  char *ans5 = (char *)s21_trim(s21_NULL, " ");
  char *ans6 = (char *)s21_trim("-test-", s21_NULL);

  ck_assert_str_eq(ans1, "1--1");
  ck_assert_str_eq(ans2, "1--1");
  ck_assert_str_eq(ans3, "1--1");
  ck_assert_str_eq(ans4, "");

  ck_assert_ptr_eq(ans5, s21_NULL);
  ck_assert_ptr_eq(ans6, s21_NULL);

  free(ans1);
  free(ans2);
  free(ans3);
  free(ans4);
}
END_TEST

Suite *s21_cs_string_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("S21 C# String");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_to_upper);
  tcase_add_test(tc_core, test_s21_to_lower);
  tcase_add_test(tc_core, test_s21_insert);
  tcase_add_test(tc_core, test_s21_trim);
  suite_add_tcase(s, tc_core);

  return s;
}

int test_cs_string() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = s21_cs_string_suite();
  runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
