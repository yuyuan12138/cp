#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            a[i] = 1;
        } else {
            a[i] = -1;
        }
    }

    int target = std::accumulate(a.begin(), a.end(), 0);

    std::vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }

    int ans = n;
    if (pref[n] == 0) {
        ans = 0;
    }
    std::map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        if (pref[i] == target) {
            ans = std::min(ans, i);
        }
        if (mp.count(pref[i] - target)) {
            ans = std::min(i - mp[pref[i] - target], ans);
        }
        mp[pref[i]] = i;
    }
    if (ans == n) {
        std::cout << "-1\n";
    } else {
        std::cout << ans << '\n';
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