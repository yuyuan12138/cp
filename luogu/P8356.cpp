/** 
 *    author:  Yuyuan
 *    created: 2026-04-09 13:43:14
**/
#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, p, x, y;
		cin >> n >> p >> x >> y;
		if (x == y) {
			bool ok = true;
			int cur = 0;
			for (int i = 1; i <= n; i++) {
				cur = (cur + x) % MOD;
				if (cur % p == 0) {
					ok = false;
				}
			}
			cout << (ok ? 1 : 0) << '\n';
		} else {
			vector<int> f(n + 1);
			f[0] = 1;
			for (int i = 1; i <= n; i++) {
				vector<int> nf(n + 1);
				for (int t = 0; t <= i; t++) {
					int nt = i - t;
					if ((1ll * t * x + 1ll * nt * y) % p != 0) {
						nf[t] += f[t];
						nf[t] %= MOD;
						if (t > 0) {
							nf[t] += f[t - 1];
						}
						nf[t] %= MOD;
					}
				}
				f = nf;
			}
			int ans = 0;
			for (int i = 0; i <= n; i++) {
				ans = (ans + f[i]) % MOD;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}