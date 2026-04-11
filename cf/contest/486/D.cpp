/**
 *      author:  yuyuan567
 *      created: 2025-08-05 15:35:41
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

template <int MOD>
struct ModInt {
    long long v;

    ModInt() : v(0) {}
    ModInt(long long _v) : v(normalize(_v)) {}

    static long long normalize(long long x) {
        if (x < 0)
            x %= MOD, x += MOD;
        return x % MOD;
    }

    explicit operator int() const {
        return v;
    }
    explicit operator long long() const {
        return v;
    }

    ModInt operator+(const ModInt& rhs) const {
        return ModInt(v + rhs.v);
    }
    ModInt operator-(const ModInt& rhs) const {
        return ModInt(v - rhs.v);
    }
    ModInt operator*(const ModInt& rhs) const {
        return ModInt(v * rhs.v);
    }
    ModInt operator/(const ModInt& rhs) const {
        return *this * rhs.inv();
    }

    ModInt& operator+=(const ModInt& rhs) {
        v = (v + rhs.v) % MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& rhs) {
        v = (v - rhs.v + MOD) % MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& rhs) {
        v = v * rhs.v % MOD;
        return *this;
    }
    ModInt& operator/=(const ModInt& rhs) {
        return *this *= rhs.inv();
    }

    ModInt pow(long long exp) const {
        ModInt base = *this, res = 1;
        for (; exp; exp >>= 1, base *= base)
            if (exp & 1)
                res *= base;
        return res;
    }

    ModInt inv() const {
        // Fermat's little theorem (MOD must be prime)
        return pow(MOD - 2);
    }

    friend std::istream& operator>>(std::istream& is, ModInt& x) {
        long long tmp;
        is >> tmp;
        x.v = normalize(tmp);
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) {
        return os << x.v;
    }
};

constexpr int MOD = 1000000007;
using Mint = ModInt<MOD>;

void solve() {
    int d, n;
    std::cin >> d >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    Mint ans = 0;

    std::vector<std::vector<int>> vis(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        auto res = [&](this auto&& self, int u, int pa) -> Mint {
            if (a[u] < a[i] || a[u] - a[i] > d) {
                return 0LL;
            }
            if (vis[u][i]) {
                return 0LL;
            }

            vis[i][u] = vis[u][i] = 1;
            // dp[u] = 1;
            Mint res = 1LL;
            for (auto& v : edges[u]) {
                if (v == pa)
                    continue;
                res *= (self(v, u) + 1);
            }
            return res;
        }(i, -1);
        ans += res;
    }
    std::cout << ans << '\n';

    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}