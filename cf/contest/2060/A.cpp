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
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    int a3 = a1 + a2;

    int ans1 = 1;
    if(a2 + a3 == a4){
        ans1++;
    }
    if(a3 + a4 == a5){
        ans1++;
    }
    a3 = a4 - a2;
    int ans2 = 1;
    if(a1 + a2 == a3){
        ans2++;
    }
    if(a3 + a4 == a5){
        ans2++;
    }
    cout << max(ans2, ans1) << "\n";

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}