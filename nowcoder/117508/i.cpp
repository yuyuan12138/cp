#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

constexpr int V = 2e7 + 5;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::map<int, std::vector<int>> posa, posb;

    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        posa[x].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        int x;
        std::cin >> x;
        posb[x].push_back(i);
    }

    bool flaga = false, flagb = false;
    std::vector<std::pair<int, int>> a, b;
    std::pair<int, int> ansa, ansb;
    for (auto& [val, pos] : posa) {
        if (pos.size() > 0) {
            a.emplace_back(val, pos[0]);
            if (pos.size() > 1) {
                flaga = true;
                ansa = {pos[0], pos[1]};
            }
        }
    }
    for (auto& [val, pos] : posb) {
        if (pos.size() > 0) {
            b.emplace_back(val, pos[0]);
            if (pos.size() > 1) {
                flagb = true;
                ansb = {pos[0], pos[1]};
            }
        }
    }

    if (flaga && flagb) {
        std::cout << ansa.first + 1 << " " << ansa.second + 1 << " " << ansb.first + 1 << " " << ansb.second + 1;
        return 0;
    }

    bool ok = false;
    std::vector<int> ans(4);
    std::vector<std::pair<int, int>> pos(V, {-1, -1});

    n = a.size();
    m = b.size();

    b.resize(std::min(b.size(), size_t(V + n - 1) / n));

    for (auto& [vala, pos_a] : a) {
        if (ok) {
            break;
        }
        for (auto& [valb, pos_b] : b) {
            if (ok) {
                break;
            }
            int val = vala + valb;
            if (pos[val].first != -1 && pos[val].first != pos_a && pos[val].second != pos_b) {
                ans[0] = pos[val].first, ans[2] = pos[val].second;
                ans[1] = pos_a, ans[3] = pos_b;
                ok = true;
            }
            pos[val] = {pos_a, pos_b};
        }
    }
    if (ok) {
        for (int i = 0; i < 4; i++) {
            std::cout << ans[i] + 1 << " ";
        }
    } else {
        std::cout << -1;
    }
    return 0;
}