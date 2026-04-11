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

template <typename T>
void discretization(std::vector<T>& a) {
  const int n = a.size();
  std::vector<T> tmp(a);  
  std::sort(tmp.begin(), tmp.end());
  tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
  for (int i = 0; i < n; i++) {
  a[i] = std::lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> adj(n);
  for (int u = 1; u < n; u++) {
    int v;
    std::cin >> v;
    v--;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  std::cerr << " " << '\n';
  discretization(a);

  Fenwick<int> fw(n);
  std::vector<int> ans(n);
  [&](this auto&& self, int u, int pa) -> void {
    int val = fw.rangeSum(a[u] + 1, n);
    fw.add(a[u], 1);
    for (int v : adj[u]) {
      if (v != pa) {
        self(v, u);
      }
    }
    ans[u] = fw.rangeSum(a[u] + 1, n) - val;
  }(0, -1);

  for (int i = 0; i < n; i++) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}