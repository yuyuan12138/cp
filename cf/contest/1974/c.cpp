#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<std::vector<int>> mp;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        pos[a[i]].push_back(i);
    }
    for (auto [x, pos] : mp) {
        
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
}
