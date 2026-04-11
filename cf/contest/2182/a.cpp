#include <bits/stdc++.h>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    bool ok1 = false, ok2 = false;
    for (int i = 3; i < n; i++) {
        if (s[i - 3] == '2' && \
            s[i - 2] == '0' && \
            s[i - 1] == '2' && \ 
            s[i] == '6') {
            ok1 = true;
        }
        if (s[i - 3] == '2' && \
            s[i - 2] == '0' && \
            s[i - 1] == '2' && \ 
            s[i] == '5') {
            ok2 = true;
        }
    }
    if (ok1 && ok2) {
        std::cout << 0 << '\n';
    } else if (ok1) {
        std::cout << 0 << '\n';
    } else if (ok2) {
        std::cout << 1 << '\n';
    } else {
        std::cout << 0 << '\n';
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