#include <bits/stdc++.h>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    bool b1 = false, b2 = false;
    for (int i = 1; i < n; i++) {
        if (s[i] == '1' && s[i - 1] == '0') {
            b1 = true;
        }
        if (s[i] == '0' && s[i - 1] == '1') {
            b2 = true;
        }
    }
    if ((b1 && b2) || (!b1 && !b2)) {
        std::cout << 1 << '\n';
    } else {
        std::cout << 2 << '\n';
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
