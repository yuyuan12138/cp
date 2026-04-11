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
	if (n == 1) {
		std::cout << 0 << '\n';
	} else {
		int ans = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] + a[i - 1] == 7 || a[i] == a[i - 1]) {
				ans += 1;
				i++;	
			}
		}
		std::cout << ans << '\n';
	}
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