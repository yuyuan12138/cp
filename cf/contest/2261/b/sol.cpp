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
		int mx = 0;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
		}
		if (all_of(a.begin(), a.end(), [&](int x) { return x == mx; })) {
			cout << mx << '\n';
		} else {
			int ans = 1;
			while (mx) {
				ans <<= 1;
				mx >>= 1;
			}
			cout << ans - 1 << '\n';
		}
	}
	return 0;
}
