#include <bits/stdc++.h>

constexpr int T = 1e4;
void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    std::string s;
    std::cin >> s;
    bool ok = false;
    int x = 0, y = 0;
    for (int i = 0; i < T; i++) {
        if (ok) {
            break;
        } 
        for (int j = 0; j < n; j++) {
            if (s[j] == 'N') {
                y++;
            } else if (s[j] == 'E') {
                x++;
            } else if (s[j] == 'S') {
                y--;
            } else {
                x--;
            }
            if (x == a && y == b) {
                ok = true;
            }
        }
        if (ok) {
            break;
        }
    } 
    std::cout << (ok ? "YES\n" : "NO\n");
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
