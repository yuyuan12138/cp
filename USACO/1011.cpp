#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> v(n);
    std::map<int, std::set<int>> x, y;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        x[a].insert(b);
        y[b].insert(a);
        v[i][0] = a, v[i][1] = b;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a = v[i][0], b = v[i][1];
        int max_a = std::max(*x[a].rbegin() - b, b - *x[a].begin());
        int max_b = std::max(*y[b].rbegin() - a, a - *y[b].begin());
        ans = std::max(max_a * max_b, ans);
    }
    std::cout << ans;
    return 0;
}