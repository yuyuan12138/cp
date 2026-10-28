#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> pos(n), a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}	
		if (k == 1) {
			cout << -1 << '\n';
			continue;
		}
		int x = max_element(a.begin(), a.begin() + n - k + 1) - a.begin();
		int y = min_element(a.begin() + n - k + 1, a.end()) - a.begin();
		if (a[x] > a[y]) {
			cout << x + 1 << ' ' << y + 1 << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
	return 0;
}
