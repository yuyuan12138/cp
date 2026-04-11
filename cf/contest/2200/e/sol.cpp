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
	sieve(1e6);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		bool ok = false;
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1]) {
				ok = true;
			}
		}
		if (!ok) {
			cout << "Bob\n";
		} else {
			bool ok1 = true;
			for (int i = 0; i < n; i++) {
				if (a[i] == 1) continue;
				int x = a[i];
				int p = minp[x];
				while (x % p == 0) {
					x /= p;
				}
				if (x != 1) {
					ok1 = false;
				} else {
					a[i] = p;
				}
			}
			if (ok1) {
				for (int i = 1; i < n; i++) {
					if (a[i] < a[i - 1]) {
						ok1 = false;
					}
				}
			}
			cout << (ok1 ? "Bob\n" : "Alice\n");
		}
	}
  return 0;
}

