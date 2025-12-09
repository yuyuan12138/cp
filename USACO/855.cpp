#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int n = 100;
    std::vector<std::array<int, 2>> a(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            std::cin >> a[i][j];
        }
    }    
    int cur = 0;
    for (int i = 0; i < 100; i++) {
        int x1 = a[cur][0], x2 = a[cur][1];
        int y1 = a[(cur + 1) % 3][0], y2 = a[(cur + 1) % 3][1];
        if (y1 - y2 >= x2) {
            a[cur][1] = 0;
            a[(cur + 1) % 3][1] += x2;
        } else {
            a[(cur + 1) % 3][1] = y1;
            a[cur][1] = x2 - (y1 - y2);
        }
        cur = (cur + 1) % 3;
    }
    for (int i = 0; i < 3; i++) {
        std::cout << a[i][1] << '\n';
    }
    return 0;
}
