#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tt;
  cin >> tt;
  while (tt--) {
    int64_t x, y, k;
    cin >> x >> y >> k;
    while (k > 0 && x != 1) {
      int64_t ost = (x / y + 1) * y - x;
      ost = max(1ll, ost);
      ost = min(ost, k);
      x += ost;
      while (x % y == 0) {
        x /= y;
      }
      k -= ost;
    }
    cout << x + k % (y - 1) << '\n';
  }

  return 0;
}
