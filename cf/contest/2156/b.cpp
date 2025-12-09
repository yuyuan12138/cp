#include <bits/stdc++.h>

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    if (s.find("B") == -1) {
        while (q--) {
            int x;
            std::cin >> x;
            std::cout << x << '\n';
        }
    } else {
        while (q--) {
            int x;
            std::cin >> x;
            int ans = 0;
            int cur = 0;
            while (x) {
                if (cur == n) {
                    cur = 0;
                }
                ans += 1;
                if (s[cur] == 'A') {
                    x--;
                } else {
                    x /= 2;
                }
                cur++;
            }
            std::cout << ans << '\n';    
        }
        
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