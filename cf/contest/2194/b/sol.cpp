#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	int tt;
	cin >> tt;
	while (tt--) {
		int n, x, y;
		cin >> n >> x >> y;
		vector<int> a(n), b(n);
		int64_t tot = 0;
		int64_t cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i] / x * x;
			tot += b[i];
			cnt += a[i] / x;	
		}
	
		int64_t ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, tot - b[i] + a[i] - int64_t(cnt - a[i] / x) * (x - y));	
		}
		cout << ans << '\n';
	}

  return 0;
}

