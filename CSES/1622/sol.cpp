/**
 *    author:  yuyuan
 *    created: 2025-12-17 17:17:41
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

  string s;
  cin >> s;
  sort(s.begin(), s.end());
  vector<string> ans;
  do {
    ans.push_back(s);
  } while (next_permutation(s.begin(), s.end()));

  cout << ans.size() << '\n';
  for (auto x: ans) {
    cout << x << '\n';
  }

  return 0;
}


