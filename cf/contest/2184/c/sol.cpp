#include <bits/stdc++.h>

void solve() {
	int n, k;
	std::cin >> n >> k;
	// 2 // 4 5 // 8 9 10 11 // 16 17 18 19 20 21 22 23 //
	int l = k, r = k;
	int ans = 0;
	while (l <= n) {
		if (l <= n && r >= n) {
			break;
		}
		ans++;
		l = l * 2 - 1;
		r = r * 2 + 1;
	}
	std::cout << ((l > n) ? -1 : ans) << '\n';
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
