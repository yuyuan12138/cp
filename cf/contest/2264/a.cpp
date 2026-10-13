#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n), bad;
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        if (p[i] != i + 1) {
            bad.push_back(i);
        }
    }
    auto a = p;
    sort(a.begin(), a.end());
    for (int i = 0; i < bad.size() / 2; i++) {
        std::swap(p[bad[i]], p[bad[bad.size() - i - 1]]);
    }
    if (a == p) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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