#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, W;
	std::cin >> n >> W;
	std::vector<int> w(n);
	std::vector<int> cnt(32);
	for (int i = 0; i < n; i++) {
		std::cin >> w[i];
		int cur = 0;
		while (((1 << cur) & w[i]) == 0) {
			cur++;
		}
		cnt[cur]++;
	}
	int h = 0;
	i64 c = 0;
	for (int i = 0; i < 32; i++) {
		while (cnt[i] > 0) {
			if (c + (1ll << i) > W) {
				h++;
				c = 0;
			}
			int max = ((W - c) / (1ll << i));
			int del = std::min(max, cnt[i]);
			c += del * (1ll << i);
			cnt[i] -= del;
		}
	}


	std::cout << h + (c > 0);
	return 0;
}