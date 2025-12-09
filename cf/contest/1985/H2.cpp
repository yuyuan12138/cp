/**
 *      author:  yuyuan567
 *      created: 2025-08-02 19:34:02
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
using ull = unsigned long long;

// how to get the insection of col c and row r ?

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
    vector<int> er(n), ec(m);
    vector<int> Mx(n * m, -1), mx(n * m, n), My(n * m, -1), my(n * m, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grids[i][j] == '.') {
                er[i]++;
                ec[j]++;
            } else {
                int u = dsu.find(i * m + j);
                Mx[u] = max(Mx[u], min(n - 1, i + 1));
                mx[u] = min(mx[u], max(0, i - 1));
                My[u] = max(My[u], min(m - 1, j + 1));
                my[u] = min(my[u], max(0, j - 1));
            }
        }
    }

    vector<vector<int>> f(n, vector<int>(m));
    for (int i = 0; i < n * m; i++) {
        if (dsu.find(i) == i && grids[i / m][i % m] == '#') {
            int sz = dsu.get_size(i);
            f[mx[i]][my[i]] -= sz;
            f[mx[i]][0] += sz;
            f[0][my[i]] += sz;
            if (My[i] + 1 < m) {
                f[mx[i]][My[i] + 1] += sz;
                f[0][My[i] + 1] -= sz;
            }
            if (Mx[i] + 1 < n) {
                f[Mx[i] + 1][my[i]] += sz;
                f[Mx[i] + 1][0] -= sz;
                if (My[i] + 1 < m) {
                    f[Mx[i] + 1][My[i] + 1] -= sz;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            f[i][j] += f[i][j - 1];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f[i][j] += f[i - 1][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int res = er[i] + ec[j] + f[i][j] - (grids[i][j] == '.');
            ans = max(ans, res);
        }
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