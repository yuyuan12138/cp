#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using pii = pair<int, int>;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

template<typename T>
T power_with_mod(T base, T exp, T mod) {
    if(exp == 0) return 1;
    if(exp == 1) return base;
    if(exp % 2){
        return (power_with_mod(base, exp / 2, mod) % mod) % mod * (power_with_mod(base, exp / 2, mod) % mod) % mod * base % mod;
    }
    return (power_with_mod(base, exp / 2, mod) % mod) % mod * (power_with_mod(base, exp / 2, mod) % mod) % mod;
}

void solve(){
    ll n, m; cin >> n >> m;
    const ll MOD = 998244353LL;

    vector<vector<pair<ll, ll>>> ibr(m + 1);

    ll total_error_possibility = 1;
    for(int i = 1; i <= n; i++){
        ll l, r, p, q;
        cin >> l >> r >> p >> q;
        p %= MOD; q %= MOD;
        ll q_minus_p = 0;
        if(q - p < 0){
            q_minus_p = q - p + MOD;
        }else{
            q_minus_p = (q - p) % MOD;
        }

        ll inv_q = power_with_mod(q % MOD, MOD - 2, MOD);
        ll inv_qp = power_with_mod(q_minus_p % MOD, MOD - 2, MOD);
        total_error_possibility = total_error_possibility * q_minus_p % MOD * inv_q % MOD;
        ll w = p % MOD * inv_qp % MOD;
        ibr[r].emplace_back(l, w);
    }

    vector<ll> memo(m + 1, -1);
    auto dfs = [&](auto&& dfs, ll idx) -> ll{
        if(idx == 0) return 1LL;
        if(memo[idx] != -1){
            return memo[idx];
        }
        ll res = 0LL;
        for(auto& [l, w]: ibr[idx]){
            res = (res + dfs(dfs, l - 1) * w) % MOD;
        }
        return memo[idx] = res % MOD;
    };

    cout << dfs(dfs, m) * total_error_possibility % MOD << "\n";

    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}