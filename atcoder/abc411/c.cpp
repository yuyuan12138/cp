#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 2);
    n = n + 2;
    int cnt = 0;
    while (q--) {
        int i;
        std::cin >> i;
        if (a[i] == 1) {
            a[i] = 0;
            if (a[i - 1] == 0) {
                cnt--;
            }
            if (a[i + 1] == 1) {
                cnt++;
            }
        } else {
            a[i] = 1;
            if (a[i - 1] == 0) {
                cnt++;
            }
            if (a[i + 1] == 1) {
                cnt--;
            }
        }
        std::cout << cnt << '\n';
    }
    return 0;
}
