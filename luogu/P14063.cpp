#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, b;
    std::cin >> n >> b;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int ans = 0;
    int cur = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && cur + a[j] <= b) {
            cur += a[j];
            j++;
        }
        ans = std::max(j - i, ans);
        cur -= a[i];
    }
    std::cout << ans;

    return 0;
}
