#include <bits/stdc++.h>

void solve() {
    int a, b;
    std::cin >> a >> b;
    int ans = 0;
    int x = a, y = b;
    int cur = 1;
    int flag = 0;
    int cnt = 0;
    while (x || y) {
        if (!flag) {
            if (cur > x) {
                break;
            } else {
                cnt++;
                x -= cur;
            }
        } else {
            if (cur > y) {
                break;
            } else {
                cnt++;
                y -= cur;
            }
        }
        cur *= 2;
        flag ^= 1;
    }
    ans = std::max(ans, cnt);
    x = a, y = b;
    cur = 1;
    flag = 1;
    cnt = 0;
    while (x || y) {
        if (!flag) {
            if (cur > x) {
                break;
            } else {
                cnt++;
                x -= cur;
            }
        } else {
            if (cur > y) {
                break;
            } else {
                cnt++;
                y -= cur;
            }
        }
        cur *= 2;
        flag ^= 1;
    }
    ans = std::max(ans, cnt);
    std::cout << ans << '\n';
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