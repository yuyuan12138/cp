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
		vector<int> deg(n);
		for (int i = 0, u, v; i < m; i++) {
			cin >> u >> v;
			u--, v--;
			deg[u]++, deg[v]++;
		}
		sort(deg.begin(), deg.end());
		if (deg[0] == 0) {
			cout << "Brain Melt\n";
		} else if (deg[n - 1] == n - 1 && deg[n - 2] == 1) {
			cout << "2\n";
		} else {
			cout << "Many\n";
		}
	}
	return 0;
}
