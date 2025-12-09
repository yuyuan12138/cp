#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s, t;
    std::cin >> s >> t;
    int ans = 0;
    for (int j = 0, i = 0; j < m; j++) {
        if (t[j] == s[i]) {
            i++;
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