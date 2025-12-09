/**
 *      author:  yuyuan567
 *      created: 2025-07-28 14:49:03
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
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.size() > m) {
            flag = true;
        }
        if (!flag) {
            cnt++;
            m -= s.size();
        }
    }
    cout << cnt << "\n";
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