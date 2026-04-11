#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	s = s + s;
	int ans = 0;
	for (int st = 0; st < n; st++) {
		int cnt = 1;
		for (int i = st + 1; i < st + n; i++) {
			cnt += (s[i] != s[i - 1]);
		}
		ans = std::max(ans, cnt);
	}
	std::cout << ans << '\n';
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

