#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    std::vector<int> a;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            a.push_back(i);
        }
    }
    if (a.empty()) {
        std::cout << "0\n";
    } else {
        n = a.size();
        int ans = 0;
        for (int i = 0, j = 0; j < n; i = j) {
            while (j < n && a[j] - a[i] + 1 <= k) {
                j++;
            }
            ans++;
        }
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
