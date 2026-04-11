/**
 *      author:  yuyuan567
 *      created: 2025-07-28 15:11:39
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
    vector<int> ans(n);
    int start_idx = k - 1;
    int cnt = 1;
    while (cnt != n + 1) {
        ans[start_idx] = cnt;
        start_idx = (k + start_idx) % n;
        cnt++;
        if (ans[start_idx] != 0) {
            break;
        }
    }
    for (auto& x : ans) {
        if (x == 0) {
            x = cnt;
            cnt++;
        }
        cout << x << " ";
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