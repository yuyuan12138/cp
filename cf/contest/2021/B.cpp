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
    int n, x; cin >> n >> x;
    vector<int> a(n + 1);
    map<int, int> cnt_num;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(cnt_num.find(a[i]) == cnt_num.end()){
            cnt_num[a[i]] = 0;
        }
        cnt_num[a[i]]++;
    }
    
    for(int i = 0; ; i++){
        if(cnt_num.find(i) == cnt_num.end() || cnt_num[i] == 0){
            cout << i << "\n";
            return ;
        }
        cnt_num[i]--;
        if(cnt_num.find(i + x) == cnt_num.end()){
            cnt_num[i + x] = 0;
        }
        cnt_num[i + x] += cnt_num[i];
    }


    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}