#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> freqs(n), a(n);
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      x--;
      freqs[x]++;
      a[i] = x;
    }
    if (n % k != 0) {
      std::cout << "0\n";
    } else {
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (freqs[i] % k != 0) {
          ok = false;
        }
      }
      if (!ok) {
        std::cout << "0\n";
      } else {
        std::vector<int> cnt(n), cur_cnt(n);
        for (int i = 0; i < n; i++) {
          cnt[i] = freqs[i] / k;
        }
        int64_t ans = 0;
        int slow = 0;
        for (int fast = 0; fast >= slow && fast < n; fast++) {
          cur_cnt[a[fast]]++;
          while (cur_cnt[a[fast]] > cnt[a[fast]]) {
            cur_cnt[a[slow]]--;
            slow++;
          }
          ans += int64_t(fast - slow + 1);
        }
        std::cout << ans << '\n';
      }
    }
  }
  return 0;
}
