#include <math.h>
#include <stdio.h>

unsigned long long gcd_4(unsigned long long a, unsigned long long b) {
  if (a == b) return a;
  if (a == 0) return b;
  if (b == 0) return a;
  if ((~a & 1) != 0) {
    if ((b & 1) != 0)
      return gcd_4(a >> 1, b);
    else
      return gcd_4(a >> 1, b >> 1) << 1;
  }
  if ((~b & 1) != 0) return gcd_4(a, b >> 1);
  if (a > b) return gcd_4((a - b) >> 1, b);
  return gcd_4((b - a) >> 1, a);
}

unsigned long long max(unsigned long long a, unsigned long long b) {
  return (a > b) ? a : b;
}

int prime(unsigned long long n) {
  for (unsigned long long i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return 0;
  return 1;
}

unsigned long long get_max(unsigned long long a, unsigned long long b) {
  unsigned long long nod = gcd_4(a, b);
  a = a / nod;
  b = b / nod;
  unsigned long long max = nod;

  for (unsigned long long i = a; i > 1; i--) {
    if ((i == 2 || i % 2 != 0) && prime(i) && (a % i == 0 || b % i == 0)) {
      max = nod * i;
      return max;
    };
  }
  return max;
}

#define MAX 20

int main() {
  int n = 0;
  scanf("%d", &n);

  unsigned long long a[MAX][2];

  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &a[i][0], &a[i][1]);
  }

  for (int i = 0; i < n; i++) {
    if (i != 0) printf("\n");
    if (a[i][0] < a[i][1]) {
      printf("%llu", get_max(a[i][1], a[i][0]));
    } else {
      printf("%llu", get_max(a[i][0], a[i][1]));
    }
  }
  return 0;
}