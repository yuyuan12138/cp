/**
 *    author:  Yuyuan
 *    created: 2026-04-01 17:56:20
**/
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
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		vector<int> c(n);
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				c[i] = gcd(a[i], a[i + 1]);
			} else if (i == n - 1) {
				c[i] = gcd(a[i], a[i - 1]);
			} else {
				int l = gcd(a[i], a[i - 1]);
				int r = gcd(a[i], a[i + 1]);
				c[i] = lcm(l, r);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += (c[i] != a[i]);
		}
		cout << ans << '\n';
	}
  return 0;
}
