#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) {
			s[i] = '*', s[i - 1] = '*';
		}
	}
	for (int i = 0; i < n; i++) {
		if (i < n - 1 && s[i] == '*' && s[i + 1] == '*') {
			int l = i - 1, r = i + 2;
			while (l >= 0 && s[l] == '*') {
				l--;
			}
			while (r < n && s[r] == '*') {
				r++;
			}
			while (l >= 0 && r < n && s[l] == s[r]) {
				s[l] = '*', s[r] = '*';
				l--, r++;
			}
		}
	}
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if (s[i] != '*') {
			ok = false;
		}
	}
	std::cout << (ok ? "YES\n" : "NO\n");
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
