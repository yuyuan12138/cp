#include <bits/stdc++.h>

using namespace std;
class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
  
  inline bool is_same(int x, int y) {
    return get(x) == get(y);
  }
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		dsu d(n);
		vector<int> cnt(n);
		vector<vector<int>> g(n);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			d.unite(u, v);
			g[u].push_back(v);
		}
		for (int u = 0; u < n; u++) {
			for (int v : g[u]) {
				cnt[d.get(u)]++;
			}
		}
		vector<int> s(n);
		for (int i = 0; i < n; i++) {
			s[d.get(i)]++;
		}
		int ans = 0;
		bool ok = true;
		vector<int> vis(n);
		for (int u = 0; u < n; u++) {
			if (vis[d.get(u)]) continue;
			vis[d.get(u)] = 1;
			if (s[d.get(u)] == 1) {
				ok = false;
			} else if (s[d.get(u)] == 2) {
				ans += 2;
			} else if (s[d.get(u)] == 3 && cnt[d.get(u)] == 2) {
				ans += 2;
			} else if (s[d.get(u)] >= 3) {
				ans += 3;
			}
		}
		if (!ok) {
			cout << "Brain Melt\n";
		} else if (ans > 2) {
			cout << "Many\n";
		} else {
			cout << 2 << '\n';
		}
	}
	return 0;
}
