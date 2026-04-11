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

vector<ll> primes;

void init(const ll n){
    primes = eratosthenes(n);
}

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for(auto& x: a) cin >> x;
    if(n <= 1){
        cout << 0 << "\n";
        return ;
    }
    sort(all(a), greater<ll>());
    
    
    ll prefix_sum = 0LL;
    ll prefix_prime = 0LL;
    for(int i = 1; i <= n; i++){
        prefix_sum += a[i - 1];
        prefix_prime += primes[i - 1];
        if(prefix_prime > prefix_sum){
            cout << n - i + 1 << "\n";
            return ;
        }
        
    }
    cout << 0 << "\n";
    return ;
}

int main() {
    speedup();
    init(10000000);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}