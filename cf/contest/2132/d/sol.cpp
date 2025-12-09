/**
 *      author:  yuyuan567
 *      created: 2025-08-22 00:21:47
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using i128 = __int128_t;

uint64_t digitsCount(uint64_t N) {
    if (N == 0) return 0;
    uint64_t res = 0;
    uint64_t p = 1;
    for (int d = 1; p <= N; ++d) {
        uint64_t start = p;
        uint64_t cnt = 0;
        if (N >= start) cnt = std::min(N - start + 1, static_cast<uint64_t>(9) * start);
        res += cnt * static_cast<uint64_t>(d);
        if (p > static_cast<uint64_t>(1e18) / 10) break;
        p *= 10;
    }
    return res;
}

uint64_t sumDigitsUpTo(uint64_t N) {
    if (N == 0) return 0;
    i128 res = 0;
    for (uint64_t pow10 = 1; pow10 <= N; pow10 *= 10) {
        uint64_t high = N / (pow10 * 10);
        uint64_t cur = (N / pow10) % 10;
        uint64_t low = N % pow10;
        res += static_cast<i128>(high) * static_cast<i128>(pow10) * 45;
        res += static_cast<i128>(cur) * static_cast<i128>(low + 1);
        res += static_cast<i128>(cur * (cur - 1) / 2) * static_cast<i128>(pow10);
        if (pow10 > static_cast<uint64_t>(1e18) / 10) break;
    }
    return static_cast<uint64_t>(res);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        uint64_t k;
        std::cin >> k;
        
        uint64_t lo = 0, hi = k;
        while (lo < hi) {
            uint64_t mid = lo + (hi - lo + 1) / 2;
            if (digitsCount(mid) <= k) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        
        uint64_t N = lo;
        uint64_t used = digitsCount(N);
        uint64_t rem = k - used;
        uint64_t ans = sumDigitsUpTo(N);
        
        if (rem > 0) {
            std::string s = std::to_string(N + 1);
            for (int i = 0; i < rem && i < s.size(); ++i) {
                ans += (s[i] - '0');
            }
        }
        
        std::cout << ans << "\n";
    }
    
    return 0;
}
