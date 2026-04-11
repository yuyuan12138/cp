/**
 *      author:  yuyuan567
 *      created: 2025-08-06 18:54:45
 */
#include <bits/stdc++.h>


#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

void solve(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> suffix_max(n);
    std::vector<int> suffix_idx(n);

    suffix_max[n - 1] = a[n - 1];
    suffix_idx[n - 1] = n - 1;

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > suffix_max[i + 1]) {
            suffix_max[i] = a[i];
            suffix_idx[i] = i;
        } else {
            suffix_max[i] = suffix_max[i + 1];
            suffix_idx[i] = suffix_idx[i + 1];
        }
    }

    int mx = suffix_max[1];
    int idx = suffix_idx[1];

    if (mx == 0) {
        std::cout << n << "\n";
        for (int x: a) {
            std::cout << x << " ";
        }
    } else {
        std::cout << n - 1 << "\n";
        std::cout << mx + a[0] << ' ';
        for (int i = 1; i < n; i++) {
            if (i == idx) continue;
            std::cout << a[i] << ' ';
        }
    }

    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}