#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(i);
    }
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (st.count(a[i] - 1)) {
            st.erase(st.find(a[i] - 1));
        }
    }

    int l = n, r = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            a[i] = *st.rbegin() + 1;
            st.erase(std::prev(st.end()));
            if (a[i] != i + 1) {
                l = i;
                break;
            }
        } else if (a[i] != i + 1 && a[i] != 0) {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            a[i] = *st.begin() + 1;
            st.erase(st.begin());
            if (a[i] != i + 1) {
                r = i;
                break;
            }
        } else if (a[i] != i + 1 && a[i] != 0) {
            r = i;
            break;
        }
    }
    std::cerr << l << " " << r << '\n';
    std::cout << std::max(0, r - l + 1) << "\n";
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
