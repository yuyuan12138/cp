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
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (i > 0 && s[i] == '0' && s[i - 1] == '1') {
        ok = false;
      }
    }
    if (ok) {
      cout << "Bob\n";
    } else {
      cout << "Alice\n";
      vector<int> pref(n + 1);
      for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + (s[i] == '1');
      }
      for (int i = 1; i <= n; i++) {
        if (pref[i] == n - i - pref[n] + pref[i]) {
          cout << pref[i] * 2 << '\n';
          for (int j = 0; j < i; j++) {
            if (s[j] == '1') cout << j + 1 << ' ';
          }
          for (int j = i; j < n; j++) {
            if (s[j] == '0') {
              cout << j + 1 << ' ';
            }
          }
          cout << '\n';
          break;
        }
      }
    }
	}
	return 0;
}