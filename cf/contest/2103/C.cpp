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
    vector<int> suffix_sum(n + 2);

    vector<int> prefix_min(n + 1, INT32_MAX);
    vector<int> suffix_min(n + 2, INT32_MAX);
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        if(x <= k){
            a[i] = 1;
        }else{
            a[i] = -1;
        }
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
        prefix_min[i] = min(prefix_min[i - 1], prefix_sum[i]);
    }

    
    for(int i = n; i >= 1; i--){
        suffix_sum[i] = suffix_sum[i + 1] + a[i];
        suffix_min[i] = min(suffix_sum[i], suffix_min[i + 1]);
    }
    
    if([&]() -> bool {
        // prefix and median
        for(int i = 1; i <= n - 2; i++){
            if(prefix_sum[i] >= 0 && prefix_sum[n] - prefix_sum[i] - suffix_min[i + 2] >= 0){
                cout << "YES\n";
                return true;
            }
        }
        return false;
    }()){
        return ;
    };

    if([&]() -> bool {
        // median and suffix
        for(int i = n; i >= 3; i--){
            if(suffix_sum[i] >= 0 && suffix_sum[1] - suffix_sum[i] - prefix_min[i - 2] >= 0){
                cout << "YES\n";
                return true;
            }
        }
        return false;
    }()){
        return ;
    }

    if([&]() -> bool {
        int idx = -1;
        for(int i = 1; i <= n - 2; i++){
            if(prefix_sum[i] >= 0){
                idx = i;
                break;
            }
        }
        if(idx == -1){
            return false;
        }
        for(int i = idx + 2; i <= n; i++){
            if(suffix_sum[i] >= 0){
                cout << "YES\n";
                return true;
            }
        }
        return false;
    }()){
        return ;
    }
    
    cout << "NO\n";
    
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}