#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	int max = 0;
	for (int i = 0, x; i < n; i++) {
		std::cin >> x;
		max = std::max(x, max);
	}
	std::cout << max * n << '\n';
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
