#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		cout << 2 * n - 1 << '\n';
		for (int i = 2 * n; i >= 2; i--) {
			cout << i << " \n"[i == 2];
		}
	}
	return 0;
}
