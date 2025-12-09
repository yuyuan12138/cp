#include <bits/stdc++.h>

using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> k(n);
    int64_t sum = 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> k[i];
      sum = lcm(sum, k[i]);
    }
    int64_t cnt = 0;
    for (int i = 0; i < n; i++) {
      a[i] = sum / k[i];
      cnt += a[i];
    }

    if (cnt < sum) {
      for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
      }
    } else {
      cout << -1 << '\n';
    }

  }

  return 0;
}