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
		vector<string> s(2);
		for (int i = 0; i < 2; i++) {
			cin >> s[i];
		}
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (s[0][i] != s[1][i]) {
				flag = !flag;
			}
		}
		cout << flag << '\n';
	}
	return 0;
}
