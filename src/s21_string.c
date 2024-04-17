#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t answer = 0;
  s21_size_t size1 = s21_strlen(str1);
  s21_size_t size2 = s21_strlen(str2);
  bool flag = false;
  char table[256] = {0};
  for (s21_size_t i = 0; i < size2; i++) {
    table[(int)str2[i]] = true;
  }
  for (s21_size_t i = 0; i < size1 && (flag == false); i++) {
    if (table[(int)str1[i]] == true) {
      flag = true;
      answer = i;
    }
  }

  if (flag == false) {
    answer = size1;
  }

  return answer;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t size = 0;
  s21_size_t i = 0;
  while (str[i] != '\0') {
    size++;
    i++;
  }
  return size;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *answer = s21_NULL;
  s21_size_t size1 = s21_strlen(str1);
  s21_size_t size2 = s21_strlen(str2);
  char table[256] = {0};
  for (s21_size_t i = 0; i < size2; i++) {
    table[(int)str2[i]] = true;
  }
  for (s21_size_t i = 0; i < size1; i++) {
    if (table[(int)str1[i]] == true) {
      answer = (char *)(str1 + i);
      break;
    }
  }
  return answer;
}

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t haystack_len = s21_strlen(haystack);
  s21_size_t needle_len = s21_strlen(needle);
  char *haystack2 = (char *)haystack;

  s21_size_t i = 0;
  s21_size_t j = 0;
  char *res = s21_NULL;
  int match_counter = 0;
  while (i != haystack_len) {
    if (needle[j] == haystack2[i]) {
      if (match_counter == 0) res = &haystack2[i];
      match_counter++;
      j++;
      i++;
    } else {
      res = s21_NULL;
      i++;
      j = 0;
      match_counter = 0;
    }
    if (j == needle_len) {
      break;
    }
  }

  return res;
}

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;
  char *ptr = (char *)str;
  while (*ptr != '\0') {
    if (*ptr == c) {
      res = ptr;
    }
    ptr++;
  }
  if (*ptr == c) {
    res = ptr;
  }
  return res;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t str1_len = s21_strlen(str1);
  s21_size_t str2_len = s21_strlen(str2);
  char table[256] = {0};
  s21_size_t res = str1_len;
  for (s21_size_t i = 0; i < str2_len; i++) {
    table[(int)str2[i]] = true;
  }
  for (s21_size_t i = 0; i < str1_len; i++) {
    if (table[(int)str1[i]] != true) {
      res = i;
      break;
    }
  }
  return res;
}

static char *saveptr;

char *s21_strtok(char *str, const char *delim) {
  char *token = s21_NULL;
  int checker = true;

  if (!str) str = saveptr;

  str += s21_strspn(str, delim);
  if (!*str) {
    saveptr = str;
    checker = 0;
  }
  if (checker == true) {
    token = str;
    str = s21_strpbrk(str, delim);
    if (str) {
      *str = '\0';
      saveptr = str + 1;
    } else {
      saveptr = token + s21_strlen(token);
    }
  }
  return token;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *ptr = dest;
  while (n != 0 && *src != '\0') {
    *dest++ = *src++;
    n--;
  }
  while (n > 0) {
    *dest++ = '\0';
    n--;
  }
  return ptr;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  while (n > 1 && *str1 && *str2 && *str1 == *str2) {
    ++str1;
    ++str2;
    --n;
  }
  return (int)(*str1) - (int)(*str2);
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  int length = s21_strlen(dest);
  char *ptr = dest + length;
  char *ptr1 = dest;
  for (s21_size_t i = 0; i < n; i++) {
    *(ptr) = *src;
    src++;
    ptr++;
  }

  *(ptr) = '\0';
  return ptr1;
}

int s21_strcmp(const char *str1, const char *str2) {
  char *a = (char *)str1;
  char *b = (char *)str2;
  while (*a && *b && *a == *b) ++a, ++b;
  return ((int)*a - (int)*b);
}

char *s21_strcpy(char *destination, const char *source) {
  char *ptr = destination;
  while (*source != '\0') {
    *destination = *source;
    destination++;
    source++;
  }
  *destination = '\0';
  return ptr;
}

char *s21_strcat(char *destination, const char *source) {
  s21_strcpy(destination + s21_strlen(destination), source);
  return destination;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *result = s21_NULL;
  unsigned char *byte = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    if (*byte == c) {
      result = byte;
      break;
    }
    byte++;
  }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  const unsigned char *str_1, *str_2;
  str_1 = str1;
  str_2 = str2;
  for (s21_size_t i = 0; result == 0 && str_1[i] != '\0' && i < n; i += 1) {
    result = str_1[i] - str_2[i];
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i += 1) {
    ((char *)dest)[i] = ((char *)src)[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    *(ptr++) = c;
  }
  return (void *)str;
}

char *s21_strchr(const char *str, int c) {
  char *res = s21_NULL;
  char *ptr = (char *)str;
  while (*ptr != '\0') {
    if (*ptr == c) {
      res = ptr;
      break;
    }
    ptr++;
  }
  if (*ptr == c) {
    res = ptr;
  }
  return res;
}
