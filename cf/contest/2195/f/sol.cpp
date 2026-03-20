#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i] >> b[i] >> c[i];
	}
	std::vector<int> dp(n, 1);
	for (int i = 1; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (a[i] == a[j] && b[i] == b[j]) {
				max = std::max(a[i]
		}
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

