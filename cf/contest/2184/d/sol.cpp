#include <bits/stdc++.h>

void solve() {
	int n, k;
	std::cin >> n >> k;

	int sum = 0;

	for (int i = 0, flag = 0; i < k && sum <= n; i++, flag ^= 1) {
		if (!flag) {
			sum += 1;
		} else {
			sum *= 2;
		}
	}
	std::cout << std::max(0, n - sum	
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
