#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
    const int n = s.size();
    int cur = 0;
    int ans = 0;
    
    if (s[0] == 'u') {
        ans++;
        s[0] = 's';
    }
    if (s[n - 1] == 'u') {
        ans++;
        s[n - 1] = 's';
    }
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'u') {
            cur++;
        } else {
            ans += cur / 2;
            cur = 0;
        }
    }
    ans += cur / 2;
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