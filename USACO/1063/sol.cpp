#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    {
        std::vector<int> t(x);
        std::sort(t.begin(), t.end());
        t.erase(std::unique(t.begin(), t.end()), t.end());
        for (int i = 0; i < n; i++) {
            x[i] = std::lower_bound(t.begin(), t.end(), x[i]) - t.begin();
        }
    }
    {
        std::vector<int> t(y);
        std::sort(t.begin(), t.end());
        t.erase(std::unique(t.begin(), t.end()), t.end());
        for (int i = 0; i < n; i++) {
            y[i] = std::lower_bound(t.begin(), t.end(), y[i]) - t.begin();
        }
    }

    return 0;
}
