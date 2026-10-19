/**
 *    author:  yuyuan
 *    created: .. ::
**/
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
    int ans = 1;
    int l = a[0], r = a[0];
    for (int i = 1; i < n; i++) {
      if (a[i] > a[i - 1] + 1) {
        ans++;
        l = a[i], r = a[i];
      } else {
        if (a[i] > l && a[i] <= r + 1) {
          r = max(r, a[i]);
        } else {
          l = a[i], r = a[i];
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}