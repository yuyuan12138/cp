/**
 *      author:  yuyuan567
 *      created: 2025-07-28 00:13:55
 */
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;

inline void speedup() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

void solve() {
  ll n;
  cin >> n;
  vector<ll> p(n);
  for (auto &x : p)
    cin >> x;
  ll tot = n * (n + 1) * (n + 2) / 6;
  for (int i = 1; i <= n; i++) {
    if (p[i - 1] < p[i]) {
      tot -= i * (n - i);
    }
  }
  cout << tot << "\n";
  return;
}

int main() {
  speedup();
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}