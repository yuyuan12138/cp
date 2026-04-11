/**
 *      author:  yuyuan567
 *      created: 2025-07-30 14:48:09
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
    int n;
    cin >> n;
    vector<int> c(n);
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        // st.insert(c[i]);
        cnt[--c[i]]++;
    }

    sort(all(c), [&](int x, int y) { return cnt[x] < cnt[y]; });
    int ans = 0;
    vector<int> vis(n);
    int flag = 0;

    for (int i = 0; i < n; i++) {
        if (cnt[i] >= 2) {
            ans++;
        }
        if (cnt[i] == 1 && !flag) {
            ans += 2;
            flag ^= 1;
        } else if (cnt[i] == 1 && flag) {
            flag ^= 1;
        }
    }
    cout << ans << "\n";
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