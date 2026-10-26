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
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] -= i;
		}
		sort(a.begin(), a.end());
		auto new_end = unique(a.begin(), a.end());
		a.erase(new_end, a.end());
		n = a.size();
		int ans = 1;
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] == a[i - 1] + 1) {
				cnt++;
			} else {
				cnt = 1;
			}
			ans = max(ans, cnt);
		}
		cout << ans << '\n';
	}
	return 0;
}
