/**
 *      author:  yuyuan567
 *      created: 2025-08-19 12:09:03
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
        int n;
        std::cin >> n;
        auto cmp = [&](std::array<int, 3>& a, std::array<int, 3>& b) -> bool {
            if (a[2] == b[2]) {
                if (a[0] == b[0]) {
                    return a[1] < b[1];
                } 
                return a[0] < b[0];
            } else {
                return a[2] < b[2];
            }
        };
        std::vector<std::array<int, 3>> pq;
        
        for (int i = 1, x = 1; x <= 2 * std::sqrt(n) + 10; i += 3, x++) {
            for (int j = 1, y = 1; y <= 2 * std::sqrt(n) + 10; j += 3, y++) {
                pq.push_back({i, j, i + j});
                pq.push_back({i + 1, j, i + j + 1});
                pq.push_back({i, j + 1, i + j + 1});
                pq.push_back({i + 1, j + 1, i + j + 4});
            }
        }
        std::sort(pq.begin(), pq.end(), cmp);
        int cur0 = 0;
        int cur1 = 0;
        std::set<std::array<int, 3>> st;
        std::set<std::array<int, 3>> vis;
        while (n--) {
            int x; std::cin >> x;
            if (x == 0) {
               while (true) {
                   int i = pq[cur0][0], j = pq[cur0][1];
                   if (st.count(pq[cur0])) {
                       cur0++;
                       continue;
                   } else {
                        vis.insert(pq[cur0]);
                        std::cout << i << " " << j << '\n';
                       i = i / 3 * 3 + 1;
                       j = j / 3 * 3 + 1;
                       st.insert({i, j, i + j});
                       st.insert({i + 1, j, i + j + 1});
                       st.insert({i, j + 1, i + j + 1});
                       st.insert({i + 1, j + 1, i + j + 4});
                       break;
                   }
               } 
            } else {
               while (true) {
                   int i = pq[cur1][0], j = pq[cur1][1];
                   if (vis.count(pq[cur1])) {
                       cur1++;
                       continue;
                   } else {
                       vis.insert(pq[cur1]);
                       std::cout << i << " " << j << '\n';

                       i = i / 3 * 3 + 1;
                       j = j / 3 * 3 + 1;
                       st.insert({i, j, i + j});
                       st.insert({i + 1, j, i + j + 1});
                       st.insert({i, j + 1, i + j + 1});
                       st.insert({i + 1, j + 1, i + j + 4});
                       break;
                   }
               } 
            }
        }
         
    }
    return 0;
}
