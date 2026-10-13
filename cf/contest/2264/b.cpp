#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1e9;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	i64 init = 0;
	std::multiset<int> st;
	int max = -inf;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		if (i < m - 1) {
			init += a[i];
			st.insert(a[i]);
		}
		max = std::max(max, a[i]);
	}

	i64 ans = i64(m) * a[m - 1] - init;
	if (m > 1) {
		for (int i = m - 1; i < n; i++) {
			ans = std::max(ans, i64(m) * a[i] - init);
			if (a[i] <= *(std::prev(st.end()))) {
				init -= *(std::prev(st.end())); 
				init += a[i];
				st.erase(std::prev(st.end()));
				st.insert(a[i]);
			}
		}
		std::cout << ans << '\n';
	} else {
		std::cout << max << '\n';
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