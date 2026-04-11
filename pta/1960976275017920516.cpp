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

	int n, x, y, z;
	std::cin >> n >> x >> y >> z;
	std::string ans(n, '?');

	for (int i = 179; i < n; i += 180) {
		if (z > 0) {
			z--;
			ans[i] = 'D';
		}
	}
	for (int i = 89; i < n; i += 90) {
		if (z > 0 && ans[i] == '?') {
			z--;
			ans[i] = 'D';
		} else if (y > 0 && ans[i] == '?') {
			ans[i] = 'C';
			y--;
		}
	}
	for (int i = 9; i < n; i += 10) {
		if (z > 0 && ans[i] == '?') {
			z--;
			ans[i] = 'D';
		} else if (y > 0 && ans[i] == '?') {
			ans[i] = 'C';
			y--;
		} else if (x > 0 && ans[i] == '?') {
			ans[i] = 'B';
			x--;
		}
	}

	for (int i = 0; i < n; i++) {
		if (ans[i] == '?') {
			if (z) {
				ans[i] = 'D';
				z--;
			} else if (y) {
				ans[i] = 'C';
				y--;
			} else if (x) {
				ans[i] = 'B';
				x--;
			} else {
				ans[i] = 'A';
			}
		}
	}
	std::cout << ans;

	return 0;
}










