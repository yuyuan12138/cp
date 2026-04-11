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
    int ans = count(s.begin(), s.end(), '1');
    if (n == 1 || n == 2) {
      cout << max(ans, 1) << '\n';
    } else {
      if (s[0] == '0' && s[1] == '0') {
        s[1] = '1';
        ans++;
      }
      if (s[n - 1] == '0' && s[n - 2] == '0') {
        s[n - 2] = '1';
        ans++;
      }
      int cnt = 0;
      for (int i = 1; i < n - 1; i++) {
        if (s[i] == '1') {
          ans += (cnt / 3);
          cnt = 0;
        } else {
          cnt++;
        }
      }
      cout << ans + (cnt / 3) << '\n';
    }
	} 

	return 0;
}