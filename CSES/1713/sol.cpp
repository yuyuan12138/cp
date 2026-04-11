#include <bits/stdc++.h>

constexpr int N = 1e6;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    std::vector<int> memo(N);

    for (int x = 1; x <= N; x++) {
        for (int i = 1; i * x <= N; i++) {
            memo[i * x]++;
        }
    }
    while (t--) {
        int n;
        std::cin >> n;
        std::cout << memo[n] << '\n';
    }

    return 0;
}
