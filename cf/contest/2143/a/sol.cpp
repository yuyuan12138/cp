#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int idx = -1;
    int cur = n - 1;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] == n) {
            idx = i;
        }
    }
    int l = idx, r = idx;
    while (l >= 0 || r <= n - 1) {
        bool ok = false;
        if (l > 0 && a[l - 1] == cur) {
            l--;
            cur--;
            ok = true;
        } else if (r < n - 1 && a[r + 1] == cur) {
            r++;
            cur--;
            ok = true;
        }
        if (!ok) {
            break;
        }
    }
    if (l == 0 && r == n - 1) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
