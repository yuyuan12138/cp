#include <bits/stdc++.h>

#define int int64_t

void solve() {
    int64_t n, k;
    std::cin >> n >> k;
    if (n <= 60 && (1LL << (n - 1)) < k) {
        std::cout << "-1\n";
        return;
    }
    std::vector<int> digits;
    // digits.push_back(0);
    int64_t k1 = k;
    while (k1) {
        if (k1 & 1LL) {
            digits.push_back(1);
        } else {
            digits.push_back(0);
        }
        k1 >>= 1LL;
    }

    std::vector<int> ans(n);
    int64_t m = n;
    int64_t cur = 1;
    auto check = [&](int64_t x) -> bool {
        for (int i = x + 1; i < digits.size(); i++) {
            if (digits[i] == 1) {
                return false;
            }
        }
        if (digits[x] == 0) {
            return true;
        }
        bool ok = false;
        for (int i = 0; i <= x - 1; i++) {
            if (digits[i] == 1) {
                return false;
            }
        }
        return true;
    };
    int l = 0, r = n - 1;
    while (l <= r) {
        if (check(m - 2)) {
            ans[l] = cur;
            l++;
        } else {
            ans[r] = cur;
            // k -= ((1LL << (m - 2)));
            for (int i = m - 2; i < digits.size(); i++) {
                if (digits[i] == 0) {
                    digits[i] = 1;
                } else {
                    digits[i] = 0;
                    break;
                }
            }
            r--;
        }
        m--;
        cur++;
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
