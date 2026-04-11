#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> b(n);
    for (int i = 0; i < m; i++) {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        b[l]++;
        if (r < n - 1) {
            b[r + 1]--;
        }
    }
    for (int i = 1; i < n; i++) {
        b[i] += b[i - 1];
    }
    std::vector<int> c1(n), c2(n);
    for (int i = 0; i < n; i++) {
        c1[i] = a[i] + b[i];
        c2[i] = a[i] - b[i];
    }
    std::sort(c1.begin(), c1.end());
    std::sort(c2.begin(), c2.end());
    std::cout << std::max(0, c2[n - 1] - c1[0]) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}

