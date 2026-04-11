#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m, -1);
    std::vector<std::vector<int>> adj(n);
    std::vector<int> deg(n);
    std::vector<std::vector<int>> ops(n);

    for (int i = 0; i < n; i++) {
        int y;
        std::cin >> y;
        std::vector<int> v;
        for (int j = 0; j < y; j++) {
            int pos;
            std::cin >> pos;
            pos--;
            a[pos] = i;
            v.push_back(pos);
        }
        ops[i] = v;
    }

    for (int i = 0; i < n; i++) {
        for (int v : ops[i]) {
            if (i != a[v]) {
                adj[i].push_back(a[v]);
                deg[a[v]]++;
            }
        }
    }
    std::set<int> st;
    for (int u = 0; u < n; u++) {
        if (deg[u] == 0) {
            st.insert(u);
        }
    }
    std::vector<int> ans;
    while (!st.empty()) {
        int u = *st.rbegin();
        st.erase(st.find(u));
        ans.push_back(u);
        for (int v : adj[u]) {
            if (deg[v] == 1) {
                st.insert(v);
            }
            deg[v]--;
        }
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (ans[i] != i) {
            ok = true;
        }
    }
    if (ok) {
        std::cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            std::cout << ans[i] + 1 << " \n"[i == n - 1];
        }
    } else {
        std::cout << "No\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
