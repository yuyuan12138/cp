#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1e9;

void solve() {
	int n, h, k;
	std::cin >> n >> h >> k;
	std::vector<i64> a(n);
	i64 tot = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		tot += a[i];
	}

	i64 ans = h / tot * k + h / tot * n; 
	i64 rem = h % tot;
	if (rem == 0) {
		std::cout << ans - k << '\n';
		return ;
	}

	std::vector<i64> max(n + 1), min(n + 1, inf);
	for (int i = n - 1; i >= 0; i--) {
		max[i] = std::max(a[i], max[i + 1]);
	}
	for (int i = 0; i < n; i++) {
		min[i + 1] = std::min(min[i], a[i]);
	}
	
	std::vector<i64> pref(n + 1);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + a[i];
	}
	int cnt = inf;
	for (int i = 0; i < n; i++) {
		if (pref[i + 1] + std::max(0ll, - min[i + 1] + max[i + 1]) >= rem) {
			cnt = std::min(i + 1, cnt);
		}
	}
	std::cout << cnt + ans << '\n';
	
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

