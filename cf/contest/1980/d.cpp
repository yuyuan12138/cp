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

    int c = 0;
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
      b[i] = gcd(a[i], a[i + 1]);
    }
    int bad = 0;
    for (int i = 1; i < n - 1; i++) {
      if (b[i] < b[i - 1]) {
        bad++;
      }
    }
    bool ok = false;
    if (bad - (b[1] < b[0]) == 0) {
      ok = true;
    }
    if (bad - (b[n - 2] < b[n - 3]) == 0) {
      ok = true;
    }
    for (int i = 1; i < n - 1; i++) {
      int tmp = bad;
      tmp -= (b[i - 1] > b[i]);
      if (i > 1) {
        tmp -= (b[i - 2] > b[i - 1]);
        tmp += (b[i - 2] > gcd(a[i - 1], a[i + 1]));
      }
      if (i < n - 2) {
        tmp -= (b[i] > b[i + 1]);
        tmp += (gcd(a[i - 1], a[i + 1]) > b[i + 1]);
      }
      if (tmp == 0) {
        ok = true;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
