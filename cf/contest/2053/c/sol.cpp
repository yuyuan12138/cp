#include <bits/stdc++.h>

void solve(){
    int n, k;
    std::cin >> n >> k;
    if (k == 1) {
        std::cout << 1LL * (1 + n) * n / 2 << '\n';
    } else {
        int64_t ans = 0;
        int64_t mul = n + 1, sum = 0, cur = 1;
        while (n >= k) {
            if (n % 2 == 1) {
                sum += cur;
            }
            n >>= 1;
            cur <<= 1;
        }
        std::cout << mul * sum / 2 << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t; std::cin >> t;
    while(t--) solve();
    return 0;
}
