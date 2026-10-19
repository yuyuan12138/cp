#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cnt = count(s.begin(), s.end(), '1');
		if (cnt == 1) cout << 0 << '\n';
		else if (cnt == 2) cout << 1 << '\n';
		else {
			int mx = 0, mn = n;
			for (int i = 0; i < n; i++) {
				if (s[i] == '1') {
					mx = max(mx, i + 1);
					mn = min(mn, i + 1);
				}
			}
			cout << mx - mn << '\n';
		}
	}
	return 0;
}
