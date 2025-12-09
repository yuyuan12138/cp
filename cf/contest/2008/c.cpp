#include <bits/stdc++.h>

void solve() {
    int l, r;
    std::cin >> l >> r;
    int cnt = 1;
    int i = l, j = l + 1;
    while (j <= r) {
        cnt++; 
        int c = j - i + 1;
        i = j;
        j += c;
    }
    std::cout << cnt << '\n';
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
