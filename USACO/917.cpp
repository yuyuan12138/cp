#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::freopen("traffic.in", "r", stdin);
    std::freopen("traffic.out", "w", stdout);
    int n;
    std::cin >> n;
    std::vector<std::array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        std::string op;
        int lo, hi;
        std::cin >> op >> lo >> hi;
        if (op == "on") {
            a[i][0] = 0;
        } else if (op == "none") {
            a[i][0] = 1;
        } else {
            a[i][0] = 2;
        }
        a[i][1] = lo;
        a[i][2] = hi;
    }
    bool found = false;
    std::array<int, 2> ans1 = {-1, -1}, ans2 = {-1, -1};
    for (int i = n - 1; i >= 0; i--) {
        if (found) {
            if (a[i][0] == 0) {
                ans1[0] -= a[i][2];
                ans1[1] -= a[i][1];
                ans1[0] = std::max(ans1[0], 0);
                ans1[1] = std::max(ans1[1], 0);                
            } else if (a[i][0] == 1) {
                ans1[0] = std::max(a[i][1], ans1[0]);
                ans1[1] = std::min(a[i][2], ans1[1]);
            } else {
                ans1[0] += a[i][1];
                ans1[1] += a[i][2];
            }
        } else {
            if (a[i][0] == 1) {
                found = true;
                ans1[0] = a[i][1];
                ans1[1] = a[i][2];
            }
        }
    }    
    found = false;
    for (int i = 0; i < n; i++) {
        if (found) {
            if (a[i][0] == 0) {
                ans2[0] += a[i][1];
                ans2[1] += a[i][2];
            } else if (a[i][0] == 1) {
                ans2[0] = std::max(a[i][1], ans2[0]);
                ans2[1] = std::min(a[i][2], ans2[1]);
            } else {
                ans2[0] -= a[i][2];
                ans2[1] -= a[i][1];
                ans2[0] = std::max(ans2[0], 0);
                ans2[1] = std::max(ans2[1], 0);
            }
        } else {
            if (a[i][0] == 1) {
                found = true;
                ans2[0] = a[i][1];
                ans2[1] = a[i][2];
            }
        }
    }
    if (ans1[0] != -1) {
        std::cout << ans1[0] << " " << ans1[1] << '\n';
        std::cout << ans2[0] << " " << ans2[1];
    } else {
        ans1 = ans2 = {0, 0};
        for (int i = 0; i < n; i++) {
            if (a[i][0] == 0) {
                ans2[0] += a[i][1];
                ans2[1] += a[i][2];
            } else {
                ans2[0] -= a[i][2];
                ans2[1] -= a[i][1];
                ans2[0] = std::max(ans2[0], 0);
                ans2[1] = std::max(ans2[1], 0);
            }
        }
        for (int i = n - 1; i >= 0; i++) {
            if (a[i][0] == 0) {
                ans1[0] -= a[i][2];
                ans1[1] -= a[i][1];
                ans1[0] = std::max(ans1[0], 0);
                ans1[1] = std::max(ans1[1], 0); 
            } else {
                ans1[0] += a[i][1];
                ans1[1] += a[i][2];
            }
        }
        std::cout << ans1[0] << " " << ans1[1] << '\n';
        std::cout << ans2[0] << " " << ans2[1];
    }
    return 0;
}