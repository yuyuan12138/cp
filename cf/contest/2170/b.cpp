#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int cnt = 0;
    int max = 0;
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        cnt += (a[i] > 0);
        max = std::max(max, a[i]);
        sum += a[i];
    }
    std::cout << std::min(i64(cnt), sum - n + 1) << '\n';
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