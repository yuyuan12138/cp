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
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(all(a));
    
    int slow = -1;
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1]){
            cnt++;
        }else{
            cnt = 1;
        }
        if(a[i] > a[i - 1] + 1){
            cnt = 1;
            slow = -1;
        }
        if(cnt == 4){
            cout << "Yes\n";
            return ;
        }
        
        if(cnt == 2 && slow != -1){
            cout << "Yes\n";
            return ;
        }
        if(cnt == 2 && slow == -1){
            slow = i - 1;
        }
    }

    cout << "No\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}