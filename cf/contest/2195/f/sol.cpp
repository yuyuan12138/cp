#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i] >> b[i] >> c[i];
	}
	auto check = [&](int x, int y) -> bool {
		int ai = a[x] - a[y], bi = b[x] - b[y], ci = c[x] - c[y];
		if (ai == 0) {
			return bi == 0 && ci > 0;
		}
		return 1ll * bi * bi - 4ll * ai * ci < 0 && ci > 0;
	};
	std::vector<int> p(n);
	std::iota(p.begin(), p.end(), 0);
	std::sort(p.begin(), p.end(), [&](const int a, const int b) { return c[a] <= c[b]; });
	std::vector<int> l(n, 1), r(n, 1);
	for (auto i : p) {
		for (auto j : p) {
			if (check(i, j)) {
				l[i] = std::max(l[i], l[j] + 1);
			}
		}
	}
	std::reverse(p.begin(), p.end());
	for (auto i : p) {
		for (auto j : p) {
			if (check(j, i)) {
				r[i] = std::max(r[i], r[j] + 1);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << l[i] + r[i] - 1 << " \n"[i == n - 1];
	}
	
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
	
	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}

    return 0;
}

