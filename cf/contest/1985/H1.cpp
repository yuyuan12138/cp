/**
 *      author:  yuyuan567
 *      created: 2025-08-02 16:46:14
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

struct DSU {
    vector<int> parent, size;
    int components;

    DSU(int n) : parent(n), size(n, 1), components(n) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return false;

        if (size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        components--;
        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int get_size(int x) {
        return size[find(x)];
    }

    int count() const {
        return components;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grids(n);
    DSU dsu(n * m);

    for (int i = 0; i < n; i++) {
        cin >> grids[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grids[i][j] == '.')
                continue;
            if (i > 0 && grids[i - 1][j] == '#') {
                dsu.unite((i - 1) * m + j, i * m + j);
            }
            if (i < n - 1 && grids[i + 1][j] == '#') {
                dsu.unite((i + 1) * m + j, i * m + j);
            }
            if (j > 0 && grids[i][j - 1] == '#') {
                dsu.unite(i * m + j - 1, i * m + j);
            }
            if (j < m - 1 && grids[i][j + 1] == '#') {
                dsu.unite(i * m + j + 1, i * m + j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        set<int> vis;
        for (int j = 0; j < m; j++) {
            if (grids[i][j] == '#') {
                if (!vis.count(dsu.find(i * m + j))) {
                    vis.insert(dsu.find(i * m + j));
                    cnt += dsu.get_size(i * m + j);
                }

            } else {
                if (i > 0 && grids[i - 1][j] == '#' && !vis.count(dsu.find((i - 1) * m + j))) {
                    vis.insert(dsu.find((i - 1) * m + j));
                    cnt += dsu.get_size((i - 1) * m + j);
                }
                if (i < n - 1 && grids[i + 1][j] == '#' && !vis.count(dsu.find((i + 1) * m + j))) {
                    vis.insert(dsu.find((i + 1) * m + j));
                    cnt += dsu.get_size((i + 1) * m + j);
                }
                cnt += 1;
            }
        }
        ans = max(ans, cnt);
    }
    for (int j = 0; j < m; j++) {
        int cnt = 0;
        set<int> vis;
        for (int i = 0; i < n; i++) {
            if (grids[i][j] == '#') {
                if (!vis.count(dsu.find(i * m + j))) {
                    vis.insert(dsu.find(i * m + j));
                    cnt += dsu.get_size(i * m + j);
                }

            } else {
                if (j > 0 && grids[i][j - 1] == '#' && !vis.count(dsu.find(i * m + j - 1))) {
                    vis.insert(dsu.find(i * m + j - 1));
                    cnt += dsu.get_size(i * m + j - 1);
                }
                if (j < m - 1 && grids[i][j + 1] == '#' && !vis.count(dsu.find(i * m + j + 1))) {
                    vis.insert(dsu.find(i * m + j + 1));
                    cnt += dsu.get_size(i * m + j + 1);
                }
                cnt += 1;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}