/** 
 *    author:  Yuyuan
 *    created: 2026-04-04 16:05:56
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int64_t a, b, c;
		int64_t m;
		cin >> a >> b >> c >> m;
		int64_t ab = lcm(a, b);
		int64_t ac = lcm(a, c);
		int64_t bc = lcm(b, c);
		int64_t abc = lcm(ab, ac);
		int64_t ans_a = m / a * 6 - m / ab * 3 - m / ac * 3 + m / abc * 2;
		int64_t ans_b = m / b * 6 - m / ab * 3 - m / bc * 3 + m / abc * 2;
		int64_t ans_c = m / c * 6 - m / ac * 3 - m / bc * 3 + m / abc * 2;
		cout << ans_a << ' ' << ans_b << ' ' << ans_c << '\n'; 
	}
	return 0;
}