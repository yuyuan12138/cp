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
		int mx = INT_MIN, mn = INT_MAX;
		for (int i = 0, x; i < n; i++) {
			cin >> x;
			mx = max(mx, x);
			mn = min(mn, x);
		}
		if (mx == mn) {
			cout << mx << '\n';
		} else {
			cout << (((1 << (32 - __builtin_clz(mx ^ mn))) - 1) | mx) << '\n';
		}
	}
	return 0;
}
