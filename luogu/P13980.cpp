#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    std::vector<int> block(n);
    int B = std::sqrt(n);    
    std::vector<int> tag(n);
    std::vector<i64> sum(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        block[i] = i / B;
        sum[block[i]] += a[i];
    }
    auto add = [&](int l, int r) -> void {
        int bl = block[l], br = block[r];
        if (!tag[bl]) {
            for (int i = l; i <= std::min((bl + 1) * B - 1, r); i++) {
                sum[bl] -= a[i];
                a[i] = std::sqrt(a[i]);
                sum[bl] += a[i];
            }
        }
        if (bl != br && !tag[br]) {
            for (int i = br * B; i <= r; i++) {
                sum[br] -= a[i];
                a[i] = std::sqrt(a[i]);
                sum[br] += a[i];
            }
        }
        for (int i = bl + 1; i <= br - 1; i++) {
            if (tag[i] == 1) {
                continue;
            }
            i64 max = 0;
            i64 s = 0;
            for (int j = i * B; j <= (i + 1) * B - 1; j++) {
                a[j] = std::sqrt(a[j]);
                max = std::max(max, a[j]);
                s += a[j];
            }
            sum[i] = s;
            if (max <= 1) {
                tag[i] = 1;
            }
        }
    };
    auto query = [&](int l, int r) -> i64 {
        i64 ans = 0;
        int bl = block[l], br = block[r];
        for (int i = l; i <= std::min((bl + 1) * B - 1, r); i++) {
            ans += a[i];
        }
        if (bl != br) {
            for (int i = br * B; i <= r; i++) {
                ans += a[i];
            }
        }
        for (int i = bl + 1; i <= br - 1; i++) {
            ans += sum[i];
        }
        return ans;
    };
    for (int i = 0; i < n; i++) {
        int op, l, r;
        std::cin >> op >> l >> r;
        l--, r--;
        if (op == 0) {
            add(l, r);
        } else {
            std::cout << query(l, r) << '\n';
        }
    }
    return 0;
}