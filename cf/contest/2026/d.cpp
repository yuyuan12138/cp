#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<i64> pref_sum(n + 1);
    for (int i = 0; i < n; i++) {
        pref_sum[i + 1] = pref_sum[i] + a[i];
    }
    std::vector<i64> pref_pref(n + 1);
    i64 cur = 0;
    i64 cnt = 1;
    for (int i = n; i >= 1; i--) {
        cur += cnt * a[i - 1];
        pref_pref[i] = cur;
        cnt++;
    }
    std::vector<i64> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + pref_pref[i];
    }
    std::vector<int> size(n + 1);
    for (int i = 1; i <= n; i++) {
        size[i] = n - i + 1;
    }
    for (int i = 1; i <= n; i++) {
        size[i] += size[i - 1];
    }
    int q;
    std::cin >> q;
    while (q--) {
        i64 l, r;
        std::cin >> l >> r;
        int L, R;
        {
            int lo = 0, hi = n;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (size[mid] < l) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            L = lo;
        }
        {
            int lo = 0, hi = n;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (size[mid] < r) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            R = lo;
        }
        i64 ans = pref[R] - pref[L - 1];
        i64 size_r = size[R] - r;
        for (int i = 0; i < size_r; i++) {
            ans -= pref[n - i] - pref[R - 1];
        }
        i64 size_l = l - size[L - 1];
        for (int i = 0; i < size_l; i++) {
            ans -= pref[L + i] - pref[L - 1];
        }
        std::cout << ans << '\n';
    }
    return 0;
}
