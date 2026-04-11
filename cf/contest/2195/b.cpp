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

	bool ok = true;
	for (int i = 0, x; i < n; i++) {
		std::cin >> x;
		if ((x / (x & -x)) != (i + 1) / ((i + 1) & -(i + 1))) {
			ok = false;
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