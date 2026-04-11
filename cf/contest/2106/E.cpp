/**
 *      author:  yuyuan567
 *      created: 2025-07-30 19:37:07
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    while (q--) {
        int L, R, x;
        cin >> L >> R >> x;
        int k = pos[x];
        if (k < L || k > R) {
            cout << "-1 ";
        } else {
            int cnt0 = 0, cnt1 = 0, cntL = 0, cntR = 0;
            int l = L, r = R;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (mid == k)
                    break;
                if (mid < k) {
                    if (a[mid] < x)
                        cnt0++;
                    else
                        cntL++, cnt1++;
                    l = mid + 1;
                } else {
                    if (a[mid] > x)
                        cnt1++;
                    else
                        cntR++, cnt0++;
                    r = mid - 1;
                }
            }
            if (x - 1 - cnt0 < max(0, cntL - cntR) || n - x - cnt1 < max(0, cntR - cntL))
                cout << "-1 ";
            else
                cout << 2 * max(cntL, cntR) << " ";
        }
    }
    cout << "\n";
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