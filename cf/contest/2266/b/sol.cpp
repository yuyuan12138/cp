#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << max(abs(a + c - b), abs(a - b)) << '\n';
	}
	return 0;
}
