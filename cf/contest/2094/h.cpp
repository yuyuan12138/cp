#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5;

std::vector<std::set<int>> divs(N + 1);

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    std::map<int, std::vector<int>> pos;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        pos[a[i]].push_back(i);
    }

    while (q--) {
        int k, l, r;
        std::cin >> k >> l >> r;
        l--, r--;
        i64 ans = 0;
        int cur = l;
        while (true) {
            int mn = n + 2;
            for (int div : divs[k]) {
                if (pos.count(div)) {
                    auto it = std::lower_bound(pos[div].begin(), pos[div].end(), cur);
                    if (it != pos[div].end()) {
                        mn = std::min(mn, *it - cur);
                    }
                }
            }
            if (mn == n + 2 || cur + mn > r) {
                ans += i64(r - cur + 1) * k;
                break;
            } else {
                ans += i64(mn) * k;
                while (k % a[cur + mn] == 0) {
                    k /= a[cur + mn];
                }
                cur += mn;
            }

        }
        std::cout << ans << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            divs[j].insert(i);
        }
    }
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
