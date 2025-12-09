#include <bits/stdc++.h>

using i64 = long long;

int power(int a, i64 b, int p) {
    int res = 1;
    for (; b; b /= 2, a = i64(1) * a * a % p) {
        if (b % 2) {
            res = i64(1) * res * a % p;
        }
    }
    return res;
}

i64 mul(i64 a, i64 b, i64 p) {
    i64 c = a * b - i64(1.0L * a * b / p) * p;
    c %= p;
    if (c < 0) {
        c += p;
    }
    return c;
}

i64 power(i64 a, i64 b, i64 p) {
    i64 res = 1;
    for (; b; b /= 2, a = mul(a, a, p)) {
        if (b % 2) {
            res = mul(res, a, p);
        }
    }
    return res;
}

constexpr int N = 1E7;

bool isprime[N + 1];
int phi[N + 1];
std::vector<int> primes;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::fill(isprime + 2, isprime + N + 1, true);
	phi[1] = 1;
	for (int i = 2; i <= N; i++) {
	    if (isprime[i]) {
	        primes.push_back(i);
	        phi[i] = i - 1;
	    }
	    for (auto p : primes) {
	        if (i * p > N) {
	            break;
	        }
	        isprime[i * p] = false;
	        if (i % p == 0) {
	            phi[i * p] = phi[i] * p;
	            break;
	        }
	        phi[i * p] = phi[i] * (p - 1);
	    }
	}
  
  int tt;
  std::cin >> tt;
  while (tt--) {
  	int p;
  	std::cin >> p;
  	auto dfs = [&](this auto&& self, int p) -> int {
  		if (p == 1) {
  			return 0;
  		}
  		return power(2, self(phi[p]) + phi[p], p);
  	};
  	int ans = dfs(p);
  	std::cout << ans << '\n';
  }
 	
  return 0;
}