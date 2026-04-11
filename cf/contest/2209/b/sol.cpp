#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int cnt0 = 0, cnt1 = 0;
        for (int j = i + 1; j < n; j++) {
            cnt0 += (a[j] > a[i]);
            cnt1 += (a[j] < a[i]);
        }
        std::cout << std::max(cnt0, cnt1) << " \n"[i == n];
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
