/**
 *      author:  yuyuan567
 *      created: 2025-07-28 15:29:21
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
    if (n % 33 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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