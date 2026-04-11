#include <bits/stdc++.h>

void solve() {
    int n, km;
    std::cin >> n >> km;
    std::string s, t;
    std::cin >> s >> t;
    std::vector<std::string> res(km + 1, std::string(n, '?')); 
    std::map<char, std::vector<int>> pos;
    for (int i = 0; i < n; i++) {
        pos[s[i]].push_back(i);
    }
    int ptr = n - 1;
    int mx = -1;
    bool fail = false;
    for (int i = n - 1; i >= 0; i--) {
        int lo = 0, hi = pos[t[i]].size() - 1;
        ptr = std::min(i, ptr);
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (pos[t[i]][mid] > ptr) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        if (hi == -1) {
            fail = true;    
            break;
        }
        // std::cerr << "hi: " << hi <<  '\n';
        // std::cerr << "ptr: " << ptr << '\n';
        int idx = pos[t[i]][hi];
        ptr = idx;
        mx = std::max(mx, i - idx);
        for (int k = 1; k <= km; k++) {
            res[k][std::min(k + idx, i)] = t[i];
        }
    }
    if (fail || mx > km) {
        std::cout << -1 << '\n';
        return ;
    }
    std::cout << mx << '\n';
    res[0] = s;
    for (int k = 1; k <= mx; k++) {
        for (int i = 0; i < n; i++) {
            if (res[k][i] == '?') {
                res[k][i] = res[k - 1][i];
            }
        }
        std::cout << res[k] << '\n';
    }
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
