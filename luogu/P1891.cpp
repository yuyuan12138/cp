#include <bits/stdc++.h>

constexpr int N = 1E6;
bool isprime[N + 1];
int phi[N + 1];

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    i64 ans = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans += i64(phi[i]) * i / 2;
            if (n / i != i) {
                ans += i64(phi[n / i]) * (n / i) / 2;
            }
        }
    }
    std::cout << i64(ans + 1) * n << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<int> primes;
    std::fill(isprime + 2, isprime + N + 1, true);
    phi[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (isprime[i]) {
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for (auto p : primes) {
            if (i * p > N) {
                break;
            }
            isprime[i * p] = false;
            if (i % p == 0) {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}