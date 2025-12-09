/**
 *      author:  yuyuan567
 *      created: 2025-08-12 23:52:07
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
    int cnt0 = 0;
    int cnt1 = 0;
    for (auto& c: s) {
        if (c == '1') {
            cnt1++;
        } else {
            cnt0++;
        }
    }
    if (cnt0 == 0) {
        if (cnt1 == 4) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
        return ;
    }
    bool ok = false;
    int cur = 0;
    for (int i = 0; i * i <= cnt0 + 1; i++) {
        if (i * i == cnt0) {
            cur = i;
            ok = true;
        }
        if (i * i >= cnt0) {
            break;
        }
    }
    
    if (!ok) {
        std::cout << "No\n";
    } else {
        if ((cur + 1) * 4 != cnt1) {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
        }
    }

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