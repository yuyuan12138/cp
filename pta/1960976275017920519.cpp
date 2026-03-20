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
	std::vector<int> node(n);
	for (int i = 0; i < n; i++) {
		std::cin >> node[i];
	}
	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	std::vector<int> vis(n, -1);
	auto dfs = [&](auto&& self, int u, int c) -> std::array<int, 3> {
		vis[u] = c;
		int cnt = (vis[u] != node[u]);
		int total = 1;
		for (int v : adj[u]) {
			if (vis[v] == c) {
				return {false, 0, 0};
			}
			if (vis[v] == -1) {
				auto [is, cc, tot] = self(self, v, 1 - c);
				if (!is) {
					return {false, 0, 0};
				}
				cnt += cc;
				total += tot;
			}
		}
		return {true, cnt, total};
	};
	int cnt = 0;
	for (int u = 0; u < n; u++) {
		if (vis[u] >= 0) {
			continue;
		}
		auto [is, c, tot] = dfs(dfs, u, 0);
		if (!is) {
			std::cout << "Impossible";
			return 0;
		}
		cnt += std::min(c, tot - c);
	}

	
	
	std::cout << cnt;

	return 0;
}