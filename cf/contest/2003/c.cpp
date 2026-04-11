#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define int long long

using ll = long long;
using pii = pair<int, int>;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    map<char, int> cnt;
    for(auto& c: s){
        cnt[c]++;
    }
    vector<pair<char, int>> num_cnt;

    for(auto it = cnt.begin(); it != cnt.end(); it++){
        num_cnt.push_back({it->first, it->second});
    }
    if(num_cnt.empty()){
        cout << "\n";
        return ;
    }
    if(num_cnt.size() == 1){
        cout << s << "\n";
        return ;
    }
    sort(all(num_cnt), [](pair<char, int>& a, pair<char, int>& b){
        return a.second > b.second;
    });

    int max_n = num_cnt[0].second;
    int max_2 = num_cnt[1].second;

    num_cnt[0].second -= (max_n - max_2);

    cout << string(max_n - max_2, num_cnt[0].first);
    int c = max_n - max_2;
    int idx = 0;
    while(true){
        if(c == s.size()){
            break;
        }
        if(idx >= num_cnt.size()){
            idx = 0;
        }
        if(num_cnt[idx].second <= 0){
            idx++;
            continue;
        }
        cout << num_cnt[idx].first;
        num_cnt[idx].second --;
        c++;
        idx++;
    }
    cout << "\n";

    return ;
}

signed main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}