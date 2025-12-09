#include <bits/stdc++.h>

void solve() {
    std::string a, b;
    std::cin >> a >> b;
    int n = a.size();
    int m = b.size();
    if (n < m) {
        std::cout << "NO\n";
    } else {
        int j = 0; 
        for (int i = 0; i < n && j < m; i++) {
            if (a[i] == b[j] || a[i] == '?') {
                if (a[i] == '?') a[i] = b[j];
                j++;
            }
        }
        if (j == m) {
            for (int i = 0; i < n; i++) {
                if (a[i] == '?') a[i] = 'a';
            }
            std::cout << "YES\n" << a << "\n";
        } else {
            std::cout << "NO\n";
        }
    }
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
