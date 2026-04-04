/** 
 *    author:  Yuyuan
 *    created: 2026-04-04 16:00:01
**/
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
		}
		int mx = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] >= mx) {
				mx = a[i];
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}