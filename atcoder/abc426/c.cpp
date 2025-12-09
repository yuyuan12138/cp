#include <bits/stdc++.h>

template <typename T>
struct Fenwick {
  int n;
  std::vector<T> a;
  
  Fenwick(int n_ = 0) {
    init(n_);
  }
  
  void init(int n_) {
    n = n_;
    a.assign(n, T{});
  }
  
  void add(int x, const T &v) {
    for (int i = x + 1; i <= n; i += i & -i) {
      a[i - 1] = a[i - 1] + v;
    }
  }
  
  T sum(int x) {
    T ans{};
    for (int i = x; i > 0; i -= i & -i) {
      ans = ans + a[i - 1];
    }
    return ans;
  }
  
  T rangeSum(int l, int r) {
    return sum(r) - sum(l);
  }
  
  int select(const T &k) {
    int x = 0;
    T cur{};
    for (int i = 1 << std::__lg(n); i; i /= 2) {
      if (x + i <= n && cur + a[x + i - 1] <= k) {
        x += i;
        cur = cur + a[x - 1];
      }
    }
    return x;
  }
};



int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  int q;
  std::vector<int> cnt(n + 1, 1);
  Fenwick<int> fw(n + 1);
  for (int i = 1; i <= n; i++) {
    fw.add(i, 1);
  }
  int cur = 0;
  std::cin >> q;
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    if (x <= cur) {
      std::cout << 0 << '\n';
    } else {
      int val = fw.rangeSum(cur + 1, x + 1);
      cur = x;
      std::cout << val << '\n';
      fw.add(y, val);
    }
  }   
  return 0;
}