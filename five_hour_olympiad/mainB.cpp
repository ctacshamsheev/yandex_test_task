#include <stdio.h>

#define MAX 100

int main() {
  int n = 0;
  int m = 0;

  char a[MAX][MAX] = {0};
  char t[MAX][MAX] = {'.'};

  scanf("%d", &n);
  scanf("%d", &m);

  for (int i = 0; i < n; i++) {
    scanf("\n");
    for (int j = 0; j < m; j++) {
      scanf("%c", &a[n - i - 1][m - j - 1]);
    }
  }

  for (int j = 0; j < m; j++) {
    for (int i = n - 1; i >= 0; i--) {
      if (a[i][j] == '/' || a[i][j] == '\\') {
        t[i + 1][j] = a[i][j];
        t[i][j] = '.';
      } else {
        t[i][j] = a[i][j];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (i != 0) printf("\n");
    for (int j = 0; j < m; j++) {
      printf("%c", t[i][j]);
    }
  }

  return 0;
}
