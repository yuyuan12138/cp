#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int last = n - i * 2;
        if (last % 4 == 0 && last >= 0) {
            ans++;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    } 
}
