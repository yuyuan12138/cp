/**
 *    author:  yuyuan
 *    created: 2025-12-22 11:08:01
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

  int n;
  cin >> n;
  if (n == 1) {
    cout << 1;
  } else if (n == 4) {
    cout << "3 1 4 2";
  } else if (n <= 4) {
    cout << "NO SOLUTION";
  } else {
    for (int i = 1; i <= n; i += 2) {
      cout << i << ' ';
    }
    for (int i = 2; i <= n; i += 2) {
      cout << i << ' ';
    }
  }

  return 0;
}


