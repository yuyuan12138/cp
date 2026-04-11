#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>

using ll = long long;

void solve() {
    ll p, q;
    std::cin >> p >> q;
    if (p >= q) {
        std::cout << "Alice\n";
    } else {
        if ((q - p) * 3 <= q) {
            std::cout << "Bob\n";
        } else {
            std::cout << "Alice\n";
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