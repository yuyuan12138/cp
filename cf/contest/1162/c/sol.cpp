#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int lo = 1, hi = 2e9;
    auto check = [&](const int x) -> bool {
        int cnt = 0;
        int64_t sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < x && cnt >= n / 2) {
                sum += (x - a[i]);
            } else if (a[i] < x) {
                cnt++;
            }
        }
        if (sum <= k) {
            return true;
        } else {
            return false;
        }
    };
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    std::cout << hi;
    return 0;
}
