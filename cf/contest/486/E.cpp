/**
 *      author:  yuyuan567
 *      created: 2025-08-05 16:27:08
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

constexpr int N = 1e5 + 3;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(N);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> st;
    std::vector<int> pos(N);

    st.push_back(std::vector<int>());
    st[0].push_back(0);
    pos[0] = 0;
    for (int i = 1; i < n; i++) {
        int lo = 0, hi = st.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int cur = st[mid].back();
            if (a[cur] < a[i]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (lo >= st.size()) {
            st.push_back(std::vector<int>());
        }
        st[lo].push_back(i);
        pos[i] = lo;
    }
    std::vector<std::vector<int>> visited(st.size() + 3);
    std::vector<int> vis(N), cnt(N);
    for (int i = 0; i < st[st.size() - 1].size(); i++) {
        vis[st[st.size() - 1][i]] = 1;
        cnt[pos[st[st.size() - 1][i]]]++;
        visited[st.size() - 1].push_back(st[st.size() - 1][i]);
    }

    for (int k = st.size() - 2; k >= 0; k--) {
        for (int j = 0; j < st[k].size(); j++) {
            int cur = st[k][j];
            int lo = 0, hi = visited[k + 1].size() - 1;
            int cmp;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                cmp = visited[k + 1][mid];
                if (cur > cmp) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            hi = visited[k + 1].size() - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                cmp = visited[k + 1][mid];
                if (a[cur] >= a[cmp]) {
                    hi = mid - 1;
                } else {
                    vis[cur] = 1;
                    cnt[pos[cur]]++;
                    break;
                }
            }
            if (vis[cur]) {
                visited[k].push_back(cur);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            std::cout << "1";
        } else {
            if (cnt[pos[i]] == 1) {
                std::cout << "3";
            } else {
                std::cout << "2";
            }
        }
    }
    std::cout << "\n";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--)
        solve();
    return 0;
}