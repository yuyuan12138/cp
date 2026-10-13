#include <bits/stdc++.h>

using namespace std;

constexpr int64_t inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> a;
		int64_t ans = 0;
		for (int i = 1, x; i <= n; i++) {
			cin >> x;
			if (i >= k && i <= n - k + 1) {
				ans += x;
			} else {
				a.push_back(x);
			}
		}
		int l = 0, r = a.size() - 1;
		int res = max(0, (int)a.size() - k + 1);
		while (res--) {
			ans += max(a[l], a[r]);
			l++;
			r--;
		}
		cout << ans << '\n';
	}
	return 0;
}
