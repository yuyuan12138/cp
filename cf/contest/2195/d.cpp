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
	std::vector<ll> f(n);
	for (int i = 0; i < n; i++) {
		std::cin >> f[i];
	}
	ll sum = (f[n - 1] + f[0]) / (n - 1);
	ll cur = 0;
	for (int i = 0; i < n - 1; i++) {
		ll o = (f[i + 1] - f[i] + sum) / 2 - cur;
		std::cout << o << ' ';
		cur += o;
	}
	std::cout << sum - cur << '\n';
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