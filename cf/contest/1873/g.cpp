#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            cnt++;
        }
    }
    if (s[0] == 'B' && s[n - 1] == 'B') {
        std::cout << cnt << '\n';
    } else {
        int mn = INT32_MAX;
        int i;
        if (s[0] == 'B') {
            i = 0;
        } else {
            i = -1;
        }
        for (int j = 0; i < n; i = j++) {
            while (j < n && s[j] != 'B') {
                j++;
            }
            mn = std::min(mn, std::max(0, j - i - 1));
        }
        std::cout << cnt - mn << '\n';
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
