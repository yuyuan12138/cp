#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt;
	cin >> tt;
	while (tt--) {
		int64_t n, a, b;
		cin >> n >> a >> b;
		cout << min({a * n, n / 3 * b + (n % 3) * a, (n + 2) / 3 * b}) << '\n';
	}

	return 0;
}
