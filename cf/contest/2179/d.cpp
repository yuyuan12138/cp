#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    int max = ((1 << n) - 1);
    int cur = ((1 << n) - 1);
    int idx = n - 1;

    while (idx != -2) {
        std::cout << cur << ' ';
        for (int val = cur + (1 << (idx + 2)); val <= std::min(max, (max ^ (1 << (idx + 1)))); val += (1 << (idx + 2))) {
            std::cout << val << ' ';
        }
        if (idx >= 0) {
            cur ^= (1 << idx);
        }
        idx--;
    }
    std::cout << '\n';
    return ;
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