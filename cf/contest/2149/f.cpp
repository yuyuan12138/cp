#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int h, d;
    std::cin >> h >> d;
    int lo = 0, hi = d;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int a = d / (mid + 1);
        i64 need = i64(a) * (a + 1) / 2 * (mid + 1);
        need += (a + 1) * (d % (mid + 1));
        if (need < h + mid) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    std::cout << d + lo << '\n';
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