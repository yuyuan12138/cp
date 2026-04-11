/**
 *      author:  yuyuan567
 *      created: 2025-07-31 23:21:01
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

struct BIT {
    int n;
    vector<int> f;
    BIT(int _n = 0) : n(_n), f(n + 1, 0) {}
    void update(int i) {
        do {
            f[i]++;
            i += i & -i;
        } while (i <= n);
    }
    int query(int i) {
        int s = 0;
        do {
            s += f[i];
            i -= i & -i;
        } while (i > 0);

        return s;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<int> right_smaller(n), left_bigger(n);
    BIT bit1(n);
    BIT bit2(n);

    for (int i = n - 1; i >= 0; i--) {
        right_smaller[i] = bit1.query(p[i] - 1);
        bit1.update(p[i]);
    }
    for (int i = 0; i < n; i++) {
        left_bigger[i] = i - bit2.query(p[i]);
        bit2.update(p[i]);
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += min(0, n - i - 1 - right_smaller[i] - left_bigger[i]);
    }
    cout << sum + accumulate(all(right_smaller), 0LL) << "\n";
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