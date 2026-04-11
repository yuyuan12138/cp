#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int m, k;
    std::cin >> m >> k;
    std::vector<int> a(m);
	std::vector<i64> ans(m, -1);    
	for (int i = 0; i < m; i++) {
		std::cin >> a[i];
	}
	int cur = m - 2;
	i64 tot = 1ll * m * (m + 1) / 2;
	ans[m - 1] = tot;
	for (int i = m - 2; i >= 0; i--) {
		if (a[i] >= a[i + 1]) {
			tot -= i + 1;
			ans[cur] = tot;
			cur--;
		}
	}
	for (int i = 0; i < m; i++) {
		std::cout << ans[i] << " \n"[i == m - 1];
	}
    return 0;
}