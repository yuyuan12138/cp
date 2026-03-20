#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <tuple>
#include <array>
#include <utility>
#include <functional>
#include <climits>
#include <cstring>
#include <cmath>


using ll = long long;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, q;
	std::cin >> n >> q;
	std::string s;
	std::cin >> s;
	std::vector pref(n + 1, std::vector<int> (26));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			pref[i + 1][j] = pref[i][j];
			pref[i + 1][j] += (s[i] - 'a' == j);
		}
	}
	while (q--) {
		int l, r;
		std::cin >> l >> r;
		bool ok = false;
		for (int j = 0; j < 26; j++) {
			if (pref[r][j] - pref[l - 1][j] == 1) {
				ok = true;
			}
		}
		std::cout << (ok ? "YES\n" : "NO\n");
	}

	return 0;
}