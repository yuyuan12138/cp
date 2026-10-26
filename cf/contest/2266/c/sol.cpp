#include <bits/stdc++.h>

using namespace std;

constexpr int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		string s;
		cin >> n >> s;
		if (s[0] == '1') {
			cout << count(s.begin(), s.end(), '0') << '\n';
		} else {
			int zero = count(s.begin(), s.end(), '0');
			int one = 0;
			int ans = inf;
			for (int i = 0; i < n; i++) {
				zero -= (s[i] == '0');
				one += (s[i] == '1');
				ans = min(ans, one + zero);
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
