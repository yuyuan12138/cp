/** 
 *    author:  Yuyuan
 *    created: 2026-04-05 18:57:20
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
	cin >> tt;
	sieve(1e7);
	while (tt--) {
		int n;
		cin >> n;
		cout << primes[0] << ' ';
		for (int i = 1; i < n; i++) {
			cout << int64_t(primes[i]) * primes[i - 1] << ' ';
		}
		cout << '\n';
	}
	return 0;
}