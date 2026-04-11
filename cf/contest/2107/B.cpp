#include <iostream>
#include <algorithm>
#include <vector>

// #define int long long

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    long long sum_ = 0LL;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum_ += (long long) a[i];
    }
    sort(a.begin(), a.end());
    a[n-1]--;
    sort(a.begin(), a.end());
    if(a[n - 1] - a[0] > k){
        cout << "Jerry" << "\n";
        return ;
    }
    
    if(sum_ % 2 == 0){
        cout << "Jerry" << "\n";
        
        return;
    }
    cout << "Tom" << "\n";
    
}

signed main(){
    int t;
    cin >> t;
    while(t --) solve();
    return 0;
}