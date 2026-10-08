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
		auto work = [](int num) -> int {
			int tmp = num;
			int res = 0;
			while (tmp) {
				res += (tmp % 10) * (tmp % 10);
				tmp /= 10;
			}
			num = res;
			return num;
		};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			for (int j = 1; j <= 100; j++) {
				a[i] = work(a[i]);
			}
		}
		sort(a.begin(), a.end());
		int64_t ans = 0;
		for (int i = 0, j = 1; i < n; i = j) {
			j = i + 1;
			while (j < n && a[j] == a[j - 1]) {
				j++;
			}
			ans += int64_t(j - i) * (j - i - 1) / 2;
		}
		cout << ans << '\n';
	}
	return 0;
}
