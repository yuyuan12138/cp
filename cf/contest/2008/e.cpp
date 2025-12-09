#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<std::vector<int>> cnt(2, std::vector<int> (26));
    for (int i = 0; i < n; i++) {
        cnt[i % 2][s[i] - 'a']++;
    }
    int ans = n;
    int mx1 = *std::max_element(cnt[0].begin(), cnt[0].end());
    int mx2 = *std::max_element(cnt[1].begin(), cnt[1].end());
    if (n % 2 == 0) {
        ans = n - mx1 - mx2;
    } 
    {
        
        for (int i = n - 1; i >= 0; i--) {
            cnt[i % 2][s[i] - 'a']--;
            if (n % 2 == 1)
            ans = std::min(n - *std::max_element(cnt[0].begin(), cnt[0].end()) 
                - *std::max_element(cnt[1].begin(), cnt[1].end()), ans);
            cnt[(i + 1) % 2][s[i] - 'a']++;
        }
        std::cout << ans << '\n';
    }

    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
