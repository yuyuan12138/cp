#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<std::vector<std::vector<i64>>> memo(23, std::vector<std::vector<i64>> (23, std::vector<i64> (23, -1)));
    auto w = [&](this auto&& self, i64 a, i64 b, i64 c) -> i64 {
        if (a <= 0 || b <= 0 || c <= 0) {
            return 1ll;
        } else if (a > 20 || b > 20 || c > 20) {
            return self(20, 20, 20);
        } 
        if (memo[a][b][c] != -1) {
            return memo[a][b][c];
        }
        if (a < b && b < c) {
            i64 ans = self(a, b, c - 1) + self(a, b - 1, c - 1) - self(a, b - 1, c);
            memo[a][b][c] = ans;
            return ans;
        } else {
            i64 ans = self(a - 1, b, c) + self(a - 1, b - 1, c) + self(a - 1, b, c - 1) - self(a - 1, b - 1, c - 1);
            memo[a][b][c] = ans;
            return ans;
        }
    };
    while (true) {
        i64 a, b, c;
        std::cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            break;
        } else {
            std::cout << "w(" << a << ", " << b << ", " << c << ") = ";
            std::cout << w(a, b, c) << '\n';
        }
    }
    return 0;
}
