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
	double ans = 0;
	for (int i = 0; i < n; i++) {
		double x;
		std::cin >> x;
		double add = (x - ans) / 4.;
		int out = std::round(ans + add);
		ans = out;
		std::cout << out << " \n"[i == n - 1];
	}

	return 0;
}