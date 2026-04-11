#include <bits/stdc++.h>

using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool ok = false;
    if (a[0] != a[1]) {
      ok = true;
    }
    for (int i = 2; i < n; i++) {
      if (a[i] % a[0] != 0) {
        ok = true;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}