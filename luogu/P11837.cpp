/**
 *    author:  Yuyuan
 *    created: 2026-04-18 15:18:38
 **/
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> freqs(n + 1);
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        freqs[x]++;
    }
    int cnt = 0;
    for (int mex = 0; mex <= n; mex++) {
        std::cout << std::max(cnt, freqs[mex]) << '\n';
        cnt += (freqs[mex] == 0);
    }
    return 0;
}
