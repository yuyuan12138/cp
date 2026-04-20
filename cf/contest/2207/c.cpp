/**
 *    author:  Yuyuan
 *    created: 2026-04-19 14:02:26
 **/
#include <bits/stdc++.h>

using i64 = long long;

// find the last element which greater than a[i], and l < i.
// the first one should contian all water above the dirts.
// the second one should find the most big set.

void solve() {
    int n, h;
    std::cin >> n >> h;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<i64> l(n + 1), r(n + 1);
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
