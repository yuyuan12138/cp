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

	int n, m;
	std::cin >> n >> m;
	std::string s;
	std::cin >> s;

	int size = 1;
	for (int i = 0; i < m; i++) {
		size *= s.size();
	}
	int bit = s.size();
	int b = size / n;
	int last = size % n;
	std::vector ans(n, std::vector<std::string> (2, ""));
	// std::cerr << "bit: " << bit << '\n';
	int cur = 0;
	for (int i = 0; i < n; i++) {
		{
			int t = cur;
			std::string res = "";
			// std::cerr << t << '\n';
			for (int j = 0; j < m; j++) {	
				int rem = t % bit;
				res += s[rem];
				t /= bit;
			}
			// std::cerr << res << '\n';
			std::reverse(res.begin(), res.end());
			ans[i][0] = res;
		}
		{
			int t = cur + b + (last > 0) - 1;
			std::string res = "";
			// std::cerr << t << '\n';
			for (int j = 0; j < m; j++) {	
				int rem = t % bit;
				res += s[rem];
				t /= bit;
			}
			// std::cerr << res << '\n';
			std::reverse(res.begin(), res.end());
			ans[i][1] = res;
		}
		cur += b + (last > 0);
		last--;
	}
	// std::cerr << "ans[0][0]: " << ans[0][0] << '\n';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << ans[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}