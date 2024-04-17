#include "check_s21_sprintf.h"

START_TEST(sprintf_p_check) {
  char str[100] = {'\0'};
  char str2[100] = {'\0'};
  s21_sprintf(str, "%*p", 20, str);
  sprintf(str2, "%*p", 20, str);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_n_check) {
  char str[5100] = {'\0'};
  char str2[5100] = {'\0'};
  int n1 = 0;
  int n2 = 0;
  sprintf(str, "hello%n %d", &n1, 35);
  s21_sprintf(str2, "hello%n %d", &n2, 35);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_G_check) {
  char str[NMAX] = {'\0'};
  char str2[NMAX] = {'\0'};

  s21_sprintf(str, "%G", 0.12345);
  sprintf(str2, "%G", 0.12345);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  s21_sprintf(str, "%G", 0.000000000000000000000003);
  sprintf(str2, "%G", 0.000000000000000000000003);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  s21_sprintf(str, "%LG", (long double)0.000000000000000000000003);
  sprintf(str2, "%LG", (long double)0.000000000000000000000003);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  s21_sprintf(str, "%.0LG", (long double)0.000000000000000000000003);
  sprintf(str2, "%.0LG", (long double)0.000000000000000000000003);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.2G", -4000.1);
  s21_sprintf(str2, "%.2G", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%G", 4000.1);
  s21_sprintf(str2, "%G", 4000.1);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%LG", 4000.1L);
  s21_sprintf(str2, "%LG", 4000.1L);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_g_check) {
  char str[NMAX] = {'\0'};
  char str2[NMAX] = {'\0'};

  s21_sprintf(str, "%g", 0.12345);
  sprintf(str2, "%g", 0.12345);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  s21_sprintf(str, "%g", 0.000000000000000000000003);
  sprintf(str2, "%g", 0.000000000000000000000003);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  s21_sprintf(str, "%Lg", (long double)0.000000000000000000000003);
  sprintf(str2, "%Lg", (long double)0.000000000000000000000003);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  s21_sprintf(str, "%.0Lg", (long double)0.000000000000000000000003);
  sprintf(str2, "%.0Lg", (long double)0.000000000000000000000003);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.2g", -4000.1);
  s21_sprintf(str2, "%.2g", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%g", 4000.1);
  s21_sprintf(str2, "%g", 4000.1);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%Lg", 4000.1L);
  s21_sprintf(str2, "%Lg", 4000.1L);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%020g", 4000.1);
  s21_sprintf(str2, "%020g", 4000.1);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%g", 400056.1);
  s21_sprintf(str2, "%g", 400056.1);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%g", 400056.99999999);
  s21_sprintf(str2, "%g", 400056.99999999);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%g", -4000.1);
  s21_sprintf(str2, "%g", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2g", -4000.1);
  s21_sprintf(str2, "%2g", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2g", 4000.1);
  s21_sprintf(str2, "%2g", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "% 2g", 4000.1);
  s21_sprintf(str2, "% 2g", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%- 2g", 4000.1);
  s21_sprintf(str2, "%- 2g", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.0g", 4000.6);
  s21_sprintf(str2, "%.0g", 4000.6);
  ck_assert_str_eq(str, str2);
  // memset(str, '\0', strlen(str));
  // memset(str2, '\0', strlen(str2));
  // sprintf(str, "%.0g", 0.9);
  // s21_sprintf(str2, "%.0g", 0.9);
  // ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%0g", 4000.1);
  s21_sprintf(str2, "%0g", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%0g", -4000.1);
  s21_sprintf(str2, "%0g", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+g %+g", 4000.1, 30.9);
  s21_sprintf(str2, "%+g %+g", 4000.1, 30.9);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+.8g %+g", 4000.0001, 30.9);
  s21_sprintf(str2, "%+.8g %+g", 4000.0001, 30.9);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-15g", 4000.1);
  s21_sprintf(str2, "%-15g", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+15g", 4000.1);
  s21_sprintf(str2, "%+15g", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-15g", -4000.1);
  s21_sprintf(str2, "%-15g", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+15.10g", -4000.1);
  s21_sprintf(str2, "%+15.10g", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-15g", 4000.1);
  s21_sprintf(str2, "%+-15g", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-15g", -4000.1);
  s21_sprintf(str2, "%+-15g", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%8.2g", 4000.1);
  s21_sprintf(str2, "%8.2g", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%8.2g", -4000.1);
  s21_sprintf(str2, "%8.2g", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%*.8g", 2, 4000.1);
  s21_sprintf(str2, "%*.8g", 2, 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.8g", 4000.001);
  s21_sprintf(str2, "%2.8g", 4000.001);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.8g", -4000.1);
  s21_sprintf(str2, "%2.8g", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%8.*g", 8, -4000.1);
  s21_sprintf(str2, "%8.*g", 8, -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%8.8g", -4000.0001);
  s21_sprintf(str2, "%8.8g", -4000.0001);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-8.2g", 4000.1);
  s21_sprintf(str2, "%-8.2g", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-8.2g", -4000.1);
  s21_sprintf(str2, "%-8.2g", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.8g", 4000.1);
  s21_sprintf(str2, "%-2.8g", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.8g", 4000.1);
  s21_sprintf(str2, "%-2.8g", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.8g", -4000.1);
  s21_sprintf(str2, "%-2.8g", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-8.8g", -4000.1);
  s21_sprintf(str2, "%-8.8g", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-8.8g", 4000.1);
  s21_sprintf(str2, "%-8.8g", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%9.0g", 4000.1);
  s21_sprintf(str2, "%9.0g", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%9.0Lg", (long double)4000.1);
  s21_sprintf(str2, "%9.0Lg", (long double)4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%9.0Lg", (long double)-4000.1);
  s21_sprintf(str2, "%9.0Lg", (long double)-4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.1g", 5.99);
  s21_sprintf(str2, "%.1g", 5.99);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.6g", 5.99);
  s21_sprintf(str2, "%.6g", 5.99);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%020.6g", 5.99);
  s21_sprintf(str2, "%020.6g", 5.99);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.2g", -4000.1);
  s21_sprintf(str2, "%.2g", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%10g", 1.0);
  s21_sprintf(str2, "%10g", 1.0);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%g", 1.123123);
  s21_sprintf(str2, "%g", 1.123123);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%g", 0.123123);
  s21_sprintf(str2, "%g", 0.123123);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%g", 0.);
  s21_sprintf(str2, "%g", 0.);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%#g", 0.0);
  s21_sprintf(str2, "%#g", 0.0);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.10g", 0.0012000000001);
  s21_sprintf(str2, "%.10g", 0.0012000000001);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%#.10g", 0.10000000001);
  s21_sprintf(str2, "%#.10g", 0.10000000001);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%Lg", (long double)4123123123123);
  s21_sprintf(str2, "%Lg", (long double)4123123123123);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%#g", 40.32);
  s21_sprintf(str2, "%#g", 40.32);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.6g", 5.99);
  s21_sprintf(str2, "%.6g", 5.99);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-.2g", 4000.1);
  s21_sprintf(str2, "%-.2g", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+.2g", 4000.1);
  s21_sprintf(str2, "%+.2g", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+0.2g", 4000.1);
  s21_sprintf(str2, "%+0.2g", 4000.1);
  ck_assert_str_eq(str, str2);
  // memset(str, '\0', strlen(str));
  // memset(str2, '\0', strlen(str2));
  // sprintf(str, "% 12.2g", 4000.1);
  // s21_sprintf(str2, "% 12.2g", 4000.1);
  // ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "% 12.2g", -4000.1);
  s21_sprintf(str2, "% 12.2g", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "% 12.2Lg", -4000.1L);
  s21_sprintf(str2, "% 12.2Lg", -4000.1L);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%022.2Lg", -4000.1L);
  s21_sprintf(str2, "%022.2Lg", -4000.1L);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_o_check) {
  char str[NMAX] = {'\0'};
  char str2[NMAX] = {'\0'};

  sprintf(str, "%o", 0);
  s21_sprintf(str2, "%o", 0);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%#o", 4);
  s21_sprintf(str2, "%#o", 4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.2o", -4);
  s21_sprintf(str2, "%.2o", -4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10.3o", 4);
  s21_sprintf(str2, "%-10.3o", 4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10.3o", -4);
  s21_sprintf(str2, "%-10.3o", -4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-3.10o", 4);
  s21_sprintf(str2, "%-3.10o", 4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-3.10o", -4);
  s21_sprintf(str2, "%-3.10o", -4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.2x %o", 4000000, -9);
  s21_sprintf(str2, "%2.2x %o", 4000000, -9);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.2o", -4000000);
  s21_sprintf(str2, "%2.2o", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.2o", 4000000);
  s21_sprintf(str2, "%.2o", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));

  sprintf(str, "%2.o", 4000000);
  s21_sprintf(str2, "%2.o", 4000000);
  ck_assert_str_eq(str, str2);

  sprintf(str, "%.2o", -4000000);
  s21_sprintf(str2, "%.2o", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%15.15o", 4000000);
  s21_sprintf(str2, "%15.15o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%16.15o", -4000000);
  s21_sprintf(str2, "%16.15o", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%15.15o", -4000000);
  s21_sprintf(str2, "%15.15o", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%12.2o", -4000000);
  s21_sprintf(str2, "%12.2o", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%12.2o", 4000000);
  s21_sprintf(str2, "%12.2o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.12o", 4000000);
  s21_sprintf(str2, "%2.12o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.12o", -4000000);
  s21_sprintf(str2, "%2.12o", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.2o", 4000000);
  s21_sprintf(str2, "%2.2o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.2o", -4000000);
  s21_sprintf(str2, "%2.2o", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.2o", 4000000);
  s21_sprintf(str2, "%2.2o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.2o", -4000000);
  s21_sprintf(str2, "%2.2o", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%o%%\n", 4000000);
  s21_sprintf(str2, "%o%%\n", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.2o", 4000000);
  s21_sprintf(str2, "%.2o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.2o", 4000000);
  s21_sprintf(str2, "%-2.2o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.2o", -4000000);
  s21_sprintf(str2, "%-2.2o", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-15.15o", 4000000);
  s21_sprintf(str2, "%-15.15o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-15.15o", -4000000);
  s21_sprintf(str2, "%-15.15o", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-12.2o", -4000000);
  s21_sprintf(str2, "%-12.2o", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-12.2o", 4000000);
  s21_sprintf(str2, "%-12.2o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.12o", 4000000);
  s21_sprintf(str2, "%-2.12o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.12o", -4000000);
  s21_sprintf(str2, "%-2.12o", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.2o", 4000000);
  s21_sprintf(str2, "%-2.2o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.2o", 4000000);
  s21_sprintf(str2, "%-2.2o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-o%%\n", 4000000);
  s21_sprintf(str2, "%-o%%\n", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-.2o", 4000000);
  s21_sprintf(str2, "%-.2o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2o", 4000000);
  s21_sprintf(str2, "%-2o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10o", 4000000);
  s21_sprintf(str2, "%-10o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2o", 4000000);
  s21_sprintf(str2, "%-2o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10o", 4000000);
  s21_sprintf(str2, "%-10o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%11.10x", 4000000);
  s21_sprintf(str2, "%11.10x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.2o", 4000000);
  s21_sprintf(str2, "%2.2o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.15o", -4000000);
  s21_sprintf(str2, "%.15o", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.15o", 4000000);
  s21_sprintf(str2, "%.15o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.15o", 4000000);
  s21_sprintf(str2, "%.15o", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.15o", -4000000);
  s21_sprintf(str2, "%.15o", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  s21_sprintf(str2, "%15.2o", 4000000);
  sprintf(str, "%15.2o", 4000000);
  s21_sprintf(str2, "%15.2o", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));

  sprintf(str, "%15.2o", -4000000);
  s21_sprintf(str2, "%15.2o", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%15.8o", -4000000);
  s21_sprintf(str2, "%15.8o", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-.8o", -4000000);
  s21_sprintf(str2, "%-.8o", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.8o", 4000000);
  s21_sprintf(str2, "%.8o", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-.8x", 4000000);
  s21_sprintf(str2, "%-.8x", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-11o", -4000000);
  s21_sprintf(str2, "%-11o", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-5o", -4000000);
  s21_sprintf(str2, "%-5o", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10.8o", -4000000);
  s21_sprintf(str2, "%-10.8o", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10.8o", 4000000);
  s21_sprintf(str2, "%-10.8o", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10.8o", -4000000);
  s21_sprintf(str2, "%-10.8o", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%13.10o", -4000000);
  s21_sprintf(str2, "%13.10o", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));

  sprintf(str, "%-11.11o", 4000000);
  s21_sprintf(str2, "%-11.11o", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-5.11o", 4000000);
  s21_sprintf(str2, "%-5.11o", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-9.7o", 4000000);
  s21_sprintf(str2, "%-9.7o", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%u", (unsigned int)-4000000);
  s21_sprintf(str2, "%u", -4000000);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_c_check) {
  char str[5100] = {'\0'};
  char str2[5100] = {'\0'};
  sprintf(str, "%11c %c", 'A', 'b');
  s21_sprintf(str2, "%11c %c", 'A', 'b');
  ck_assert_str_eq(str, str2);

  sprintf(str, "%c %97c", 'n', 'j');
  s21_sprintf(str2, "%c %97c", 'n', 'j');
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-c %-3c", 'j', 'z');
  s21_sprintf(str2, "%-c %-3c", 'j', 'z');
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-c %-3c %c %c %c %c", 'j', 'z', 'z', 'z', 'z', 'z');
  s21_sprintf(str2, "%-c %-3c %c %c %c %c", 'j', 'z', 'z', 'z', 'z', 'z');
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%c", 'A');
  s21_sprintf(str2, "%c", 'A');
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_s_check) {
  char str[100] = {'\0'};
  char str2[100] = {'\0'};
  sprintf(str, "%s", "abcde");
  s21_sprintf(str2, "%s", "abcde");
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.1s", "abcde");
  s21_sprintf(str2, "%.1s", "abcde");
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.20s", "abcde");
  s21_sprintf(str2, "%.20s", "abcde");
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%10.3s", "abcde");
  s21_sprintf(str2, "%10.3s", "abcde");
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10.7s", "abcde");
  s21_sprintf(str2, "%-10.7s", "abcde");
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10.7s %send", "abcde", "abc");
  s21_sprintf(str2, "%-10.7s %send", "abcde", "abc");
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_u_check) {
  char str[100] = {0};
  char str2[100] = {0};
  sprintf(str, "%hu", (unsigned short)4);
  s21_sprintf(str2, "%hu", (unsigned short)4);
  ck_assert_str_eq(str, str2);

  sprintf(str, "%2u", (unsigned int)4);
  s21_sprintf(str2, "%2u", 4);
  ck_assert_str_eq(str, str2);

  sprintf(str, "%2.5u", (unsigned int)4);
  s21_sprintf(str2, "%2.5u", 4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-u", (unsigned int)6);
  s21_sprintf(str2, "%-u", 6);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-20u", (unsigned int)6);
  s21_sprintf(str2, "%-20u", 6);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-20.u", (unsigned int)6);
  s21_sprintf(str2, "%-20.u", 6);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-u", (unsigned int)6);
  s21_sprintf(str2, "%-u", 6);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.3u", (unsigned int)6);
  s21_sprintf(str2, "%2.3u", 6);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_d_check) {
  char str[100] = {'\0'};
  char str2[100] = {'\0'};
  sprintf(str, "%d", 0);
  s21_sprintf(str2, "%d", 0);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%d", 4);
  s21_sprintf(str2, "%d", 4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.d", 0);
  s21_sprintf(str2, "%.d", 0);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.d", 0);
  s21_sprintf(str2, "%.d", 0);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%d", -4);
  s21_sprintf(str2, "%d", -4);
  ck_assert_str_eq(str, str2);

  sprintf(str, "%-10.3d", 4);
  s21_sprintf(str2, "%-10.3d", 4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10.3d", -4);
  s21_sprintf(str2, "%-10.3d", -4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-3.10d", 4);
  s21_sprintf(str2, "%-3.10d", 4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-3.10d", -4);
  s21_sprintf(str2, "%-3.10d", -4);

  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+2.2d", 4000000);
  s21_sprintf(str2, "%+2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+2.2d", -4000000);
  s21_sprintf(str2, "%+2.2d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+.2d", 4000000);
  s21_sprintf(str2, "%+.2d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+2.d", 4000000);
  s21_sprintf(str2, "%+2.d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+.2d", -4000000);
  s21_sprintf(str2, "%+.2d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%15.15d", 4000000);
  s21_sprintf(str2, "%15.15d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%16.15d", -4000000);
  s21_sprintf(str2, "%16.15d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%15.15d", -4000000);
  s21_sprintf(str2, "%15.15d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%12.2d", -4000000);
  s21_sprintf(str2, "%12.2d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%12.2d", 4000000);
  s21_sprintf(str2, "%12.2d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.12d", 4000000);
  s21_sprintf(str2, "%2.12d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.12d", -4000000);
  s21_sprintf(str2, "%2.12d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.2d", 4000000);
  s21_sprintf(str2, "%2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.2d", -4000000);
  s21_sprintf(str2, "%2.2d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+2.2d", 4000000);
  s21_sprintf(str2, "%+2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+2.2d", -4000000);
  s21_sprintf(str2, "%+2.2d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%d%%\n", 4000000);
  s21_sprintf(str2, "%d%%\n", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.2d", 4000000);
  s21_sprintf(str2, "%.2d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-2.2d", 4000000);
  s21_sprintf(str2, "%+-2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-2.2d", -4000000);
  s21_sprintf(str2, "%+-2.2d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-15.15d", 4000000);
  s21_sprintf(str2, "%-15.15d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-15.15d", -4000000);
  s21_sprintf(str2, "%-15.15d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-12.2d", -4000000);
  s21_sprintf(str2, "%-12.2d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-12.2d", 4000000);
  s21_sprintf(str2, "%-12.2d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.12d", 4000000);
  s21_sprintf(str2, "%-2.12d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.12d", -4000000);
  s21_sprintf(str2, "%-2.12d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-2.2d", 4000000);
  s21_sprintf(str2, "%+-2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-2.2d", 4000000);
  s21_sprintf(str2, "%+-2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-d%%\n", 4000000);
  s21_sprintf(str2, "%-d%%\n", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-.2d", 4000000);
  s21_sprintf(str2, "%-.2d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2d", 4000000);
  s21_sprintf(str2, "%-2d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10d", 4000000);
  s21_sprintf(str2, "%-10d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-2d", 40000004);
  s21_sprintf(str2, "%+-2d", 40000004);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-10d", -40000004);
  s21_sprintf(str2, "%+-10d", -40000004);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%11.10d", 4000000);
  s21_sprintf(str2, "%11.10d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "% 2.2d", 4000000);
  s21_sprintf(str2, "% 2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.15d", -4000000);
  s21_sprintf(str2, "%.15d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.15d", 4000000);
  s21_sprintf(str2, "%.15d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+.15d", 4000000);
  s21_sprintf(str2, "%+.15d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+.15d", -4000000);
  s21_sprintf(str2, "%+.15d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%15.2d", 4000000);
  s21_sprintf(str2, "%15.2d", 4000000);
  sprintf(str, "%+15.2d", 4000000);
  s21_sprintf(str2, "%+15.2d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+15.2d", -4000000);
  s21_sprintf(str2, "%+15.2d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%15.8d", -4000000);
  s21_sprintf(str2, "%15.8d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-.8d", -4000000);
  s21_sprintf(str2, "%-.8d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+.8d", 4000000);
  s21_sprintf(str2, "%+.8d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-.8d", 4000000);
  s21_sprintf(str2, "%+-.8d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-11d", -4000000);
  s21_sprintf(str2, "%+-11d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+050d", -4000000);
  s21_sprintf(str2, "%+050d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-10.8d", -4000000);
  s21_sprintf(str2, "%+-10.8d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-10.8d", 4000000);
  s21_sprintf(str2, "%+-10.8d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-10.8d", -4000000);
  s21_sprintf(str2, "%+-10.8d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+13.10d", -4000000);
  s21_sprintf(str2, "%+13.10d", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));

  sprintf(str, "%+-11.11d", 4000000);
  s21_sprintf(str2, "%+-11.11d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-5.11d", 4000000);
  s21_sprintf(str2, "%+-5.11d", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-9.7d %d", 4000000, 67);
  s21_sprintf(str2, "%+-9.7d %d", 4000000, 67);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%u", (unsigned int)-4000000);
  s21_sprintf(str2, "%u", -4000000);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_X_check) {
  char str[NMAX] = {'\0'};
  char str1[NMAX] = {'\0'};
  s21_sprintf(str, "HELLOO%020X %Xend", 46, 45);
  sprintf(str1, "HELLOO%020X %Xend", 46, 45);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', strlen(str));
  memset(str1, '\0', strlen(str1));
  s21_sprintf(str, "HELLOO%-#20Xend", 46);
  sprintf(str1, "HELLOO%-#20Xend", 46);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', strlen(str));
  memset(str1, '\0', strlen(str1));
  s21_sprintf(str, "HELLOO%20.Xend", 0X46);
  sprintf(str1, "HELLOO%20.Xend", 0X46);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', strlen(str));
  memset(str1, '\0', strlen(str1));
  s21_sprintf(str, "HELLOO%25.17Xend", 46123456);
  sprintf(str1, "HELLOO%25.17Xend", 46123456);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', strlen(str));
  memset(str1, '\0', strlen(str1));
  s21_sprintf(str, "HELLOO%020Xend", 0X46);
  sprintf(str1, "HELLOO%020Xend", 0X46);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', strlen(str));
  memset(str1, '\0', strlen(str1));
  s21_sprintf(str, "HELLOO%#20Xend", 46);
  sprintf(str1, "HELLOO%#20Xend", 46);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', strlen(str));
  memset(str1, '\0', strlen(str1));
  s21_sprintf(str, "HELLOO%#20Xend", -46);
  sprintf(str1, "HELLOO%#20Xend", -46);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_x_check) {
  char str[NMAX] = {'\0'};
  char str2[NMAX] = {'\0'};

  sprintf(str, "%x", 0);
  s21_sprintf(str2, "%x", 0);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%#x", 4);
  s21_sprintf(str2, "%#x", 4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.2x", -4);
  s21_sprintf(str2, "%.2x", -4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10.3x", 4);
  s21_sprintf(str2, "%-10.3x", 4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10.3x", -4);
  s21_sprintf(str2, "%-10.3x", -4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-3.10x", 4);
  s21_sprintf(str2, "%-3.10x", 4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-3.10x", -4);
  s21_sprintf(str2, "%-3.10x", -4);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.2x %x", 4000000, -9);
  s21_sprintf(str2, "%2.2x %x", 4000000, -9);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.2x", -4000000);
  s21_sprintf(str2, "%2.2x", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.2x", 4000000);
  s21_sprintf(str2, "%.2x", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.x", 4000000);
  s21_sprintf(str2, "%2.x", 4000000);
  ck_assert_str_eq(str, str2);

  sprintf(str, "%.2x", -4000000);
  s21_sprintf(str2, "%.2x", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%15.15x", 4000000);
  s21_sprintf(str2, "%15.15x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%16.15x", -4000000);
  s21_sprintf(str2, "%16.15x", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%15.15x", -4000000);
  s21_sprintf(str2, "%15.15x", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%12.2x", -4000000);
  s21_sprintf(str2, "%12.2x", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%12.2x", 4000000);
  s21_sprintf(str2, "%12.2x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.12x", 4000000);
  s21_sprintf(str2, "%2.12x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.12x", -4000000);
  s21_sprintf(str2, "%2.12x", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.2x", 4000000);
  s21_sprintf(str2, "%2.2x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.2x", -4000000);
  s21_sprintf(str2, "%2.2x", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.2x", 4000000);
  s21_sprintf(str2, "%2.2x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.2x", -4000000);
  s21_sprintf(str2, "%2.2x", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%x%%\n", 4000000);
  s21_sprintf(str2, "%x%%\n", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.2x", 4000000);
  s21_sprintf(str2, "%.2x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.2x", 4000000);
  s21_sprintf(str2, "%-2.2x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.2x", -4000000);
  s21_sprintf(str2, "%-2.2x", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-15.15x", 4000000);
  s21_sprintf(str2, "%-15.15x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-15.15x", -4000000);
  s21_sprintf(str2, "%-15.15x", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-12.2x", -4000000);
  s21_sprintf(str2, "%-12.2x", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-12.2x", 4000000);
  s21_sprintf(str2, "%-12.2x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.12x", 4000000);
  s21_sprintf(str2, "%-2.12x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.12x", -4000000);
  s21_sprintf(str2, "%-2.12x", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.2x", 4000000);
  s21_sprintf(str2, "%-2.2x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.2x", 4000000);
  s21_sprintf(str2, "%-2.2x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-x%%\n", 4000000);
  s21_sprintf(str2, "%-x%%\n", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-.2x", 4000000);
  s21_sprintf(str2, "%-.2x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2x", 4000000);
  s21_sprintf(str2, "%-2x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10x", 4000000);
  s21_sprintf(str2, "%-10x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2x", 4000000);
  s21_sprintf(str2, "%-2x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10x", 4000000);
  s21_sprintf(str2, "%-10x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%11.10x", 4000000);
  s21_sprintf(str2, "%11.10x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.2x", 4000000);
  s21_sprintf(str2, "% 2.2x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.15x", -4000000);
  s21_sprintf(str2, "%.15x", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.15x", 4000000);
  s21_sprintf(str2, "%.15x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.15x", 4000000);
  s21_sprintf(str2, "%.15x", 4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.15x", -4000000);
  s21_sprintf(str2, "%.15x", -4000000);
  ck_assert_str_eq(str, str2);

  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%15.2x", 4000000);
  s21_sprintf(str2, "%15.2x", 4000000);
  sprintf(str, "%15.2x", 4000000);
  s21_sprintf(str2, "%15.2x", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));

  sprintf(str, "%15.2x", -4000000);
  s21_sprintf(str2, "%15.2x", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%15.8x", -4000000);
  s21_sprintf(str2, "%15.8x", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-.8x", -4000000);
  s21_sprintf(str2, "%-.8x", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.8x", 4000000);
  s21_sprintf(str2, "%.8x", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-.8x", 4000000);
  s21_sprintf(str2, "%-.8x", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-11x", -4000000);
  s21_sprintf(str2, "%-11x", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-5x", -4000000);
  s21_sprintf(str2, "%-5x", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10.8x", -4000000);
  s21_sprintf(str2, "%-10.8x", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10.8x", 4000000);
  s21_sprintf(str2, "%-10.8x", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-10.8x", -4000000);
  s21_sprintf(str2, "%-10.8x", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%13.10x", -4000000);
  s21_sprintf(str2, "%13.10x", -4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));

  sprintf(str, "%-11.11x", 4000000);
  s21_sprintf(str2, "%-11.11x", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-5.11x", 4000000);
  s21_sprintf(str2, "%-5.11x", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-9.7x", 4000000);
  s21_sprintf(str2, "%-9.7x", 4000000);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%u", (unsigned int)-4000000);
  s21_sprintf(str2, "%u", -4000000);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_f_check) {
  char str[100] = {'\0'};
  char str2[100] = {'\0'};
  sprintf(str, "%.2f", 4000.1);
  s21_sprintf(str2, "%.2f", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.2f", -4000.1);
  s21_sprintf(str2, "%.2f", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%f", 4000.1);
  s21_sprintf(str2, "%f", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%f", -4000.1);
  s21_sprintf(str2, "%f", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2f", -4000.1);
  s21_sprintf(str2, "%2f", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2f", 4000.1);
  s21_sprintf(str2, "%2f", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "% 2f", 4000.1);
  s21_sprintf(str2, "% 2f", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%- 2f", 4000.1);
  s21_sprintf(str2, "%- 2f", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.0f", 4000.6);
  s21_sprintf(str2, "%.0f", 4000.6);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.0f", 0.9);
  s21_sprintf(str2, "%.0f", 0.99);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%0f", 4000.1);
  s21_sprintf(str2, "%0f", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%0f", -4000.1);
  s21_sprintf(str2, "%0f", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+f %+f", 4000.1, 30.9);
  s21_sprintf(str2, "%+f %+f", 4000.1, 30.9);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+.8f %+f", 4000.0001, 30.9);
  s21_sprintf(str2, "%+.8f %+f", 4000.0001, 30.9);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-15f", 4000.1);
  s21_sprintf(str2, "%-15f", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+15f", 4000.1);
  s21_sprintf(str2, "%+15f", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-15f", -4000.1);
  s21_sprintf(str2, "%-15f", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+15.10f", -4000.1);
  s21_sprintf(str2, "%+15.10f", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-15f", 4000.1);
  s21_sprintf(str2, "%+-15f", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+-15f", -4000.1);
  s21_sprintf(str2, "%+-15f", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%8.2f", 4000.1);
  s21_sprintf(str2, "%8.2f", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%8.2f", -4000.1);
  s21_sprintf(str2, "%8.2f", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%*.8f", 2, 4000.1);
  s21_sprintf(str2, "%*.8f", 2, 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.8f", 4000.001);
  s21_sprintf(str2, "%2.8f", 4000.001);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%2.8f", -4000.1);
  s21_sprintf(str2, "%2.8f", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%8.*f", 8, -4000.1);
  s21_sprintf(str2, "%8.*f", 8, -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%8.8f", -4000.0001);
  s21_sprintf(str2, "%8.8f", -4000.0001);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-8.2f", 4000.1);
  s21_sprintf(str2, "%-8.2f", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-8.2f", -4000.1);
  s21_sprintf(str2, "%-8.2f", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.8f", 4000.1);
  s21_sprintf(str2, "%-2.8f", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.8f", 4000.1);
  s21_sprintf(str2, "%-2.8f", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-2.8f", -4000.1);
  s21_sprintf(str2, "%-2.8f", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-8.8f", -4000.1);
  s21_sprintf(str2, "%-8.8f", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-8.8f", 4000.1);
  s21_sprintf(str2, "%-8.8f", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%9.0f", 4000.1);
  s21_sprintf(str2, "%9.0f", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%9.0Lf", (long double)4000.1);
  s21_sprintf(str2, "%9.0Lf", (long double)4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%9.0Lf", (long double)-4000.1);
  s21_sprintf(str2, "%9.0Lf", (long double)-4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.1f", 5.99);
  s21_sprintf(str2, "%.1f", 5.99);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.6f", 5.99);
  s21_sprintf(str2, "%.6f", 5.99);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%020.6f", 5.99);
  s21_sprintf(str2, "%020.6f", 5.99);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_lhidu_check) {
  char str[100] = {0};
  char str2[100] = {0};
  long int s = 4;
  sprintf(str, "%-20.6ld", s);
  s21_sprintf(str2, "%-20.6ld", s);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  long unsigned f = 10;
  sprintf(str, "%12.lu", f);
  s21_sprintf(str2, "%12.lu", f);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-20hd", (short int)4);
  s21_sprintf(str2, "%-20hd", 4);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%hd", (short int)4);
  s21_sprintf(str2, "%hd", 4);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%%");
  s21_sprintf(str2, "%%");
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%%");
  s21_sprintf(str2, "%%");
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.2f %d %c %s %g", 4000.1, 2, 'h', "fgh", 67.8);
  s21_sprintf(str2, "%.2f %d %c %s %g", 4000.1, 2, 'h', "fgh", 67.8);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_e_check) {
  char str[100] = {'\0'};
  char str2[100] = {'\0'};
  sprintf(str, "%.2e", 4000.1);
  s21_sprintf(str2, "%.2e", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.2e", -4000.1);
  s21_sprintf(str2, "%.2e", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%10e", 1.0);
  s21_sprintf(str2, "%10e", 1.0);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%e", 1.123123);
  s21_sprintf(str2, "%e", 1.123123);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%e", 0.123123);
  s21_sprintf(str2, "%e", 0.123123);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%e", 0.);
  s21_sprintf(str2, "%e", 0.);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%#E", 0.0);
  s21_sprintf(str2, "%#E", 0.0);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%#.10e", 0.10000000001);
  s21_sprintf(str2, "%#.10e", 0.10000000001);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%Le", (long double)4123123123123);
  s21_sprintf(str2, "%Le", (long double)4123123123123);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%#e", 40.32);
  s21_sprintf(str2, "%#e", 40.32);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%.6e", 5.99);
  s21_sprintf(str2, "%.6e", 5.99);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%-.2e", 4000.1);
  s21_sprintf(str2, "%-.2e", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+.2e", 4000.1);
  s21_sprintf(str2, "%+.2e", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%+0.2e", 4000.1);
  s21_sprintf(str2, "%+0.2e", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "% 12.2e", 4000.1);
  s21_sprintf(str2, "% 12.2e", 4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "% 12.2e", -4000.1);
  s21_sprintf(str2, "% 12.2e", -4000.1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "% 12.2Le", -4000.1L);
  s21_sprintf(str2, "% 12.2Le", -4000.1L);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', strlen(str));
  memset(str2, '\0', strlen(str2));
  sprintf(str, "%022.2Le", -4000.1L);
  s21_sprintf(str2, "%022.2Le", -4000.1L);
  ck_assert_str_eq(str, str2);

  // memset(str, '\0', strlen(str));
  // memset(str2, '\0', strlen(str2));
  // sprintf(str, "%0*.*Le", 22, 2, -4000.1L);
  // s21_sprintf(str2, "%0*.*Le", 22, 2 -4000.1L);
  // ck_assert_str_eq(str, str2);
}
END_TEST

Suite *s21_sprintf_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("S21 sprintf");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, sprintf_o_check);
  tcase_add_test(tc_core, sprintf_n_check);
  tcase_add_test(tc_core, sprintf_p_check);
  tcase_add_test(tc_core, sprintf_c_check);
  tcase_add_test(tc_core, sprintf_s_check);
  tcase_add_test(tc_core, sprintf_u_check);
  tcase_add_test(tc_core, sprintf_d_check);
  tcase_add_test(tc_core, sprintf_x_check);
  tcase_add_test(tc_core, sprintf_X_check);
  tcase_add_test(tc_core, sprintf_f_check);
  tcase_add_test(tc_core, sprintf_e_check);
  tcase_add_test(tc_core, sprintf_g_check);
  tcase_add_test(tc_core, sprintf_G_check);
  tcase_add_test(tc_core, sprintf_lhidu_check);
  suite_add_tcase(s, tc_core);
  return s;
}

int test_sprintf() {
  int failed = 0;
  Suite *s;
  SRunner *runner;
  s = s21_sprintf_suite();
  runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
