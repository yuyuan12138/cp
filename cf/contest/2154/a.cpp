#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::string s;
    std::cin >> n >> k;
    std::cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < k - 1; j++) {
            if (i - j - 1 >= 0 && s[i - j - 1] == '1') {
                ok = false;
            }
        }
        if (ok && s[i] == '1') {
            ans++;
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
