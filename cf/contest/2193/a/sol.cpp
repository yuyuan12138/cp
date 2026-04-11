#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;

  while (tt--) {
    int n, s, x;
    cin >> n >> s >> x;
    for (int i = 0, y; i < n; i++) {
      cin >> y;
      s -= y;
    }
    if (s >= 0 && s % x == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
