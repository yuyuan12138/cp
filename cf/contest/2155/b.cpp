#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n, k;
    std::cin >> n >> k;
    int last = n * n - k;
    if (last == 1) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        std::vector<std::vector<char>> s(n, std::vector<char> (n, 'R'));
        for (int i = 0, cnt = 0; i < n && cnt < last; i++) {
            for (int j = 0; j < n && cnt < last; j++, cnt++) {
                if (!(i == 0 && j == 0)) {
                    if (i == 0) {
                        s[i][j] = 'L';
                    } else {
                        s[i][j] = 'U';
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << s[i][j];
            }
            std::cout << '\n';
        }
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