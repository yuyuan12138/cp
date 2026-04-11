/**
 *      author:  yuyuan567
 *      created: 2025-07-28 23:42:06
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<int, ll> divs;

    for (int i = 1; i * i <= m; i++) {
        if (!(m % i)) {
            divs[i] = 0;
            divs[m / i] = 0;
        }
    }

    auto mod = [](int x, int m) { return (x % m + m) % m; };
    for (auto& [g, value] : divs) {
        for (int i = 1; i <= n; i++) {
            value += mod(a[i] - a[i - 1], g);
        }
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, x;
            cin >> i >> x;
            for (auto& [g, value] : divs) {
                value += (mod(x - a[i - 1], g) - mod(a[i] - a[i - 1], g));
                if (i != n) {
                    value += (mod(a[i + 1] - x, g) - mod(a[i + 1] - a[i], g));
                }
            }
            a[i] = x;
        } else {
            int k;
            cin >> k;
            if (divs[gcd(k, m)] < m) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

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