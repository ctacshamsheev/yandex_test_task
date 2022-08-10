#include <iostream>

using std::cin;
using std::cout;
using std::string;

int main() {
  string j, s;
  cin >> j >> s;
  int result = 0;
  for (const char ch : s) {
    result += j.find(ch) != string::npos;
  }
  cout << result;
  return 0;
}
