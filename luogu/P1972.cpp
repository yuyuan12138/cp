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
  std::vector<int> a(n);
  Fenwick<int> fw(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  } 
  int m;
  std::cin >> m;
  std::vector<std::array<int, 3>> queries(m);
  for (int i = 0; i < m; i++) {
    queries[i][0] = i;
    std::cin >> queries[i][1] >> queries[i][2];
    queries[i][1]--, queries[i][2]--;
  }
  std::sort(queries.begin(), queries.end(), [](const auto& a, const auto& b) -> bool {
    if (a[2] == b[2]) {
      if (a[1] == b[1]) {
        return a[0] < b[0];
      } else {
        return a[1] < b[1];
      }
    } else {
      return a[2] < b[2];
    }
  });
  int cur_r = 0;
  std::vector<int> vis(1e6 + 1, -1);
  std::vector<int> ans(m);
  for (int i = 0; i < m; i++) {
    while (cur_r <= queries[i][2]) {
      if (vis[a[cur_r]] != -1) {
        fw.add(vis[a[cur_r]], -1);
      }
      vis[a[cur_r]] = cur_r;
      fw.add(cur_r, 1);
      cur_r++;
    }
    ans[queries[i][0]] = fw.rangeSum(queries[i][1], cur_r);
  } 
  for (int i = 0; i < m; i++) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}