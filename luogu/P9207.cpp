#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::set<int> pos, neg;
    int ans = 0;
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        if (x > 0) {
            pos.insert(x);
        } else if (x < 0) {
            neg.insert(-x);
        } else {
            ans++;
        }
    }
    int cur = 0;
    int max = (1 << (k - 1)), min = -(1 << (k - 1));
    while (true) {
        bool ok = false;
        if (cur <= 0 && !pos.empty() && cur + *pos.begin() < max) {
            int add = *pos.begin();
            cur += add;
            pos.erase(pos.find(add));
            ok = true;
            ans++;
        } else if (!neg.empty()) {
            
        }   
    }
    return 0;
}