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

void solve(){
    // 2, 3, 5, 7
    ll l, r; cin >> l >> r;
    vector<ll> primes = {2, 3, 5, 7};
    auto dfs = [](auto&& dfs, int idx, ll current, ll cnt, ll X, const vector<ll>& primes) -> ll{
        if(current > X){
            return 0LL;
        }
        if(idx == 4){
            if(cnt % 2 == 1){
                return - X / current;
            }else{
                return X / current;
            }
        }
        ll res = dfs(dfs, idx + 1, current, cnt, X, primes);
        if(current <= X / primes[idx]){
            res += dfs(dfs, idx + 1, current * primes[idx], cnt + 1, X, primes);
        }
        
        return  res;
    };

    cout << dfs(dfs, 0, 1, 0, r, primes) - dfs(dfs, 0, 1, 0, l - 1, primes) << "\n";
    
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}