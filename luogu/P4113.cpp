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

    int n, c, m;
    std::cin >> n >> c >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }  
    std::vector<std::array<int, 3>> q(m);
    for (int i = 0; i < m; i++) {
        q[i][0] = i;
        std::cin >> q[i][1] >> q[i][2];
        q[i][1]--, q[i][2]--;
    }
    std::sort(q.begin(), q.end(), [](const auto& a, const auto& b) -> bool {
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
    Fenwick<int> fw(n);
    std::vector<int> ans(m);
    std::vector<std::array<int, 2>> vis(c, {-1, -1});
    for (int i = 0, cur = 0; i < m; i++) {
        while (cur <= q[i][2]) {
            int color = a[cur];
            if (vis[color][0] != -1) {
                fw.add(vis[color][0], -1);
            }
            std::swap(vis[color][0], vis[color][1]);
            if (vis[color][0] != -1) {
                fw.add(vis[color][0], 1);
            }
            vis[color][1] = cur;
            cur++;
        }
        ans[q[i][0]] = fw.rangeSum(q[i][1], cur);
    }
    for (int i = 0; i < m; i++) {
        std::cout << ans[i] << '\n';
    }

    return 0;
}