#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    std::vector<std::vector<int>> adj(n);
    int root = -1;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<bool> ans(n);

    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (a[u] == a[v]) {
                ans[a[u]] = 1;
            }
        }
        std::set<int> st;
        for (int v : adj[u]) {
            if (st.contains(a[v])) {
                ans[a[v]] = 1;
            } else {
                st.insert(a[v]);
            }
        }
    }

    for (int u = 0; u < n; u++) {
        std::cout << ans[u];
    }
    std::cout << '\n';

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
