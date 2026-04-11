#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, d, m;
    std::cin >> n >> d >> m;
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
      std::cin >> b[i];
    } 
    std::vector<int> ans(n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (b[i] == 0) {
        while (cur % d == 0) {
          cur += 1;
        }
      } else {
        if (cur % d != 0) {
          cur += d - cur % d;
        }
      }
      ans[i] = cur;
    }
    int tot = std::accumulate(ans.begin(), ans.end(), 0);
    if (tot > m) {
      std::cout << "No\n";
    } else {
      int last = m - tot;
      for (int i = n - 1; i >= 0; i--) {
        if (last == 0) {
          break;
        }
        if (i == n - 1) {
          if (b[i] == 0) {
            if ((ans[i] + last) % d != 0) {
              ans[i] += last;
              last = 0;
            } else {
              ans[i] += last - 1;
              last = 1;
            }
          } else {
            if ((ans[i] + last) % d == 0) {
              ans[i] += last;
              last = 0;
            } else {
              int tmp = last - (ans[i] + last) % d;
              ans[i] += tmp;
              last -= tmp;
            }
          }
        } else {
          if (last == 0) {
            break;
          } else {
            if (b[i] == 0) {
              int up = std::min(ans[i] + last, ans[i + 1]);
              if (up % d != 0) {
                int tmp = up - ans[i];
                ans[i] += tmp;
                last -= tmp;
              } else {
                int tmp = up - ans[i] - 1;
                ans[i] += tmp;
                last -= tmp;
              }
            } else {
              int up = std::min(ans[i] + last, ans[i + 1]);
              if (up % d == 0) {
                int tmp = up - ans[i];
                ans[i] += tmp;
                last -= tmp;
              } else {
                int tmp = up - up % d - ans[i];
                ans[i] += tmp;
                last -= tmp;
              }
            }
          }
        }
      }
      if (last == 0) {
        for (int i = 0; i < n; i++) {
          std::cout << ans[i] << " \n"[i == n - 1];
        }
      } else {
        std::cout << "No\n";
      }
    }
  }

  return 0;
}