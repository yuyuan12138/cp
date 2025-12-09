/**
 *      author:  yuyuan567
 *      created: 2025-08-30 12:16:17
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        const int n = 3;
        std::vector<std::string> s(n);
        for (int i = 0; i < n; i++) {
            std::cin >> s[i];
        }
        for (int i = 0; i < n; i++) {
            bool ok = false;
            for (int j = 0; j < n; j++) {
                if (s[i][j] == '?') {
                    std::set<char> st;
                    for (int k = 0; k < n; k++) {
                        if (s[i][k] != '?') {
                            st.insert(s[i][k]);
                        }
                    }
                    if (!st.contains('A')) {
                        std::cout << 'A' << '\n';
                    } else if (!st.contains('B')) {
                        std::cout << 'B' << '\n';
                    } else {
                        std::cout << 'C' << '\n';
                    }
                    ok = true;
                    break;
                }
            }
            if (ok)
                break;
        }
    }
    return 0;
}
