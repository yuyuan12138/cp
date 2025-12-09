#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n), b(n);
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0] >> a[i][1];
        ans += a[i][1] - a[i][0];
        b[i][0] = a[i][1] + a[i][0];
        b[i][1] = i;
        ans += a[i][1];
    }
    std::sort(
        b.begin(), b.end(),
        [](const std::array<int, 2>& a, const std::array<int, 2>& b) -> bool {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            } else {
                return a[0] < b[0];
            }
        });
    std::set<int> st;
    for (int i = 0; i < n / 2; i++) {
        ans -= b[i][0];
        st.insert(b[i][1]);
    }
    if (n % 2 == 0) {
        std::cout << ans << '\n';
    } else {
        int64_t add = INT64_MIN;
        for (int i = 0; i < n; i++) {
            if (st.contains(i)) {
                add = std::max(add, int64_t(a[i][0]) + a[i][1] - b[n / 2][0] - a[i][1]); 
            } else {
                add = std::max(add, 0LL - a[i][1]);
            }
        } 
        std::cout << ans + add << '\n';
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
