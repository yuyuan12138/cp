#include <bits/stdc++.h>

constexpr int inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int ans = 0;
    
    int max = -inf, cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur - max < 0) {
            cur = 0;
            max = 0;
        }
        max = std::max(a[i], max);
        cur += a[i];
        ans = std::max(ans, cur - max);
    } 
    

    
    std::cout << ans;
    return 0;
}