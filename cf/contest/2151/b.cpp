#include <bits/stdc++.h>

using i64 = long long;

void solve() {
   int n, m;
   std::cin >> n >> m;
   std::string s;
   std::cin >> s;
   std::set<int> st;
   for (int i = 0; i < m; i++) {
        int x;
        std::cin >> x;
        st.insert(x);
   }
   
   int cur = 1;
   for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            cur++;
            while (cur == 1 || st.contains(cur)) {
                cur++;
            }
            st.insert(cur);
            while (cur == 1 || st.contains(cur)) {
                cur++;
            }
        } else {
            cur++;
            st.insert(cur);
        }
        // std::cerr << cur << '\n';
   }
   std::cout << st.size() << '\n';
   for (int x: st) {
        std::cout << x << " ";
   }
   std::cout << '\n';
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
