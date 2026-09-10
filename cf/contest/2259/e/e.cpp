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
    if (n == 1) {
      if (a[0] == 0 || a[0] == -1) {
        cout << 1 << '\n';
      } else {
        cout << -1 << '\n';
      }
      continue;
    }

    set<pair<int, int>> check;
    vector<int> diff(n + 1);
    for (int i = 0; i < n; i++) {
      if (a[i] != -1) {
        int x = -1, y = -1;
        if (i - a[i] >= 0) {
          x = i - a[i];
        }
        if (i + a[i] < n) {
          y = i + a[i];
        }
        check.insert({x, y});
        if (a[i] != 0) {
          if (i - a[i] + 1 >= 0) {
            diff[i - a[i] + 1] += 1;
          } else {
            diff[0] += 1;
          }
          if (a[i] + i < n) {
            diff[a[i] + i] -= 1;
          } else {
            diff[n] -= 1;
          }
        }
      }
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        b[i] = diff[i];
      } else {
        b[i] = b[i - 1] + diff[i];
      }
    }
    bool ok = true;
    for (auto [x, y] : check) {
      if (x == -1) {
        if (y >= 0 && b[y] > 0) {
          ok = false;
        }
      } else if (y == -1) {
        if (x >= 0 && b[x] > 0) {
          ok = false;
        }
      } else {
        if (x >= 0 && b[x] > 0 && y >= 0 && b[y] > 0) {
          ok = false;
        }
      }
    }
    // for (int i = 0; i < n; i++) {
    //   cerr << b[i] << " \n"[i == n - 1];
    // }
    if (!ok ||
        all_of(b.begin(), b.end(), [](int x) -> bool { return x > 0; })) {
      cout << -1 << '\n';
    } else {
      for (int i = 0; i < n; i++) {
        if (a[i] == -1 && b[i] == 0) {
          a[i] = 0;
        }
      }
      auto ans = a;
      for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == -1) {
          ans[i] = ans[i - 1] + 1;
        }
      }
      for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1 && a[i] == -1) {
          ans[i] = min(a[i], ans[i + 1] + 1);
        }
      }
      for (int i = 0; i < n; i++) {
        if (ans[i] == 0)
          cout << 1;
        else
          cout << 0;
      }
      cout << '\n';
    }
  }
  return 0;
}
