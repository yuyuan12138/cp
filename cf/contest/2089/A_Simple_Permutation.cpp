/**
 *      author:  yuyuan567
 *      created: 2025-08-02 23:56:38
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
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    cout << "2 1";
    for (int i = 3; i <= n; i++) {
        cout << " " << i;
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