#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (a[i] % k != a[i - 1] % k) {
            ok = false;
        }
    }

    if (ok) {
        int mx = *max_element(a.begin(), a.end());
        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            ans += 1ll * (mx - a[i]) / k;
        }
        std::cout << "YES " << ans;
    } else {
        std::cout << "NO";
    }
    

    return 0;
}