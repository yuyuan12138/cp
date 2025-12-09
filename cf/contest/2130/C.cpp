/**
 *      author:  yuyuan567
 *      created: 2025-07-31 22:58:55
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
    const int N = 1e4;
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> idxs(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        idxs[i] = i;
    }
    sort(idxs.begin() + 1, idxs.end(), [&](int x, int y) { return b[x] - a[x] > b[y] - a[y]; });
    DSU dsu(N);
    vector<int> ans;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int idx = idxs[i];
        if (!dsu.connected(a[idx], b[idx])) {
            dsu.unite(a[idx], b[idx]);
            ans.push_back(idx);
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << "\n";
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