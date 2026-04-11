#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }   
    for (auto [ch, cnt] : mp) {
        if (cnt == 1) {
            std::cout << ch;
        }
    }
    return 0;
}