#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    auto get = [](const int op, int l, int r) -> i64 {
        std::cout << op << " " << l + 1 << " " << r + 1 << std::endl;
        i64 x;
        std::cin >> x;
        return x;
    };
    i64 tot = get(2, 0, n - 1) - get(1, 0, n - 1);
    int l, r;
    {
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            i64 x = get(1, 0, mid);
            i64 y = get(2, 0, mid);
            if (x == y) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        l = lo;
    }
    r = tot + l - 1;
    std::cout << "! " << l + 1 << " " << r + 1 << std::endl;
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
