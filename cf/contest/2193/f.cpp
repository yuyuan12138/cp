/**
 *    author:  Yuyuan
 *    created: 2026-04-12 16:01:35
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, Ax, Ay, Bx, By;
    std::cin >> n >> Ax >> Ay >> Bx >> By;
    std::map<int, std::vector<int>> mp;
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> y[i];
    }
    for (int i = 0; i < n; i++) {
        mp[x[i]].push_back(y[i]);
    }
    std::vector<i64> f(2);
    int last = Ax;
    mp[Ax].push_back(Ay);
    mp[Bx].push_back(By);
    for (auto &[x, yl] : mp) {
        std::sort(yl.begin(), yl.end());
        int tot = yl.back() - yl[0] + x - last;
        auto nf = f;
        nf[0] = std::min(f[0] + std::abs(mp[last][0] - yl.back()) + tot,
                         f[1] + std::abs(mp[last].back() - yl.back()) + tot);
        nf[1] = std::min(f[0] + std::abs(mp[last][0] - yl[0]) + tot,
                         f[1] + std::abs(mp[last].back() - yl[0]) + tot);
        last = x;
        f = nf;
    }
    std::cout << std::min(f[0], f[1]) << '\n';
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
