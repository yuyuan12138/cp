#include <bits/stdc++.h>

using i64 = long long;

int power(int a, i64 b, int p) {
    int res = 1;
    for (; b; b /= 2, a = i64(1) * a * a % p) {
        if (b % 2) {
            res = i64(1) * res * a % p;
        }
    }
    return res;
}

i64 mul(i64 a, i64 b, i64 p) {
    i64 c = a * b - i64(1.0L * a * b / p) * p;
    c %= p;
    if (c < 0) {
        c += p;
    }
    return c;
}

i64 power(i64 a, i64 b, i64 p) {
    i64 res = 1;
    for (; b; b /= 2, a = mul(a, a, p)) {
        if (b % 2) {
            res = mul(res, a, p);
        }
    }
    return res;
}


void solve() {
    i64 k;
    i64 n;
    std::cin >> k >> n;
    i64 num = power(10LL, k, 1E12) - 1;
    std::cerr << num << '\n';
    if (n % num == 0) {
        std::cout << "aya\n";
    } else {
        std::cout << "baka\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}