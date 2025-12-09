#include <bits/stdc++.h>

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::array<int, 3>> queries(q);
    for (int i = 0; i < q; i++) {
        queries[i][0] = i;
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        queries[i][1] = l;
        queries[i][2] = r;
    }
    std::sort(queries.begin(), queries.end(), [](const auto& a, const auto& b) -> bool {
        if (a[2] == b[2]) {
            if (a[1] == b[1]) {
                return a[0] < b[0];
            } else {
                return a[1] < b[1];
            }
        } else {
            return a[2] < b[2];
        }
    });
    std::vector<int> ans(q);
    int cur = 0;
    Fenwick<int> fw(n);
    int cnt = 0;
    for (int i = 0; i < q; i++) {
        while (cur <= queries[i][2]) {
            if (cur > 0 && a[cur] > a[cur - 1]) {
                fw.add(cur, 1);
            }
            cur++;
        }
        ans[queries[i][0]] = fw.rangeSum(queries[i][1], cur);
    }
    for (int i = 0; i < q; i++) {
        std::cout << ans[i] + 1 << " \n"[i != q - 1];
    }
    return 0;
}