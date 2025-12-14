/**
 *    author:  yuyuan
 *    created: 2025-12-14 09:29:04
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

  int n;
  cin >> n;
  vector<vector<int>> vec(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    cin >> vec[i][0] >> vec[i][1];
    vec[i][2] = i;
  }
  sort(vec.begin(), vec.end());
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  int cnt = 0;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int st = vec[i][0], ed = vec[i][1], idx = vec[i][2];
    if (pq.empty() || pq.top().first >= st) {
      cnt++;
      pq.push({ed, cnt});
      ans[idx] = cnt;
    } else {
      int last_room = pq.top().second;
      pq.pop();
      pq.push({ed, last_room});
      ans[idx] = last_room;
    }
  }

  cout << cnt << '\n';
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }

  return 0;
}


