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
    vector<int> a(n), idx(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
         [&](const int i, const int j) -> bool { return a[i] < a[j]; });
    vector<pair<int, char>> trace(3, {0, '?'});
    trace[0].second = 'A', trace[1].second = 'B', trace[2].second = 'C';
    string ans(n, '?');
    for (int i = 0; i < n; i++) {
      if (trace[0].first == a[idx[i]]) {
        trace[0].first++;
      }
      ans[idx[i]] = trace[0].second;
      sort(trace.begin(), trace.end());
    }
    if (trace[0].first + trace[1].first + trace[2].first >=
        2 * max({trace[0].first, trace[1].first, trace[2].first})) {
      cout << "YES\n";
      cout << ans << '\n';
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
