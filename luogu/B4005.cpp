#include <iostream>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    int max = 0;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            for (int i = 0; i < n - x + 1; i++) {
                for (int j = 0; j < m - y + 1; j++) {
                    int cnt = 0;
                    for (int l = i; l < i + x; l++) {
                        for (int r = j; r < j + y; r++) {
                            cnt += (s[l][r] == '1');
                        }
                    }
                    if (cnt * 2 == x * y) {
                        max = std::max(max, cnt * 2);
                    }
                }
            }
        }
    }
    std::cout << max;
    return 0;
}