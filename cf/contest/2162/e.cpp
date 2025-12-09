#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    if (n == 1) {
        for (int i = 0; i < k; i++) {
            std::cout << 1 << " \n"[i == k - 1];
        }
    } else if (n == 2) {
        if (a[0] == 1 && a[1] == 1) {
            int flag = 0;
            for (int i = 0; i < k; i++) {
                std::cout << (flag ? 1 : 2) << " \n"[i == k - 1];
                flag ^= 1;
            }
        } else if (a[0] == 2 && a[1] == 2) {
            int flag = 1;
            for (int i = 0; i < k; i++) {
                std::cout << (flag ? 1 : 2) << " \n"[i == k - 1];
                flag ^= 1;
            }
        } else {
            int flag = 1;
            for (int i = 0; i < k; i++) {
                std::cout << (flag ? 1 : 2) << " \n"[i == k - 1];
                flag ^= 1;
            }
        }
    } else {
        int x, y, z;
        std::set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(a[i]);
        }
        if (st.size() == n) {
            x = a[0], y = a[1], z = a[2];
        } else {
            for (int i = 1; i <= n; i++) {
                if (!st.contains(i)) {
                    x = i;
                    break;
                }
            }
            z = a[n - 1];
            for (int i = 1; i <= n; i++) {
                if (i != x && i != z) {
                    y = i;
                    break;
                }
            }
        }
        std::vector<int> base = {x, y, z};
        for (int i = 0; i < k; i++) {
            std::cout << base[i % 3] << " \n"[i == k - 1];
        }
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
    return 0;
}
