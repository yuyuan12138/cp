#include <bits/stdc++.h>

/**   并查集（DSU）
 *    2023-08-04:
 *https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63239142
 **/
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
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        dsu.merge(u, v);
    }
    std::set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(dsu.find(i));
    }
    std::cout << st.size() - 1 << '\n';
    std::vector<int> a(st.begin(), st.end());
    for (int i = 0; i < int(a.size()) - 1; i++) {
        std::cout << a[i] + 1 << " " << a[i + 1] + 1 << '\n';
    }

    return 0;
}
