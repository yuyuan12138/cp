/**
 *    author:  yuyuan
 *    created: 2025-12-22 10:47:41
 **/
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

  int64_t n;
  cin >> n;
  cout << n;
  while (n != 1) {
    cout << ' ';
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n * 3 + 1;
    }
    cout << n;
  }

  return 0;
}


