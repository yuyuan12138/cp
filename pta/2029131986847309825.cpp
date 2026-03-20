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
	std::cout << "Congratulations on 38 happy Women's Day To:\n";
	for (int i = 0; i < n; i++) {
		std::string s, t;
		std::cin >> s >> t;
		if (t == "Ms") {
			std::cout << s << '\n';
		}
	}
	std::cout << "chutiren";

	return 0;
}