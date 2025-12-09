#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;

struct DSU {
    int n;
    std::vector<int> p;
    std::vector<int> sz;
    DSU(int n=0) { init(n); }
    void init(int n_) {
        n = n_;
        p.resize(n+1);
        sz.resize(n+1);
        for (int i=1;i<=n;i++) { p[i]=i; sz[i]=1; }
    }
    int find(int x) {
        while (p[x]!=x) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }
    void unite(int a,int b) {
        a = find(a); b = find(b);
        if (a==b) return;
        if (sz[a] < sz[b]) std::swap(a,b);
        p[b] = a;
        sz[a] += sz[b];
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<ll> w(n+1);
    for (int i=1;i<=n;i++) std::cin >> w[i];
    std::vector<std::vector<int>> g(n+1);
    for (int i=0;i<n-1;i++){
        int u,v; std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    std::vector<std::pair<ll,int>> ord;
    ord.reserve(n);
    for (int i=1;i<=n;i++) ord.emplace_back(w[i], i);
    std::sort(ord.begin(), ord.end(), [](auto &a, auto &b){
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    std::map<ll, std::vector<int>, std::greater<ll>> groups;
    for (int i=1;i<=n;i++) groups[w[i]].push_back(i);

    DSU dsu(n);
    std::vector<char> active(n+1, 0);
    ll ans = 0;

    int pos = 0;

    std::vector<int> cnt(n+1,0);
    std::vector<int> rootsTouched;
    rootsTouched.reserve(n);
    std::vector<int> last_seen(n+1, 0);
    int token = 1;

    for (auto &kv : groups) {
        ll cur = kv.first;
        const std::vector<int> &nodes = kv.second;

        while (pos < n && ord[pos].first > cur) {
            int x = ord[pos].second;
            active[x] = 1;
            for (int v : g[x]) if (active[v]) dsu.unite(x, v);
            pos++;
        }

        rootsTouched.clear();
        for (int u : nodes) {
            
            for (int v : g[u]) {
                if (w[v] > cur && active[v]) {
                    int r = dsu.find(v);
                    if (last_seen[r] != token) {
                        last_seen[r] = token;
                        if (cnt[r] == 0) rootsTouched.push_back(r);
                        cnt[r] += 1;
                    }
                }
            }
            token++; 
        }


        for (int r : rootsTouched) {
            ll k = cnt[r];
            if (k >= 2) ans += k * (k - 1) / 2;
            cnt[r] = 0; 
            
        }

        
        for (int u : nodes) {
            for (int v : g[u]) {
                if (v > u && w[v] == cur) {
                    ans += 1;
                }
            }
        }
    }

    std::cout << ans * 2 << '\n';
    return 0;
}
