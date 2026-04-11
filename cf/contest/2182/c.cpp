#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    i64 ans = n;
    {
        int cnt = 0;
        for (int k = 0; k < n; k++) {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (c[i] <= b[(i + k) % n]) {
                    ok = false;
                } 
            }
            cnt += ok;
        }
        ans *= cnt;
    }
    {
        int cnt = 0;
        for (int k = 0; k < n; k++) {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (b[i] <= a[(i + k) % n]) {
                    ok = false;
                } 
            }
            cnt += ok;
        }
        ans *= cnt;
    }
    std::cout << ans << '\n';

    return ;
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