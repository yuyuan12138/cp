#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0) {
        even.push_back(a[i]);
      } else {
        odd.push_back(a[i]);
      }
    }
    bool ok = false;
    int cur = -1;
    if (even.size() >= 2) {
      cout << even[0] << " " << even[1] << '\n';
      continue;
    } else if (even.size() == 1) {
      for (int i = 0; i < n - 1; i++) {
        if (odd[i] < even[0] && (even[0] % odd[i]) % 2 == 0) {
          ok = true;
          cur = odd[i];
          break;
        }
        if (odd[i] > even[0] && (odd[i] % even[0]) % 2 == 0) {
          ok = true;
          cur = odd[i];
          break;
        }
      }
    }
    if (ok) {
      if (cur > even[0]) {
        swap(cur, even[0]);
      }
      cout << cur << ' ' << even[0] << '\n';
    } else {
      int x, y;
      for (int i = 0; i < odd.size(); i++) {
        for (int j = i + 1; j < odd.size(); j++) {
          if ((odd[j] % odd[i]) % 2 == 0) {
            ok = true;
            x = odd[i], y = odd[j];
            break;
          }
        }
      }
      if (ok) {
        cout << x << ' ' << y << '\n';
      } else {
        cout << -1 << '\n';
      }
    }
  }
  return 0;
}
