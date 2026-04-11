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
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(n == 1){
        cout << 0 << "\n";
        return ;
    }
    int g = a[1];
    for(int i = 2; i <= n; i++){
        g = gcd(g, a[i]);
    }
    int tmp_n = n;
    for(int i = 1; i <= n; i++){
        if(g == a[i]){
            tmp_n--;
        }
    }
    if(tmp_n != n){
        cout << tmp_n << "\n";
        return ;
    }
    vector<ll> memo(5003, -1);
    auto dfs = [&](auto&& dfs, ll num, vector<bool>& vis) -> ll {
        if(num == g){
            return 0LL;
        }
        if(vis[num]){
            return INT32_MAX;
        }
        if(memo[num] != -1){
            return memo[num];
        }
        vis[num] = true;
        ll min_num = INT32_MAX;
        for(int i = 1; i <= n; i++){
            min_num = min(min_num, dfs(dfs, gcd(a[i], num), vis) + 1LL);
        }
        memo[num] = min_num;
        return min_num;
    };

    ll min_n = INT32_MAX;

    for(int i = 1; i <= n; i++){
        vector<bool> vis(5003, false);
        min_n = min(min_n, dfs(dfs, a[i], vis));
    }

    cout << min_n - 1 + n << "\n";

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}