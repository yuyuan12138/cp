/**
 *      author:  yuyuan567
 *      created: 2025-08-03 17:24:56
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

struct TwoSat {
    int n;
    std::vector<std::vector<int>> e;
    std::vector<bool> ans;
    TwoSat(int n) : n(n), e(2 * n), ans(n) {}
    void addClause(int u, bool f, int v, bool g) {
        e[2 * u + !f].push_back(2 * v + g);
        e[2 * v + !g].push_back(2 * u + f);
    }
    bool satisfiable() {
        std::vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);
        std::vector<int> stk;
        int now = 0, cnt = 0;
        std::function<void(int)> tarjan = [&](int u) {
            stk.push_back(u);
            dfn[u] = low[u] = now++;
            for (auto v : e[u]) {
                if (dfn[v] == -1) {
                    tarjan(v);
                    low[u] = std::min(low[u], low[v]);
                } else if (id[v] == -1) {
                    low[u] = std::min(low[u], dfn[v]);
                }
            }
            if (dfn[u] == low[u]) {
                int v;
                do {
                    v = stk.back();
                    stk.pop_back();
                    id[v] = cnt;
                } while (v != u);
                ++cnt;
            }
        };
        for (int i = 0; i < 2 * n; ++i)
            if (dfn[i] == -1)
                tarjan(i);
        for (int i = 0; i < n; ++i) {
            if (id[2 * i] == id[2 * i + 1])
                return false;
            ans[i] = id[2 * i] > id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() {
        return ans;
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> grids(3, std::vector<int>(n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> grids[i][j];
        }
    }
    TwoSat ts(n);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < 3; i++) {
            int nxt = (i + 1) % 3;
            ts.addClause(abs(grids[i][j]) - 1, grids[i][j] > 0, abs(grids[nxt][j]) - 1, grids[nxt][j] > 0);
        }
    }
    std::cout << (ts.satisfiable() ? "YES" : "NO") << "\n";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}