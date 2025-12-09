/**
 *      author:  yuyuan567
 *      created: 2025-08-11 22:34:12
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

void solve(){
    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    std::vector<int> a(n + 1), b(n + 1);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += ll(int(s[i] == '1') + int(t[i] == '1')) * n * (n - i);
    }

    for (int i = 0; i < n; i++) {
        a[i + 1] = a[i] + (s[i] == '1' ? 1 : -1);
    }
    for (int i = 0; i < n; i++) {
        b[i + 1] = b[i] + (t[i] == '1' ? 1 : -1);
    }

    a.erase(a.begin());
    b.erase(b.begin());

    std::sort(all(a));
    std::sort(all(b));

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         ans -= std::max(0LL, (ll) a[i] + b[j]);
    //     }
    // }
    std::vector<ll> suf_b(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        suf_b[i] = suf_b[i + 1] + b[i];
    }
    int ptr = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (ptr < n && a[i] + b[ptr] < 0) {
            ptr++;
        }
        ans -= (ll) a[i] * (n - ptr) + suf_b[ptr];
    }

    std::cout << ans << "\n";
    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1; std::cin >> t;
    while(t--) solve();
    return 0;
}