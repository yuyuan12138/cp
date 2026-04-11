#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    int win = n;
    int loss = 0;
    int cnt = 0;
    while (!(loss == 1 && win == 1)) {
        cnt += loss / 2;
        cnt += win / 2;
        loss -= loss / 2;
        loss += win / 2;
        win -= win / 2;
    }
    std::cout << cnt + 1 << '\n';
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
