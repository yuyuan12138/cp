#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; 
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> adj(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> dis(n);
		vector<int> vis(n);
		[&](this auto&& self, int u, int pa, int d, int get) -> void {
			dis[u] = d;
			vis[u] = get;
			for (int v : adj[u]) {
				if (pa != v) {
					self(v, u, d + 1, (u == 0) || get);
				}
			}	
		} (n - 1, -1, 0, 0);
		int ans = dis[0];
		for (int i = 0, u; i < m; i++) {
			cin >> u;
			u--;
			if (!vis[u]) {
				ans = max(ans, dis[u] + 1);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
