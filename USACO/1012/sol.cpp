#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::string s, t;
    std::cin >> n >> s >> t;
    int ans = 0;
    bool is_same = (s[0] == t[0]);

    for (int i = 1; i < n; i++) {
        ans += (is_same ^ (s[i] == t[i]));
        is_same = (s[i] == t[i]);
    }
    std::cout << ans << '\n';

    return 0;
}
