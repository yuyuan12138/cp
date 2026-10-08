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
		int ans = 2 * (k - 1);
		int cnt = 2;
		for (int i = 1; i <= n - k; i++) {
			cnt *= 2;
		}
		cout << ans + cnt << '\n';
	}
	return 0;
}
