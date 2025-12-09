#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), c(m);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> c[i];
    }
  }
  return 0;
}
