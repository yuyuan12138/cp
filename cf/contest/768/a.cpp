#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	if (n <= 2) {
		std::cout << "0";
	} else {
		int x = a[0], y = a[n - 1];
		int z = int(n) - std::count(a.begin(), a.end(), x) - std::count(a.begin(), a.end(), y);
		std::cout << std::max(0, z);
	}
}