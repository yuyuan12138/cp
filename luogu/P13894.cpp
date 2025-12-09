#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;
    const int n = s.size();

    std::vector<int> f(n);
    if (s[1] == '?' || (s[0] == s[1])) {
        f[1] = 1;
    }
    for (int i = 2; i < n; i++) {
        f[i] = f[i - 1];
        if (s[i] == '?' || s[i - 1] == '?') {
            f[i] = std::max(f[i - 1], f[i - 2] + 1);
        } else if (s[i] == s[i - 1]) {
            f[i] = std::max(f[i - 1], f[i - 2] + 1);
        }
    }
    std::cout << std::max(f[n - 1], f[n - 2]);

    return 0;
}

