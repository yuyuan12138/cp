#include <bits/stdc++.h>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> dir(n), cnt(n);
    if (n == 1) {
        std::cout << "YES\n";
        return ;
    }
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = 1 - (s[i] - '0');
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            int c = 0;
            if (i > 0 && a[i - 1] == 1) {
                c++;
            }
            if (i < n - 1 && a[i + 1] == 1) {
                c++;
            }
            if (c == 2) {
                if (dir[i - 1] != 0) {
                    dir[i + 1] = -dir[i - 1];
                }
            }
            if (c == 1) {
                if (i == 0) {
                    dir[i + 1] = 1;
                } else if (i == n - 1) {
                    if (dir[i - 1] == 1) {
                        ok = false;
                    } 
                } else if (a[i - 1] == 1) {
                    if (dir[i - 1] == 1) {
                        ok = false;
                    }
                } else if (a[i + 1] == 1) {
                    dir[i + 1] = 1;
                }
            }
        }
    }
    std::cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}