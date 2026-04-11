#include <bits/stdc++.h>

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1);
    while (q--) {
        int x, y;
        std::cin >> x >> y;
        int num = x / n;
        a[0] += num;
        a[n] -= num;
        int rem = x % n;
        a[y]++;
        if (rem + y > n - 1) {
            a[0]++;
            a[n]--;
            a[(rem + y) % n]--;
        } else {
            a[rem + y]--;
        }
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
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
