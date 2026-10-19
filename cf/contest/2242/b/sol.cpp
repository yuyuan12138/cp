#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    } 
    int idx = 0;
    int cnt = ((a[idx] > 1) ? +1 : -1);
    idx++;
    for (int i = idx; i < n; i++) {
        cnt += ((a[i] > 1) ? +1 : -1); 
        if (cnt <= 0) {
            idx = i;
            break;
        }
    }
    idx++;
    if (idx == n) {
        std::cout << "NO\n";
        return ;
    }
    cnt = ((a[idx] > 2) ? +1 : -1);
    idx++;
    for (int i = idx; i < n; i++) {
        cnt += ((a[i] > 2) ? +1 : -1); 
        if (cnt <= 0) {
            idx = i;
            break;
        }
    }
    if (idx >= n - 1) {
        std::cout << "NO\n";
        return ;
    }
    std::cout << "YES\n";
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
