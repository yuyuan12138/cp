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
    int n, x; cin >> n;
    cout << "mul 999999999" << endl;
    cin >> x;
    cout << "digit" << endl;
    cin >> x;
    if(n != 81){
        cout << "add " << n - 81 << endl;
        cin >> x;
    }
    cout << "!" << endl;
    cin >> x;
    assert(x == 1);
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}