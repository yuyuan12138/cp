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
    int n, m, k; cin >> n >> m >> k;
    int cur = 0;
    k = max(k, n / (m + 1));
    for(int i = 1; i <= n; i++){
        if(cur == k){
            cur = 0;
        }
        cout << cur << " ";
        cur++;
    }
    cout << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}