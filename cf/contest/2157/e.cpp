#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> freqs(5 * n + 2);
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        freqs[x]++;
    }
    int ans = 0;
    int idx = 0;
    for (int x = 1; x <= 5 * n; x++) {
        if (freqs[x] > k) {
            freqs[x + 1] += freqs[x] - 1;
        } else {
            ans = std::max(ans, x - idx - 1);
            idx = x;            
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
    return 0;
}