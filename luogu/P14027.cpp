#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b, k;
    int ans = 0;
    std::cin >> a >> b >> k;
    while (a < b) {
        if (a + k > a * k) {
            a += k;
        } else {
            a *= k;
        }
        ans++;
    }

    std::cout << ans;
    return 0;
}

