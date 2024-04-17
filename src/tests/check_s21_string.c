#include "check_s21_string.h"

START_TEST(test_s21_memchr) {
  char str1[NMAX] = "bulking season now";
  char str2[NMAX] = "im on cut";
  int c = 's';

  char *s21_ans1 = (char *)s21_memchr((void *)str1, c, 15);
  char *orig_ans1 = (char *)memchr((void *)str1, c, 15);

  char *s21_ans2 = (char *)s21_memchr((void *)str2, 'c', 7);
  char *orig_ans2 = (char *)memchr((void *)str2, 'c', 7);

  ck_assert_str_eq(s21_ans1, orig_ans1);
  ck_assert_str_eq(s21_ans2, orig_ans2);
}
END_TEST

START_TEST(test_s21_memcmp) {
  char str1[NMAX] = "im on bulk";
  char str2[NMAX] = "im on cut";

  int s21_ans1 = (int)s21_memcmp(str1, str2, 5);
  int orig_ans1 = (int)memcmp(str1, str2, 5);

  int s21_ans2 = (int)s21_memcmp(str1, str2, 9);
  int orig_ans2 = (int)memcmp(str1, str2, 9);

  ck_assert_int_eq(s21_ans1, orig_ans1);
  ck_assert_int_eq(s21_ans2, orig_ans2);
}
END_TEST

START_TEST(test_s21_memcpy) {
  char str1[NMAX] = "bulking season";
  char str2[NMAX] = " cutting season";
  char s21_dest[NMAX] = {0};
  char dest[NMAX] = {0};

  char *s21_ans1 = (char *)s21_memcpy((void *)s21_dest, (void *)str1, 4);
  char *orig_ans1 = (char *)memcpy((void *)dest, (void *)str1, 4);

  ck_assert_str_eq(s21_ans1, orig_ans1);

  s21_ans1 = (char *)s21_memcpy((void *)s21_dest, (void *)str2, 4);
  orig_ans1 = (char *)memcpy((void *)dest, (void *)str2, 4);

  ck_assert_str_eq(s21_ans1, orig_ans1);
}
END_TEST

