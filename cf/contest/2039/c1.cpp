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

void solve() {
    ll x, m;
    cin >> x >> m;
    ll ans = 0;
    for (ll y = 1; y <= min(2LL * x, m); y++) {
        if (y != x && ((x % (y ^ x) == 0) || (y % (y ^ x) == 0))) {
            ans++;
        }
    }
    cout << ans << "\n";
    return;
}

int main() {
    speedup();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}