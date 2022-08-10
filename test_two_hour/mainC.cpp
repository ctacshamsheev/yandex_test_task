#include <iostream>
#include <set>

using std::cin;
using std::cout;

int main() {
  int n = 0;
  cin >> n;
  std::set<int> a;

  for (int i = 0; i < n; i++) {
    int t = 0;
    cin >> t;
    a.insert(t);
  }

  for (auto it = a.begin(); it != a.end(); ++it) {
    cout << *it << std::endl;
  }

  return 0;
}
