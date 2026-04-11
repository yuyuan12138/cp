#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int t, n;
int s[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> cnt(n, 0);  // frequency of each score

        bool invalid = false;
        int unknown = 0;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            if (s[i] == -1)
                unknown++;
            else {
                if (s[i] >= n)
                    invalid = true;
                else
                    cnt[s[i]]++;
            }
        }

        if (invalid) {
            cout << 0 << '\n';
            continue;
        }

        // The key: number of permutations that yield same count histogram
        // is multinomial coefficient:
        // total = n! / (count[0]! * count[1]! * ...)

        vector<int> fact(n + 1, 1), invfact(n + 1, 1);
        for (int i = 1; i <= n; ++i)
            fact[i] = 1LL * fact[i - 1] * i % MOD;
        // Precompute inverse factorials
        invfact[n] = 1;
        int base = fact[n];
        for (int i = n - 1; i >= 0; --i)
            invfact[i] = 1LL * invfact[i + 1] * (i + 1) % MOD;

        int total = fact[n];
        for (int i = 0; i < n; ++i) {
            if (cnt[i])
                total = 1LL * total * invfact[cnt[i]] % MOD;
        }

        cout << total << '\n';
    }

    return 0;
}
