#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::set<char> s;
    for (int i = 0; i < n; i++) {
        std::string x;
        std::cin >> x;
        s.insert(x[0]);
    }
    bool ok = true;
    for (int i = 0; i < m; i++) {
        std::string x;
        std::cin >> x;
        for (char c : x) {
            c = c - 'A' + 'a';
            if (!s.count(c)) {
                ok = false;
            }
        }
    }
    std::cout << (ok ? "YES\n" : "NO\n");
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
