#include <bits/stdc++.h>

using i64 = long long;

std::vector<i64> minp, primes;
void sieve(i64 n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (i64 i = 2; i <= n; i++) {
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
    i64 n;
    std::cin >> n;
    std::vector<i64> ans;
    int m = primes.size();
    for (int i = 0; i < m && n > 1; i++) {
        while (n % primes[i] == 0) {
            ans.push_back(primes[i]);
            n /= primes[i];
        }
    }
    if (n > 1) {
       ans.push_back(n);
    }
    for (i64 x : ans) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    sieve(2E6);
    while (t--) {
        solve();
    }
    return 0;
}
