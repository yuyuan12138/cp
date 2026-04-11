/**
 * @author: yuyuan567
 * @date: 2025-07-25 14:41:35
 */

#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int k; cin >> k;

    if(k == 0){
        cout << "0\n";
    }else{
        vector<pair<int, int>> ans;
        [&](this auto&& self, int remaining, int start_idx, int y) -> void {
            if(remaining == 0){
                return ;
            }
            int mx = 0;
            for(int i = 1; i * (i - 1) / 2 <= remaining; i++){
                mx = i;
                ans.emplace_back(i + start_idx - 1, y);
            }
            self(remaining - mx * (mx - 1) / 2, mx + start_idx, y + 1);
        }(k, 1, 1);
        cout << ans.size() << "\n";
        debug(ans.size());
        for(auto& [fst, snd]: ans){
            cout << fst << " " << snd << "\n";
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