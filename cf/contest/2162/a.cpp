#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int tot = 0;
            for (int k = i; k <= j; k++) {
                tot += a[i];
            }
            ans = std::max(ans, tot / (j - i + 1));
        }
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
