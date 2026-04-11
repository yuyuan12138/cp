/** 
 *    author:  Yuyuan
 *    created: 2026-04-04 15:52:21
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
		string s;
		cin >> s;
		vector<int> cnt(n);
		int idx = 0;
		for (int i = 0; i < n; i++) {
			cnt[idx] = 1;
			if (s[idx] == 'L') {
				idx -= 1;
			} else {
				idx += 1;
			}	
		}
		cout << count(cnt.begin(), cnt.end(), 1) << '\n';
	}
	return 0;
}