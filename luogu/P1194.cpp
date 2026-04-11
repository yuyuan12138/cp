/** 
 *    author:  Yuyuan
 *    created: 2026-04-10 15:31:47
**/
#include <bits/stdc++.h>
using namespace std;

class dsu {
	public:
		vector<int> pa;
		int n;

		dsu(int _n) : n(_n) {
			pa.resize(n);
			iota(pa.begin(), pa.end(), 0);
		}

		inline int get(int x) {
			return (x == pa[x] ? x : (pa[x] = get(pa[x])));
		}

		inline bool unite(int x, int y) {
			x = get(x);
			y = get(y);
			if (x != y) {
				pa[x] = y;	
				return true;
			}
			return false;
		}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	cin >> a >> b;
	vector<array<int, 2>> edges;
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < b; j++) {
			int x;
			cin >> x;
			if (i < j) {
				edges.push_back({x, i * b + j});
			}
		}
	}
	sort(edges.begin(), edges.end());	
	dsu dsu(b);
	int ans = 0;
	int cnt = 0;
	for (auto [c, e] : edges) {
		if (cnt == b) {
			break;
		}
		int i = e / b;
		int j = e % b;
		if (dsu.get(i) == dsu.get(j)) {
			continue;
		}
		if (c > a || c == 0) {
			
		}	else {
		}		
	}
	cout << max(ans, a) << '\n';
	return 0;
}