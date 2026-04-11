/**
 *      author:  yuyuan567
 *      created: 2025-11-18 19:07:08
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ull = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    std::set<std::string> st;
    for (int i = m; i <= n; i++) {
        for (int j = m; j <= n; j++) {
            std::string res = "";
            for (int x = i - m; x < i; x++) {
                for (int y = j - m; y < j; y++) {
                    res += s[x][y];
                }
            }
            st.insert(res);
        }
    }
    std::cout << st.size();
    return 0;
}