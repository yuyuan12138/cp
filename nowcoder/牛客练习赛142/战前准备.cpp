/**
 *      author:  yuyuan567
 *      created: 2025-08-14 15:44:28
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


int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(2 * n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a[i] = a[i + n] = x;
    }

    int ans = 0;

    std::vector<std::vector<int>> pos(m);
    std::vector<int> cnt(m, 0);
    int c = 0;
    for (int i = 0; i < 2 * n; i++) {
        pos[a[i]].push_back(i);
        if (a[i] > 0) {
            if (pos[a[i] - 1].size() > 0 && pos[a[i]][0] > pos[a[i] - 1][0]) {
                if (!cnt[a[i] - 1]) {
                    cnt[a[i] - 1] = 1;
                    c++;
                }
            }
        }
        if (a[i] < m - 1) {
            if (pos[a[i] + 1].size() > 0 && pos[a[i]][0] < pos[a[i] + 1][0]) {
                if (!cnt[a[i]]) {
                    cnt[a[i]] = 1;
                    c++;
                }
            }
        }

        if (i >= n) {
            pos[a[i - n]].erase(pos[a[i - n]].begin());
            if (a[i - n] > 0) {
                if (cnt[a[i - n] - 1] == 1) {
                    c--;
                    cnt[a[i - n] - 1] = 0;
                }
                
                if (pos[a[i - n] - 1].size() > 0 && pos[a[i - n]][0] > pos[a[i - n] - 1][0]) {
                    cnt[a[i - n] - 1] = 1;
                    c++;
                }
            }

            if (a[i - n] < m - 1) {
                if (cnt[a[i - n]] == 1) {
                    c--;
                    cnt[a[i - n]] = 0;
                }
                if (pos[a[i - n] + 1].size() > 0 && pos[a[i - n]][0] < pos[a[i - n] + 1][0]) {
                    cnt[a[i - n]] = 1;
                    c++;
                }
            }
            
            if (c == m - 1) {
                ans++;
            }
        }
    }
    std::cout << ans << "\n";


    return 0;
}