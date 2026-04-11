#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    int cur = 0;
    std::vector<int> freqs(m + 1);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    i64 ans = 0;
    bool ok = false;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && m > cur) {
            freqs[a[j]]++;
            if (freqs[a[j]] == 1) {
                cur++;
            }
            j++;
        }
        if (cur == m) {
            ans += i64(n - j + 1);
        }
        
        freqs[a[i]]--;
        if (freqs[a[i]] == 0) {
            cur--;
        }
    }
    std::cout << ans;

    return 0;
}