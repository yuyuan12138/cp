#include <bits/stdc++.h>

int work(int l, int r, std::vector<int> &a, int n) {
    std::vector<int> v;
    while (l >= 0 && r <= 2 * n - 1) {
        if (a[l] == a[r]) {
            v.push_back(a[l]);
            l--, r++;
        } else {
            break;
        }
    }
    std::sort(v.begin(), v.end());
    int mex = 0;
    for (int x : v) {
        if (x == mex) {
            mex++;
        }
    }
    return mex;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(2 * n);
    std::vector<int> p;
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> a[i];
        if (a[i] == 0) {
            p.push_back(i);
        }
    }
    int ans = 1;
    ans = std::max(work(p[0], p[0], a, n), ans);
    ans = std::max(work(p[1], p[1], a, n), ans);
    ans = std::max(work((p[0] + p[1]) / 2, (p[0] + p[1] + 1) / 2, a, n), ans);
    std::cout << ans << '\n';
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
