/**
 *      author:  yuyuan567
 *      created: 2025-08-20 16:17:17
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
    int n, k, q;
    std::cin >> n >> k >> q;
    std::vector<std::vector<ll>> grids(n, std::vector<ll> (k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            std::cin >> grids[i][j];
        }
    }

    for (int j = 0; j < k; j++) {
        for (int i = 1; i < n; i++) {
            grids[i][j] = grids[i][j] | grids[i - 1][j];
        }
    }
    while (q--) {
        int m;
        std::cin >> m;
        std::map<int, std::pair<ll, ll>> intervals;
        for (int i = 0; i < m; i++) {   
            int r;
            ll c;
            char op;
            std::cin >> r >> op >> c;
            r--;
            if (intervals.find(r) == intervals.end()) {
                intervals[r].first = -32LL;
                intervals[r].second = 100000000000009LL;
            }
            if (op == '>') {
                intervals[r].first = std::max(intervals[r].first, c);
            } else {
                intervals[r].second = std::min(intervals[r].second, c);
            } 
        }
        bool ok = true;
        int cur = 0;
        
        debug(grids);
        for (auto& [region, interval]: intervals) {
            ll l = interval.first, r = interval.second;
            if (r <= l + 1) {
                ok = false;
                break;
            }
            if (grids[cur][region] >= r) {
                ok = false;
                break;
            }
            if (grids[cur][region] <= l) {
                int lo = cur + 1, hi = n - 1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (grids[mid][region] > l) {
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
                }
                if (lo == n) {
                    ok = false;
                    break;
                }
                cur = lo;
                if (grids[cur][region] >= r) {
                    ok = false;
                    break;
                }
            }
        }
        for (auto& [region, interval]: intervals) {
            ll r = interval.second;
            if (grids[cur][region] >= r) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            std::cout << "-1\n";
        } else {
            std::cout << cur + 1 << '\n';
        }
    }
    return 0;
}
