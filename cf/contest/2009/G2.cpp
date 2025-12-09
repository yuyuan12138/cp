/**
 *      author:  yuyuan567
 *      created: 2025-08-01 17:03:57
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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n + 1);
    vector<int> ans(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += n - i;
    }

    multiset<int> all;
    map<int, int> cnt;

    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
        int v = cnt[a[i]];
        auto it = all.find(v - 1);
        if (it != all.end()) {
            all.erase(it);
        }
        all.insert(v);
        if (i >= k) {
            ans[i] = *all.rbegin();
            int remove_val = cnt[a[i - k + 1]];
            it = all.find(remove_val);
            if (it != all.end()) {
                all.erase(it);
            }
            cnt[a[i - k + 1]]--;
            if (cnt[a[i - k + 1]] > 0) {
                all.insert(cnt[a[i - k + 1]]);
            }
        }
    }

    vector<int> next_index(n + 2, n + 1);
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && ans[st.top()] < ans[i]) {
            next_index[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
        st.pop();

    int LOG = 0;
    if (n > 0) {
        while ((1 << (LOG + 1)) <= n) {
            LOG++;
        }
    }

    vector<vector<int>> up(n + 1, vector<int>(LOG + 1, n + 1));
    vector<vector<ll>> sum_arr(n + 1, vector<ll>(LOG + 1, 0));

    for (int i = 1; i <= n; i++) {
        up[i][0] = next_index[i];
        ll len;
        if (next_index[i] == n + 1) {
            len = n - i + 1;
        } else {
            len = next_index[i] - i;
        }
        sum_arr[i][0] = len * ans[i];
    }

    for (int j = 1; j <= LOG; j++) {
        for (int i = 1; i <= n; i++) {
            int prev = up[i][j - 1];
            if (prev <= n) {
                up[i][j] = up[prev][j - 1];
                sum_arr[i][j] = sum_arr[i][j - 1] + sum_arr[prev][j - 1];
            } else {
                up[i][j] = n + 1;
                sum_arr[i][j] = sum_arr[i][j - 1];
            }
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int s = l + k - 1;
        if (s > r) {
            cout << 0 << "\n";
            continue;
        }
        ll total_max = 0;
        int current = s;
        for (int j = LOG; j >= 0; j--) {
            if (up[current][j] <= r) {
                total_max += sum_arr[current][j];
                current = up[current][j];
            }
        }
        if (current <= r) {
            total_max += (ll)(r - current + 1) * ans[current];
        }
        ll total_segments = r - s + 1;
        ll result = total_segments * (ll)k - total_max;
        cout << result << "\n";
    }
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