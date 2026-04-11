#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int cur = 0;
    int ans = INT32_MAX;
    std::set<char> st, st2;
    for (int i = 0; i < n; i++) {
        st.insert(s[i]);
    }
    std::map<char, int> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
        st2.insert(s[i]);
        while (mp[s[cur]] >= 2 && cur < i) {
            mp[s[cur]]--;
            cur++;
        }
        if (st2.size() == st.size()) {
            ans = std::min(i - cur + 1, ans);
        }
    }
    std::cout << ans;
    return 0;
}
