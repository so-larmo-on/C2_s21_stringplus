#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  flags f = flags_init(&f);
  int index = 0;
  va_list factor;
  va_start(factor, format);
  char tmp[NMAX] = {'\0'};
  while (*format) {
    if (*format != '%') {
      str[index++] = *format++;
      continue;
    }
    s21_memset(&f, 0, sizeof(flags));
    s21_memset(tmp, 0, sizeof(tmp));
    format++;
    format = get_flags(format, &f);
    format = get_width(format, &f, factor);
    format = get_precision(format, &f, factor);
    format = get_lenght(format, &f);
    f.specifier = *format;

    if (f.specifier == 'n') {
      int *n = va_arg(factor, int *);
      *n = (int)s21_strlen(str);
    } else {
      handle_value(&f, tmp, factor);
    }

    format++;
    for (int i = 0; i < (int)s21_strlen(tmp); i++) {
      str[index++] = tmp[i];
    }
  }
  va_end(factor);
  return (int)s21_strlen(str);
}

flags flags_init(flags *f) {
  f->is_precision_set = 0;
  f->length = '0';
  f->plus = 0;
  f->minus = 0;
  f->space = 0;
  f->width = 0;
  f->zero = 0;
  f->specifier = '0';
  f->precision = 0;
  f->hash = 0;
  f->base = 10;
  f->sign_e_degree = 0;
  return *f;
}

void handle_value(flags *f, char *str, va_list factor) {
  f->base = 10;
  switch (f->specifier) {
    case '%':
      parse_procent(str);
      break;
    case 'd':
      parse_int(f, str, factor);
      break;
    case 'c':
      parse_char(f, str, factor);
      break;
    case 's':
      parse_string(f, str, factor);
      break;
    case 'f':
      parse_float(f, str, factor);
      break;
    case 'u':
      parse_unsigned(f, str, factor);
      break;
    case 'x':
      parse_x(f, str, factor);
      break;
    case 'X':
      parse_x(f, str, factor);
      break;
    case 'e':
      parse_e(f, str, factor);
      break;
    case 'E':
      parse_e(f, str, factor);
      break;
    case 'p':
      parse_p(f, str, factor);
      break;
    case 'o':
      parse_o(f, str, factor);
      break;
    case 'g':
      parse_g(f, str, factor);
      break;
    case 'G':
      parse_g(f, str, factor);
      break;
  }
}

