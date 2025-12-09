/**
 *      author:  yuyuan567
 *      created: 2025-07-29 15:19:27
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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int med = 1; med <= 100; med++) {
        // vector<int> b(n + 1);
        // 随着med的增大，prefix_sum的值一定会更小，如果med大于了某个数字。
        // 那么这个数字对应后面的所有pre_sum都会 -2
        // 所以我们可以动态更新这个pre_sum.
        vector<int> prefix_sum(n + 1);
        int b;
        for (int i = 1; i <= n; i++) {
            if (a[i] >= med) {
                b = 1;
            } else {
                b = -1;
            }
            prefix_sum[i] = prefix_sum[i - 1] + b;
        }

        vector<int> prefix_min(n + 1, 0x3f3f3f3f);
        prefix_min[0] = 0;
        vector<int> suffix_max(n + 1);
        suffix_max[n] = prefix_sum[n];
        for (int i = 1; i <= n; i++) {
            prefix_min[i] = min(prefix_min[i - 1], prefix_sum[i]);
        }
        for (int i = n - 1; i >= 1; i--) {
            suffix_max[i] = max(suffix_max[i + 1], prefix_sum[i]);
        }

        for (int i = 1; i <= n; i++) {
            if (prefix_min[i - 1] <= prefix_sum[i] || suffix_max[i] >= prefix_sum[i - 1]) {
                ans = max(ans, med - a[i]);
            }
        }
    }
    cout << ans << "\n";
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