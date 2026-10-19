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
		int lo = 0, hi = n;
		auto check = [&](int x) -> bool {
			int64_t sum = 0;
			for (int i = 1; i <= n; i++) {
				sum += (x / i) * i;
			}
			if (sum >= n) {
				return true;
			} else {
				return false;
			}
		};
		int ans = 0;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (check(mid)) {
				hi = mid - 1;
				ans = mid;
			} else {
				lo = mid + 1;
			}
		}
		cout << ans << '\n';
		int tot = 0;
		int num = 1;
		for (int len = n; len >= 1 && tot < n; len--) {
			int cnt = ans / len;
			for (int j = 1; j <= cnt && tot < n; j++) {
				for (int i = 0; i < len && tot < n; i++) {
					cout << num << ' ';
					tot++;
				}
				num++;
			}
		}
		cout << '\n';
	}
	return 0;
}
