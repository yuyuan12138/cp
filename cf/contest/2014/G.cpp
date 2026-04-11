/**
 *      author:  yuyuan567
 *      created: 2025-07-31 16:26:17
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

struct Milk {
    int day, content;
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<Milk> milk(n);
    for (int i = 0; i < n; i++) {
        cin >> milk[i].day >> milk[i].content;
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