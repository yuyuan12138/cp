#include <bits/stdc++.h>

void solve() {
    int a, b;
    std::cin >> a >> b;
    int bit = 0;
    int na = a;
    std::vector<int> ans;
    bool ok = true;
    while (a || b) {
        if (!((a & 1) == (b & 1))) {
            ans.push_back(1 << bit);
            if ((1 << bit) > na) {
                ok = false;
            }
        } 
        bit++;
        a >>= 1, b >>= 1;
    }
    if (!ok) {
        std::cout << "-1\n";
    } else {
        std::cout << ans.size() << '\n';
        for (int x : ans) {
            std::cout << x << " ";
        }
        if (ans.size() != 0) {
            std::cout << '\n';
        }
        
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t; 
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
