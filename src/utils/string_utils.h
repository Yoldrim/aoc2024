//
// Created by Harald Bergqvist on 2024-12-03.
//

#include <string.h>

int string_utils_is_allowed_letter(char ac, char c[]) {
  int allowed = 0;
  for (int i = 0; i < strlen(c); i++) {
    if (ac == c[i]) {
      allowed = 1;
    }
  }
  return allowed;
}

int string_utils_is_ascii_number(char c) {
  return c >= 48 && c <= 57;
}

size_t string_utils_find_all_indices(char *s, char *c, int *out) {
  int i = 0;
  const char *pos = s;
  pos = strstr(pos, c);
  while (pos != NULL) {
    *(out + i) = pos - s;
    i++;
    pos++;
    pos = strstr(pos, c);
  }
  return i;
}