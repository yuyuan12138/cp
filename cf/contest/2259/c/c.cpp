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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    {
      bool ok = false;
      for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
          ok = true;
        }
        if (!ok && a[i] == -1) {
          a[i] = 1;
          ok = true;
        }
      }
    }
    {
      bool ok = false;
      for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
          ok = true;
        }
        if (!ok && a[i] == -1) {
          a[i] = 1;
          ok = true;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == -1)
        a[i] = 0;
      cout << a[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}
