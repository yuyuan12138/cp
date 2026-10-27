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
		vector<int> a(n);
		bool found = false;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			found |= (a[i] == 0);
		}
		if (found) {
			cout << n << '\n';
		} else {
			sort(a.begin(), a.end());
			bool ok = false;
			for (int i = 0; i < n; i++) {
				if (n - i - 1 >= a[i]) {
					ok = true;
				}
			}
			cout << (ok ? n : 0) << '\n';
		}
	}
	return 0;
}
