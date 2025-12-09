#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n), pref(n + 1);
    std::map<int, std::vector<int>> at;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        at[a[i]].push_back(i);
        pref[i + 1] = pref[i] + a[i];
    }
    int ans = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int val = (pref[r + 1] - pref[l]);
            if (val % (r - l + 1) == 0) {
                val /= (r - l + 1);
                if (at.count(val)) {
                    auto pos = std::lower_bound(at[val].begin(), at[val].end(), l);
                    if (pos != at[val].end() && *pos <= r) {
                        ans++;
                    }
                }
            }
        }
    }
    std::cout << ans;
    return 0;
}
