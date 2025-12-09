#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int64_t> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::array<int64_t, 3>> queries(m);
  for (int i = 0; i < m; i++) {
    int64_t l, r, d;
    std::cin >> l >> r >> d;
    l--, r--;
    queries[i][0] = l;
    queries[i][1] = r;
    queries[i][2] = d;
  }
  std::vector<int64_t> diff_q(m + 1);
  for (int i = 0; i < k; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    diff_q[x] += 1;
    diff_q[y + 1] -= 1;
  }
  for (int i = 1; i < m; i++) {
    diff_q[i] += diff_q[i - 1];
  }
  for (int i = 0; i < m; i++) {
    queries[i][2] *= diff_q[i];
  }
  std::vector<int64_t> diff_o(n + 1);
  for (int i = 0; i < m; i++) {
    int64_t l = queries[i][0];
    int64_t r = queries[i][1];
    int64_t d = queries[i][2];
    diff_o[l] += d;
    diff_o[r + 1] -= d;
  }
  for (int i = 1; i < n; i++) {
    diff_o[i] = diff_o[i - 1] + diff_o[i];
  }
  for (int i = 0; i < n; i++) {
    std::cout << a[i] + diff_o[i] << ' ';
  }
  return 0;
}
