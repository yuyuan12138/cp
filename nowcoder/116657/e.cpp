#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<i64, int>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    std::sort(a.begin(), a.end());
    std::vector<int> ans(n, -1);

    int cur = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[i].first % a[j].first != 0) {
                ans[a[i].second] = a[j].second + 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
