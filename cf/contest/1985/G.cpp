/**
 *      author:  yuyuan567
 *      created: 2025-08-02 16:22:57
 */
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;

template <typename T>
T power_with_mod(T base, T exp, T mod) {
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base;
    if (exp % 2) {
        return (power_with_mod(base, exp / 2, mod) % mod) * (power_with_mod(base, exp / 2, mod) % mod) % mod * base %
            mod;
    }
    return (power_with_mod(base, exp / 2, mod) % mod) * (power_with_mod(base, exp / 2, mod) % mod) % mod;
}

template <typename T>
T power(T base, T exp) {
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base;
    if (exp % 2) {
        return power(base, exp / 2) * power(base, exp / 2) * base;
    }
    return power(base, exp / 2) * power(base, exp / 2);
}

void solve() {
    const ll mod = 1e9 + 7;
    ll l, r, k;
    cin >> l >> r >> k;
    vector<int> nums = {0, 10, 5, 4, 3, 2, 2, 2, 2, 2};
    if (k >= 10) {
        cout << "0\n";
    } else {
        ll cnt = nums[k];
        cout << (power_with_mod(cnt, r, mod) - power_with_mod(cnt, l, mod) % mod + mod) % mod << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}