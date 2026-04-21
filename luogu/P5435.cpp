#include <bits/stdc++.h>

using i64 = long long;

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

bool isprime(int n) {
    return minp[n] == n;
}

constexpr int MOD = 998244353;

int gcd(int x, int y) {
    int t = x;
    std::vector<int> fac(3);
    for (int i = 0; i < 3; i++) {
        fac[i] = t;
        t /= minp[t];
    }
    t = y;
    int out = 1;
    int last = 1;
    for (int i = 0; i < 3; i++) {
        out = out % MOD * std::gcd(fac[i], y / last) % MOD;
        last *= std::gcd(fac[i], y / last);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(1e6);
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int cur = 1;
        for (int j = 0; j < n; j++) {
            cur = (cur * (i + 1)) % MOD;
            ans[i] = (ans[i] + gcd(a[i], b[j]) % MOD * cur % MOD) % MOD;
        }
    }
    return 0;
}
