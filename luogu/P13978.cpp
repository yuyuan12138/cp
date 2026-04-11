#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    std::vector<int> idx(n);
    std::vector<int> block(n);
    std::vector<i64> tags(n);
    const int B = std::sqrt(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::iota(idx.begin(), idx.end(), 0);
    auto sort_block = [&](int k) -> void {
        int l = k * B;
        int r = std::min((k + 1) * B, n);
        std::sort(idx.begin() + l, idx.begin() + r, [&](const int x, const int y) -> bool {
            return a[x] < a[y];
        });
    };
    for (int i = 0; i <= (n - 1) / B; i++) {
        sort_block(i);
    }
    for (int i = 0; i < n; i++) {
        block[i] = i / B;
    }
    auto add = [&](const int l, const int r, const i64 c) -> void {
        int bl = block[l], br = block[r];
        for (int i = l; i <= std::min((bl + 1) * B - 1, r); i++) {
            a[i] += c;
        }
        sort_block(bl);
        if (bl != br) {
            for (int i = br * B; i <= r; i++) {
                a[i] += c;
            }
            sort_block(br);
        }
        for (int i = bl + 1; i <= br - 1; i++) {
            tags[i] += c;
        }
    };
    auto query = [&](const int l, const int r, const i64 c) -> i64 {
        i64 ans = INT64_MIN;
        int bl = block[l], br = block[r];
        for (int i = l; i <= std::min((bl + 1) * B - 1, r); i++) {
            if (a[i] + tags[bl] < c) {
                ans = std::max(ans, a[i] + tags[bl]);
            }
        }
        if (bl != br) {
            for (int i = br * B; i <= r; i++) {
                if (a[i] + tags[br] < c) {
                    ans = std::max(ans, a[i] + tags[br]);
                }
            }
        }
        for (int i = bl + 1; i <= br - 1; i++) {
            int lo = i * B, hi = std::min((i + 1) * B, n) - 1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (a[idx[mid]] + tags[i] < c) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            if (hi >= i * B) {
                ans = std::max(ans, a[idx[hi]] + tags[i]);
            }
        }
        if (ans == INT64_MIN) {
            return -1ll;
        } else {
            return ans;
        }
    };
    for (int i = 0; i < n; i++) {
        int op, l, r;
        i64 c;
        std::cin >> op >> l >> r >> c;
        l--, r--;
        if (op == 0) {
            add(l, r, c);
        } else {
            std::cout << query(l, r, c) << '\n';
        }
    }
    return 0;
}