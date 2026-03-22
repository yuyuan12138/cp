#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	int cnt1 = std::count(s.begin(), s.end(), '1');
	int cnt2 = n - cnt1;
	if (cnt1 == 0) {
		std::cout << 0 << '\n';
	} else if (cnt1 % 2 == 0) {
		std::cout << cnt1 << '\n';
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				std::cout << i + 1 << ' ';
			}
		}
		std::cout << '\n';
	} else if (cnt2 % 2 == 1) {
		std::cout << cnt2 << '\n';
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				std::cout << i + 1 << ' ';
			}
		}
		std::cout << '\n';
	} else {
		std::cout << -1 << '\n';
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

