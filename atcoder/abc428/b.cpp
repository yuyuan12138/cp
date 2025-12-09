#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::string s;
    int n, k;
    std::cin >> n >> k;
    std::cin >> s;
    std::map<std::string, int> mp;
    for (int i = 0; i + k <= n; i++) {
        mp[s.substr(i, k)]++;
    }
    int max = 0;
    for (auto& [c, cnt] : mp) {
        max = std::max(cnt, max);
    }
    std::set<std::string> st;
    for (auto& [c, cnt] : mp) {
        if (cnt == max) {
            st.insert(c);
        }
    }
    std::cerr << mp["owo"] << '\n';
    std::cout << max << '\n';
    for (auto x : st) {
        std::cout << x << " ";
    }
    return 0;
}
