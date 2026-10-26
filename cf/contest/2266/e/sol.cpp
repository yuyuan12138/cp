#include <bits/stdc++.h>

using namespace std;

int find_largest_prime_factor(int n) {
	int d = 2;
	int res = 1;
	while (n > 1) {
		while (n % d == 0) {
			res = d;
			n /= d;
		}
		d += 1;
		if (d * d > n) {
			if (n > 1) res = n;
			break;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> cnt(n + 1);
		for (int i = 0, x; i < n; i++) {
			cin >> x;
			cnt[x]++;
		}
		int ans = 0;
		for (int x = n; x > k; x--) {
			if (cnt[x] > 0) {
				ans += cnt[x];
				int fac = find_largest_prime_factor(x);
				cnt[x / fac] += fac * cnt[x];
				cnt[x] = 0;
			}	
		}
		cout << ans << '\n';
	}
	return 0;
}
