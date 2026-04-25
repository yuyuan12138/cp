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

constexpr int MOD = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  sieve(1e6);

  [&]() -> void {
      
  }();

  return 0;
}
