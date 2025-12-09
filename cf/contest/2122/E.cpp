/**
 *      author:  yuyuan567
 *      created: 2025-07-30 12:23:10
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
#define int long long

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    int n, k;
    cin >> n >> k;
    const ll mod = 998244353LL;
    vector a(2, vector<int>(n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            a[i][j] %= mod;
        }
    }

    vector cnt(n, vector<int>(2 * k + 1));
    for (int i = n - 1; i > 0; --i) {
        if (a[0][i] == -1 && a[1][i - 1] == -1) {
            for (int j = 1; j <= k; ++j) {
                for (int x = 1; x <= k; ++x) {
                    cnt[i][j - x + k] += 1;
                    cnt[i][j - x + k] %= mod;
                }
            }
        } else if (a[0][i] == -1) {
            for (int j = 1; j <= k; ++j) {
                cnt[i][j - a[1][i - 1] + k] += 1;
                cnt[i][j - a[1][i - 1] + k] %= mod;
            }
        } else if (a[1][i - 1] == -1) {
            for (int j = 1; j <= k; ++j) {
                cnt[i][a[0][i] - j + k] += 1;
                cnt[i][a[0][i] - j + k] %= mod;
            }
        } else {
            cnt[i][a[0][i] - a[1][i - 1] + k] = 1;
            cnt[i][a[0][i] - a[1][i - 1] + k] %= mod;
        }
    }

    vector<int> pre(n);
    pre[0] = 1;
    for (int i = 1; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j <= k; ++j) {
            sum += cnt[i][j + k];
            sum %= mod;
        }

        pre[i] = pre[i - 1] * sum;
        pre[i] %= mod;
    }

    vector<int> f(k + 1);
    f[0] = 1;
    int ans = pre[n - 1];
    for (int i = n - 1; i > 0; --i) {
        vector<int> g(k + 1);
        for (int j = 0; j <= k; ++j) {
            for (int x = 0; x + j <= k; ++x) {
                g[j + x] += f[x] % mod * cnt[i][j + k] % mod;
                g[j + x] %= mod;
            }
        }

        for (int j = -k; j < 0; ++j) {
            for (int x = 0; x + j <= 0; ++x) {
                g[0] += f[x] % mod * cnt[i][j + k] % mod;
                g[0] %= mod;
                ans += pre[i - 1] % mod * f[x] % mod * cnt[i][j + k] % mod;
                ans %= mod;
            }
        }

        f = g;
    }

    if (a[0][0] == -1) {
        ans *= k;
        ans %= mod;
    }

    if (a[1][n - 1] == -1) {
        ans *= k;
        ans %= mod;
    }

    cout << ans % mod << "\n";
}

signed main() {
    speedup();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}