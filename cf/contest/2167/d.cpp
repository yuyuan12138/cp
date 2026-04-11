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

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int prime : primes) {
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (std::gcd(a[i], i64(prime)) == 1) {
                ok = true;
            }
        }
        if (ok) {
            std::cout << prime << '\n';
            return ;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    sieve(1E6 + 1);
    while (t--) {
        solve();
    }
    return 0;
}
