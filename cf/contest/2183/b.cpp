#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> freqs(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        freqs[x]++;
    }
    int mex = 0;
    while (freqs[mex] != 0) {
        mex++;
    }
    std::cout << std::min(mex, k - 1) << '\n';
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