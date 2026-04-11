#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

constexpr int inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 n;
    int q;
    std::cin >> n >> q;
    std::vector<i64> qs(q);
    std::set<i64> vis;
    for (int i = 0; i < q; i++) {
        std::cin >> qs[i];
        vis.insert(qs[i]);
    }
    int max = *std::max_element(qs.begin(), qs.end());    
    
    return 0;
}