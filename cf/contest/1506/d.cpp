#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        mp[x]++;
    }
    std::vector<int> a;
    int sum = 0;
    for (auto [key, value] : mp) {
        a.push_back(value);
        sum += value;
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    sum -= a[0];
    if (sum <= a[0]) {
        std::cout << a[0] - sum << '\n';
    } else {
        std::cout << n % 2 << '\n';
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
