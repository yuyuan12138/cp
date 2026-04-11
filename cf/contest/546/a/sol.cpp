/**
 *      author:  yuyuan567
 *      created: 2025-09-02 09:34:35
 */
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#elseCodeforces Round 304(Div.2)
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k, n, w;
  cin >> k >> n >> w;
  int64_t tot = (w + 1) * w * k / 2;
  cout << max(tot - n, 0LL);
  return 0;
}
