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
    std::vector<i64> tag(2 * n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        block[i] = i / B;
    }
    auto add = [&](int l, int r, i64 c) -> void {
        int bl = block[l], br = block[r];
        for (int i = l; i <= std::min((bl + 1) * B - 1, r); i++) {
            a[i] += c;
        }
        if (bl != br) {
            for (int i = br * B; i <= r; i++) {
                a[i] += c;
            }
        }
        for (int i = bl + 1; i <= br - 1; i++) {
            tag[i] += c;
        }
    };
    auto query = [&](int i) -> i64 {
        return a[i] + tag[block[i]];
    };
    for (int i = 0; i < n; i++) {
        int op, l, r;
        i64 c;
        std::cin >> op >> l >> r >> c;
        l--, r--;
        if (op == 0) {
            add(l, r, c);
        } else {
            std::cout << query(r) << '\n';
        }
    }
    return 0;
}