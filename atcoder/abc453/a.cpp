/**
 *    author:  Yuyuan
 *    created: 2026-04-18 14:57:29
 **/
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (!ok && s[i] == 'o') {
            continue;
        } else {
            ok = true;
            std::cout << s[i];
        }
    }

    return 0;
}
