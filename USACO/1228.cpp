#include <bits/stdc++.h>

constexpr int inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> g;
    std::vector<int> l;
    for (int i = 0; i < n; i++) {
        char c;
        int x;
        std::cin >> c >> x;
        if (c == 'G') {
            g.push_back(x);
        } else {
            l.push_back(x);
        }
    }
    std::sort(g.begin(), g.end());
    std::sort(l.begin(), l.end());
    int ans = 1e9;
    if (g.size() == 0 || l.size() == 0) {
        std::cout << 0;
    } else {
        for (int i = 0; i < g.size(); i++) {
            int x = g[i];
            int cnt = g.size() - i - 1;
            auto idx = std::lower_bound(l.begin(), l.end(), x);
            if (idx == l.begin()) {
                ans = std::min(cnt, ans);
            } else {
                cnt += int(idx - l.begin());
                ans = std::min(cnt, ans);                
            }
        }
        for (int i = 0; i < l.size(); i++) {
            int x = l[i];
            int cnt = i;
            auto idx = std::upper_bound(g.begin(), g.end(), x);
            cnt += int(g.end() - idx);
            ans = std::min(ans, cnt);
        }
        std::cout << ans;
    }
}