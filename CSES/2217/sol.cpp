/**
 *    author:  yuyuan
 *    created: 2025-12-12 11:14:13
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
 
  int n, m;
  cin >> n >> m;
  vector<int> pos(n), x(n);
  
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    x[i]--;
    pos[x[i]] = i;
  }
 
  int ans = 1;
  int cur = -1;
  for (int x = 0; x < n; x++) {
    if (cur > pos[x]) {
      ans++;
    }
    cur = pos[x];
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (x[a] > x[b]) {
      swap(a, b);
    }
    if (a == b) {
      debug();
    } else if (x[a] + 1 == x[b]) {
      if (x[a] > 0 && pos[x[a] - 1] > pos[x[a]]) {
        ans--;
      }
      if (x[b] < n - 1 && pos[x[b] + 1] < pos[x[b]]) {
        ans--;
      }

      swap(x[a], x[b]);
      swap(pos[x[a]], pos[x[b]]);
      swap(a, b);

      if (x[a] > 0 && pos[x[a] - 1] > pos[x[a]]) {
        ans++;
      }
      if (x[b] < n - 1 && pos[x[b] + 1] < pos[x[b]]) {
        ans++;
      }
      if (pos[x[b]] > pos[x[a]]) {
        ans--;
      } else {
        ans++;
      }
    } else {
      if (x[a] > 0 && pos[x[a] - 1] > pos[x[a]]) {
        ans--;
      }
      if (x[b] < n - 1 && pos[x[b] + 1] < pos[x[b]]) {
        ans--;
      }
      if (x[b] > 0 && pos[x[b] - 1] > pos[x[b]]) {
        ans--;
      }
      if (x[a] < n - 1 && pos[x[a] + 1] < pos[x[a]]) {
        ans--;
      }
      
      swap(x[a], x[b]);
      swap(pos[x[a]], pos[x[b]]);
      swap(a, b);
 
      if (x[a] > 0 && pos[x[a] - 1] > pos[x[a]]) {
        ans++;
      }
      if (x[b] < n - 1 && pos[x[b] + 1] < pos[x[b]]) {
        ans++;
      }
      if (x[b] > 0 && pos[x[b] - 1] > pos[x[b]]) {
        ans++;
      }
      if (x[a] < n - 1 && pos[x[a] + 1] < pos[x[a]]) {
        ans++;
      }
    }
    cout << ans << '\n'; 
  }
 
  return 0;
}

