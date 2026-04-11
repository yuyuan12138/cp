/**
 *      author:  yuyuan567
 *      created: 2025-08-30 20:32:21
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
    int64_t rt, ct, ra, ca;
    std::cin >> rt >> ct >> ra >> ca;
    int64_t n, m, l;
    std::cin >> n >> m >> l;
    std::vector<std::pair<char, int64_t>> a(m);
    std::vector<std::pair<char, int64_t>> b(l);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < l; i++) {
        std;:cin >> b[i].first >> b[i].second;
    }

    return 0;
}
