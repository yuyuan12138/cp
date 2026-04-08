/** 
 *    author:  Yuyuan
 *    created: 2026-04-05 20:36:42
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
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mx = max(mx, a[i] ^ a[j]);
			}
		}
		cout << mx << '\n';
	}
	return 0;
}