#include <iostream>

using std::cin;
using std::cout;

int main() {
  int n = 0;
  int t = 0;
  int max = 0;
  int current = 0;
  bool prev = false;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t == 1) {
      current++;
      prev = true;
    } else if (prev && t != 1) {
      prev = false;
      max = std::max(current, max);
      current = 0;
      prev = false;
    }
  }

  max = std::max(current, max);
  cout << max;
  return 0;
}