void parse_p(flags *f, char *str, va_list factor) {
  f->base = 16;
  long p = va_arg(factor, long);
  char tmp[NMAX] = {'\0'};
  int_to_string(tmp, f, p);
  s21_strcpy(str, "0x");
  s21_strcat(str, tmp);
  set_flags(str, f);
}
void e_notation_g(char *tmp_e, flags *f, int count_e, char *buff_e) {
  int index_e = 0;
  if (f->plus == -1) {
    tmp_e[index_e++] = '-';
  } else if (f->plus == 1) {
    tmp_e[index_e++] = '+';
  }
  int index_point = 0;
  char degree_buff[NMAX] = {'\0'};
  if (count_e < 0) {
    f->sign_e_degree = -1;
    count_e *= -1;
  }
  int_to_string(degree_buff, f, count_e);
  int length = (int)s21_strlen(buff_e);

  for (int i = 0; i < length; i++) {
    if (buff_e[index_point] == '.') {
      index_point++;
    }
    buff_e[i] = buff_e[index_point++];
  }
  while ((buff_e[s21_strlen(buff_e) - 1] == '0' ||
          buff_e[s21_strlen(buff_e) - 1] == '.') &&
         s21_strlen(buff_e) > 1) {
    buff_e[s21_strlen(buff_e) - 1] = '\0';
  }
  ge_to_string(tmp_e, f, &index_e, count_e, degree_buff, buff_e);
  s21_strcat(tmp_e, degree_buff);
  set_flags(tmp_e, f);
}
void f_notation_g(char *tmp_f, flags *f, int count_f, char *buff_f) {
  int index_f = 0;
  char buf_help[NMAX] = {'\0'};
  plus_minus(tmp_f, &index_f, f);
  int count_ff = 0;
  while (buff_f[count_ff] == '0' || buff_f[count_ff] == '.') {
    count_ff++;
  }
  s21_strncat(buf_help, buff_f,
              MIN((int)s21_strlen(buff_f), f->precision + 1 + count_ff));
  s21_memset(buff_f, '\0', s21_strlen(buff_f));
  s21_strcat(buff_f, buf_help);
  if (!f->hash) {
    while (buff_f[s21_strlen(buff_f) - 1] == '0') {
      buff_f[s21_strlen(buff_f) - 1] = '\0';
    }
  } else {
    while (buff_f[s21_strlen(buff_f) - 1] == '0' &&
           (int)s21_strlen(buff_f) - abs(count_f) -
                   (s21_strchr(buff_f, '.') != s21_NULL) >
               f->precision + (f->is_precision_set)) {
      buff_f[s21_strlen(buff_f) - 1] = '\0';
    }
  }
  if (buff_f[s21_strlen(buff_f) - 1] == '.') {
    buff_f[s21_strlen(buff_f) - 1] = '\0';
  }
  if (f->zero) {
    for (int i = 0; i < f->width - (int)s21_strlen(buff_f) - abs(f->plus);
         i++) {
      tmp_f[index_f++] = '0';
    }
  }
  s21_strcat(tmp_f, buff_f);
  set_flags(tmp_f, f);
}
void parse_g(flags *f, char *str, va_list factor) {
  if (!f->is_precision_set) {
    f->precision = 6;
  }
  char buff_e[NMAX] = {'\0'};
  char buff_f[NMAX] = {'\0'};
  void *num = s21_NULL;
  int count_e = 0;
  int count_f = 0;
  make_float(f, factor, &count_e, &count_f, buff_e, buff_f);
  char tmp_e[NMAX] = {'\0'};
  e_notation_g(tmp_e, f, count_e, buff_e);
  char tmp_f[NMAX] = {'\0'};
  f_notation_g(tmp_f, f, count_f, buff_f);
  if (f->precision <= count_f) {
    s21_strcat(tmp_f, tmp_e);
  }
  if (s21_strlen(tmp_f) > s21_strlen(tmp_e) || (abs(count_f) > f->precision)) {
    s21_strcpy(str, tmp_e);
  } else {
    s21_strcpy(str, tmp_f);
  }

  free(num);
}

void make_float(flags *f, va_list factor, int *count_e, int *count_f,
                char *buff_e, char *buff_f) {
  void *num = malloc(sizeof(long double));
  void *num_f = malloc(sizeof(long double));
  if (num && num_f) {
    if (f->length == 'L') {
      *((long double *)num) = va_arg(factor, long double);
      if (*((long double *)num) < 0) {
        f->plus = -1;
        *((long double *)num) *= -1;
      }
      if (!(f->specifier == 'e') && !(f->specifier == 'E')) {
        *((long double *)num_f) = *((long double *)num);
        *count_f = get_degree((((long double *)num_f)));
        buffs(*((long double *)num), f, buff_f, *count_f);
      }
      if (!(f->specifier == 'f')) {
        *count_e = get_degree((((long double *)num)));
        buffs(*((long double *)num), f, buff_e, *count_e);
      }
    } else {
      *((double *)num) = va_arg(factor, double);
      if (*((double *)num) < 0) {
        f->plus = -1;
        *((double *)num) *= -1;
      }
      if (!(f->specifier == 'e') && !(f->specifier == 'E')) {
        *((double *)num_f) = *((double *)num);
        *count_f = get_degree_double((((double *)num_f)));
        buffs(*((double *)num), f, buff_f, *count_f);
      }
      if (!(f->specifier == 'f')) {
        *count_e = get_degree_double((((double *)num)));
        buffs(*((double *)num), f, buff_e, *count_e);
      }
    }
    free(num);
    free(num_f);
  }
}

