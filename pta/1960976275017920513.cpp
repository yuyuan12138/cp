#include <bits/stdc++.h>


using ll = long long;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<int> a, b;
	std::vector<int> p_a, p_b;
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		if (x % 2 == 0) {
			a.push_back(x);
			p_a.push_back(i);
		} else {
			b.push_back(x);
			p_b.push_back(i);
		}
	}

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	std::vector<int> res(n);
	for (int i = 0; i < a.size(); i++) {
		res[p_a[i]] = a[i];
	}	
	for (int i = 0; i < b.size(); i++) {
		res[p_b[i]] = b[i];
	}	

	bool ok = true;
	for (int i = 1; i < n; i++) {
		if (res[i] < res[i - 1]) {
			ok = false;
		}
	}
	std::cout << (ok ? "YES\n" : "NO\n" );

	return 0;
}