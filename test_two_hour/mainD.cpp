#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;

void rec(int t, int open, int close, string s) {
  if (t < 0) {
    return;
  }

  if (open > 0) {
    rec(t + 1, open - 1, close, s + '(');
  }

  if (close > 0) {
    rec(t - 1, open, close - 1, s + ')');
  }

  if (t == 0 && open == 0 && close == 0) {
    cout << s << std::endl;
  }
}

int main() {
  int n = 0;
  cin >> n;
  string s;
  rec(0, n, n, s);
  return 0;
}
