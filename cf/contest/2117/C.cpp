#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto& x : nums) cin >> x;
    set<int> cur, seen;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cur.insert(nums[i]);
        seen.insert(nums[i]);
        if(cur.size() == seen.size()){
            ans += 1;
            seen.clear();
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}