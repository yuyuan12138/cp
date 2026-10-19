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
		vector<int64_t> pref(n + 1);
		for (int i = 0, x; i < n; i++) {
			cin >> x;
			pref[i + 1] = pref[i] + x;
		}
		vector<vector<int>> g(k);		
		for (int i = 0; i <= n; i++) {
			g[pref[i] % k].push_back(i);
		}
		int64_t ans = 0;
		for (int i = 1; i <= n; i++) {
			int lo = i - k;
			if (lo < 0) continue;
			int k_g = pref[i] % k;
			auto ptr = lower_bound(g[k_g].begin(), g[k_g].end(), lo);
			if (ptr != g[k_g].begin()) {
				ans += ptr - g[k_g].begin();
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
