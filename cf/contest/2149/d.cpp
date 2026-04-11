#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> a, b;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    if (a.size() == 0 || b.size() == 0) {
        std::cout << 0 << '\n';
    } else {
        i64 ans = INT64_MAX;
        n = a.size();
        int m = b.size();
        i64 cnt = 0;
        for (int i = 0; i < n / 2; i++) {
            cnt += a[n / 2] - a[i] - (n / 2 - i);
        }
        std::cerr << "cnt: " << cnt << '\n';
        for (int i = n / 2 + 1; i < n; i++) {
            cnt += a[i] - a[n / 2] - (i - n / 2);
        }
        std::cerr << "cnt: " << cnt << '\n';
        ans = std::min(ans, cnt);
        cnt = 0;
        for (int i = 0; i < m / 2; i++) {
            cnt += b[m / 2] - b[i] - (m / 2 - i);
        }
        std::cerr << "cnt: " << cnt << '\n';
        for (int i = m / 2 + 1; i < m; i++) {
            cnt += b[i] - b[m / 2] - (i - m / 2);
        }
        std::cerr << "cnt: " << cnt << '\n';
        ans = std::min(ans, cnt);
        std::cout << ans << '\n';
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
