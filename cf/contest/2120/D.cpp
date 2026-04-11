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

/**
 *  Problem statement: 
 *      1. a, b, k; integer. Two people: A and H
 *      2. A gives H Two integer: n and m.
 *          then H gives A a matrix: X with n rows and m cols. Between [1, k].
 *      3. A wins: 
 *          1. find a submatrix Y of X with a rows and b cols that all elements of Y are equal.
 *      
 *      4. find the lexicographically minimum tuple (n,m). 
 *  
 *  Observation:
 *      1. n * m >= a * b;
 *      2. We can choose any number in the [1, k] to match the rule of winner.
 *      3. 在n * m 中至少有一个元素大于等于 a * b 个。
 *          1. If k >= a * b: 
 *              
 */

template<typename T>
T power_with_mod(T base, T exp, T mod) {
    if(exp == 0) return 1;
    if(exp == 1) return base;
    if(exp % 2){
        return (power_with_mod(base, exp / 2, mod) % mod) * (power_with_mod(base, exp / 2, mod) % mod) % mod * base % mod;
    }
    return (power_with_mod(base, exp / 2, mod) % mod) * (power_with_mod(base, exp / 2, mod) % mod) % mod;
}

void solve(){
    const ll MOD = 1e9 + 7;
    ll a, b, k; cin >> a >> b >> k;
    ll n = (k % MOD * (a - 1) % MOD + 1LL) % MOD;
    a = min((n - a + MOD) % MOD, a);
    ll m = 1;
    ll inv = 1;
    for(int i = 1; i <= a; i++){
        m = m % MOD * (n - i + 1) % MOD;
        m = m % MOD * power_with_mod((i + MOD) % MOD, MOD - 2, MOD) % MOD;
    }
    m = m % MOD * (b - 1) % MOD * k % MOD + 1LL;
    cout << n % MOD << " " << m % MOD << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}