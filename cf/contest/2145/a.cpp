#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        for (int i = 0; i < 3; i++) {
            if ((n + i) % 3 == 0) {
                std::cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}