#include <bits/stdc++.h>

using i64 = long long;

i64 helper(std::vector<int>& a, int k, int l, int r) {
    int n = a.size();
    std::vector<int> b = a;
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());
    std::map<int, int> mp;
    for (int i = 0; i < b.size(); i++) {
        mp[b[i]] = i;
    }
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = mp[a[i]];
    }

    std::vector<int> cnt(b.size());
    int dis = 0;
    int R = -1;
    i64 res = 0;

    for (int L = 0; L < n; L++) {
        while (R + 1 < n) {
            int idx = c[R + 1];
            if (cnt[idx] == 0 && dis + 1 > k) break;
            R++;
            if (cnt[idx] == 0) dis++;
            cnt[idx]++;
        }
        int lo = L + l - 1;
        int hi = std::min(L + r - 1, R);
        if (hi >= lo) res += (i64)(hi - lo + 1);
        int idxL = c[L];
        cnt[idxL]--;
        if (cnt[idxL] == 0) dis--;
    }
    return res;
}

void solve() {
    int n, k, l, r;
    std::cin >> n >> k >> l >> r;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    i64 ans = helper(a, k, l, r) - helper(a, k - 1, l, r);
    std::cout << ans << '\n';
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
