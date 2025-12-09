#include <bits/stdc++.h>

constexpr int N = 3;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n;
    std::cin >> n;
    std::vector<std::array<int, 3>> q(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> q[i][j];
        }
    }
    int ans = 0;
    for (int pos = 0; pos < N; pos++) {
        std::vector<int> at(N);
        at[pos] = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int a = q[i][0], b = q[i][1], c = q[i][2];
            a--, b--, c--;
            std::swap(at[a], at[b]);
            cnt += (at[c] == 1);
        }
        ans = std::max(ans, cnt);
    }
    std::cout << ans;
    return 0;
}
