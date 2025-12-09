#include <bits/stdc++.h>

std::vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

using i64 = long long;

constexpr int N = 2e5;
constexpr i64 inf = 1e18;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::vector<bool> vis(N + 1, false);
    std::vector<int> ps;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        for (int x = a[i]; x > 1;) {
            int p = minp[x];
            while (x % p == 0) {
                x /= p;
            }
            ps.push_back(p);
            if (vis[p]) {
                ok = true;
            }
            vis[p] = true;
        }
    } 
    if (ok) {
        std::cout << 0 << '\n';
    } else {
        std::vector<int> q(n);
        std::iota(q.begin(), q.end(), 0);
        std::sort(q.begin(), q.end(), [&](int x, int y) {
            return b[x] < b[y];
        });
        i64 ans = b[q[0]] + b[q[1]];
        for (int i = 0; i < n; i++) {
            for (int x = a[q[i]] + 1; x > 1; x /= minp[x]) {
                if (vis[minp[x]]) {
                    ans = std::min<i64>(ans, b[q[i]]);
                }
            }
        }
        for (int x = a[q[0]]; x > 1;) {
            int p = minp[x];
            while (x % p == 0) {
                x /= p;
            }
            vis[p] = false;
        }
        for (int p : ps) {
            if (!vis[p]) {
                continue;
            }
            int k = (a[q[0]] + p - 1) / p;
            ans = std::min(ans, i64(k * p - a[q[0]]) * b[q[0]]);
        }
        std::cout << ans << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    sieve(N + 1);
    int t; 
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
