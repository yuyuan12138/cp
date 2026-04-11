#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, x, y;
		cin >> n >> x >> y;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> b, c;
		bool flag = 0;
		for (int i = 0; i < n; i++) {
			if (i == x || i == y) {
				flag ^= 1;
			}
			if (flag) {
				c.push_back(a[i]);
			} else {
				b.push_back(a[i]);
			}
		}
		if (b.size() > 0)
			b.insert(b.end(), b.begin(), b.end());
		if (c.size() > 0)
			c.insert(c.end(), c.begin(), c.end());
		int mn = 1e9;
		int idx = -1;
		for (int i = 0; i < c.size() / 2; i++) {
			if (mn > c[i]) {
				mn = c[i];
				idx = i;
			}
		}
		if (b.size() == 0) {
			for (int i = idx; i < n + idx; i++) {
				cout << c[i] << " \n"[i == n + idx - 1];
			}
		} else if (c.size() == 0) {
			for (int i = 0; i < n; i++) {
				cout << b[i] << " \n"[i == n - 1];
			}
		} else {
			int idx1 = b.size() / 2;
			for (int i = 0; i < b.size() / 2; i++) {
				if (b[i] > c[idx]) {
					idx1 = i;
					break;
				}
			}
			b.insert(b.begin() + idx1, c.begin() + idx, c.begin() + idx + c.size() / 2);
			for (int i = 0; i < n; i++) {
				cout << b[i] << " \n"[i == n - 1];
			}
		}
	}
  return 0;
}

