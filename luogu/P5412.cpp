#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::set<long double> st1, st2;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        long double x;
        std::cin >> x;
        if (a[i]) {
            st2.insert(x);
        } else {
            st1.insert(x);
        }
    }
    for (auto x: st1) {
        std::cout << x << " ";
    }
    std::cout << '\n';
    for (auto x : st2) {
        std::cout << x << " ";
    }
    std::cout << '\n';
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
