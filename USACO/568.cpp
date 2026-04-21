#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> limit(100);
    int st = 0;
    while (n--) {
        int x, l;
        std::cin >> x >> l;
        for (int y = st; y < st + x; y++) {
            limit[y] = l;
        }
        st += x;
    }
    int ans = 0;
    st = 0;
    while (m--) {
        int x, sp;
        std::cin >> x >> sp;
        for (int y = st; y < st + x; y++) {
            if (limit[y] < sp) {
                ans = std::max(ans, sp - limit[y]);
            }
        }
        st += x;
    }
    std::cout << ans;
}