void parse_e(flags *f, char *str, va_list factor) {
  char buff[NMAX] = {'\0'};
  int count = 0;
  make_float(f, factor, &count, s21_NULL, buff, s21_NULL);
  char tmp[NMAX] = {'\0'};
  int index = 0;
  if (f->plus == -1) {
    tmp[index++] = '-';
  } else if (f->plus == 1) {
    tmp[index++] = '+';
  }
  int index_point = 0;
  char degree_buff[NMAX] = {'\0'};
  if (count < 0) {
    f->sign_e_degree = -1;
  }
  int_to_string(degree_buff, f, count);
  int length = (int)s21_strlen(buff);
  for (int i = 0; i < length; i++) {
    if (buff[index_point] == '.') {
      index_point++;
    }
    buff[i] = buff[index_point++];
  }
  e_to_string(tmp, f, &index, count, degree_buff, buff);
  s21_strcat(tmp, degree_buff);
  s21_strcat(str, tmp);
  set_flags(str, f);
}

void parse_float(flags *f, char *str, va_list factor) {
  char buff[NMAX] = {'\0'};
  int count = 0;
  make_float(f, factor, s21_NULL, &count, s21_NULL, buff);
  int index = 0;
  plus_minus(str, &index, f);
  if (f->zero) {
    for (int i = 0; i < f->width - (int)s21_strlen(buff) - abs(f->plus); i++) {
      str[index++] = '0';
    }
  }
  s21_strcat(str, buff);
  set_flags(str, f);
}
void ge_to_string(char *tmp, flags *f, int *index, int count, char *degree_buff,
                  const char *str) {
  if (f->zero) {
    for (int i = 0; i < f->width - (int)s21_strlen(str) -
                            (s21_strchr(str, '.') != s21_NULL) -
                            (int)s21_strlen(degree_buff) - 2 - abs(f->plus) -
                            ((int)s21_strlen(degree_buff) == 1);
         i++) {
      tmp[(*index)++] = '0';
    }
  }
  tmp[(*index)++] = str[0];
  if (f->precision > 1) {
    tmp[(*index)++] = '.';
  }

  for (int i = 0; i < MIN((int)s21_strlen(str) - 1, f->precision - 1); i++) {
    tmp[(*index)++] = str[i + 1];
  }
  if (f->hash) {
    int length_for_hash = (int)s21_strlen(str);
    for (int i = 0; i < f->precision - length_for_hash; i++) {
      tmp[(*index)++] = '0';
    }
  }
  add_e_notation(tmp, index, f, count);
}
void add_e_notation(char *tmp, int *index, flags *f, int count) {
  if (tmp[(*index) - 1] == '.') {
    tmp[(*index) - 1] = '\0';
    (*index)--;
  }
  if (f->specifier == 'g' || f->specifier == 'e') {
    tmp[(*index)++] = 'e';
  } else {
    tmp[(*index)++] = 'E';
  }
  tmp[(*index)++] = f->sign_e_degree == 0 ? '+' : '-';
  if (count < 0) {
    count *= -1;
  }
  if (count < 10) {
    tmp[(*index)++] = '0';
  }
}
void e_to_string(char *tmp, flags *f, int *index, int count, char *degree_buff,
                 const char *str) {
  if (f->zero) {
    for (int i = 0; i < f->width - f->precision - (f->precision > 0) - 1 -
                            (int)s21_strlen(degree_buff) - 2 - abs(f->plus) -
                            ((int)s21_strlen(degree_buff) == 1);
         i++) {
      tmp[(*index)++] = '0';
    }
  }
  tmp[(*index)++] = str[0];
  if (f->precision) {
    tmp[(*index)++] = '.';
  }

  for (int i = 0; i < f->precision; i++) {
    tmp[(*index)++] = str[i + 1];
  }

  add_e_notation(tmp, index, f, count);
}

void set_precision_buf(flags *f) {
  if (!f->is_precision_set) {
    f->precision = 6;
  }
  if (f->is_precision_set && f->precision == 0 &&
      (f->specifier == 'g' || f->specifier == 'G')) {
    f->precision = 1;
  }
}

long double s21_roundl(long double a) {
  long double b = a * 10;
  long int tmp = (long int)b;
  if (tmp % 10 >= 5) {
    a = (long int)a + 1;
  } else {
    a = (long int)a;
  }
  return (long double)a;
}

