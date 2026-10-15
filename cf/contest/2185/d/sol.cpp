#include <bits/stdc++.h>

void solve() {
	int n, m, h;
	std::cin >> n >> m >> h;
	std::vector<int> a(n);
	std::vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		ans[i] = a[i];
	}
	std::set<int> vis;
	for (int i = 0; i < m; i++) {
		int b, c;
		std::cin >> b >> c;
		b--;
		if (ans[b] + c > h) {
			for (int x : vis) {
				ans[x] = a[x];
			}
			vis.clear();
			ans[b] = a[b];
		} else {
			vis.insert(b);
			ans[b] += c;
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << ans[i] << " \n"[i == n - 1];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
