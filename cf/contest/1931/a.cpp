#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    int N = 26;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            for (int k = j; k <= N; k++) {
                if (i + j + k == n) {
                    std::cout << char('a' + i - 1);
                    std::cout << char('a' + j - 1);
                    std::cout << char('a' + k - 1);
                    std::cout << '\n';
                    return;
                }
            }
        }
    }
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
