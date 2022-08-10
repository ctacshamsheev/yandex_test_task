#include <stdio.h>

char get_char(long int w) {
  char curent = 'a';
  char result = 0;
  const long int mask = 0x1;
  while (w) {
    if (w & mask) {
      result = curent;
    }
    curent++;
    w = w >> 1;
  }
  if (result == '{') result = ' ';
  return result;
}

int main() {
  int n = 0;
  long int input = 0;
  scanf("%d", &n);
  long int w = 0;
  for (int i = 0; i < n; i++) {
    scanf("%ld", &input);
    printf("%c", get_char(input ^ w));
    w = input;
  }
  return 0;
}