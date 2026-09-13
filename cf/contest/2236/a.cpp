#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int mx = 0, mn = 1e9;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      mx = max(mx, x), mn = min(mn, x);
    }
    cout << mx + 1 - mn << '\n';
  }
  return 0;
}