long double s21_modfl(long double a, long double *ptr) {
  long long int ans = (long long int)a;
  *ptr = (long double)ans;
  return (a - (long double)ans);
}

void buffs(long double val_f, flags *f, char *str, int count) {
  char left_buff[NMAX] = {'\0'};
  char right_buff[NMAX] = {'\0'};
  char help_right_buff[NMAX] = {'\0'};
  long double left = 0;
  long double right = s21_modfl(val_f, &left);
  set_precision_buf(f);
  for (int i = 0; i < f->precision; i++) {
    right *= 10;
  }
  if (s21_roundl(right) == (pow(10, (f->precision)))) {
    right = 0;
    left++;
  } else {
    right = s21_roundl(right);
  }
  if (f->precision == 0 && f->is_precision_set) {
    left = s21_roundl(val_f);
  }
  long double help_right = right;
  int degree_float = get_degree(&help_right) + 1;
  for (int i = 0; i < f->precision - degree_float; i++) {
    help_right_buff[i] = '0';
  }
  int_to_string(left_buff, f, (long int)left);
  if ((f->specifier == 'g' || f->specifier == 'G') && count < 0) {
    for (int i = 0; i < abs(count) - 1; i++) {
      right *= 10;
    }
  }
  int_to_string(right_buff, f, labs((long int)right));
  s21_strcat(help_right_buff, right_buff);
  if (!((f->specifier == 'g' || f->specifier == 'G') && count < 0)) {
    set_precision(help_right_buff, f);
  }
  s21_strcat(str, left_buff);
  s21_strcat(str, ".");
  s21_strcat(str, help_right_buff);
  if (str[s21_strlen(str) - 1] == '.') {
    str[s21_strlen(str) - 1] = '\0';
  }
}

char *int_to_string(char *str, flags *f, long int d) {
  char tmp[NMAX] = {'\0'};
  int index = NMAX - 2;
  if (d == 0 && f->is_precision_set && !f->precision) {
    s21_memset(str, '\0', s21_strlen(str));
  }
  if ((d == 0 && !(f->is_precision_set && !f->precision)) ||
      (d == 0 && f->is_precision_set && !f->precision && f->specifier != 'd' &&
       f->specifier != 'u'))
    tmp[index--] = '0';
  if (d < 0) {
    d *= -1;
    f->plus = -1;
  }

  while (d > 0) {
    tmp[index--] = "0123456789abcdef"[d % f->base];
    d /= f->base;
  }
  for (int i = index + 1; i < NMAX - 1; i++) {
    str[i - index - 1] = tmp[i];
  }
  return str;
}

char *int_to_string_u(char *str, flags *f, s21_size_t d) {
  char tmp[NMAX] = {'\0'};
  int index = NMAX - 2;
  if (d == 0 && !(f->is_precision_set && !f->precision)) tmp[index--] = '0';
  while (d > 0 && f->base > 0) {
    tmp[index--] = "0123456789abcdef"[d % f->base];
    d /= f->base;
  }
  for (int i = index + 1; i < NMAX - 1; i++) {
    str[i - index - 1] = tmp[i];
  }
  return str;
}

int get_degree(long double *val_e) {
  int degree = 0;
  int boolean = 0;

  while (*val_e < 1 && *val_e != 0) {
    *val_e *= 10;
    degree -= 1;
    boolean = 1;
  }
  while (*val_e > 9 && boolean == 0) {
    *val_e /= 10;
    degree += 1;
  }
  return degree;
}
int get_degree_double(double *val_e) {
  int degree = 0;
  int boolean = 0;

  while (*val_e < 1 && *val_e != 0) {
    *val_e *= 10;
    degree -= 1;
    boolean = 1;
  }
  while (*val_e > 9 && boolean == 0) {
    *val_e /= 10;
    degree += 1;
  }
  return degree;
}

void parse_x(flags *f, char *str, va_list factor) {
  f->base = 16;
  make_int(str, f, factor);
  set_precision_x(str, f);
  set_flags(str, f);
}

