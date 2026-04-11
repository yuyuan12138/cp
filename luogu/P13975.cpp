#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t, c1, c2;
    std::cin >> t >> c1 >> c2;
    int val1 = t / 60 * 60 * c1;
    int val2 = (t * c2 + 99) / 100 * 100;

    std::cout << std::min(val1, val2);

    return 0;
}

