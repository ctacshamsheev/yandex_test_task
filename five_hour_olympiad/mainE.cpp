#include <stdio.h>

#define MAX 100000

int a[MAX][4];

int get(int x11, int x12, int x21, int x22) {
  if (x11 < x21 && x21 < x12) {
    return 1;
  }
  if (x11 < x22 && x22 < x12) {
    return 1;
  }
  if (x11 == x22 || x12 == x22 || x11 == x21 || x12 == x21) {
    return -1;
  }
  return 0;
}

int get_per(int a1, int a2) {
  int x = get(a[a1][0], a[a1][2], a[a2][0], a[a2][2]);
  int y = get(a[a1][1], a[a1][3], a[a2][1], a[a2][3]);
  if (x == 1 && y == 1) return 1;
  return 0;
}

int main() {
  int n = 0;

  scanf("%d", &n);

  int result[MAX] = {0};
  for (int i = 0; i < n; i++) {
    result[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int t = get_per(i, j);
      result[i] += t;

      result[j] += t;
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", result[i]);
  }

  return 0;
}