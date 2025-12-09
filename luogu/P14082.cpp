#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, k;
	std::cin >> n >> k;
	std::string s;
	std::cin >> s;
	
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) {
			cnt++;
		}
	}

	int internal = n - cnt;
	int b = cnt - 1;

	int l = std::max(0, k - b);
	int u = std::min(k, internal);
	
	if (l > u) {
			std::cout << 0;
	} else {
			std::cout << (u - l + 1);
	}
	return 0;
}
