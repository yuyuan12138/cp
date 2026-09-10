#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int cnt = 0;
    int cnt2 = 0;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      if (abs(2 - x) % 2 != 0) {
        cnt++;
      }
      if (abs(2 - x) % 4 == 0) {
        cnt2++;
      }
    }
    cout << max({cnt, cnt2, n - cnt - cnt2}) << '\n';
  }
  return 0;
}
