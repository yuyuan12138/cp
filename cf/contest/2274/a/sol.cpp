#include <bits/stdc++.h>

using std::cin;
using std::cout;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		std::vector<int> a(n);
		int p = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		std::reverse(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			p = 2 * a[i] - p;
		}
		cout << p / 2 << '\n';
	}
  return 0;
}
