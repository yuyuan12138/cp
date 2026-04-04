/**
 *    author:  Yuyuan
 *    created: 2026-04-01 17:56:20
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> minp, primes;

void sieve(int n) {
  minp.assign(n + 1, 0);
  primes.clear();
  
  for (int i = 2; i <= n; i++) {
    if (minp[i] == 0) {
      minp[i] = i;
      primes.push_back(i);
    }
      
    for (auto p : primes) {
      if (i * p > n) {
        break;
      }
      minp[i * p] = p;
      if (p == minp[i]) {
        break;
      }
    }
  }
}

bool isprime(int n) {
  return minp[n] == n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	int tt;
	sieve(1e6);
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		vector<int> c(n);
		for (int i = 0; i < n; i++) {
			int l = 1, r = 1;
			if (i == 0) {
				r = gcd(a[i], a[i + 1]);
				c[i] = r;
				int mp = -1;
				for (int p : primes) {
					if (gcd(p, r) == 1 && gcd(p, a[i + 1]) == 1) {
						mp = p;
						break;
					}
				}
				while (c[i] == a[i] && c[i] * mp <= b[i]) {
					c[i] = c[i] * mp;
				}
			} else if (i == n - 1) {
				l = gcd(a[i], a[i - 1]);
				c[i] = l;
				int mp = -1;
				for (int p : primes) {
					if (gcd(p, l) == 1 && gcd(p, a[i - 1]) == 1) {
						mp = p;
						break;
					}
				}
				while (c[i] == a[i] && c[i] * mp <= b[i]) {
					c[i] = c[i] * mp;
				}
			} else {
				l = gcd(a[i], a[i - 1]);
				r = gcd(a[i], a[i + 1]);
				c[i] = lcm(l, r);
				int mp = -1;
				for (int p : primes) {
					if (gcd(p, l) == 1 && gcd(p, r) == 1) {
						mp = p;
						break;
					}
				}
				while (c[i] == a[i] && c[i] * mp <= b[i]) {
					c[i] = c[i] * mp;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += (c[i] != a[i] && c[i] <= b[i]);
		}
		cout << ans << '\n';
	}
  return 0;
}
