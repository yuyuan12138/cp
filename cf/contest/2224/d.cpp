#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;

template <typename T> constexpr T power(T a, u64 b) {
    T res{1};
    for (; b != 0; b /= 2, a *= a) {
        if (b % 2 == 1) {
            res *= a;
        }
    }
    return res;
}

template <u32 P> constexpr u32 mulMod(u32 a, u32 b) {
    return 1ULL * a * b % P;
}

template <u64 P> constexpr u64 mulMod(u64 a, u64 b) {
    u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}

template <typename U, U P>
    requires std::unsigned_integral<U>
struct ModIntBase {
  public:
    constexpr ModIntBase() : x{0} {
    }

    template <typename T>
        requires std::integral<T>
    constexpr ModIntBase(T x_) : x{norm(x_ % T{P})} {
    }

    constexpr static U norm(U x) {
        if ((x >> (8 * sizeof(U) - 1) & 1) == 1) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }

    constexpr U val() const {
        return x;
    }

    constexpr ModIntBase operator-() const {
        ModIntBase res;
        res.x = norm(P - x);
        return res;
    }

    constexpr ModIntBase inv() const {
        return power(*this, P - 2);
    }

    constexpr ModIntBase &operator*=(const ModIntBase &rhs) & {
        x = mulMod<P>(x, rhs.val());
        return *this;
    }

    constexpr ModIntBase &operator+=(const ModIntBase &rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }

    constexpr ModIntBase &operator-=(const ModIntBase &rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }

    constexpr ModIntBase &operator/=(const ModIntBase &rhs) & {
        return *this *= rhs.inv();
    }

    friend constexpr ModIntBase operator*(ModIntBase lhs,
                                          const ModIntBase &rhs) {
        lhs *= rhs;
        return lhs;
    }

    friend constexpr ModIntBase operator+(ModIntBase lhs,
                                          const ModIntBase &rhs) {
        lhs += rhs;
        return lhs;
    }

    friend constexpr ModIntBase operator-(ModIntBase lhs,
                                          const ModIntBase &rhs) {
        lhs -= rhs;
        return lhs;
    }

    friend constexpr ModIntBase operator/(ModIntBase lhs,
                                          const ModIntBase &rhs) {
        lhs /= rhs;
        return lhs;
    }

    friend constexpr std::ostream &operator<<(std::ostream &os,
                                              const ModIntBase &a) {
        return os << a.val();
    }

    friend constexpr bool operator==(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr bool operator!=(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() != rhs.val();
    }

    friend constexpr bool operator<(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() < rhs.val();
    }

  private:
    U x;
};

constexpr i64 inf = 1e9;

template <u32 P> using ModInt = ModIntBase<u32, P>;

template <u64 P> using ModInt64 = ModIntBase<u64, P>;

constexpr u32 P = 998244353;
using Z = ModInt<P>;
template <typename T> struct Fenwick {
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

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    std::vector<i64> vals(n * n), avals(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        avals[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    if (n == 1) {
        std::cout << 0 << '\n';
        return;
    }
    Fenwick<int> fw(n * n), fwa(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vals[i * n + j] = 1LL * a[i] * b[j];
        }
    }

    std::sort(vals.begin(), vals.end());
    vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
    std::sort(avals.begin(), avals.end());
    avals.erase(std::unique(avals.begin(), avals.end()), avals.end());
    auto get_prod_id = [&](i64 x) {
        return int(std::lower_bound(vals.begin(), vals.end(), x) -
                   vals.begin());
    };
    auto get_a_id = [&](int x) {
        return int(std::lower_bound(avals.begin(), avals.end(), x) -
                   avals.begin());
    };

    std::vector<std::vector<int>> inv(n, std::vector<int>(n));
    Z res = 0;
    for (int i = 0; i < n; i++) {
        int bad = fwa.rangeSum(get_a_id(a[i]) + 1, n);
        for (int j = 0; j < n; j++) {
            int all = fw.rangeSum(get_prod_id(1ll * a[i] * b[j]) + 1, n * n);
            res += all - bad;
        }
        for (int j = 0; j < n; j++) {
            fw.add(get_prod_id(1ll * a[i] * b[j]), 1);
        }
        fwa.add(get_a_id(a[i]), 1);
    }
    res /= Z(n) * (n - 1);
    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
