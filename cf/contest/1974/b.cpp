#include <bits/stdc++.h>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::set<char> st;
    for (int i = 0; i < n; i++) {
        st.insert(s[i]);
    }
    std::vector<char> a(st.begin(), st.end());
    std::map<char, char> mp;
    for (int i = 0; i < a.size(); i++) {
        mp[a[i]] = a[a.size() - i - 1];
    }
    for (int i = 0; i < n; i++) {
        s[i] = mp[s[i]];
    }
    std::cout << s << '\n';
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
