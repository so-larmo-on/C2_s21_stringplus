#include "s21_cs_string.h"

void *s21_to_upper(const char *str) {
  char *answer = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t len = s21_strlen(str);
    answer = (char *)calloc(len + 1, sizeof(char));
    for (s21_size_t i = 0; i < len; i++) {
      answer[i] = str[i];
      if (answer[i] >= 'a' && answer[i] <= 'z') {
        answer[i] -= 32;
      }
    }
  }
  return (void *)answer;
}

void *s21_to_lower(const char *str) {
  char *answer = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t len = s21_strlen(str);
    answer = (char *)calloc(len + 1, sizeof(char));
    for (s21_size_t i = 0; i < len; i++) {
      answer[i] = str[i];
      if (answer[i] >= 'A' && answer[i] <= 'Z') {
        answer[i] += 32;
      }
    }
  }
  return (void *)answer;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *answer = s21_NULL;
  if ((src != s21_NULL) && (trim_chars != s21_NULL)) {
    int table[256] = {0};
    s21_size_t len_src = s21_strlen(src);
    s21_size_t len_answer = 0;
    s21_size_t start_index = 0;
    s21_size_t stop_index = 0;
    if (s21_strlen(trim_chars) != 0) {
      s21_size_t len_trim = s21_strlen(trim_chars);
      for (s21_size_t i = 0; i < len_trim; i++) {
        table[(int)trim_chars[i]] = true;
      }
    }
    if (len_src != 0) {
      for (s21_size_t i = 0; i < len_src; i++) {
        if ((src[i] != ' ') && table[(int)src[i]] != true) {
          start_index = i;
          break;
        }
      }
      for (s21_size_t i = len_src - 1; i != 0; i--) {
        if (src[i] != ' ' && table[(int)src[i]] != true) {
          stop_index = i + 1;
          break;
        }
      }
      len_answer = stop_index - start_index;
    }
    answer = (char *)calloc(len_answer + 1, sizeof(char));
    s21_size_t j = 0;
    for (s21_size_t i = start_index; i < stop_index; i++) {
      answer[j] = src[i];
      j++;
    }
    answer[len_answer] = '\0';
  }
  return (void *)answer;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = s21_NULL;
  if ((src != s21_NULL) && (str != s21_NULL)) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    if ((start_index > 0) && (start_index <= src_len)) {
      result = (char *)calloc(src_len + str_len + 1, sizeof(char));

      for (s21_size_t i = 0; i < start_index; i++) {
        result[i] = src[i];
      }
      s21_size_t g = start_index;
      for (s21_size_t j = 0; j < str_len; j++) {
        result[g] = str[j];
        g++;
      }
      s21_size_t h = start_index;
      for (s21_size_t i = start_index + str_len; i < src_len + str_len; i++) {
        result[i] = src[h];
        h++;
      }
    }
  }
  return (void *)result;
}
