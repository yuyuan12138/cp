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
    vector<int> d(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }
    vector<pair<int, int>> obstacles(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> obstacles[i].first >> obstacles[i].second;
    }
    
    int last = 0;
    int pos = 0;
    stack<int> st;
    vector<int> ans(all(d));
    for(int i = 1; i <= n; i++){
        if(d[i] == 1){
            pos++;
        }else if(d[i] == -1){
            last++;
            st.push(i);
        }
        if((pos < obstacles[i].first && (obstacles[i].first - pos > last)) || pos > obstacles[i].second){
            cout << -1 << "\n";
            return ;
        }
        if(pos >= obstacles[i].first && pos <= obstacles[i].second){
            last = min(last, obstacles[i].second - pos);
            continue;
        }
        for(int _ = 1; _ <= obstacles[i].first - pos; _++){
            ans[st.top()] = 1;
            st.pop();
        }
        last -= (obstacles[i].first - pos);
        last = min(last, obstacles[i].second - obstacles[i].first);
        pos = obstacles[i].first;
    }
    
    for(int i = 1; i <= n; i++){
        cout << max(ans[i], 0) << " ";
    }
    cout << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}