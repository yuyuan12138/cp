#include <bits/stdc++.h>

int power(int a, int64_t b, int p) {
  int res = 1;
  for (; b; b /= 2, a = int64_t(1) * a * a % p) {
    if (b % 2) {
      res = int64_t(1) * res * a % p;
    }
  }
  return res;
}

int64_t mul(int64_t a, int64_t b, int64_t p) {
  int64_t c = a * b - int64_t(1.0L * a * b / p) * p;
  c %= p;
  if (c < 0) {
    c += p;
  }
  return c;
}

int64_t power(int64_t a, int64_t b, int64_t p) {
  int64_t res = 1;
  for (; b; b /= 2, a = mul(a, a, p)) {
    if (b % 2) {
      res = mul(res, a, p);
    }
  }
  return res;
}
constexpr int mod = 1e9 + 7;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;

  std::vector<int> n(t);

  for (int i = 0; i < t; i++) {
    std::cin >> n[i];
  }
  for (int i = 0; i < t; i++) {
    int k;
    std::cin >> k;
    std::cout << power(2, k, mod) << '\n';
  }
  return 0;
}
