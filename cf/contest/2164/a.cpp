#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 2e9;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int mn = inf, mx = -inf;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      mx = max(mx, x);
      mn = min(mn, x);
    }
    int x;
    cin >> x;
    if (x <= mx && mn <= x) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
