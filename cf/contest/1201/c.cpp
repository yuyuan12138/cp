#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>

using ll = long long;

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
    
    auto check = [&](int x) {
        ll tot = 0;
        for (int i = 0; i < n; i++) {
            if (i >= n / 2) {
                tot += std::max(0, x - a[i]);
            }
        }
        return tot <= k;
    };

    int l = 0, r = 2e9;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    std::cout << r;
    return 0;
}