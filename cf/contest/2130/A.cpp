/**
 *      author:  yuyuan567
 *      created: 2025-07-31 22:35:54
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
    // vector<int> a(n);
    int cnt0 = 0;
    int cnt1 = 0;
    vector<int> cnt(1e5, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    if (cnt[0] == 0 && cnt[1] == 0) {
        int ans = 0;
        for (int i = 1; i <= 1e5; i++) {
            ans += cnt[i] * i;
        }
        cout << ans << "\n";
    } else {
        int ans = 0;
        ans += 2 * min(cnt[0], cnt[1]);
        int tmp = min(cnt[0], cnt[1]);
        cnt[0] -= tmp;
        cnt[1] -= tmp;
        ans += cnt[0];
        cnt[0] = 0;
        for (int i = 1; i <= 1e5; i++) {
            ans += cnt[i] * i;
        }
        cout << ans << "\n";
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