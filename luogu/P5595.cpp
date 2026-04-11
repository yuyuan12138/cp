#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    bool ok = true;
    std::string a, b;
    const int n = s.size();
    int cnt = std::count(s.begin(), s.end(), 'Z');
    for (int i = 0; i < n; i++) {
        if (s[i] == 'Z') {
            if (n - i != cnt) {
                ok = false;
                break;
            } else {
                cnt--;                
            }
        }
    }
    if (!ok) {
        std::cout << -1;
    } else {
        int i = n - 1;
        for (; i >= 0; i--) {
            if (s[i] != 'Z') {
                break;
            } else {
                a += '0';
                b += '0';
            }
        }
        for (; i >= 0; i--) {
            if (s[i] == 'Y') {
                a += '0';
                b += '1';
            } else {
                a += '1';
                b += '0';
            }
        }
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        std::cout << a << '\n';
        std::cout << b;
    }
    return 0;
}
