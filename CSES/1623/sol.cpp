#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> p(n);
	int64_t tot = 0;	
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		tot += p[i];
	}
	int64_t ans = INT64_MAX;
	for (int i = 0; i < (1LL << n); i++) {
		int64_t t = 0;
		for (int bit = 0; bit < n; bit++) {
			if ((1 << bit) & i) {
				t += p[bit];
			}
		}
		ans = min(ans, abs(t * 2 - tot));
	}
	cout << ans;
  return 0;
}

