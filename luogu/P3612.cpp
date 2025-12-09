#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    i64 n;
    std::cin >> n;
    
    i64 size = s.size();

    auto find = [&](this auto&& self, i64 r) -> i64 {
        if (r <= size) {
            return r;
        } else {
            i64 tmp = size;
            while (true) {
                if ((tmp << 1) >= r) {
                    break;
                } else {
                    tmp <<= 1;
                }
            }
            if (r == tmp + 1) {
                // std::cerr << "tmp: " << tmp << '\n';
                return self(tmp);
            } else {
                // std::cerr << "r - tmp - 1: " << r - tmp - 1 << '\n';
                return self(r - tmp - 1);
            }
        }
    };

    i64 idx = find(n);
    // std::cerr << idx << '\n';
    std::cout << s[idx - 1];

    return 0;
}
