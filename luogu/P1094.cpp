#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int w, n;
    std::cin >> w >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    int ans = 0;
    while (l <= r) {
        if (l == r) {
            ans++;
            break;
        } else {
            if (a[r] + a[l] > w) {
                ans++;
                r--;
            } else {
                ans++;
                l++, r--;
            }
        }
    }
    std::cout << ans;
    return 0;
}
