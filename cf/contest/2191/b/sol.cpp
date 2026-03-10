#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt;
	cin >> tt;
	while (tt--) {
		int cnt0 = 0, cnt1 = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt0 += (x == 0);
			cnt1 += (x == 1);
		}
		if (cnt0 == 0) {
			cout << "NO\n";
		} else if (cnt0 == 1) {
			cout << "YES\n";
		} else if (cnt1 >= 1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}