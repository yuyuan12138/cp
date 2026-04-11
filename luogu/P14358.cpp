#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n * m);
    for (int i = 0; i < n * m; i++) {
        std::cin >> a[i];
    }
    int x = a[0];
    std::sort(a.begin(), a.end());
    int idx = 0;
    for (int i = 0; i < n * m; i++) {
        if (a[i] == x) {
            idx = i;
        }
    }
    int res = idx / n + 1;
    int rem = (idx + 1) % n;
    if (res % 2 == 1) {
        std::cout << rem << " " << res;
    }
    return 0;
}
