#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<int> c(n + 1);
    for (int i = n - 1; i >= 0; i--) {
      c[i] = max({a[i], b[i]});
      if (i < n - 1) {
        c[i] = max(c[i + 1], c[i]);
      }
    }
    for (int i = 0; i < n; i++) {
      c[i + 1] += c[i];
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      if (l == 0) {
        cout << c[r] << ' ';
      } else {
        cout << c[r] - c[l - 1] << ' ';
      }
    }
    cout << '\n';
  }
	
	return 0;
}