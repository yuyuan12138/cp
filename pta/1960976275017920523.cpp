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

	int n;
	std::cin >> n;
	std::vector<ll> a(n);
	std::map<ll, int> cnt;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin(), a.end());

	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	if (2 * a.back() > sum || sum % 2 == 1) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
	}



	return 0;
}