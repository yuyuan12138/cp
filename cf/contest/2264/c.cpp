#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128_t;

template<class T>
constexpr T power(T a, i64 b) {
    assert(b >= 0);

    T res = 1;
    while (b > 0) {
        if (b & 1) {
            res *= a;
        }
        b >>= 1;
        if (b > 0) {
            a *= a;
        }
    }
    return res;
}

constexpr i64 mul(i64 a, i64 b, i64 mod) {
    return i64(i128(a) * b % mod);
}

constexpr i64 invMod(i64 a, i64 mod) {
    assert(mod > 1);
    assert(a > 0 && a < mod);

    i64 b = mod;
    i128 u = 1;
    i128 v = 0;

    while (b != 0) {
        i64 t = a / b;

        a -= t * b;
        i64 tmpA = a;
        a = b;
        b = tmpA;

        u -= i128(t) * v;
        i128 tmpU = u;
        u = v;
        v = tmpU;
    }

    assert(a == 1);

    u %= mod;
    if (u < 0) {
        u += mod;
    }

    return i64(u);
}

template<i64 P>
struct MLong {
    static_assert(P >= 0);

    i64 x;

    static i64 Mod;

    constexpr MLong() : x(0) {}

    constexpr MLong(i64 v) : x(norm(v)) {}

    static constexpr i64 getMod() {
        if constexpr (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }

    static void setMod(i64 mod) {
        static_assert(P == 0);
        assert(mod > 0);
        Mod = mod;
    }

    static constexpr i64 norm(i128 v) {
        const i64 mod = getMod();

        v %= mod;
        if (v < 0) {
            v += mod;
        }

        return i64(v);
    }

    constexpr i64 val() const {
        return x;
    }

    explicit constexpr operator i64() const {
        return x;
    }

    constexpr MLong operator+() const {
        return *this;
    }

    constexpr MLong operator-() const {
        MLong res;
        res.x = (x == 0 ? 0 : getMod() - x);
        return res;
    }

    constexpr MLong inv() const {
        assert(x != 0);
        return MLong(invMod(x, getMod()));
    }

    constexpr MLong &operator+=(MLong rhs) & {
        const i64 mod = getMod();

        if (x >= mod - rhs.x) {
            x -= mod - rhs.x;
        } else {
            x += rhs.x;
        }

        return *this;
    }

    constexpr MLong &operator-=(MLong rhs) & {
        const i64 mod = getMod();

        if (x >= rhs.x) {
            x -= rhs.x;
        } else {
            x += mod - rhs.x;
        }

        return *this;
    }

    constexpr MLong &operator*=(MLong rhs) & {
        x = mul(x, rhs.x, getMod());
        return *this;
    }

    constexpr MLong &operator/=(MLong rhs) & {
        return *this *= rhs.inv();
    }

    friend constexpr MLong operator+(MLong lhs, MLong rhs) {
        return lhs += rhs;
    }

    friend constexpr MLong operator-(MLong lhs, MLong rhs) {
        return lhs -= rhs;
    }

    friend constexpr MLong operator*(MLong lhs, MLong rhs) {
        return lhs *= rhs;
    }

    friend constexpr MLong operator/(MLong lhs, MLong rhs) {
        return lhs /= rhs;
    }

    friend constexpr bool operator==(MLong lhs, MLong rhs) {
        return lhs.x == rhs.x;
    }

    friend constexpr bool operator!=(MLong lhs, MLong rhs) {
        return lhs.x != rhs.x;
    }

    friend std::istream &operator>>(std::istream &is, MLong &a) {
        i64 v;
        is >> v;
        a = MLong(v);
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, MLong a) {
        return os << a.val();
    }
};

template<i64 P>
i64 MLong<P>::Mod = 1000000000000000009LL;

template<int P>
struct MInt {
    static_assert(P >= 0);

    int x;

    static int Mod;

    constexpr MInt() : x(0) {}

    constexpr MInt(i64 v) : x(norm(v)) {}

    static constexpr int getMod() {
        if constexpr (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }

    static void setMod(int mod) {
        static_assert(P == 0);
        assert(mod > 0);
        Mod = mod;
    }

    static constexpr int norm(i64 v) {
        const int mod = getMod();

        v %= mod;
        if (v < 0) {
            v += mod;
        }

        return int(v);
    }

    constexpr int val() const {
        return x;
    }

    explicit constexpr operator int() const {
        return x;
    }

    constexpr MInt operator+() const {
        return *this;
    }

    constexpr MInt operator-() const {
        MInt res;
        res.x = (x == 0 ? 0 : getMod() - x);
        return res;
    }

    constexpr MInt inv() const {
        assert(x != 0);
        return MInt(invMod(x, getMod()));
    }

    constexpr MInt &operator+=(MInt rhs) & {
        const int mod = getMod();

        if (x >= mod - rhs.x) {
            x -= mod - rhs.x;
        } else {
            x += rhs.x;
        }

        return *this;
    }

    constexpr MInt &operator-=(MInt rhs) & {
        const int mod = getMod();

        if (x >= rhs.x) {
            x -= rhs.x;
        } else {
            x += mod - rhs.x;
        }

        return *this;
    }

    constexpr MInt &operator*=(MInt rhs) & {
        x = int(1LL * x * rhs.x % getMod());
        return *this;
    }

    constexpr MInt &operator/=(MInt rhs) & {
        return *this *= rhs.inv();
    }

    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        return lhs += rhs;
    }

    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        return lhs -= rhs;
    }

    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        return lhs *= rhs;
    }

    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        return lhs /= rhs;
    }

    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.x == rhs.x;
    }

    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.x != rhs.x;
    }

    friend std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, MInt a) {
        return os << a.val();
    }
};

template<int P>
int MInt<P>::Mod = 998244353;

template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 998244353;
using Z = MInt<P>;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end(), std::greater<int>());
	Z ans = 0;
	Z cur = a[0];
	Z cnt = 1;
	for (int i = 1; i < n; i++) {
		ans = ans * i + cnt * (cur - Z(a[i]) * i);
		cur += a[i];
		cnt *= i;
	}
	std::cout << ans << '\n';
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