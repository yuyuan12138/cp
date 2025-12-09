/**
 *      author:  yuyuan567
 *      created: 2025-08-17 20:56:26
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::multiset<int> b;
        for (int i = 0; i < m; i++) {
            int x;
            std::cin >> x;
            b.insert(x);
        }

        std::sort(a.begin(), a.end());
        int lft = n - 1;
        bool ok = true;
        while (lft > -1 && !b.empty() && lft + 1 >= b.size()) {
            if (*b.rbegin() == a[lft]) {
                lft--;
                b.erase(std::prev(b.end()));
            } else {
                if (a[lft] <= *b.rbegin()) {
                    int x = *b.rbegin();
                    b.erase(--b.end());
                    b.insert(x / 2);
                    b.insert((x + 1) / 2);
                } else {
                    ok = false;
                    break;
                }
            }
        }
        if (ok && b.empty() && lft == -1) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}
