#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>

using ll = long long;

std::vector<std::vector<int>> get_divisors(const int n) {
  std::vector<std::vector<int>> divs(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      divs[j].push_back(i);
    }
  }
	return divs;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, std::vector<int>> pos;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        pos[a[i]].push_back(i);
    }
    ll ans = 0;
    auto divs = get_divisors(n);
    for (int i = 1; i <= n - 1; i++) {
        std::vector<int>& ds = divs[i];
        for (int d : ds) {
            if (pos[d].size() > pos[i / d].size()) {
                auto& ps = pos[i / d];
                for (int p : ps) {
                    if (p + i < n && a[p + i] == d) {
                        ans += 1;
                    }
                }
            } else {
                auto& ps = pos[d];
                for (int p : ps) {
                    if (p - i >= 0 && a[p - i] == i / d) {
                        ans += 1;
                    }
                }
            }
            
        }
    }
    std::cout << ans << '\n';
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