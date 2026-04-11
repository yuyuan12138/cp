#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end(), std::greater<int>());
  std::vector<int> diff(n + 1);
  for (int i = 0; i < q; i++) {
    int l, r;
    std::cin >> l >> r;
    l--, r--;
    diff[l] += 1;
    diff[r + 1] -= 1;
  }
  diff.pop_back();
  for (int i = 1; i < n; i++) {
    diff[i] += diff[i - 1];
  }
  std::sort(diff.begin(), diff.end(), std::greater<int>());
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    ans += int64_t(a[i]) * diff[i];
  }
  std::cout << ans;
  return 0;
}
