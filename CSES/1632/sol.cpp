/**
 *    author:  yuyuan
 *    created: 2025-12-21 16:18:03
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  int ans = k;
  multiset<int> ed;
  for (int i = 0; i < k; i++) {
    ed.insert(a[i].second);
  }
  for (int i = k; i < n; i++) {
    int st_t = a[i].first, ed_t = a[i].second;
    auto ptr = ed.upper_bound(st_t);
    if (ptr == ed.begin()) {
      int latest = *prev(ed.end());
      ed.erase(ed.find(latest));
      ed.insert(min(latest, ed_t));
    } else {
      ans++;
      ed.erase(prev(ptr));
      ed.insert(ed_t);
    }
  }
  cout << ans;

  return 0;
}

