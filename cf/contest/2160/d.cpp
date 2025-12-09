#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    auto ask = [](const std::vector<int>& q) -> int {
        std::cout << "? ";
        std::cout << q.size() << " ";
        for (int x : q) {
            std::cout << x + 1 << ' ';
        }
        std::cout << std::endl;
        int x;
        std::cin >> x;
        return x;
    };
    std::vector<int> ans(2 * n);
    std::vector<int> queries;
    std::set<int> found;
    for (int i = 0; i < 2 * n; i++) {
        queries.push_back(i);
        int x = ask(queries);
        if (x != 0) {
            ans[i] = x;
            found.insert(i);
            queries.pop_back();
        }
    }
    for (int i = 0; i < 2 * n; i++) {
        if (ans[i] == 0) {
            found.insert(i);
            int x = ask(std::vector<int>(found.begin(), found.end()));
            ans[i] = x;
            found.erase(i);
        }
    }    
    std::cout << "! ";
    for (int i = 0; i < 2 * n; i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
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