#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s, t;
    std::cin >> s;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            t += c;
        }
    }
    std::sort(t.rbegin(), t.rend());
    std::cout << t;
    return 0;
}
