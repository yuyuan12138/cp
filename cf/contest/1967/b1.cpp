#include <bits/stdc++.h>

using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    const int n = s.size();
    if (s == t) {
      cout << s << '\n' << t << '\n';
    } else {
      int cur = -1;
      for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
          if (s[i] > t[i]) {
            swap(s[i], t[i]);
          }
          cur = i + 1;
          break;
        }
      }
      for (; cur < n; cur++) {
        if (s[cur] < t[cur]) {
          swap(s[cur], t[cur]);
        }
      }
      cout << s << '\n' << t << '\n';
    }
  }

  return 0;
}