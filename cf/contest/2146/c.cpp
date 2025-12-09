#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> ans(n);
    std::set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            st.erase(st.find(i + 1));
            ans[i] = i + 1;
        } else {
            bool ok = false;

            if ((i > 0 && s[i - 1] == '0') || (i < n - 1 && s[i + 1] == '0')) {
                ok = true;
            }
            if (!ok) {
                std::cout << "NO\n";
                return;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i + 1] != '1' && s[i] != '1') {
            ans[i] = i + 2;
            st.erase(st.find(i + 2));
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) {
            ans[i] = *st.begin();
            st.erase(st.begin());
        }
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
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
