#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << "! 1" << std::endl;
        return 0;
    }
  
    auto get = [](const int op, const std::vector<int>& q) -> int {
        std::cout << "? " << op << " ";
        std::cout << q.size();
        for (int x : q) {
            std::cout << " " << x + 1;
        }
        std::cout << std::endl;
        int x;
        std::cin >> x;
        return x;
    };
    if (n == 2) {
        int x = get(2, {0});
        if (x == -1) {
            std::cout << "! 1" << std::endl;
        } else {
            std::cout << "! 2" << std::endl;
        }
        return 0;
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 rand_num(seed);
    std::uniform_int_distribution<int> dist(0, 1);
    std::vector<int> p;
    while (true) {
        for (int i = 0; i < n; i++) {
            if (dist(rand_num)) {
                p.push_back(i);
            }
        }
        int x = get(1, p);
        if (x == 1) {
            break;
        } else {
            p.clear();
        }
    }
    int x = get(2, p);
    if (x != -1) {
        std::vector<int> np;
        std::set<int> st(p.begin(), p.end());
        for (int i = 0; i < n; i++) {
            if (!st.contains(i)) {
                np.push_back(i);
            }
        }
        p = std::move(np);
    }
    int lo = 0, hi = p.size() - 1;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        std::vector<int> np;
        for (int i = lo; i <= mid; i++) {
            np.push_back(p[i]);
        }
        int x = get(1, np);
        if (x == 1) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    std::cout << "! " << p[hi] + 1 << std::endl;
    return 0;
}