void parse_o(flags *f, char *str, va_list factor) {
  f->base = 8;
  make_int(str, f, factor);
  set_precision_x(str, f);
  set_flags(str, f);
}

void set_precision_x(char *str, flags *f) {
  int index = 0;
  int length = (int)s21_strlen(str);
  char tmp[NMAX] = {'\0'};
  if (!f->is_precision_set && f->zero) {
    for (int i = 0;
         i < f->width - (int)s21_strlen(str) - abs(f->plus) - f->hash; i++) {
      tmp[index++] = '0';
    }
  }
  for (int i = 0; i < f->precision - length; i++) {
    tmp[index++] = '0';
  }
  s21_strcat(tmp, str);
  s21_memset(str, '\0', s21_strlen(str));
  for (int i = 0; i < (int)s21_strlen(tmp); i++) {
    str[i] = tmp[i];
  }
}

void make_int(char *str, flags *f, va_list factor) {
  void *num = malloc(sizeof(long int));
  if (num) {
    if (f->specifier == 'd') {
      if (!f->length) {
        *((int *)num) = va_arg(factor, int);
      } else if (f->length == 'l') {
        *((long *)num) = va_arg(factor, long);
      } else if (f->length == 'h') {
        *((short *)num) = (short)va_arg(factor, int);
      }
    } else if (f->specifier == 'u' || f->specifier == 'x' ||
               f->specifier == 'X' || f->specifier == 'o') {
      if (!f->length) {
        *((unsigned int *)num) = va_arg(factor, unsigned int);
      } else if (f->length == 'l') {
        *((unsigned long int *)num) = va_arg(factor, unsigned long int);
      } else if (f->length == 'h') {
        *((unsigned short *)num) = (unsigned short)va_arg(factor, unsigned int);
      }
    }

    if (f->specifier != 'u' && f->specifier != 'x' && f->specifier != 'X' &&
        f->specifier != 'o') {
      if ((f->length == 'l' && *((long *)num) < 0) ||
          (!f->length && *((int *)num) < 0) ||
          (f->length == 'h' && *((short *)num) < 0)) {
        f->plus = -1;
        *((long *)num) *= -1;
      }

      if (f->length == 'l') {
        int_to_string(str, f, *((long *)num));
      } else if (f->length == 'h') {
        int_to_string(str, f, *((short *)num));
      } else if (!f->length) {
        int_to_string(str, f, *((int *)num));
      }

    } else {
      if (f->length == 'l') {
        int_to_string_u(str, f, *((unsigned long int *)num));
      } else if (f->length == 'h') {
        int_to_string_u(str, f, *((unsigned short int *)num));
      } else if (!f->length) {
        int_to_string_u(str, f, *((unsigned int *)num));
      }
    }
    free(num);
  }
}

void parse_int(flags *f, char *str, va_list factor) {
  make_int(str, f, factor);
  set_precision(str, f);
  set_flags(str, f);
}

void set_precision(char *str, flags *f) {
  int index = 0;
  int length = (int)s21_strlen(str);
  char tmp[NMAX] = {'\0'};
  if (f->specifier == 'd' || f->specifier == 'u') {
    plus_minus(tmp, &index, f);
    if (!f->is_precision_set && f->zero) {
      for (int i = 0; i < f->width - (int)s21_strlen(str) - abs(f->plus); i++) {
        tmp[index++] = '0';
      }
    }
    for (int i = 0; i < f->precision - length; i++) {
      tmp[index++] = '0';
    }
    s21_strcat(tmp, str);
  } else if (f->specifier == 'f' || f->specifier == 'e' ||
             f->specifier == 'E' || f->specifier == 'g' ||
             f->specifier == 'G') {
    for (int i = 0; i < MIN(length, f->precision); i++) {
      tmp[index++] = str[i];
    }
  }
  s21_memset(str, '\0', s21_strlen(str));
  for (int i = 0; i < (int)s21_strlen(tmp); i++) {
    str[i] = tmp[i];
  }
}

void plus_minus(char *str, int *index, flags *f) {
  if (f->plus == 1 && f->specifier != 'X' && f->specifier != 'x' &&
      f->specifier != 'u') {
    str[(*index)++] = '+';
  } else if (f->plus == -1) {
    str[(*index)++] = '-';
  }
}

