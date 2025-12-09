/**
 *      author:  yuyuan567
 *      created: 2025-09-08 15:40:54
 */
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

/**   素数测试与因式分解（Miller-Rabin & Pollard-Rho）
 *    2023-05-16: https://cf.dianhsu.com/gym/104354/submission/206130894
 **/
int64_t mul(int64_t a, int64_t b, int64_t m) {
  return static_cast<__int128>(a) * b % m;
}
int64_t power(int64_t a, int64_t b, int64_t m) {
  int64_t res = 1 % m;
  for (; b; b >>= 1, a = mul(a, a, m))
    if (b & 1) res = mul(res, a, m);
  return res;
}
bool isprime(int64_t n) {
  if (n < 2) return false;
  static constexpr int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
  int s = __builtin_ctzll(n - 1);
  int64_t d = (n - 1) >> s;
  for (auto a : A) {
    if (a == n) return true;
    int64_t x = power(a, d, n);
    if (x == 1 || x == n - 1) continue;
    bool ok = false;
    for (int i = 0; i < s - 1; ++i) {
      x = mul(x, x, n);
      if (x == n - 1) {
        ok = true;
        break;
      }
    }
    if (!ok) return false;
  }
  return true;
}
std::vector<int64_t> factorize(int64_t n) {
  std::vector<int64_t> p;
  std::function<void(int64_t)> f = [&](int64_t n) {
    if (n <= 10000) {
      for (int i = 2; i * i <= n; ++i)
        for (; n % i == 0; n /= i) p.push_back(i);
      if (n > 1) p.push_back(n);
      return;
    }
    if (isprime(n)) {
      p.push_back(n);
      return;
    }
    auto g = [&](int64_t x) { return (mul(x, x, n) + 1) % n; };
    int64_t x0 = 2;
    while (true) {
      int64_t x = x0;
      int64_t y = x0;
      int64_t d = 1;
      int64_t power = 1, lam = 0;
      int64_t v = 1;
      while (d == 1) {
        y = g(y);
        ++lam;
        v = mul(v, std::abs(x - y), n);
        if (lam % 127 == 0) {
          d = std::gcd(v, n);
          v = 1;
        }
        if (power == lam) {
          x = y;
          power *= 2;
          lam = 0;
          d = std::gcd(v, n);
          v = 1;
        }
      }
      if (d != n) {
        f(d);
        f(n / d);
        return;
      }
      ++x0;
    }
  };
  f(n);
  std::sort(p.begin(), p.end());
  return p;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int64_t k, x;
    cin >> k >> x;
    constexpr int64_t inf = LLONG_MAX;
    cout << x * power(2LL, k, inf) << '\n';
  }
  return 0;
}
