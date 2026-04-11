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
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i][0];
      a[i][1] = i % 2;
    }
    sort(a.begin(), a.end());
    bool ok = true;
    for (int i = 1; i < n; i++) {
      if (a[i][1] == a[i - 1][1]) {
        ok = false;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}