#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> block(n);
    int B = std::sqrt(n);    
    std::vector<int> tag(n), color(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        block[i] = i / B;
    }
    auto push = [&](int blockId) -> void {
        if (tag[blockId]) {
            for (int i = blockId * B; i <= std::min((blockId + 1) * B - 1, n - 1); i++) {
                a[i] = color[blockId];
            }
            tag[blockId] = 0;
        }
    };
    auto query = [&](int l, int r, int c) -> int {
        int ans = 0;
        int bl = block[l], br = block[r];
        push(bl);
        for (int i = l; i <= std::min((bl + 1) * B - 1, r); i++) {
            ans += (a[i] == c);
            a[i] = c;
        }
        if (bl != br) {
            push(br);
            for (int i = br * B; i <= r; i++) {
                ans += (a[i] == c);
                tag[br] = 0;
                a[i] = c;
            }
        }
        for (int i = bl + 1; i <= br - 1; i++) {
            if (tag[i]) {
                if (color[i] == c) {
                    ans += B;
                }
                color[i] = c;
            } else {
                tag[i] = 1;
                for (int j = i * B; j <= (i + 1) * B - 1; j++) {
                    ans += (a[j] == c);
                    a[j] = c;
                }
                color[i] = c;
            }
        }
        return ans;
    };
    for (int i = 0; i < n; i++) {
        int l, r, c;
        std::cin >> l >> r >> c;
        l--, r--;
        std::cout << query(l, r, c) << '\n';
    }
    return 0;
}