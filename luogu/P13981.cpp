#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rope __gnu_cxx::rope

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    rope<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int op, l, r, c;
        std::cin >> op;
        if (op == 0) {
            std::cin >> l >> r;
            l--;
            a.insert(l, r);
        } else {
            std::cin >> c;
            c--;
            std::cout << a.at(c) << '\n';
        }
    }
    return 0;
}