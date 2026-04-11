#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n, k;
    std::cin >> n >> k;
    int last = n * (n - 1) / 2 - k;
    

    std::vector<std::bitset<500>> f(n + 1);

    f[0][0] = 1;

    std::map<std::pair<int, int>, int> pre;
    int mx = last;

    for (int i = 0; i <= n; i++) {
        for (int bit = 1; i + bit <= n; bit++) {
            std::bitset<500> nb = (f[i] << (bit * (bit - 1) / 2)) & (~f[i + bit]);
            for (int s = 0; s <= mx; s++) {
                if (nb[s]) {
                    pre[{i + bit, s}] = bit;
                }
            }
            f[i + bit] |= (f[i] << (bit * (bit - 1) / 2));
        }
    }

    if (!f[n][last]) {
        std::cout << 0 << '\n';
    } else {
        std::vector<int> p;
        int idx = n, cur = last;
        // return ;
        while (idx > 0) {
            int tmp = pre[{idx, cur}];
            p.push_back(tmp);
            idx -= tmp;
            cur -= tmp * (tmp - 1) / 2;
        }

        std::reverse(p.begin(), p.end());
        std::vector<int> ans;
        cur = n;
        for (int pp : p) {
            for (int x = cur - pp + 1; x <= cur; x++) {
                ans.push_back(x);
            }
            cur -= pp;
        }
        for (int i = 0; i < n; i++) {
            std::cout << ans[i] << " \n"[i == n - 1];
        }
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}