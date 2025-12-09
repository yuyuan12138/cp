#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int q;
    std::cin >> q;
    std::set<int> st;
    std::string s;
    int l = 0, r = 0;
    bool ok = false;
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            char c;
            std::cin >> c;
            if (c == ')') {
                if (r >= l) {
                    st.insert(int(s.size()));
                }
                r++;
            } else {
                l++;
            }
            s += c;
        } else {
            int idx = s.size() - 1;
            if (st.find(idx) != st.end()) {
                st.erase(st.find(idx));
            }
            if (s.back() == ')') {
                r--;
            } else {
                l--;
            }
            s.pop_back();
        }
        if (st.size() == 0) {
            ok = true;
        } else {
            ok = false;
        }
        if (ok && (l == r)) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}
