#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    bool ok = true;
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (i > 0 && std::abs(a[i] - a[i - 1]) > 1) {
            ok = false;
        }
    }
    if (!ok) {
        std::cout << "0\n";
    } else {
        int ans = 0;
        auto check = [&](int state) {
            std::vector<int> b(n, -1);
            b[0] = state;
            bool flag = true;
            for (int i = 1; i < n; i++) {
                if (a[i] > a[i - 1]) {
                    if (b[i - 1] == 1) {
                        flag = false;
                    }
                    b[i] = 0;
                }
                if (a[i] < a[i - 1]) {
                    if (b[i - 1] == 0) {
                        flag = false;
                    }
                    b[i] = 1;
                }
                if (a[i] == a[i - 1]) {
                    if (b[i - 1] == 1) {
                        b[i] = 0;
                    } else {
                        b[i] = 1;
                    }
                }
            }
            std::vector<int> pref(n + 1);
            for (int i = 0; i < n; i++) {
                if (b[i] == 0) {
                    pref[i + 1] += 1;
                }
                pref[i + 1] += pref[i];
            }
            pref.erase(pref.begin());
            for (int i = 0; i < n; i++) {
                int cnt = 1;
                if (i < n - 1) {
                    cnt += n - i - 1 - (pref[n - 1] - pref[i]);
                }
                if (i > 0) {
                    cnt += pref[i - 1];
                }
                if (cnt != a[i]) {
                    flag = false;
                }
            }

            if (flag) {
                ans++;
            }
        };
        check(0);
        check(1);
        std::cout << ans << '\n';
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
