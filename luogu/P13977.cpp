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
    std::vector<int> idx(n);
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
    auto add = [&](int l, int r, i64 c) -> void {
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
            tag[i] += c;
        }
    };
    auto query = [&](int l, int r, i64 c) -> int {
        i64 thr = c * c;
        int ans = 0;
        int bl = block[l], br = block[r];
        for (int i = l; i <= std::min((bl + 1) * B - 1, r); i++) {
            if (a[i] + tag[bl] <= thr) {
                ans++;
            }
        }
        if (bl != br) {
            for (int i = br * B; i <= r; i++) {
                if (a[i] + tag[br] <= thr) {
                    ans++;
                }
            }
        }
        for (int i = bl + 1; i <= br - 1; i++) {
            int lo = i * B, hi = std::min((i + 1) * B, n) - 1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (a[idx[mid]] + tag[i] < thr) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            ans += (lo - i * B);
        }
        return ans;
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