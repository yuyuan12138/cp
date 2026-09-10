#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i += k) {
      bool ok = false;
      for (int j = i; j < k + i; j++) {
        ok |= (s[j] == '0');
      }
      ans += (!ok);
    }
    cout << ans << '\n';
  }
  return 0;
}
