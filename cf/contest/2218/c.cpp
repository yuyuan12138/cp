/** 
 *    author:  Yuyuan
 *    created: 2026-04-05 18:50:17
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
		vector<int> a(3 * n);
		int idx = 1;
		for (int i = 0; i < n; i++) {
			a[i * 3] = idx;
			idx++;
		}
		for (int i = 0; i < n; i++) {
			a[i * 3 + 1] = idx++;
			a[i * 3 + 2] = idx++;
		}
		for (int i = 0; i < 3 * n; i++) {
			cout << a[i] << " \n"[i == 3 * n - 1];
		}
	}
	return 0;
}