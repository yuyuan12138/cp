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

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> color(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    vector<vector<pair<int, int>>> graph(n + 1);
    ll cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
        if(color[u] != color[v]) cnt += c;
    }

    vector<map<int, ll>> ColorSum(n + 1);
    vector<int> parents(n + 1);
    vector<ll> parent_cost(n + 1);
    auto init = [&](auto&& init, int vertex, int parent) -> void{
        parents[vertex] = parent;
        for(auto f: graph[vertex]){
            int u = f.first, c = f.second;
            if(u != parent){
                parent_cost[u] = c;
                init(init, u, vertex);
            }
        }
    };

    init(init, 1, 1);

    for(int i = 2; i <= n; i++){
        ColorSum[parents[i]][color[i]] += parent_cost[i];
    }

    for(int i = 1; i <= q; i++){
        int v, x; cin >> v >> x;
        int old = color[v];
        cnt += ColorSum[v][old];
        cnt -= ColorSum[v][x];

        if(v != 1){
            int parent = parents[v];
            cnt -= (color[parent] != color[v]) * parent_cost[v];
            ColorSum[parent][color[v]] -= parent_cost[v];
            color[v] = x;
            ColorSum[parent][color[v]] += parent_cost[v];
            cnt += (color[parent] != color[v]) * parent_cost[v];
        }else{
            color[v] = x;
        }

        cout << cnt << "\n";

    }
    

}


int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}