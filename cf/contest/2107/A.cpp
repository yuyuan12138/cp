#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int max_n = *max_element(v.begin(), v.end());
    int min_n = *min_element(v.begin(), v.end());

    if(max_n == min_n){
        cout << "NO" << endl;
        return ;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++){
        
        cout << (1 + (v[i] == max_n)) << " \n"[i + 1 == n];
    }
}

int main(){
    int t;
    cin >> t;
    while(t --) solve();
    return 0;
}