/**
 *      author:  yuyuan567
 *      created: 2025-07-30 15:41:10
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

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n);
    ll sum = 0;
    vector<ll> suffix_sum;
    for (int i = n - 1; i >= 1; i--) {
        if (s[i] == '1') {
            a[i] = 1;
        } else {
            a[i] = -1;
        }
        sum += a[i];
        suffix_sum.push_back(sum);
    }

    sort(all(suffix_sum), greater<ll>());
    sum = 0;
    int m = 0;
    for (int i = 0; i < suffix_sum.size(); i++) {
        if (sum >= k) {
            break;
        }
        sum += suffix_sum[i];
        m++;
    }
    if (sum >= k) {
        cout << m + 1 << "\n";
    } else {
        cout << -1 << "\n";
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}