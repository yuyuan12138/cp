#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<char> ans(n, '+');
    std::vector<char> ans1;
    int cur = 0;
    std::vector<char> ans2;
    std::string op;
    std::cin >> op;
    for (int i = 0; i < k; i++) {
        if (op[i] == '0') {
            ans1.push_back('-');
        } else if (op[i] == '1') {
            ans2.push_back('-');
        } else {
            cur += 1;
        }
    }
    if (cur + ans1.size() + ans2.size() == n) {
        for (int i = 0; i < n; i++) {
            std::cout << "-";
        }
        std::cout << '\n';
    } else {
        for (int i = 0; i < ans1.size(); i++) {
            ans[i] = ans1[i];
        }
        for (int i = 0; i < ans2.size(); i++) {
            ans[n - i - 1] = ans2[i];
        }
        for (int i = 0; i < cur; i++) {
            if (ans[ans1.size() + i] == '+') {
                ans[ans1.size() + i] = '?';
            }
        }
        for (int i = 0; i < cur; i++) {
            if (ans[n - 1 - ans2.size() - i] == '+') {
                ans[n - 1 - ans2.size() - i] = '?';
            }
        }
        for (int i = 0; i < n; i++) {
            std::cout << ans[i];
        }
        std::cout << '\n';
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