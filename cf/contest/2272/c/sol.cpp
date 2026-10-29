#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int l = 1, r = 1e9 + 1;
		int ans = 0;
		auto check = [&](int x) -> bool {
			int cnt = 0;
			auto b = a;
			for (int i = 0; i < n; i++) {
				bool ok = false;
				if (i > 0 && b[i] - b[i - 1] <= x) {
					ok = true;
				}
				if (i < n - 1 && b[i + 1] - b[i] <= x) {
					ok = true;
				}
				if (!ok) {
					b[i] += x;
					cnt++;
				}
			}
			return cnt <= k;
		};
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {
				r = mid - 1;
				ans = mid;
			} else {
				l = mid + 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
