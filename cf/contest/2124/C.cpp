/**
 *      author:  yuyuan567
 *      created: 2025-07-28 12:50:36
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
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int gcd_ = 0;
    int lcm_ = 1;
    for (int i = n; i >= 1; i--) {
        gcd_ = gcd(b[i], gcd_);
        lcm_ = lcm(lcm_, b[i] / gcd_);
    }

    cout << lcm_ << "\n";

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