/**
 *      author:  yuyuan567
 *      created: 2025-07-30 14:37:42
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    sort(all(a), greater<int>());
    int sum = accumulate(all(a), 0);
    // debug(sum);
    if (sum < k) {
        cout << k - sum << "\n";
        return;
    }
    int tot = 0;
    for (int i = 0; i < n; i++) {
        if (tot + a[i] < k) {
            tot += a[i];
        } else if (tot + a[i] == k) {
            cout << "0\n";
            return;
        } else {
            cout << k - tot << "\n";
            return;
        }
    }

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