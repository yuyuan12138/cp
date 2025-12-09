/**
 *      author:  yuyuan567
 *      created: 2025-08-02 14:55:31
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
    string a, b;
    cin >> a >> b;
    swap(a[0], b[0]);
    cout << a << " " << b << "\n";
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