/** 
 *    author:  Yuyuan
 *    created: 2026-04-05 18:46:59
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int n = 7;
		vector<int> a(n);
		int tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] = -a[i];
			tot += a[i];
		}
		int ans = -1999999;
		for (int i = 0; i < n; i++) {
			ans = max(ans, tot + 2 * (-a[i]));
		}
		cout << ans << '\n';
	}
	return 0;
}