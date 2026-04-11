#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, t;
    std::cin >> n >> t;
    std::string s;
    std::cin >> s;
    std::vector<std::array<int, 3>> a(t);
    for (int i = 0; i < t; i++) {
        std::cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][1]--;
        a[i][2]--;
    }
    std::sort(a.rbegin(), a.rend());
    std::string cur(n, '0');
    for (int i = 0; i < t; i++) {
        if (s[a[i][1]] == '1' && s[a[i][2]] == '1') {
            
        }
    }
    return 0;
}