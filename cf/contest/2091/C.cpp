#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n;
    cin >> n;
    if(n % 2 == 0){
        cout << -1 << "\n";
        return ;
    }

    int idx = 0;
    for(int i = n; i > 0; i--){
        cout << i << " ";
    }
    
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
    
}