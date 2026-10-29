#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int k;
		cin >> k;
		vector<int> ans(k);
		for (int t = 0; t < k; t++) {
			int n;
			cin >> n;
			vector<int> deg(n);
			for (int i = 0; i < n - 1; i++) {
				int u, v;
				cin >> u >> v;
				u--, v--;
				deg[u]++, deg[v]++;
			}
			int idx = max_element(deg.begin(), deg.end()) - deg.begin(); 
			ans[t] = idx;	
		}
		for (int i = 1; i < k; i++) {
			cout << i << ' ' << ans[i - 1] + 1 << ' ' << i + 1 << ' ' << ans[i] + 1 << '\n';
		}
	}
	return 0;
}
