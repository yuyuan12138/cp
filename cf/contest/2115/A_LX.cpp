// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));

    int g = a[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i]);
    }

    int count_g = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == g) count_g++;
    }

    if (count_g > 0) {
        cout << n - count_g << "\n";
        return;
    }

    int min_len = 0x3f3f3f3f;
    for (int i = 0; i < n - 1; ++i) {
        int cur_g = a[i];
        int beishu = 0;
        for (int j = i + 1; j < n; ++j) {
            
            if(a[j] % cur_g == 0){
                beishu ++;
                continue;
            }
            cur_g = gcd(cur_g, a[j]);
            if (cur_g == g) {
                min_len = min(min_len, j - i + 1 - beishu);
            }
        }
    }

    int result = (min_len - 1) + (n - 1);
    cout << result << '\n';
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}