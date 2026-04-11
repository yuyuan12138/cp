#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    std::vector<int> block(n);
    std::vector<i64> tags(n), init(n);
    const int B = std::sqrt(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        block[i] = i / B;
    }
    for (int i = 0; i < n; i++) {
        init[block[i]] += a[i];
    }
    auto add = [&](const int l, const int r, const i64 c) -> void {
        int bl = block[l], br = block[r];
        for (int i = l; i <= std::min((bl + 1) * B - 1, r); i++) {
            a[i] += c;
            init[block[i]] += c;
        }
        if (bl != br) {
            for (int i = br * B; i <= r; i++) {
                a[i] += c;
                init[block[i]] += c;
            }
        }
        for (int i = bl + 1; i <= br - 1; i++) {
            tags[i] += c;
        }
    };
    auto query = [&](const int l, const int r) -> i64 {
        i64 ans = 0;
        int bl = block[l], br = block[r];
        for (int i = l; i <= std::min((bl + 1) * B - 1, r); i++) {
            ans += a[i];
            ans += tags[bl];
        }
        if (bl != br) {
            for (int i = br * B; i <= r; i++) {
                ans += a[i];
                ans += tags[br];
            }
        }
        for (int i = bl + 1; i <= br - 1; i++) {
            ans += i64(B) * tags[i] + init[i];
        }
        return ans;
    };
    for (int i = 0; i < n; i++) {
        int op, l, r, c;
        std::cin >> op >> l >> r >> c;
        l--, r--;
        if (op == 0) {
            add(l, r, c);
        } else {
            std::cout << (query(l, r) % (c + 1) + c + 1) % (c + 1) << '\n';
        }
    }
    return 0;
}