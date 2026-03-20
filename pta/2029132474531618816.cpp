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

	for (int x = 1; x <= 1000; x++) {
		if (x % 5 == 2 && x % 7 == 3 && x % 29 == 14) {
			std::cout << x;
			return 0;
		}
	}

	return 0;
}