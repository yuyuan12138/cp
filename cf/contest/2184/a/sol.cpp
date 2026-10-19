#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	if (n <= 3) {
		std::cout << n << '\n';
	} else if (n % 2 == 0) {
		std::cout << 0 << '\n';
	} else {
		std::cout << 1 << '\n';
	}
}


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
}
