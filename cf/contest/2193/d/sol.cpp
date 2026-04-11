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
    vector<int64_t> b(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
      b[i + 1] += b[i];
    }
    sort(a.begin(), a.end());
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      mp[a[i]]++;
    }    
    int64_t cnt = n;
    int64_t mx = 0;
    for (auto& [x, c] : mp) {
      auto ptr = lower_bound(b.begin(), b.end(), cnt);
      int idx = ptr - b.begin();
      if (*ptr > cnt) {
        idx--;
      }
      mx = max(mx, int64_t(idx + 1) * x);
      cnt -= c;
    }
    cout << mx << '\n';
  }
	
	return 0;
}