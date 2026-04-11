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

#define N 63


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int q;
	std::cin >> q;
	std::vector s(3, std::vector<ll> (N));
	for (ll i = 0; i <= N - 2; i++) {
		s[1][i] = (1ll << i);
	}
	std::cout << 3 << ' ' << N << '\n';
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << s[i][j] << ' ';
		}
		std::cout << '\n';
	}

	while (q--) {
		ll x;
		std::cin >> x;
		int flag = 1;
		for (ll i = 0; i <= N - 2; i++) {
			if ((x >> i) & 1ll) {
				if (flag) {
					std::cout << "DD";
				} else {
					std::cout << "UU";
				}
				flag ^= 1;
			}
			std::cout << "R";
		}
		if (flag == 1) {
			std::cout << "DD\n";
		} else {
			std::cout << "\n";
		}
	}

	return 0;
}





