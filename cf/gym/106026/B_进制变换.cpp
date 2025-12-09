/**
 *      author:  yuyuan567
 *      created: 2025-08-13 22:11:24
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using i64_t = unsigned long long;
using i128 = __int128;

#define int long long


int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        int a, b;
        std::cin >> a >> b;

        auto get_digits = [](int x) -> std::vector<int> {
            std::vector<int> digits;
            while (x) {
                digits.push_back(x % 10);
                x /= 10;
            }
            return digits;
        };
        
        std::vector<int> digits = get_digits(a);

        i64 terms = 9;

        i64 t = 0;
        for (int i = 0; i < digits.size(); i++) {
            t += digits[i] * terms;
            terms *= 9;
        }
        std::vector<int> ans;
        int x = t;
        for (int i = 0; i < 2; i++) {
            int cnt = 0;
            digits = get_digits(x);
            for (auto c: digits) {
                cnt += c;
            }
            ans.push_back(cnt);
            x = cnt;
        }

        std::cout << "8\n";

        std::cout << "9 " << t << "\n";
        for (int i = 0; i < 2; i++) {
            std::cout << "1 " << ans[i] << "\n";
        }

        std::cout << "6 54\n2 28\n1 10\n1 1\n";
        std::cout << b << " " << b << "\n";

    }
    return 0;
}