#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  vector<int> t(2 * n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    t[2 * i] = x[i], t[2 * i + 1] = y[i];
  }
  sort(t.begin(), t.end());
  auto end = unique(t.begin(), t.end());
  t.erase(end, t.end());
  int mx = 0, my = 0;
  for (int i = 0; i < n; i++) {
    x[i] = lower_bound(t.begin(), t.end(), x[i]) - t.begin();
    y[i] = lower_bound(t.begin(), t.end(), y[i]) - t.begin();
    mx = max(mx, x[i]), my = max(my, y[i]);
  }
  vector<vector<int>> grid(mx + 1, vector<int>(my + 1));
  for (int i = 0; i < n; i++) {
    grid[x[i]][y[i]] += 1;
  }
  for (int i = 0; i <= mx; i++) {
    for (int j = 0; j <= my; j++) {

      cerr << grid[i][j];
    }
    cerr << '\n';
  }
  int ans = 0;
  for (int i = 0; i <= mx; i++) {
    for (int j = i; j <= mx; j++) {
      set<int> st;
      bool ok1 = false, ok2 = false;
      int b = 0, c = INT32_MAX;
      for (int y = 0; y <= my; y++) {
        ok1 |= grid[i][y];
        if (grid[i][y]) {
          b = max(b, y);
          c = min(c, y);
        }
      }
      for (int y = 0; y <= my; y++) {
        ok2 |= grid[j][y];
        if (grid[j][y]) {
          b = max(b, y);
          c = min(c, y);
        }
      }
      if (!ok1 || !ok2) {
        continue;
      }

      for (int x = i; x <= j; x++) {
        for (int y = 0; y <= my; y++) {
          if (grid[x][y] && y <= b && y >= c)
            st.insert(y);
        }
      }
      ans += st.size() * (st.size() - 1) / 2;
    }
  }
  cout << ans;
  return 0;
}
