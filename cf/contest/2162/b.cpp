#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ans.push_back(i);
        }
    }
    std::cout << ans.size() << '\n';
    for (int x : ans) {
        std::cout << x + 1 << " ";
    }
    std::cout << '\n';
    return ;
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
