#include <bits/stdc++.h>

std::map<std::string, int> mp = {{"Ocelot", 0}, {"Serval", 1}, {"Lynx", 2}};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s, t;
    std::cin >> s >> t;
    if (mp[s] >= mp[t]) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
    return 0;
}