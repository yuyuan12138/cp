#include <bits/stdc++.h>

struct DSU {
    int n;
    std::vector<int> f, siz;
    int cnt;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        cnt = n;
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

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) {
            return false;
        }
        if (siz[x] < siz[y]) {
            std::swap(x, y);
        }
        f[y] = x;
        siz[x] += siz[y];
        cnt--;
        return true;
    }

    int size(int x) { return siz[find(x)]; }

    int count() { return cnt; }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        dsu.merge(x, y);
    }
    std::vector<std::pair<int, int>> ans;
    for (int u = 0; u < n; u++) {
        if (dsu.merge(u, 0)) {
            ans.emplace_back(1, u + 1);
        }
    }
    std::cout << ans.size() << '\n';
    for (auto [u, v]: ans) {
        std::cout << u << ' ' << v << '\n';
    }

    return 0;
}
