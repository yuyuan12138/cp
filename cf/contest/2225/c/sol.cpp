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
    vector<string> s(2);
    cin >> s[0] >> s[1];
    int ans = 0;
    bool last = (s[0][0] != s[1][0]);
    for (int i = 1; i < n; i++) {
      if (s[0][i] != s[1][i]) {
        if (last) {
          if (s[0][i] == s[0][i - 1]) {
            last = false;
          } else {
            ans += 1;
          }
        } else {
          last = true;
        }
      } else {
        ans += last;
        last = false;
      }
    }
    cout << ans + last << '\n';
  }
  return 0;
}

