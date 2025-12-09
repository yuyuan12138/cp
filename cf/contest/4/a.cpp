#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    if (n <= 2 || n % 2 == 1) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
