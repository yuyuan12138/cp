#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(2 * n);
    std::vector<i64> diff(2 * n - 1);
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> a[i];
    }
    std::vector<i64> pref_a(2 * n + 2);
    for (int i = 0; i < 2 * n; i++) {
        if (i < 2 * n - 1) {
            diff[i] = a[i + 1] - a[i]; 
        }
        
    }
    std::vector<i64> ans(n + 1);
    for (int i = 0; i < 2 * n - 1; i++) {
        pref_a[i + 2] = pref_a[i] + diff[i];
    }

    for (int i = 0; i < 2 * n - 1; i += 2) {
        ans[1] += diff[i];
    }
    int l = 1, r = 2 * n - 2;
    for (int k = 2; k <= n; k++) {
        ans[k] = ans[k - 1];
        ans[k] += 2 * (pref_a[r + 1] - pref_a[l]);
        l += 1;
        r -= 1;
    }
    // for (int x: pref_a) {
    //     std::cerr << x << " ";
    // }
    // std::cout << '\n';
    for (int k = 1; k <= n; k++) {
        std::cout << ans[k] << " \n"[k == n];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
