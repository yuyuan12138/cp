#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    std::vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, x, y;
        std::cin >> u >> v >> x >> y;
        u--, v--;
        if (x < y) {
            adj[u].push_back(v);
            deg[v]++;
        } else {
            adj[v].push_back(u);
            deg[u]++;
        }
    }
    std::queue<int> q;
    std::vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }  
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v: adj[u]) {
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }
    std::vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[ans[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        std::cout << res[i] + 1 << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
