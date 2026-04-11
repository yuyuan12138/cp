/** 
 *    author:  Yuyuan
 *    created: 2026-04-08 12:27:14
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
		int tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			tot += a[i];
		}
		if (tot % 2 == 1 || n * k % 2 == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}	
	}
	return 0;
}