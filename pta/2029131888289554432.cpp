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
	int lo = 1, hi = 7;
	while (true) {
		int mid = (lo + hi) / 2;
		std::cout << "? " << mid << std::endl;
		std::string x;
		std::cin >> x;
		if (x == "=") {
			std::cout << "! " << mid << std::endl;
			break;
		}
		if (x == "<") {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	return 0;
}