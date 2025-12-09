/**
 *      author:  yuyuan567
 *      created: 2025-07-28 14:42:25
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
    vector<int> a(n), b(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    int tot = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > b[i + 1]) {
            tot += a[i] - b[i + 1];
        }
    }
    tot += a[n - 1];
    cout << tot << "\n";
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