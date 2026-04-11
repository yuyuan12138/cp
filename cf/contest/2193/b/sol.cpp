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
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
      if (l == -1 && a[i] != n - i) {
        l = i;
      }
    }
    if (l != -1) {
      int mx = 0;
      for (int i = l; i < n; i++) {
        if (mx < a[i]) {
          mx = a[i];
          r = i;
        }
      }
      for (int i = l; i <= (r + l) / 2; i++) {
        swap(a[i], a[r - i + l]);
      }
    }
    
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
	
	return 0;
}