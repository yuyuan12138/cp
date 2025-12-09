#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> pos(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        if(a[i] == b[i]) cnt++;
    }
    if(cnt >= 2){
        cout << -1 << "\n";
        return ;
    }

    if(n % 2 == 0 && cnt >= 1){
        cout << "-1\n";
        return ;
    }

    map<pair<int, int>, int> mp;
    map<pair<int, int>, vector<int>> idx;
    for(int i = 1; i <= n; i++){
        int x = min(a[i], b[i]);
        int y = max(a[i], b[i]);
        mp[{x, y}]++;
        idx[{x, y}].push_back(a[i]);
    }

    for(auto& [key, value]: mp){
        if(key.first == key.second) continue;
        if(value < 2){
            cout << "-1\n";
            return ;
        }
    }
    // cout << n << "\n";
    int idxs = 1;
    
    vector<pair<int, int>> ans;
    for(auto& [key, value]: idx){
        if(key.first == key.second && pos[value[0]] != n / 2 + 1){
            int original_pos = pos[value[0]];
            int new_pos = n / 2 + 1;
            ans.push_back({original_pos, new_pos});
            pos[value[0]] = new_pos;
            pos[a[new_pos]] = original_pos;
            swap(a[original_pos], a[new_pos]);
        }else{
            if(key.first == key.second) continue;
            if(pos[value[0]] != idxs){
                int original_pos = pos[value[0]];
                int new_pos = idxs;
                ans.push_back({original_pos, new_pos});
                pos[value[0]] = new_pos;
                pos[a[new_pos]] = original_pos;
                swap(a[original_pos], a[new_pos]);
            }
            if(pos[value[1]] != n - idxs + 1){
                int original_pos = pos[value[1]];
                int new_pos = n - idxs + 1;
                ans.push_back({original_pos, new_pos});
                pos[value[1]] = new_pos;
                pos[a[new_pos]] = original_pos;
                swap(a[original_pos], a[new_pos]);
            }
            idxs++;
        }
    }

    cout << ans.size() << "\n";
    for(auto& [fst, snd]: ans){
        cout << fst << " " << snd << "\n";
    }


    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}