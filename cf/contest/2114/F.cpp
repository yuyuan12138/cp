/**
 *      author:  yuyuan567
 *      created: 2025-07-30 00:19:09
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

vector<vector<int>> init() {
    const int n = 1e6 + 3;
    vector<vector<int>> res(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            res[j].push_back(i);
        }
    }
    return res;
}

void solve(vector<vector<int>>& divs) {
    int x, y, k;
    cin >> x >> y >> k;
    if (x == y) {
        cout << "0\n";
        return;
    }

    int g = gcd(x, y);
    x /= g, y /= g;
    auto work = [&](const int n) -> int {
        const int m = divs[n].size();
        vector<int> dp(m, 0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 0; i < m; i++) {
            if (dp[i] == 0x3f3f3f3f)
                continue;
            for (int j = i; j < m; j++) {
                if (divs[n][j] % divs[n][i] == 0 && divs[n][j] / divs[n][i] <= k) {
                    dp[j] = min(dp[j], dp[i] + 1);
                } else if (divs[n][j] / divs[n][i] > k) {
                    break;
                }
            }
        }
        return dp[m - 1];
    };
    int ans1 = work(x), ans2 = work(y);
    if (ans1 >= 0x3f3f3f3f || ans2 >= 0x3f3f3f3f) {
        cout << "-1\n";
        return;
    }

    cout << ans1 + ans2 << "\n";
    return;
}

int main() {
    speedup();
    int t;
    cin >> t;
    auto v = init();
    while (t--)
        solve(v);
    return 0;
}