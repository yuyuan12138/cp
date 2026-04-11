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

/**
 *  Create a priority_queue to manage the botton we should press.
 *  Algo.
 *  1. Check if the top number of pq in the vis.
 *      Yes: continue
 *      No: Create a new clone in the idx of it.
 *          then. Find the non-decreasing num of them and and them into vis.
 *     
 */


void solve(){
    int n; cin >> n;
    vector<int> weights(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> weights[i];
    }
    
    auto cmp = [&](const int x, const int y){
        return weights[x] < weights[y];
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for(int i = 1; i <= n; i++){
        pq.push(i);
    }
    
    int ans = 0;
    set<int> vis;
    while(!pq.empty()){
        int idx = pq.top(); pq.pop();
        if(vis.count(idx)) continue;
        ans++;
        vis.insert(idx);
        for(int i = idx + 1; idx <= n; i++){
            if(weights[i] > weights[i - 1] || vis.count(i)){
                break;
            }
            vis.insert(i);
        }
        for(int i = idx - 1; idx >= 1; i--){
            if(weights[i] > weights[i + 1] || vis.count(i)){
                break;
            }
            vis.insert(i);
        }
    }
    cout << ans << "\n";
    




    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}