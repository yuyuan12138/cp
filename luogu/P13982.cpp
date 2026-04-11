#include <bits/stdc++.h>
using i64 = long long;
const int MOD = 10007;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    std::vector<int> block(n);
    int B = std::sqrt(n);
    std::vector<std::array<i64, 2>> tag(n, {1, 0});
    for (int i = 0; i < n; i++) std::cin >> a[i];

    for (int i = 0; i < n; i++) block[i] = i / B;

    auto add = [&](int l, int r, int c) -> void {
        c %= MOD;
        int bl = block[l], br = block[r];
        for (int i = bl * B; i <= std::min((bl + 1) * B - 1, n - 1); i++) {
            a[i] = (tag[bl][0] * a[i] + tag[bl][1]) % MOD;
        }
        tag[bl][0] = 1; tag[bl][1] = 0;
        for (int i = l; i <= std::min((bl + 1) * B - 1, r); i++) {
            a[i] = (a[i] + c) % MOD;
        }
        if (bl != br) {
            for (int i = br * B; i <= std::min((br + 1) * B - 1, n - 1); i++) {
                a[i] = (tag[br][0] * a[i] + tag[br][1]) % MOD;
            }
            tag[br][0] = 1; tag[br][1] = 0;
            for (int i = br * B; i <= r; i++) {
                a[i] = (a[i] + c) % MOD;
            }
        }
        for (int i = bl + 1; i <= br - 1; i++) {
            tag[i][1] = (tag[i][1] + c) % MOD;
        }
    };

    auto mul = [&](int l, int r, int c) -> void {
        c %= MOD;
        int bl = block[l], br = block[r];
        for (int i = bl * B; i <= std::min((bl + 1) * B - 1, n - 1); i++) {
            a[i] = (tag[bl][0] * a[i] + tag[bl][1]) % MOD;
        }
        tag[bl][0] = 1; tag[bl][1] = 0;
        for (int i = l; i <= std::min((bl + 1) * B - 1, r); i++) {
            a[i] = (a[i] * c) % MOD;
        }
        if (bl != br) {
            for (int i = br * B; i <= std::min((br + 1) * B - 1, n - 1); i++) {
                a[i] = (tag[br][0] * a[i] + tag[br][1]) % MOD;
            }
            tag[br][0] = 1; tag[br][1] = 0;
            for (int i = br * B; i <= r; i++) {
                a[i] = (a[i] * c) % MOD;
            }
        }
        for (int i = bl + 1; i <= br - 1; i++) {
            tag[i][0] = (tag[i][0] * c) % MOD;
            tag[i][1] = (tag[i][1] * c) % MOD;
        }
    };

    auto query = [&](int i) -> i64 {
        return (a[i] * tag[block[i]][0] + tag[block[i]][1]) % MOD;
    };

    for (int i = 0; i < n; i++) {
        int op, l, r, c;
        std::cin >> op >> l >> r >> c;
        l--, r--;
        if (op == 0) add(l, r, c);
        else if (op == 1) mul(l, r, c);
        else std::cout << (query(r) + MOD) % MOD << '\n';
    }

    return 0;
}
