#include <bits/stdc++.h>

using i64 = long long;

i64 solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<i64> pref(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    int la, ra, lb, rb;
    std::cin >> la >> ra >> lb >> rb;
    la--, ra--, lb--, rb--;
    int l = std::max(la, lb);
    int r = std::min(ra, rb);
    i64 ans = 0;
    if (l > r) {
        if (ra <= lb) {
            ans = pref[ra + 1];
            for (int i = 0; i < (lb - ra) / 2; i++) {
                ans += a[ra + i + 1];
            }
        } else {
            ans = pref[n] - pref[la];
            for (int i = 0; i < (la - rb) / 2; i++) {
                ans += a[la - i - 1];
            }
        }
    } else {
        for (int i = l + 1; i <= r - 1; i++) {
            i64 x = pref[i];
            i64 y = pref[n] - pref[i + 1];
            ans = std::max(ans, std::min(x, y) + a[i]);
        }
        if (lb < l) {
            i64 x = pref[l];
            i64 y = pref[n] - pref[l + 1];
            ans = std::max(ans, std::min(x, y) + a[l]);
        } else {
            ans = std::max(ans, pref[l + 1]);
        }

        if (rb > r) {
            i64 x = pref[r];
            i64 y = pref[n] - pref[r + 1];
            ans = std::max(ans, std::min(x, y) + a[r]);
        } else { 
            ans = std::max(ans, pref[n] - pref[r]);
        }
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        i64 ans = solve();
        std::cout << "Case #" << tt << ": ";
        std::cout << ans << '\n';
    }
    return 0;
}
