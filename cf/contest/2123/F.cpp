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
vector<T> eratosthenes(const T n){
    vector<T> primes;
    vector<bool> is_primes(n + 1, true);
    for(T i = 2; i <= n; i++){
        if(is_primes[i]){
            primes.push_back(i);
            for(T j = i * 2; j <= n; j += i){
                is_primes[j] = false;
            }
        }
    }
    return primes;
}

void solve(vector<int>& primes){
    int n; cin >> n;
    vector<int> ans(n + 1);
    for(int i = primes.size() - 1; i >= 0; i--){
        if(primes[i] > n) continue;
        vector<int> cycle;
        for(int j = primes[i]; j <= n; j += primes[i]){
            if(!ans[j]){
                cycle.push_back(j);
            }
        }
        for(int j = 0; j < cycle.size(); j++){
            ans[cycle[j]] = cycle[(j + 1) % cycle.size()];
        }
    }
    for(int i = 1; i <= n; i++){
        if (ans[i] != 0)
            cout << ans[i] << " ";
        else
            cout << i << " ";
    }
    cout << "\n";
    return ;
}

int main() {
    speedup();
    vector<int> primes = eratosthenes(int(1e5 + 3));
    int t; cin >> t;
    while(t--) solve(primes);
    return 0;
}