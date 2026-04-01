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
		vector<vector<int>> c(n + 1);
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			c[y].push_back(x);
		}
		
	}
  return 0;
}

