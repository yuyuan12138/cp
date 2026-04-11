#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1e15;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    i64 p;
    std::cin >> n >> p;
    std::vector<int> z(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> z[i] >> a[i] >> b[i];
    }
    i64 lo = 0, hi = inf;
    while (lo <= hi) {
        i64 x = lo + (hi - lo) / 2;
        i64 sum = 0;
        for (int i = 0; i < n; i++) {
            if (x > z[i]) {
                sum += i64(a[i]) * z[i] + i64(b[i]) * (x - z[i]);
            } else {
                sum += i64(a[i]) * x;
            }
            if (sum > inf) {
                break;
            }
        }
        if (sum >= p) {
            hi = x - 1;
        } else {
            lo = x + 1;
        }
    }
    std::cout << lo;
    return 0;
}
