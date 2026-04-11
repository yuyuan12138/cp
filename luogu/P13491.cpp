#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            ok = false;
        }
    }
    std::cout << (ok ? "Yes\n" : "No\n");

    return 0;
}
