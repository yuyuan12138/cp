/** 
 *    author:  Yuyuan
 *    created: 2026-04-08 16:28:43
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> f(n + 2, vector<int>(n + 2));
	f[2][0] = 1;
	f[2][1] = 1;
	for (int x = 2; x <= n; x++) {
		for (int y = 0; y <= x - 1; y++) {
			f[x + 1][y] += f[x][y] * (y + 1) % 2015;
			f[x + 1][y + 1] += f[x][y] * (x - y) % 2015;
		}
	}
	cout << f[n][k] % 2015 << '\n';
	return 0;
}