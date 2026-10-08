#include <bits/stdc++.h>

using namespace std;

constexpr int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt;
	cin >> tt;
	while (tt--) {
    string s;
    cin >> s;
    int ans = count(s.begin(), s.end(), '4');
    const int n = s.size();
    int cnt = inf;
    vector<int> pref(n + 1), suff(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] += (s[i] == '1' || s[i] == '3') + pref[i];
    }
    for (int i = n; i >= 1; i--) {
      suff[i - 1] = suff[i] + (s[i - 1] == '2');
    }
    for (int i = 0; i < n; i++) {
      cnt = min(cnt, pref[i] + suff[i + 1]);
    }
    cout << ans + cnt << '\n';
	}

	return 0;
}
