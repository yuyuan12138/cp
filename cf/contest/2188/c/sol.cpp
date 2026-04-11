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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b.begin(), b.end());
    int mn = 1e9;
    int mx = 0;
    for (int i = 0; i < n; i++) {
      mn = min(mn, a[i]);
      mx = max(mx, a[i]);
    }

    int l = 0, r = 1e9;
    auto check = [&](const int x) -> bool {
      int o = 1e9;
      for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
          o = min(o, max(a[i] - mn, mx - a[i]));
      }
      return o <= x;
    };

    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (check(mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    if (r >= 1e9) {
      cout << -1 << '\n';
    } else {
      cout << r << '\n';
    }
  }

	return 0;
}