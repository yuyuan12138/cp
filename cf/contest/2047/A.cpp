/**
 *      author:  yuyuan567
 *      created: 2025-07-28 17:41:34
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

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    int n;
    cin >> n;
    int cur = 1;
    int tot = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tot += x;
        while (cur * cur < tot) {
            cur += 2;
        }
        if (cur * cur == tot) {
            ans++;
        }
    }
    cout << ans << "\n";
    return;
}

int main() {
    speedup();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}