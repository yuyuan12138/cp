/**
 *  author:  yuyuan567
 *  created: 2025-08-18
 *
 *  Solution to: Paper Cutting Again
 */
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'007;
const int MAXN = 1'000'000 + 5;

long long fact[MAXN], invfact[MAXN];

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

long long inv(long long x) {
    return modpow(x, MOD - 2);
}

long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute factorials and inverses
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
    invfact[MAXN - 1] = inv(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1) % MOD;

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        long long k;
        cin >> n >> m >> k;

        if (1LL * n * m <= k) {
            cout << 0 << "\n";
            continue;
        }

        long long num = 0, den = 0;

        // denominator = total permutations of cuts = binom(n+m-2, n-1)
        den = C(n + m - 2, n - 1);

        // numerator = weighted sum over valid (i,j)
        for (int i = 1; i <= n; i++) {
            // largest j such that i*j > k
            int jmin = k / i + 1;
            if (jmin > m) continue;
            for (int j = jmin; j <= m; j++) {
                // weight = number of permutations with last surviving size i x j
                // = C((n-i)+(m-j), (n-i))
                num = (num + C((n - i) + (m - j), n - i)) % MOD;
            }
        }

        long long ans = num * inv(den) % MOD;
        cout << ans << "\n";
    }
}

