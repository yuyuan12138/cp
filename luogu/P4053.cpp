#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    auto cmp = [](auto a, auto b) -> bool { 
        if (a[0] == b[0]) {
            return a[1] > b[1];
        } else {
            return a[0] > b[0];
        }
    };
    std::priority_queue<std::array<int, 2>, std::vector<std::array<int, 2>>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < n; i++) {
        int t1, t2;
        std::cin >> t1 >> t2;
        pq.push({t1, t2});
    }
    int cur = 0;
    int ans = 0;
    while (!pq.empty()) {
        auto [t1, t2] = pq.top();
        pq.pop();
        if (t1 + cur > t2) {
            continue;
        } else {
            cur += t1;
            ans++;
        }
    }
    std::cout << ans;
    return 0;
}