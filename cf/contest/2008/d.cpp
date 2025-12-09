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


void solve() {
    int n;
    std::cin >> n;
    DSU dsu(n);
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        x--;
        dsu.merge(i, x);
    }
    std::map<int, int> mp;
    std::string s;
    std::cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            mp[dsu.find(i)]++;
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << mp[dsu.find(i)] << " \n"[i == n - 1];
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
