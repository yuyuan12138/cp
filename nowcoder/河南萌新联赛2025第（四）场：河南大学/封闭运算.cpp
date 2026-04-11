/**
 *      author:  yuyuan567
 *      created: 2025-08-06 18:51:13
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
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int v = a[i] | a[j];
            bool flag = false;
            for (int k = 0; k < n; k++) {
                if (a[k] == v) {
                    flag = true;
                }
            }
            if (!flag) {
                std::cout << "NO\n";
                return ;
            }
        }
    }
    std::cout << "YES\n";
    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}