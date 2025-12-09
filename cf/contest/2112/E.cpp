#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string> 
#include <string.h>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <bitset>
#include <forward_list>
#include <deque>
#include <set>
#include <tuple>
#include <utility>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <chrono>
#include <random>
#include <complex>
#include <functional>
#include <cassert>
#include <climits>
#include <limits>
#include <tuple>
#include <cstdint>
#include <array>
using namespace std;

// ==================== 类型定义 ===================
using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

// ==================== 宏定义 =====================
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

// ==================== 常量定义 ===================
const int INF = 0x3f3f3f3f;     // 10亿级整数无穷大
const ll LLINF = 0x3f3f3f3f3f3f3f3f; // 10^18级LL无穷大
const int MOD = 1e9 + 7;        // 常用质数模数
const ld EPS = 1e-8;            // 浮点比较容差
const db PI = acos(-1.0);       // 圆周率

// ==================== 调试宏 =====================
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}

// ==================== 输入输出优化 ================
inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// ==================== 常用函数 ===================
// 快速幂 (a^b mod m)
ll qpow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// 最大公约数
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// 最小公倍数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

template <typename Func>
ll findFirstTrue(ll low, ll high, Func&& condition){
    ll mid = 0;
    while (low <= high){
        mid = low + (high - low) / 2;
        if(condition(mid)) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

// 前缀和
namespace Partial_Sum{
    // all vectors are 1-based
    // 1D 
    template<typename T>
    vector<T> partial_sum_1D(vector<T>& original_vec){
        const int n = original_vec.size();
        vector<T> results(n);
        for(int i = 1; i < n; i++){
            results[i] = results[i - 1] + original_vec[i];
        }
        return results;
    }

    // 2D
    template<typename T>
    vector<vector<T>> partial_sum_2D(vector<vector<T>>& original_vec){
        const int n = original_vec.size();
        const int m = original_vec[0].size();
        vector<vector<T>> results(n, vector<T>(m));
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                results[i][j] = results[i - 1][j] + results[i][j - 1] - results[i - 1][j - 1] + original_vec[i][j];
            }
        }
        return results;
    }
}

template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}

// 计数函数
template<typename T>
ll count_number_of_x(vector<T>& nums, ll left, ll right, T x){
    ll cnt = 0;
    for(ll i = left; i <= right; i++){
        if(nums[i] == x){
            cnt += 1;
        }
    }
    return cnt;
}


int main() {
    speedup();
    int t;
    cin >> t;
    vector<int> test_cases(t);
    int max_val = 0;
    
    for (int idx = 0; idx < t; idx++) {
        cin >> test_cases[idx];
        if (test_cases[idx] > max_val) 
            max_val = test_cases[idx];
    }

    vector<int> min_prime(max_val + 1, 0);
    vector<int> prime_numbers;
    
    for (int num = 2; num <= max_val; num++) {
        if (min_prime[num] == 0) {
            min_prime[num] = num;
            prime_numbers.pb(num);
        }
        int prime_index = 0;
        while (prime_index < sz(prime_numbers)) {
            int p_val = prime_numbers[prime_index];
            long long product = 1LL * num * p_val;
            if (p_val > min_prime[num] || product > max_val) 
                break;
            min_prime[product] = p_val;
            prime_index++;
        }
    }

    vector<int> min_operations(max_val + 1, MOD);
    min_operations[1] = 0;

    for (int num = 2; num <= max_val; num++) {
        vector<pair<int, int>> prime_factors;
        int temp = num;
        int last_prime = 0, exp_count = 0;
        
        while (temp > 1) {
            int p = min_prime[temp];
            if (p != last_prime) {
                if (last_prime != 0) 
                    prime_factors.eb(last_prime, exp_count);
                last_prime = p;
                exp_count = 0;
            }
            exp_count++;
            temp /= p;
        }
        if (last_prime != 0) 
            prime_factors.eb(last_prime, exp_count);

        vector<int> divisors = {1};
        for (const auto& factor : prime_factors) {
            int prime = factor.first;
            int exponent = factor.second;
            vector<int> new_divisors;
            for (int d : divisors) {
                int power = 1;
                for (int e = 1; e <= exponent; e++) {
                    power *= prime;
                    new_divisors.pb(d * power);
                }
            }
            divisors.insert(divisors.end(), new_divisors.begin(), new_divisors.end());
        }

        int min_cost = MOD;
        for (int d_val : divisors) {
            if (d_val < 3) continue;
            int remainder = num / d_val;
            int chain_length = d_val - 2;
            int total_ops = min_operations[chain_length] + min_operations[remainder] + 1;
            if (total_ops < min_cost) 
                min_cost = total_ops;
        }
        min_operations[num] = min_cost;
    }

    for (int query : test_cases) {
        if (query == 1) {
            cout << 1 << '\n';
        } else if (min_operations[query] >= MOD) {
            cout << -1 << '\n';
        } else {
            cout << (min_operations[query] + 1) << '\n';
        }
    }

    return 0;
}