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
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> prefix_sum(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(all(a));
    int d = (n - k + 1) / 2;
    cout << a[n - d + 1] - a[d] + 1 << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}