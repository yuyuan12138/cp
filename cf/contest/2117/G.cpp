/**
 *      author:  yuyuan567
 *      created: 2025-07-29 17:36:51
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

class DSU {
public:
    vector<int> parent;
    vector<int> mn;
    DSU(int n) {
        parent.resize(n);
        mn.assign(n, 1e9);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y, int w) {
        int xRoot = find(x);
        int yRoot = find(y);
        parent[xRoot] = yRoot;
        mn[xRoot] = min(min(mn[xRoot], mn[yRoot]), w);
        mn[yRoot] = min(min(mn[xRoot], mn[yRoot]), w);
    }
};

struct Edge {
    int u, v, w;
};

struct min_heap {
    /* data */
    bool operator()(const Edge& o1, const Edge& o2) const {
        return o1.w > o2.w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<Edge, vector<Edge>, min_heap> edges;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges.push({u, v, w});
    }

    int ans = 2e9;
    // int ans = 0x3f3f3f3f;
    DSU dsu(n);

    while (!edges.empty()) {
        auto [u, v, w] = edges.top();
        edges.pop();
        dsu.unionSets(u, v, w);
        if (dsu.find(n - 1) == dsu.find(0)) {
            ans = min(ans, w + dsu.mn[dsu.find(0)]);
        }
    }
    cout << ans << "\n";
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