#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("lazy.in", "r", stdin);
  freopen("lazy.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  int on = n;
  n = 2 * n - 1; 
  vector<vector<int>> s(n, vector<int> (n, -1));
  for (int i = 0; i < on; i++) {
    for (int j = 0; j < on; j++) {
       cin >> s[i + j][on - i + j - 1];
    }
  }
  vector<vector<int>> pref(n + 1, vector<int> (n + 1));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
       int val = max(s[i][j], 0);
       pref[i + 1][j + 1] = (val + pref[i + 1][j] + pref[i][j + 1] - pref[i][j]);
    }
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] != -1) {
         int sr = max(i - k, 0), er = min(i + k, n - 1);
         int sc = max(j - k, 0), ec = min(j + k, n - 1);
         mx = max(mx, pref[er + 1][ec + 1] - pref[er + 1][sc] - pref[sr][ec + 1] + pref[sr][sc]);
      }
    }
  }
  cout << mx;
  return 0;
}
