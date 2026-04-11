#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    auto get = [](const int i, int x) -> int {
        std::cout << "? " << (i + 1) << " " << x << std::endl;
        int g;
        std::cin >> g;
        return g;
    };
    std::set<int> ans;
    for (int i = 1; i <= n; i++) {
        ans.insert(i);
    }
    std::set<int> idx;
    for (int i = 0; i < n - 1; i++) {
        idx.insert(i);
    }
    int bit = 0;
    while (idx.size() > 0) {
        int cur0 = 0, cur1 = 0;
        for (int x : ans) {
            if ((1 << bit) & x) {
                cur1++;
            } else {
                cur0++;
            }
        }
        int cnt0 = 0, cnt1 = 0;
        std::vector<std::vector<int>> vec(2);
        for (int i : idx) {
            int got = get(i, (1 << bit));
            if (got == 0) {
                cnt0++;
                vec[0].push_back(i);
            } else {
                vec[1].push_back(i);
                cnt1++;
            }
        }
        if (cnt0 < cur0) {
            for (int i : vec[1]) {
                idx.erase(idx.find(i));
            }
            std::vector<int> tmp(ans.begin(), ans.end());
            for (int x : tmp) {
                if (x & (1 << bit)) {
                    ans.erase(ans.find(x));
                }
            }
        } else {
            for (int i : vec[0]) {
                idx.erase(idx.find(i));
            }
            std::vector<int> tmp(ans.begin(), ans.end());
            for (int x : tmp) {
                if (!(x & (1 << bit))) {
                    ans.erase(ans.find(x));
                }
            }
        }
        bit++;
    }
    std::cout << "! " << *ans.begin() << std::endl;
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
