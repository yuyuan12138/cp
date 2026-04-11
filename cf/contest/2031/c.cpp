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
    if(n % 2 == 0){
        for(int i = 1; i <= n / 2; i++){
            cout << i << " " << i << " ";
        }
        cout << "\n";
    }else{
        if(n <= 25){
            cout << -1 << "\n";
        }else{
            int idx = 3;
            int cnt = 0;
            cout << 1 << " ";
            for(int i = 2; i <= n; i++){
                if(i == 10 || i == 26){
                    cout << "1 2 ";
                    i += 1;
                }else{
                    if(cnt == 2){
                        idx++;
                        cnt = 0;
                    }
                    cout << idx << " ";
                    cnt ++;
                }
            }
            cout << "\n";
        }
        
    }
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
