/**
 *      author:  yuyuan567
 *      created: 2025-09-09 08:14:28
 */
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> freqs(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto work = [&]() -> void {
      sort(a.begin(), a.end());
      freqs.assign(n + 1, 0);

      for (int i = 0; i < n; i++) {
        freqs[a[i]]++;
      }

      vector<int> b(n);
      int cur = n + 1;
      for (int i = 0; i <= n; i++) {
        if (freqs[i] == 0) {
          cur = i;
          break;
        }
      }
      for (int i = 0; i < n; i++) {
        if (freqs[a[i]] == 1 && a[i] < cur) {
          b[i] = a[i];
        } else {
          b[i] = cur;
        }
      }
      debug(cur);
      a = b;
    };
    debug(freqs);
    if (k == 1) {
      work();
      cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
    } else {
      work();
      work();
      k -= 2;
      if (k == 0) {
        cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
      } else if (k == 1) {
        work();
        cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
      } else {
        int64_t x, y;
        work();
        x = accumulate(a.begin(), a.end(), 0LL);
        work();
        y = accumulate(a.begin(), a.end(), 0LL);
        k -= 2;
        if (k % 2 == 0) {
          cout << y << '\n';
        } else {
          cout << x << '\n';
        }
      }
    }
  }
  return 0;
}
