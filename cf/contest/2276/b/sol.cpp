#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		int n = s.size();
		int ok1 = 0, ok2 = 0;
		for (int i = 1; i < n - 1; i++) {
			if (s[i] == s[i - 1] && s[i - 1] == s[i + 1]) {
				ok1 = 1;
			}
			if (s[i] != s[i - 1] && s[i - 1] == s[i + 1]) {
				ok2 = 1;
			}
		}
		cout << 1 + ok1 + ok2 << '\n';
	}
	return 0;
}