START_TEST(test_s21_memset) {
  char str1[NMAX] = "bulking season";
  char str2[NMAX] = "cutting season";
  s21_size_t n = 8;

  s21_memset((void *)str1, 'w', n);
  memset((void *)str2, 'w', n);
  ck_assert_str_eq(str1, str2);

  s21_memset((void *)str1, 'o', n);
  memset((void *)str2, 'o', n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_strcat) {
  char *dest1 = (char *)calloc(200, sizeof(char));
  char *dest2 = (char *)calloc(200, sizeof(char));

  dest1 = strcat(dest1, "cat");
  dest2 = s21_strcat(dest2, "cat");
  ck_assert_str_eq(dest1, dest2);

  dest1 = strcat(dest1, "dog");
  dest2 = s21_strcat(dest2, "dog");
  ck_assert_str_eq(dest1, dest2);

  dest1 = strcat(dest1, "frog");
  dest2 = s21_strcat(dest2, "frog");
  ck_assert_str_eq(dest1, dest2);

  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_s21_strncat) {
  char *dest1 = (char *)calloc(200, sizeof(char));
  char *dest2 = (char *)calloc(200, sizeof(char));

  for (s21_size_t i = 0; i < 15; i++) {
    dest1 = strncat(dest1, "1234567890", i);
    dest2 = s21_strncat(dest2, "1234567890", i);
    ck_assert_str_eq(dest1, dest2);
  }

  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_s21_strcpy) {
  char *dest1 = (char *)calloc(100, sizeof(char));
  char *dest2 = (char *)calloc(100, sizeof(char));

  char *str1 = "AbraCadabra";
  char *str2 = "Hello World";
  char *str3 = "Python sucks";
  dest1 = strcpy(dest1, str1);
  dest2 = s21_strcpy(dest2, str1);
  ck_assert_str_eq(dest1, dest2);

  dest1 = strcpy(dest1, str2);
  dest2 = s21_strcpy(dest2, str2);
  ck_assert_str_eq(dest1, dest2);

  dest1 = strcpy(dest1, str3);
  dest2 = s21_strcpy(dest2, str3);
  ck_assert_str_eq(dest1, dest2);

  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_s21_strncpy) {
  char *dest1 = (char *)calloc(100, sizeof(char));
  char *dest2 = (char *)calloc(100, sizeof(char));

  char *str1 = "AbraCadabra";
  char *str2 = "Hello World";
  char *str3 = "Python sucks";
  for (s21_size_t i = 0; i < 15; i++) {
    dest1 = strncpy(dest1, str1, i);
    dest2 = s21_strncpy(dest2, str1, i);
    ck_assert_str_eq(dest1, dest2);

    dest1 = strncpy(dest1, str2, i);
    dest2 = s21_strncpy(dest2, str2, i);
    ck_assert_str_eq(dest1, dest2);

    dest1 = strncpy(dest1, str3, i);
    dest2 = s21_strncpy(dest2, str3, i);
    ck_assert_str_eq(dest1, dest2);
  }

  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_s21_strlen) {
  char *str1 = "Hello World";
  char *str2 = "Python sucks";
  char *str3 = "C is the best";
  char *str4 = "";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
  ck_assert_int_eq(s21_strlen(str2), strlen(str2));
  ck_assert_int_eq(s21_strlen(str3), strlen(str3));
  ck_assert_int_eq(s21_strlen(str4), strlen(str4));
}
END_TEST

START_TEST(test_s21_strpbrk) {
  char *str1 = "zzzaba";
  char *str2 = "ab";
  char *str3 = "kopa";
  char *str4 = "abcd";
  char *str5 = "z";

  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
  ck_assert_str_eq(strpbrk(str3, str4), s21_strpbrk(str3, str4));
  ck_assert_str_eq(strpbrk(str1, str5), s21_strpbrk(str1, str5));
}
END_TEST

START_TEST(test_s21_strchr) {
  char s[10] = "qwerty";
  char empty[2] = "";

  for (int c = 0; c < 127; c++) {
    ck_assert_ptr_eq(strchr(s, c), s21_strchr(s, c));
    ck_assert_ptr_eq(strchr(empty, c), s21_strchr(empty, c));
  }
}
END_TEST

START_TEST(test_s21_strrchr) {
  char *str1 = "zzzaba";
  char *empty = "";

  for (int c = 0; c < 127; c++) {
    ck_assert_ptr_eq(strrchr(str1, c), s21_strrchr(str1, c));
    ck_assert_ptr_eq(strrchr(empty, c), s21_strrchr(empty, c));
  }
}
END_TEST

START_TEST(test_s21_strspn) {
  // if start wirh
  ck_assert_int_eq(strspn("school21", "chs"), s21_strspn("school21", "chs"));
  // if not start with
  ck_assert_int_eq(strspn("sber", "yandex"), s21_strspn("sber", "yandex"));
  // if full match
  ck_assert_int_eq(strspn("sber", "sberbank"), s21_strspn("sber", "sberbank"));
}
END_TEST

START_TEST(test_s21_strstr) {
  ck_assert_ptr_eq(strstr("school21", "ool"), s21_strstr("school21", "ool"));
  ck_assert_ptr_eq(strstr("school21", "21"), s21_strstr("school21", "21"));
  ck_assert_ptr_eq(strstr("school21", "c"), s21_strstr("school21", "c"));
  ck_assert_ptr_eq(strstr("school21", "sch"), s21_strstr("school21", "sch"));
  ck_assert_ptr_eq(strstr("school", "work"), s21_strstr("school", "work"));
}
END_TEST

START_TEST(test_s21_strncmp) {
  char str1[NMAX] = "season of bulk";
  char str2[NMAX] = "season of cut";

  int s21_ans = s21_strncmp(str1, str2, 6);
  int orig_ans = strncmp(str1, str2, 6);
  ck_assert_int_eq(s21_ans, orig_ans);

  s21_ans = s21_strncmp(str1, str2, 11);
  orig_ans = strncmp(str1, str2, 11);
  ck_assert_int_eq(s21_ans, orig_ans);
}
END_TEST

START_TEST(test_s21_strcmp) {
  char str1[NMAX] = "bulk";
  char str2[NMAX] = "cut";
  char str3[NMAX] = "bulk";

  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
  ck_assert_int_eq(s21_strcmp(str1, str3), strcmp(str1, str3));
  // ck_assert_int_eq(s21_strcmp("bulk", s21_NULL), strcmp("bulk", NULL));
}
END_TEST

START_TEST(test_s21_strcspn) {
  char str1[NMAX] = "BULK";
  char str2[NMAX] = "CUT";
  char str3[NMAX] = "BOMJ";
  char str4[NMAX] = "GARAGE";

  s21_size_t s21_ans1 = s21_strcspn(str1, str2);
  size_t orig_ans1 = strcspn(str1, str2);

  s21_size_t s21_ans2 = s21_strcspn(str1, str3);
  size_t orig_ans2 = strcspn(str1, str3);

  s21_size_t s21_ans3 = s21_strcspn(str2, str2);
  size_t orig_ans3 = strcspn(str2, str2);

  s21_size_t s21_ans4 = s21_strcspn(str1, str4);
  size_t orig_ans4 = strcspn(str1, str4);

  ck_assert_int_eq(s21_ans1, orig_ans1);
  ck_assert_int_eq(s21_ans2, orig_ans2);
  ck_assert_int_eq(s21_ans3, orig_ans3);
  ck_assert_int_eq(s21_ans4, orig_ans4);
}
END_TEST

START_TEST(test_s21_strtok) {
  char str1[25] = "school21 is the best";
  char str2[25] = "school21 is the best";
  char *token1 = strtok(str1, " ");
  char *token2 = s21_strtok(str2, " ");
  while (token1 != NULL && token2 != NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = strtok(NULL, " ");
    token2 = s21_strtok(NULL, " ");
  }
  ck_assert_ptr_eq(token1, token2);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("S21 String");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memchr);
  tcase_add_test(tc_core, test_s21_memcmp);
  tcase_add_test(tc_core, test_s21_memcpy);
  tcase_add_test(tc_core, test_s21_memset);
  tcase_add_test(tc_core, test_s21_strchr);
  tcase_add_test(tc_core, test_s21_strcat);
  tcase_add_test(tc_core, test_s21_strncat);
  tcase_add_test(tc_core, test_s21_strcmp);
  tcase_add_test(tc_core, test_s21_strncmp);
  tcase_add_test(tc_core, test_s21_strcpy);
  tcase_add_test(tc_core, test_s21_strncpy);
  tcase_add_test(tc_core, test_s21_strcspn);
  tcase_add_test(tc_core, test_s21_strlen);
  tcase_add_test(tc_core, test_s21_strpbrk);
  tcase_add_test(tc_core, test_s21_strrchr);
  tcase_add_test(tc_core, test_s21_strspn);
  tcase_add_test(tc_core, test_s21_strstr);
  tcase_add_test(tc_core, test_s21_strtok);
  suite_add_tcase(s, tc_core);

  return s;
}

int test_string() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = s21_string_suite();
  runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
