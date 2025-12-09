#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

constexpr int inf = 1e9 + 1;

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> freqs;
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        freqs[x]++;
    }
    int cnt = 0;
    for (auto [x, c] : freqs) {
        cnt += c / 2;
    }
    if (cnt < 4) {
        std::cout << "NO\n";
        return ;
    }
    std::vector<int> ans(8);
    {
        int max = -inf;
        for (auto [x, cnt] : freqs) {
            if (cnt >= 2) {
                max = std::max(max, x);
            }
        }
        freqs[max] -= 2;
        ans[1] = max;
        ans[3] = max;
    }
    {
        int max = -inf;
        for (auto [x, cnt] : freqs) {
            if (cnt >= 2) {
                max = std::max(max, x);
            }
        }
        freqs[max] -= 2;
        ans[0] = max;
        ans[6] = max;
    }
    {
        int min = inf;
        for (auto [x, cnt] : freqs) {
            if (cnt >= 2) {
                min = std::min(min, x);
            }
        }
        freqs[min] -= 2;
        ans[2] = min;
        ans[4] = min;
    }
    {
        int min = inf;
        for (auto [x, cnt] : freqs) {
            if (cnt >= 2) {
                min = std::min(min, x);
            }
        }
        freqs[min] -= 2;
        ans[5] = min;
        ans[7] = min;
    }
    std::cout << "YES\n";

    for (int i = 0; i < 8; i++) {
        std::cout << ans[i] << " \n"[i == 7];
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