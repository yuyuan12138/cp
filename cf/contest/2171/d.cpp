#include <bits/stdc++.h>

constexpr int inf = 1e9;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> pref_min(n + 1, inf), suf_max(n + 1);
    for (int i = 0; i < n; i++) {
        pref_min[i + 1] = std::min(pref_min[i], a[i]);
    } 
    for (int i = n - 1; i >= 0; i--) {
        suf_max[i] = std::max(suf_max[i + 1], a[i]);
    }
    for (int i = 1; i <= n - 1; i++) {
        if (pref_min[i] > suf_max[i]) {
            std::cout << "No\n";
            return ;
        }
    }
    std::cout << "Yes\n";
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