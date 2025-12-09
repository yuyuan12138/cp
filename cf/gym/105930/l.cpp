#include <bits/stdc++.h>

std::map<char, int> mp1 = {
    {'O', 100000},
    {'B', 200000},
    {'A', 300000},
    {'F', 400000},
    {'G', 500000},
    {'K', 600000},
    {'M', 700000},
};

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    int a = mp1[s[0]] + s[1] - '0';
    int b = mp1[t[0]] + t[1] - '0';
    if (a == b) {
        std::cout << "same\n";
    } else if (a < b) {
        std::cout << "hotter\n";
    } else {
        std::cout << "cooler\n";
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
