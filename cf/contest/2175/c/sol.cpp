#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	int tt;
	cin >> tt;
	while (tt--) {
		string s, t;
		cin >> s >> t;
		vector<int> cnt(80);
		for (char c : t) {
			cnt[c - 'a']++;
		}
		string res = "";
		bool ok = true;
		for (char c : s) {
			cnt[c - 'a']--;
			if (cnt[c - 'a'] < 0) {
				ok = false;
			}
		}
		if (!ok) {
			cout << "Impossible\n";
		} else {
			const int n = s.size(), m = t.size();
			for (int i = 0, j = 0; i < 70; i++) {
				while (j < n && s[j] <= i + 'a') {
					res += s[j];
					j++;
				}
				while (cnt[i]--) {
					res += 'a' + i;
				}
			}
			cout << res << '\n';
		}
	}

  return 0;
}

