#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;
using i64 = long long;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;
constexpr i64 N = 1e6;
vector<int> pri;
vector<bool> not_prime;
void pre(int n) {
    not_prime.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) {
            pri.push_back(i);
        }
        for (int pri_j : pri) {
            if (i * pri_j > n) {
                break;
            }
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0) {
                break;
            }
        }
    }
}
 
void solve() {
    vector<bool> v(N + 1);
    for (const auto &x : pri) {
        for (i64 i = 2, y = 1ll * x * x; y <= N * N; i++, y *= x) {
            if (!not_prime[i + 1]) {
                v[sqrtl(y)] = true;
            }
        }
    }
    int n;
    cin >> n;
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        i64 x;
        cin >> x;
        i64 sqx = sqrtl(x);
        if (sqx * sqx == x && v[sqx]) {
            ans += x;
        }
    }
    cout << ans << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    pre(N);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
