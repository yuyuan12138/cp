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
    for (int i = 0; i < n - k; i++) {
      if (s[i] == '1') {
        s[i] = '0';
        s[i + k] = (s[i + k] == '0') ? '1' : '0';
      }
    }
    if (all_of(s.begin(), s.end(), [](auto c) { return c == '0';})) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}