/**
 *      author:  yuyuan567
 *      created: 2025-08-20 15:40:44
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        std::string s;
        std::cin >> s;
        int q;
        std::cin >> q;
        std::set<int> st; 
        for (int i = 3; i < s.size(); i++) {
            if (s[i] == '0' && s[i - 1] == '0' && s[i - 2] == '1' && s[i - 3] == '1') {
                st.insert(i);
            } 
        }
        int n = s.size();
        while (q--) {
            int i, v;
            std::cin >> i >> v;
            i--;
            if (v == 0 && s[i] != '0') {
                if (i < n - 2 && st.count(i + 2)) {
                    st.erase(i + 2);
                }
                if (i < n - 3 && st.count(i + 3)) {
                    st.erase(i + 3);
                }
                if ((i >= 2 && i < n - 1 && s[i + 1] == '0' && s[i - 1] == '1' && s[i - 2] == '1')) {
                    st.insert(i + 1);
                }
                if ((i >= 3 && i < n && s[i - 1] == '0' && s[i - 2] == '1' && s[i - 3] == '1')) {
                    st.insert(i);
                }
                s[i] = '0';
            } else if (v == 1 && s[i] != '1') {
                if (i < n && st.count(i)) {
                    st.erase(i);
                }
                if (i < n - 1 && st.count(i + 1)) {
                    st.erase(i + 1);
                }
                if (i >= 1 && i < n - 2 && s[i - 1] == '1' && s[i + 1] == '0' && s[i + 2] == '0') {
                    st.insert(i + 2);
                }
                if (i < n - 3 && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') {
                    st.insert(i + 3);
                }
                s[i] = '1';
            }
            if (st.size() > 0) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        }
    }
    return 0;
}
