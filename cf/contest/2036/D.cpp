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
char a[1005][1005];
char layer[4005];
void solve(){
    int n, m; 
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    int cnt = 0;
    for (int i = 0; (i + 1) * 2 <= n && (i + 1) * 2 <= m; ++i) {
        int pos = 0;
        for (int j = i; j < m - i; ++j) layer[pos++] = a[i][j];
        for (int j = i + 1; j < n - i - 1; ++j) layer[pos++] = a[j][m - i - 1];
        for (int j = m - i - 1; j >= i; --j) layer[pos++] = a[n - i - 1][j];
        for (int j = n - i - 2; j >= i + 1; --j) layer[pos++] = a[j][i];
        
        for (int j = 0; j < pos; ++j)
            if (layer[j] == '1' && layer[(j + 1) % pos] == '5' && layer[(j + 2) % pos] == '4' && layer[(j + 3) % pos] == '3')
                cnt++;
        
    }
    
    cout << cnt << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}