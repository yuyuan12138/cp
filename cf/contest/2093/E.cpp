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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 0, r = n;
    vector<bool> vis(2e5 + 2, false);
    while(l <= r){
        int mid = (l + r) >> 1;
        if([&]() -> bool {
            int cnt = 0;
            int cur_mex = 0;
            for(int i = 0; i < n; i++){
                if(a[i] < mid && vis[a[i]] == false){
                    cur_mex++;
                    vis[a[i]] = true;
                }
                if(cur_mex == mid){
                    cnt++;
                    cur_mex = 0;
                    for(int i = 0; i < mid; i++){
                        vis[i] = false;
                    }
                }
            }
            for(int i = 0; i < mid; i++){
                vis[i] = false;
            }
            if(cnt >= k){
                return true;
            }else{
                return false;
            }
        }()){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << r << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}