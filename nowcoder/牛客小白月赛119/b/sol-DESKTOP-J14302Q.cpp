/**
 *      author:  yuyuan567
 *      created: 2025-08-31 13:57:00
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
        int n = 5;
        std::vector<int> freqs(1001);
        bool ok = false;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            freqs[x]++;
            if (x != 0) {
                ok = true;
                cnt++;
            }
        }
        int k;
        std::cin >> k;
        if (!ok) {
            std::cout << "1/1000\n";
        } else if (freqs[k] == 0) {
            std::cout << "0/1\n";
        } else if (freqs[k] == cnt) {
            std::cout << "1/1\n";
        } else {
            int g = std::gcd(freqs[k], cnt);
            std::cout << freqs[k] / g << "/" << cnt / g << '\n';
        }
    }
    return 0;
}
