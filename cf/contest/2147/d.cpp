#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    i64 tot = std::accumulate(a.begin(), a.end(), 0LL);
    i64 ans = 0;
    int flag = 1;
    std::vector<int> b;
    for (int l = 0, r = 0; l < n; l = r) {
        while (r < n && a[l] == a[r]) {
            r++;
        }
        if (a[l] % 2 == 1) {
            b.push_back(r - l);
            for (int j = l; j < r; j++) {
                a[j]--;
            }
        }
    }
    std::sort(b.rbegin(), b.rend());
    for (int x : b) {
        if (flag) {
            ans += x;
        }
        flag ^= 1;
    }
    for (int l = 0, r = 0; l < n; l = r) {
        while (r < n && a[l] == a[r]) {
            r++;
        }
        ans += i64(a[l]) / 2 * (r - l);
    }
    std::cout << ans << " " << tot - ans << '\n';
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
