#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s, t;
    std::cin >> s >> t;
    
    std::map<char, std::map<char, int>> mp;
    for (int i = 0; i < 4; i++) {
        char l, r;
        if (i == 0) {
            l = 'A'
        } else if (i == 1) {
            l = 'T';
        } else if (i == 2) {
            l = 'C';
        } else {
            l = 'G';
        }
        for (int j = 0; j < 4; j++) {
            if (j == 0) {
                r = 'A'
            } else if (j == 1) {
                r = 'T';
            } else if (j == 2) {
                r = 'C';
            } else {
                r = 'G';
            }
            std::cin >> mp[l][r];
        }
    }
    int a, b;
    std::cin >> a >> b;
    std::vector f()
    return 0;
}
