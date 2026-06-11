#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            a[i] = 1;
        } else {
            a[i] = -1;
        }
        if (t[i] == '(') {
            b[i] = 1;
        } else {
            b[i] = -1;
        }
    }
    std::array<int, 2> pref({0, 0});
    for (int i = 0; i < n; i++) {
        pref[0] += a[i];
        pref[1] += b[i];
        if ((pref[0] < 0 && pref[1] < 2) || (pref[1] < 0 && pref[0] < 2)) {
            std::cout << "NO\n";
            return;
        }
        if (pref[0] < 0) {
            pref[0] += 2;
            pref[1] -= 2;
        }
        if (pref[1] < 0) {
            pref[1] += 2;
            pref[0] -= 2;
        }
    }
    if (pref[0] == 0 && pref[1] == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
