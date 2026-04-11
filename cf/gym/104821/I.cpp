#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> ops(m);
    for (int i = 0; i < m; i++) {
        std::cin >> ops[i].first >> ops[i].second;
    }
    ops.push_back({0, 0});
    std::sort(ops.begin(), ops.end());
    m = m + 1;
    bool ok = true;
    for (int i = 1; i < m; i++) {
        int prev_x = ops[i - 1].first, prev_y = ops[i - 1].second;
        int x = ops[i].first, y = ops[i].second;
        int d = x - prev_x;
        if (d - 1 < y) {
            if (d != y - prev_y) {
                ok = false;
            }
        }
        if (x < y) {
            ok = false;
        }
    }
    std::cout << (ok ? "Yes\n" : "No\n");
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

