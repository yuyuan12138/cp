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
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}	
	
	std::multiset<int> st;
	st.insert(0);
	std::vector<int> dp(n + 2);
	for (int i = 1; i <= n + 1; i++) {
		if (i - k >= 1) {
			st.erase(st.find(dp[i - k - 1]));
		}
		if (i <= n)
			dp[i] = std::max(*st.begin(), a[i]);
		else
			dp[i] = *st.begin();

		st.insert(dp[i]);
	}
	std::cout << dp[n + 1] << '\n';
	// for (int i = 1; i <= n + 1; i++) {
	// 	std::cerr << dp[i] << " \n"[i == n + 1];
	// }
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