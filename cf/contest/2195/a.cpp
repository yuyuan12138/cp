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

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int mask = 0;
	bool ok = false;
	for (int i = 0; i < 32; i++) {
		int tot = 1;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				tot *= a[j];
			}
		}
		if (tot == 67) {
			ok = true;
		}
	}
	std::cout << (ok ? "YES\n" : "NO\n");
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);


	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}