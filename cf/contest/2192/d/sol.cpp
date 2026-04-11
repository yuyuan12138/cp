#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		std::cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	std::vector<std::vector<i64>> dp(n, std::vector<i64> (2));
	std::vector<int> depth(n);
	std::vector<i64> s(n);
	[&](this auto &&self, int u, int pa) -> void {
		for (int v : adj[u]) {
			if (v != pa) {
				self(v, u);
				depth[u] = std::max(depth[v] + 1, depth[u]);
			}
		}
	} (0, -1);

	[&](this auto &&self, int u, int pa) -> void {
		if (pa != -1 && adj[u].size() == 1) {
			s[u] = a[u];
		} else {
			s[u] = a[u];
			for (int v : adj[u]) {
				if (v != pa) {
					self(v, u);
					s[u] += s[v];
				}
			}
			for (int v : adj[u]) {
				if (v != pa)
					dp[u][0] += dp[v][0] + s[v];
			}
			std::vector<std::array<int, 2>> d;
			for (int v : adj[u]) {
				if (v != pa) {
					dp[u][1] = std::max(dp[u][1], dp[u][0] - dp[v][0] + dp[v][1]);
					d.push_back({depth[v], v});
				}
			}
			std::sort(d.begin(), d.end());
			std::reverse(d.begin(), d.end());
			if (adj[u].size() >= 2 + (pa != -1)) {
				for (int v : adj[u]) {
					if (v != pa) {
						int idx = d[0][1];
						if (idx == v) {
							idx = d[1][1];
						}
						dp[u][1] = std::max(dp[u][1], dp[u][0] + i64(depth[idx] + 1) * s[v]);
					}
				}
			}
		}
	} (0, -1);
	for (int i = 0; i < n; i++) {
		std::cout << std::max(dp[i][0], dp[i][1]) << " \n"[i == n - 1];
	}
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

