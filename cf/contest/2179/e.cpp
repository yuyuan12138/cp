#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::string s;
    std::cin >> s;
    std::vector<int> p(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            b[i] = p[i];
        } else {
            a[i] = p[i];
        }
    }
    i64 sum_a = std::accumulate(a.begin(), a.end(), 0ll);
    i64 sum_b = std::accumulate(b.begin(), b.end(), 0ll);
    int cnt = std::count(s.begin(), s.end(), '0');  
    if (cnt > x || (n - cnt) > y) {
        std::cout << "NO\n";
        return;
    }
    if (sum_a > x && sum_b > x) {
        std::cout << "NO\n";
    } else if (sum_a <= x && sum_b <= x) {
        if (cnt == 0) {
            if (x >= y - sum_b) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        } else if (cnt == n) {
            if (y >= x - sum_a) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        } else {
            std::cout << "YES\n";
        }
    } else {
        bool flag = (sum_a <= x);
        for (int i = 0; i < n; i++) {
            int less_one = (p[i] + 1) / 2 - 1;
            if (s[i] == '1') {
                b[i] = p[i] - less_one;
                a[i] = less_one;
            } else {
                b[i] = less_one;
                a[i] = p[i] - less_one;
            }
        }
        sum_a = std::accumulate(a.begin(), a.end(), 0ll);
        sum_b = std::accumulate(b.begin(), b.end(), 0ll);
        if ((sum_a <= x) ^ (flag)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    
    return ;
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