void set_flags(char *str, flags *f) {
  char tmp[NMAX] = {'\0'};
  if (f->space && f->specifier != 'u' && f->specifier != 'x' &&
      f->specifier != 'X') {
    tmp[0] = ' ';
    s21_strcat(tmp, str);
    s21_memset(str, '\0', s21_strlen(str));
    s21_strcpy(str, tmp);
    s21_memset(tmp, '\0', s21_strlen(tmp));
  }
  if (!f->zero && !f->minus) {
    int index = 0;
    for (int i = 0; i < f->width - (int)s21_strlen(str) - f->hash; i++) {
      tmp[index++] = ' ';
    }
  }
  if (f->hash && (f->specifier == 'x' || f->specifier == 'X')) {
    s21_strcat(tmp, "0x");
  }
  if (f->hash && (f->specifier == 'o')) {
    s21_strcat(tmp, "0");
  }
  if (f->hash && (f->specifier == 'g' || f->specifier == 'G') &&
      s21_strchr(str, 'e') == s21_NULL && s21_strchr(str, 'E') == s21_NULL) {
  }

  s21_strcat(tmp, str);
  if (f->minus) {
    for (int i = (int)s21_strlen(tmp); i < f->width; i++) {
      tmp[i] = ' ';
    }
  }
  s21_memset(str, '\0', s21_strlen(str));
  for (int i = 0; i < (int)s21_strlen(tmp); i++) {
    str[i] = tmp[i];
  }
  if (f->specifier == 'X') {
    to_upper(str);
  }
}

void to_upper(char *str) {
  while (*str != '\0') {
    if (*(str) > 96 && *(str) < 123) {
      *(str) -= 32;
    }
    (str++);
  }
}

void parse_string(flags *f, char *str, va_list factor) {
  char tmp[NMAX] = {'\0'};
  s21_strcpy(tmp, va_arg(factor, char *));
  if (!f->is_precision_set) {
    s21_strcpy(str, tmp);
  } else {
    for (int i = 0; i < f->precision; i++) {
      str[i] = tmp[i];
    }
  }
  set_flags(str, f);
}

void parse_char(flags *f, char *str, va_list factor) {
  char c = va_arg(factor, int);
  str[0] = c;
  set_flags(str, f);
}

const char *get_flags(const char *format, flags *f) {
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '0' ||
         *format == '#') {
    switch (*format) {
      case '#':
        f->hash = 2;
        break;
      case '-':
        f->minus = 1;
        break;
      case '+':
        f->plus = 1;
        break;
      case ' ':
        f->space = 1;
        break;
      case '0':
        f->zero = 1;
        break;
    }
    format++;
  }
  return format;
}

const char *get_lenght(const char *format, flags *f) {
  if (*format == 'l' || *format == 'h' || *format == 'L') {
    switch (*format) {
      case 'l':
        f->length = 'l';
        break;
      case 'h':
        f->length = 'h';
        break;
      case 'L':
        f->length = 'L';
        break;
    }
    format++;
  }
  return format;
}

const char *get_precision(const char *format, flags *f, va_list factor) {
  if (*format == '.') {
    f->is_precision_set = 1;
    format++;
    while ((int)*format > 47 && (int)*format < 58) {
      f->precision = f->precision * 10;
      f->precision += (int)(*format) - 48;
      format++;
    }
    if ((char)*format == '*') {
      f->precision = va_arg(factor, int);
      format++;
    }
  }
  return format;
}

const char *get_width(const char *format, flags *f, va_list factor) {
  while ((int)*format > 47 && (int)*format < 58) {
    f->width = f->width * 10;
    f->width += (int)(*format) - 48;
    format++;
  }
  if ((char)*format == '*') {
    f->width = va_arg(factor, int);
    format++;
  }
  return format;
}

void parse_procent(char *str) {
  int index = 0;
  str[index++] = '%';
}

void parse_unsigned(flags *f, char *str, va_list factor) {
  make_int(str, f, factor);
  set_precision(str, f);
  set_flags(str, f);
}
