/**
 *      author:  yuyuan567
 *      created: 2025-08-21 23:23:42
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

struct Hash2D {
    int n, m;
    uint64_t BR1, BC1, BR2, BC2;
    std::vector<uint64_t> pr1, pc1, pr2, pc2;
    std::vector<std::vector<uint64_t>> P1, P2;
    Hash2D() {}
    Hash2D(const std::vector<std::string>& a, uint64_t br1, uint64_t bc1, uint64_t br2, uint64_t bc2): n((int) a.size()), m((int)a[0].size()), BR1(br1), BC1(bc1), BR2(br2), BC2(bc2) {
        pr1.assign(n + 1, 1); 
        pr2.assign(n + 1, 1);
        pc1.assign(m + 1, 1);
        pc2.assign(m + 1, 1);
        for (int i = 1; i <= n; i++) {
            pr1[i] = pr1[i - 1] * BR1;
            pr2[i] = pr2[i - 1] * BR2;
        }
        for (int j = 1; j <= m; j++) {
            pc1[j] = pc1[j - 1] * BC1;
            pc2[j] = pc2[j - 1] * BC2;
        }
        P1.assign(n + 1, std::vector<uint64_t>(m + 1, 0));
        P2.assign(n + 1, std::vector<uint64_t>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                uint64_t v = (uint64_t)(a[i - 1][j - 1] - 'a' + 1);
                P1[i][j] = v + P1[i - 1][j] * BR1 + P1[i][j - 1] * BC1 - P1[i - 1][j - 1] * BR1 * BC1;
                P2[i][j] = v + P2[i - 1][j] * BR2 + P2[i][j - 1] * BC2 - P2[i - 1][j - 1] * BR2 * BC2;

            }
        }
    }
    std::pair<uint64_t, uint64_t> get(int x1, int y1, int x2, int y2) const {
        if (x1 > x2 || y1 > y2) return {0ULL, 0ULL};
        int lx = x2 - x1 + 1;
        int ly = y2 - y1 + 1;
        uint64_t a1 = P1[x2][y2];
        a1 -= P1[x1 - 1][y2] * pr1[lx];
        a1 -= P1[x2][y1 - 1] * pc1[ly];
        a1 += P1[x1 - 1][y1 - 1] * pr1[lx] * pc1[ly];
        uint64_t a2 = P2[x2][y2];
        a2 -= P2[x1 - 1][y2] * pr2[lx];
        a2 -= P2[x2][y1 - 1] * pc2[ly];
        a2 += P2[x1 - 1][y1 - 1] * pr2[lx] * pc2[ly];
        return {a1, a2};
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    const uint64_t BR1 = 911382323ULL;
    const uint64_t BC1 = 972663749ULL;
    const uint64_t BR2 = 972663541ULL;
    const uint64_t BC2 = 911382322ULL;
    while (tt--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::string> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::vector<std::string> b(n, std::string(m, 'a'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[i][j] = a[n - 1 - i][m - 1 - j];
            }
        }
        Hash2D HA(a, BR1, BC1, BR2, BC2);
        Hash2D HB(b, BR1, BC1, BR2, BC2);
        uint64_t best = ULLONG_MAX;
        for (int dr = 1 - n; dr <= n - 1; dr++) {
            int r1 = std::max(0, -dr);
            int r2 = std::min(n - 1, n - 1 - dr);
            if (r1 > r2) continue;
            for (int dc = -m + 1; dc <= m - 1; dc++) {
                int c1 = std::max(0, -dc);
                int c2 = std::min(m - 1, m - 1 - dc);
                if (c1 > c2) continue;
                auto hA = HA.get(r1 + 1, c1 + 1, r2 + 1, c2 + 1);
                auto hB = HB.get(r1 + dr + 1, c1 + dc + 1, r2 + dr + 1, c2 + dc + 1);
                if (hA == hB) {
                    uint64_t N = uint64_t(n + std::abs(dr));
                    uint64_t M = uint64_t(m + std::abs(dc));
                    uint64_t area = N * M;
                    if (area < best) best = area;
                    if (best == uint64_t(n) * m) break;
                }
            }
            if (best == uint64_t(n) * m) break;
        }
        std::cout << best - uint64_t(n) * m << '\n';
    }
    return 0;
}
