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

// ==================== 优化指令 ===================
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
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

void solve(){
    int n, s;
    cin >> n >> s;
    vector<vector<int>> balls(n, vector<int>(4)); // dx dy xi yi;
    for(auto& x: balls){
        for(auto& y: x){
            cin >> y;
        }
    }
    int cnt = 0;
    FOR(i, 0, n - 1){
        if(((balls[i][2] + balls[i][3]) == s && (balls[i][0] * balls[i][1] == -1)) || (balls[i][2] == balls[i][3]&& (balls[i][0] * balls[i][1] == 1))){
            cnt += 1;
        }
    }
    cout << cnt << endl;
    return ;
}

signed main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}