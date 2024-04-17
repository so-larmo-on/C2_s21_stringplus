#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H
#include <math.h>

#include "s21_string.h"

#define NMAX 8000
#define MIN(X, Y) (((X) <= (Y)) ? (X) : (Y))

typedef struct flags {
  int is_precision_set;
  char length;
  int plus;
  int minus;
  int space;
  int width;
  int zero;
  char specifier;
  int precision;
  int hash;
  int base;
  int sign_e_degree;

} flags;

flags flags_init(flags *f);
int s21_sprintf(char *str, const char *format, ...);
long double s21_roundl(long double a);
long double s21_modfl(long double a, long double *ptr);
char *int_to_string(char *str, flags *f, long int d);
char *int_to_string_u(char *str, flags *f, s21_size_t d);
const char *get_flags(const char *format, flags *f);
const char *get_width(const char *format, flags *f, va_list factor);
const char *get_precision(const char *format, flags *f, va_list factor);
const char *get_lenght(const char *format, flags *f);
void handle_value(flags *f, char *str, va_list factor);
void parse_int(flags *f, char *str, va_list factor);
void parse_float(flags *f, char *str, va_list factor);
void parse_string(flags *f, char *str, va_list factor);
void parse_char(flags *f, char *str, va_list factor);
void parse_unsigned(flags *f, char *str, va_list factor);
void set_precision(char *str, flags *f);
void set_flags(char *str, flags *f);
void parse_procent(char *str);
void parse_x(flags *f, char *str, va_list factor);
void set_precision_x(char *str, flags *f);
void to_upper(char *str);
void parse_e(flags *f, char *str, va_list factor);
int get_degree(long double *val_d);
void buffs(long double val_f, flags *f, char *str, int count);
void plus_minus(char *str, int *index, flags *f);
void e_to_string(char *tmp, flags *f, int *index, int count, char *degree_buff,
                 const char *str);
void make_int(char *str, flags *f, va_list factor);
int get_degree_double(double *val_e);
void parse_p(flags *f, char *str, va_list factor);
void parse_o(flags *f, char *str, va_list factor);
void parse_g(flags *f, char *str, va_list factor);
void make_float(flags *f, va_list factor, int *count_e, int *count_f,
                char *buff_e, char *buff_f);
void e_notation_g(char *tmp_e, flags *f, int count_e, char *buff_e);
void f_notation_g(char *tmp_f, flags *f, int count_f, char *buff_f);
void ge_to_string(char *tmp, flags *f, int *index, int count, char *degree_buff,
                  const char *str);
void add_e_notation(char *tmp, int *index, flags *f, int count);
// void buffs_precision_and_roundl(flags *f, long double *right, long double
// *left, char *help_right_buff, long double *val_f);
void set_precision_buf(flags *f);
#endif
