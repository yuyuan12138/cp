#include <bits/stdc++.h>

void solve() {
    int n, h, l;
    std::cin >> n >> h >> l;
    int cnt1 = 0, cnt2 = 0;
    int min = std::min(h, l), max = std::max(h, l);
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        if (x <= min) {
            cnt1++;
        } else if (x <= max) {
            cnt2++;
        }
    }
    std::cout << std::min(cnt1, cnt2) + (std::max(0, cnt1 - cnt2) / 2) << '\n';    
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