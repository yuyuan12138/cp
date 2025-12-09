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
    string s; cin >> s;
    sort(all(s), [](char& a, char& b) -> bool {
        if(a == b && a == 'T') return false;
        if(a == 'T') return true;
        if(b == 'T') return false;
        return a < b;
    });
    cout << s << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}