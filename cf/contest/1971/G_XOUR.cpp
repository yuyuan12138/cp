/**
 *      author:  yuyuan567
 *      created: 2025-08-03 17:15:48
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
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> mp;
    map<int, vector<int>> idxs;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i] >> 2].push_back(i);
        idxs[a[i] >> 2].push_back(i);
    }
    vector<int> ans(n);
    for (auto& [key, values] : mp) {
        sort(all(values), [&](int x, int y) { return a[x] < a[y]; });
        auto idxss = idxs[key];
        for (int i = 0; i < idxss.size(); i++) {
            ans[idxss[i]] = a[values[i]];
        }
    }
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
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