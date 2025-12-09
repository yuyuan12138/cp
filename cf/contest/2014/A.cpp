/**
 *      author:  yuyuan567
 *      created: 2025-07-30 23:46:44
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
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0 && cnt > 0) {
            cnt--;
            ans++;
        }
        if (x >= k) {
            cnt += x;
        }
    }
    cout << ans << "\n";
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