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
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    set<int> a_st; set<int> b_st;
    set<set<int>> st;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    
    for(int i = 1; i <= n; i++){
        
        for(int j = 1; j <= n; j++){
            set<int> tmp;
            tmp.insert(a[i]); tmp.insert(b[j]);
            st.insert(tmp);
        }
    }
    if(st.size() >= 3){
        cout << "YES\n";
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