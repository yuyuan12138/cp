/** 
 *    author:  Yuyuan
 *    created: 2026-04-08 12:46:20
**/
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
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		auto get = [&](int i, int v) -> int {
			int cnt1 = 0, cnt2 = 0;
			for (int j = 0; j < i; j++) {
				if (a[j] == v ^ 1 && a[j + 1] == v) {
					cnt1++;
				}
			}
			for (int j = i; j < n - 1; j++) {
				if (a[j] == v && a[j + 1] == v ^ 1) {
					cnt2++;
				}
			}
			return max(cnt1, cnt2) * 2;
		};
		int ans = 0;
		for (int i = 0; i < k; i++) {
			int p;
			cin >> p;
			ans += get(p - 1, a[p - 1]);
		}
		cout << ans << '\n';
	}
	return 0;
}