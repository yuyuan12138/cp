#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 rand_num(seed);
    int n;
    std::cin >> n;
    std::uniform_int_distribution<int> dist(1, n);
    auto query = [](int u, int v) -> int {
        std::cout << u << " " << v << std::endl;
        int x;
        std::cin >> x;
        return x;
    };
    while (true) {
        int u = dist(rand_num);
        int v;
        while (true) {
            v = dist(rand_num);
            if (v != u) {   
                break;
            }
        }
        int x = query(u, v);
        if (x == 1) {
            return ;
        }
    }
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
