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
    for(int i = 1; i <= n; i++) cin >> a[i];

    int slow = 0;
    int cnt = 0;
    int ans = 0;
    for(int fast = 1; fast <= n; fast++){
        if(a[fast] == 1){
            slow = fast;
            cnt = 0;
        }
        cnt = max(cnt, fast - slow);
        if(cnt == k){
            ans++;
            slow = fast + 1;
            cnt = 0;
        }
    }
    cout << ans << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}