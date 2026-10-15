#include <bits/stdc++.h>

using std::cin;
using std::cout;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		std::vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int64_t s_min = a[0], s_max = a[0];
		int64_t ans = a[0];
		for (int i = 1; i < n; i++) {
			ans = std::max({ans, int64_t(a[i]), s_max + a[i], - s_min + a[i]});
			s_max = int64_t(a[i]) + 2 * std::max(int64_t(0), s_max);
			s_min = int64_t(a[i]) + 2 * std::min(int64_t(0), s_min);
		}
		std::cout << ans << '\n';
	}
  return 0;
}
