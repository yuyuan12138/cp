/**
 *    author:  yuyuan
 *    created: .. ::
**/
#include <bits/stdc++.h>

using namespace std;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pos[a[i]].push_back(i);
    }
    vector<bool> is_del(n, false);
    vector<int> mergeto(n, 0);
    iota(mergeto.begin(), mergeto.end(), 0);
    int l = a[0], r = a[0];
    int j = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[i - 1] + 1) {
        l = a[i], r = a[i];
        j = i;
      } else {
        if (a[i] > l && a[i] <= r + 1) {
          r = max(r, a[i]);
          is_del[i] = true;
        } else {
          l = a[i], r = a[i];
          j = i;
        }
      }
      mergeto[i] = j;
    }
    int64_t ans = 1, cur = 1;
    for (int i = 1; i < n; i++) {
      if (!is_del[i]) {
        ans += cur + i + 1;
        cur += i + 1;
      } else {
        auto it = lower_bound(pos[a[i] - 1].begin(), pos[a[i] - 1].end(), i);
        it = prev(it);
        int idx = *it;
        ans += cur + i - idx;
        cur += i - idx;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}