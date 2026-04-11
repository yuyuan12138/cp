#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n;
    std::cin >> n;
    bool has_one = false;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] == 1) {
            has_one = true;
        }
    }
    if (has_one) {
        std::set<int> st;
        for (int i = 0; i < n; i++) {
            if (a[i] != 1) {
                st.insert(a[i]);
            }
        }
        bool ok = true;
        st.insert(1);
        std::vector<int> b(st.begin(), st.end());

        for (int i = 1; i < b.size(); i++) {
            if (b[i] - b[i - 1] == 1) {
                ok = false;
            }
        }

        if (ok) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    } else {
        std::cout << "YES\n";
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