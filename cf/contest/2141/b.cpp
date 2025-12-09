#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    std::set<int> at, bt;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        at.insert(a[i]);
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
        bt.insert(b[i]);
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (!bt.contains(a[i])) {
            cnt1++;
        }
    }
    for (int i = 0; i < m; i++) {
        if (!at.contains(b[i])) {
            cnt2++;
        }
    }
    if (cnt2 < cnt1) {
        std::cout << 2 * (cnt2 + 1) << '\n';
    } else {
        std::cout << 2 * cnt1 + 1 << '\n';
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