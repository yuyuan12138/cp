#include <bits/stdc++.h>

/**   动态取模类（ModIntBase）
 *    2024-08-14:
 *https://ac.nowcoder.com/acm/contest/view-submission?submissionId=70980889&returnHomeType=1&uid=329687984
 **/
// TODO: Dynamic ModInt

using u32 = unsigned int;
using u64 = unsigned long long;

template <typename T>
constexpr T power(T a, u64 b) {
    T res{1};
    for (; b != 0; b /= 2, a *= a) {
        if (b % 2 == 1) {
            res *= a;
        }
    }
    return res;
}

template <u32 P>
constexpr u32 mulMod(u32 a, u32 b) {
    return 1ULL * a * b % P;
}

template <u64 P>
constexpr u64 mulMod(u64 a, u64 b) {
    u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}

template <typename U, U P>
requires std::unsigned_integral<U> struct ModIntBase {
   public:
    constexpr ModIntBase() : x{0} {}

    template <typename T>
    requires std::integral<T> constexpr ModIntBase(T x_) : x{norm(x_ % T{P})} {}

    constexpr static U norm(U x) {
        if ((x >> (8 * sizeof(U) - 1) & 1) == 1) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }

    constexpr U val() const { return x; }

    constexpr ModIntBase operator-() const {
        ModIntBase res;
        res.x = norm(P - x);
        return res;
    }

    constexpr ModIntBase inv() const { return power(*this, P - 2); }

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

template <u32 P>
using ModInt = ModIntBase<u32, P>;

template <u64 P>
using ModInt64 = ModIntBase<u64, P>;

constexpr u32 P = 998244353;
using Z = ModInt<P>;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::vector<Z> f(n);
    f[0] = 2;
    for (int i = 1; i < n; i++) {
        if (std::min(a[i], b[i]) >= std::max(a[i - 1], b[i - 1])) {
            f[i] = f[i - 1] * 2;
        } else if (std::max(a[i], b[i]) <= std::min(a[i - 1], b[i - 1])) {
            f[i] = 0;
        } else {
            f[i] = f[i - 1];
        }
    }
    std::cout << f[n - 1] << '\n';
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
