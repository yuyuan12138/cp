#include <bits/stdc++.h>

struct DSU {
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n) { init(n); }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x) { return siz[find(x)]; }
};


void solve() {
    int n;
    std::cin >> n;
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        x--;
        dsu.merge(x, i);
    }

    std::set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(dsu.find(i));
    }

    int ans = 0;
    for (int x : st) {
        ans += std::max(0, (dsu.size(x) + 1) / 2 - 1);
    }
    std::cout << ans << '\n';

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