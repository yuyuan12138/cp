#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

constexpr int inf = 1e9;

void solve() {
    int n, k, q;
    std::cin >> n >> k >> q;
    std::vector<std::array<int, 2>> note(n + 1);
    for (int i = 0; i < q; i++) {
        int c, l, r;
        std::cin >> c >> l >> r;
        l--, r--;
        c--;
        note[l][c] += 1;
        note[r + 1][c] -= 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            note[i][j] += note[i - 1][j];
        }
    }
    std::vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (!((note[i][0] > 0) ^ (note[i][1] > 0))) {
            ans[i] = inf;
        } else {
            if (note[i][0]) {
                ans[i] = k;
            } 
        }
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if ((i == 0 || ans[i - 1] == inf) && (ans[i] == -1)) {
            cur = 0;
            ans[i] = cur;
        } else if (ans[i] == -1) {
            cur++;
            if (cur == k) {
                cur = 0;
            }
            ans[i] = cur;
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
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