#include <bits/stdc++.h>

using namespace std;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    bool has_zero = false;
    for(auto& x: nums) {
        cin >> x;
        if(x == 0){
            has_zero = true;
        }
    }

    if(!has_zero){
        cout << "YES" << "\n";
        return ;
    }

    for(int i = 0; i < n - 1; i++){
        if(nums[i] + nums[i + 1] == 0){
            cout << "YES" << "\n";
            return ;
        }
        
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