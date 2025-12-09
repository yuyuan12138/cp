/**
 *      author:  yuyuan567
 *      created: 2025-07-28 19:01:47
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
    int n, d;
    cin >> n >> d;
    cout << "1 ";
    if (d % 3 == 0 || n >= 3) {
        cout << "3 ";
    }
    if (d == 5) {
        cout << "5 ";
    }

    if (d == 7 || (n >= 3)) {
        cout << "7 ";
    }
    if ((d % 9 == 0) || n >= 6 || (d % 3 == 0 && n >= 3)) {
        cout << "9";
    }
    cout << "\n";
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