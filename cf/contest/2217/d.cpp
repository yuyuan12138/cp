/** 
 *    author:  Yuyuan
 *    created: 2026-04-08 12:46:20
**/
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int l = 0, r = 0;
	int idx = 0;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		vector<Node> nodes(k);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < k; i++) {
			int p;
			cin >> p;
			nodes[i].idx = --p;
		}
		auto get = [&](int i, int v, int idx) {
			int cnt1 = 0, cnt2 = 0;
			int l = 0, r = n - 1;
			if (idx > 0) {
				l = nodes[idx - 1].idx;
			}
			if (idx < k - 1) {
				r = nodes[idx + 1].idx;
			}
			for (int j = i - 1; j >= l; j--) {
				if (a[j] == v ^ 1 && a[j + 1] == v) {
					cnt1++;
				}
			}
			for (int j = i; j < r; j++) {
				if (a[j] == v && a[j + 1] == v ^ 1) {
					cnt2++;
				}
			}
			nodes[idx].l = cnt1 * 2;
			nodes[idx].r = cnt2 * 2;
		};
		for (int i = 0; i < k; i++) {
			int p = nodes[i].idx;
			get(p, a[p], i);
		}
		vector<int> c;
		for (int i = 0, j = 0; j < k; j++) {
			i = j;
			while (j < k - 1 && nodes[j + 1].idx == nodes[j].idx + 1) {
				j++;
			}
			// c.emplace_back(nodes[i].l, nodes[j].r, 0);	
			c.push_back(nodes[i].l);
			if (j == k - 1) {
				c.push_back(nodes[i].r);
			}
		}
		int64_t tot = 0;
		for (int i = 0; i < c.size(); i++) {
			cerr << c[i] << " \n"[i == c.size() - 1];
			tot += c[i];
		}
		vector<int64_t> pref(c.size() + 1);
		for (int i = 0; i < c.size(); i++) {
			pref[i + 1] = pref[i] + c[i];	
		}
		int64_t ans = int64_t(1e18);
		for (int i = 0; i < c.size(); i++) {
			int64_t pre = pref[i], aft = tot - pref[i + 1];
			int64_t mn = min(pre, aft);
			pre -= mn, aft -= mn;
			if ((pre > 0 && pre <= c[i]) || (aft > 0 && aft <= c[i])) {
				ans = min(ans, mn + pre + aft + (c[i] - (c[i] - aft - pre) + 1) / 2);
			} else if (pre == 0 && aft == 0) {
				ans = min(ans, mn + c[i] / 2);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}