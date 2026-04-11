/**
 *    author:  Yuyuan
 *    created: 2026-04-01 17:47:38
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
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			p[i]--;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (p[i] <= i) {
				ans++;
			}
		}
		cout << max(ans, 1) << '\n';
	}

  return 0;
}
