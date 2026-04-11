/**
 *      author:  yuyuan567
 *      created: 2025-08-10 01:43:06
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
    std::string s;
    std::cin >> s;
    std::cout << std::fixed << std::setprecision(9);
    if (s.size() <= 2) {
        std::cout << "0";
    } else {
        double mx = 0;
        for (int l = 0; l < s.size(); l++) {
            for (int r = l; r < s.size(); r++) {
                if (r - l + 1 <= 2) {
                    continue;
                } else {
                    if (s[l] != 't' || s[r] != 't') {
                        continue;
                    } else {
                        double cnt = 0;
                        for (int k = l + 1; k <= r - 1; k++) {
                            if (s[k] == 't') {
                                cnt++;
                            }
                        }
                        mx = std::max(mx, cnt / (double) (r - l - 1));
                    }
                }
            }
        }
        std::cout << mx << "\n";
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