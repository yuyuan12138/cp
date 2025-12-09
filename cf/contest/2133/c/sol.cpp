/**
 *      author:  yuyuan567
 *      created: 2025-08-24 22:51:23
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
        int n;
        std::cin >> n;
        auto Ask = [&] (int v) -> void {
            std::cout << "? " << v << " " << n << " ";
            for (int i = 0; i < n; i++) {
                std::cout << i + 1 << " ";
            }
            std::cout << std::endl;
        };
        std::vector<int> len(n + 1);
        for (int i = 0; i < n; i++) {
            int x;
            Ask(i + 1);
            std::cin >> x;
            len[i + 1] = x;
        }
        int st = 0;
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            if (len[i] > mx) {
                mx = len[i];
                st = i;
            }
        }
        int len_mx = len[st];
        std::vector<int> route;
        route.push_back(st);
        int cur = st;
        auto Query = [&] (int x, int y) -> void {
            std::cout << "? " << x << " 2 " << x << " " << y << std::endl;
        };
        for (int d = len_mx - 1; d >= 1; d--) {
            for (int u = 1; u <= n; u++) {
                if (len[u] == d) {
                    Query(cur, u);
                    int x;
                    std::cin >> x;
                    if (x == 2) {
                        route.push_back(u);
                        cur = u;
                        break;
                    }
                }
            }
        }
        std::cout << "! " << route.size();
        for (int v: route) {
            std::cout << " " << v;
        }
        std::cout << std::endl;
    }
    return 0;
}
