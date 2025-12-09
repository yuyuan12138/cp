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
    std::vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        mx = std::max(mx, a[i]);
    }

    int cnt = 0;
    i64 ans = 0;
    std::vector<int> freqs(n + 1);
    
    for (int i = 0; i < n; i++) {
        std::vector<int> v;
        if (minp[a[i]] == a[i]) {
            v.push_back(a[i]);
        } else if (minp[a[i] / minp[a[i]]] == a[i] / minp[a[i]]) {
            v.push_back(a[i] / minp[a[i]]);
            v.push_back(minp[a[i]]);
        }
        if (v.size() == 1) {
            for (int p : primes) {
                if (i64(p) * v[0] > i64(mx)) {
                    break;
                }
                ans += freqs[p * v[0]];
            }
            ans += cnt - freqs[a[i]];
            cnt++;
            freqs[a[i]]++;
        } else if (v.size() == 2) { 
            if (v[0] == v[1]) {
                ans += freqs[v[0]] + freqs[a[i]] + 1;
            } else {
                ans += freqs[v[0]] + freqs[v[1]] + freqs[a[i]] + 1;
            }
            freqs[a[i]]++;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    sieve(2E5);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
