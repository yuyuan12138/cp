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
    string s;
    cin >> s;
    s = s + s;
    int mx = 0;
    for (int i = 0, cnt = 0; i < 2 * n; i++) {
      if (s[i] == '0') {
        cnt++;
      } else {
        mx = max(cnt, mx);
        cnt = 0;
      }
    }
    cout << mx << '\n';
  }

	return 0;
}