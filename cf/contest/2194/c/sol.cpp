#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;

vector<vector<int>> get_divisors(const int n) {
  vector<vector<int>> divs(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      divs[j].push_back(i);
    }
  }
	return divs;
}


constexpr int inf = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	auto divs = get_divisors(5e5 + 1);
	int tt;
	cin >> tt;
	string res = "";
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<string> s(k);
		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}
		int mn = 1e9;
		for (int div : divs[n]) {
			string t;
			bool ok = true;
			for (int x = 0; x < div; x++) {
				int a = (1 << 26) - 1;
				for (int j = x; j < n; j += div) {
					int o = 0;
					for (int i = 0; i < k; i++) {
						o |= 1 << (s[i][j] - 'a');
					}
					a &= o;
				}
				if (!a) {
					ok = false;
					break;
				}
				t += 'a' + __builtin_ctz(a);	
			}
			if (ok && div < mn) {
				mn = div;
				res = t;
			}
		}
		string ans = "";
		for (int i = 0; i < n / mn; i++) {
			ans += res;
		}
		cout << ans << '\n';
	}

  return 0;
}

