/**
 *      author:  yuyuan567
 *      created: 2025-07-29 23:31:00
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
    vector<int> a(n + 1), b(n + 1), pos(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<int> prefix_min(n + 1, 0x3f3f3f3f);
    vector<int> suffix_max(n + 2);
    for (int i = 1; i <= n; i++) {
        prefix_min[i] = min(prefix_min[i - 1], a[i]);
    }

    prefix_min[0] = 0;

    for (int i = n; i >= 1; i--) {
        suffix_max[i] = max(suffix_max[i + 1], a[i]);
    }

    int l = 0, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        vector<int> sa = a;
        if ([&]() -> bool {
                if (mid != 0 && mid != n && sa[pos[prefix_min[mid]]] < sa[pos[suffix_max[mid + 1]]])
                    swap(sa[pos[prefix_min[mid]]], sa[pos[suffix_max[mid + 1]]]);
                int a_idx = 1, b_idx = 1;
                int score = 0;
                for (int i = 1; i <= n; i++) {
                    if (sa[a_idx] > b[b_idx]) {
                        score++;
                        a_idx++;
                    } else {
                        b_idx++;
                    }
                }
                if (score >= mid) {
                    return true;
                } else {
                    return false;
                }
            }()) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r << "\n";
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