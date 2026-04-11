/**
 *      author:  yuyuan567
 *      created: 2025-08-01 17:03:57
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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n + 1);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += n - i;
        ans[i] = 1;
    }

    multiset<int> all;
    map<int, int> cnt;

    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
        int v = cnt[a[i]];
        if (all.find(v - 1) != all.end()) {
            all.erase(all.find(v - 1));
        }
        all.insert(v);
        if (i >= k) {
            ans[i] = *all.rbegin();
            if (all.find(cnt[a[i - k + 1]]) != all.end()) {
                all.erase(all.find(cnt[a[i - k + 1]]));
            }
            cnt[a[i - k + 1]]--;
            all.insert(cnt[a[i - k + 1]]);
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << k - ans[r] << "\n";
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