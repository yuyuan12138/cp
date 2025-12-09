/**
 *      author:  yuyuan567
 *      created: 2025-07-30 22:06:18
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

void solve() {
    int n;
    cin >> n;
    int size = n - 2;
    map<int, int> mp;
    int ans1, ans2;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if ((n - 2) % x != 0) {
            continue;
        }
        if (mp.find(x) == mp.end()) {
            mp[(n - 2) / x] = x;
        } else {
            ans1 = x, ans2 = mp[x];
        }
    }
    cout << ans1 << " " << ans2 << "\n";
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