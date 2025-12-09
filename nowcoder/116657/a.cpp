#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::map<char, int> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }
    auto check = [&]() -> bool {
        std::vector<int> cnt;
        for (auto& [ch, cnt_]: mp) {
            cnt.push_back(cnt_);
        }
        std::sort(cnt.begin(), cnt.end());
        bool ok = true;
        for (int i = 1; i < cnt.size(); i++) {
            if (cnt[i] != cnt[i - 1] + 1) {
                ok = false;
            }
        }
        return ok;
    };
    std::cout << (check() ? "YES\n" : "NO\n");
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
