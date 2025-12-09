#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    std::cin >> n;
    int cur = 501;
    std::cout << cur << " ";
    for (int i = 0; i < n - 1; i++) {
        int x;
        std::cin >> x;
        cur += x;
        std::cout << cur << " "; 
    }
    std::cout << '\n';
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