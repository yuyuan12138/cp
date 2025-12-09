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
 * It is obvious that we should found the difference of all characters. 
 *      Every query we need use O(26) time. Can we do better?
 *      May be we do not need calculate them over and over agian. 
 *      Means we have a strategy that we can calculate it in O(1) time. 
 *      
 */

void solve(){
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;

    vector<vector<int>> prefix_a(n + 1, vector<int> ('z' + 1)); // O(n * 26)
    vector<vector<int>> prefix_b(n + 1, vector<int> ('z' + 1));
    for(char c = 'a'; c <= 'z'; c++){
        prefix_a[0][c] = 0;
        prefix_b[0][c] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(char c = 'a'; c <= 'z'; c++){
            prefix_a[i][c] = prefix_a[i - 1][c];
            prefix_b[i][c] = prefix_b[i - 1][c];
            if(a[i - 1] == c){
                prefix_a[i][c]++;
            }
            if(b[i - 1] == c){
                prefix_b[i][c]++;
            }
        }
    }

    while(q--){
        int l, r; cin >> l >> r;
        int ans = 0;

        for(char c = 'a'; c <= 'z'; c++){
            ans += abs(prefix_a[r][c] - prefix_a[l - 1][c] - prefix_b[r][c] + prefix_b[l - 1][c]);
        }

        cout << ans / 2 << "\n";
    }
    
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}