#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, t;
    std::cin >> n >> t;
    auto ask = [](const int l, const int r) -> int {
        int x;
        std::cout << "? " << l << " " << r << std::endl;
        std::cin >> x;
        return x;
    };
    std::vector<int> a(n + 1, -1);
    while (t--) {
        int k;
        std::cin >> k;
        auto check = [&](const int ed) -> bool {
            int cnt;
            if (a[ed] != -1) {
                cnt = a[ed];
            } else {
                cnt = ask(1, ed);
                a[ed] = cnt;
            }
            if (ed - cnt < k) {
                return true;
            } else {
                return false;
            }
        };
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        std::cout << "! " << lo << std::endl;
    }
    return 0;
}
