/**
 *      author:  yuyuan567
 *      created: 2025-08-07 16:34:23
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

void solve(){
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::vector<int> divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            divs.push_back(n / i);
        }
    }
    int ans = n;
    for (auto div: divs) {
        int cnt = 2;
        for (int i = 0; i < div; i++) {
            for (int j = div + i; j < n; j += div) {
                if (s[i] != s[j]) {
                    cnt--;
                }
            }
        }
        if (cnt > 0) {
            ans = std::min(ans, div);
        }
        cnt = 2;
        for (int i = n - div; i < n; i++) {
            for (int j = i - div; j >= 0; j -= div) {
                if (s[i] != s[j]) {
                    cnt --;
                }
            }
        }
        if (cnt > 0) {
            ans = std::min(ans, div);
        }
    }
    std::cout << ans << "\n";

    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1; std::cin >> t;
    while(t--) solve();
    return 0;
}