#pragma once
#include <bits/stdc++.h>

// =========================== dbg namespace ===========================
namespace dbg {

// ---------- helpers ----------
inline std::string trim_float(std::string s) {
    auto pos = s.find('.');
    if (pos == std::string::npos) return s;
    while (!s.empty() && s.back() == '0') s.pop_back();
    if (!s.empty() && s.back() == '.') s.pop_back();
    return s.empty() ? "0" : s;
}

template <class It>
std::string join(It first, It last, const char* sep = ", ") {
    std::string res;
    bool fst = true;
    for (; first != last; ++first) {
        if (!fst) res += sep;
        fst = false;
        res += *first;
    }
    return res;
}

// type traits
template <class...>
using void_t = void;

template <class T, class = void>
struct is_iterable : std::false_type {};
template <class T>
struct is_iterable<T, void_t<decltype(std::begin(std::declval<T>())),
                                                         decltype(std::end(std::declval<T>()))>>
        : std::true_type {};
template <class T>
constexpr bool is_iterable_v = is_iterable<T>::value;

template <class T>
struct is_string_like : std::false_type {};
template <>
struct is_string_like<std::string> : std::true_type {};
template <>
struct is_string_like<std::string_view> : std::true_type {};
template <>
struct is_string_like<const char*> : std::true_type {};
template <>
struct is_string_like<char*> : std::true_type {};
template <class T>
constexpr bool is_string_like_v = is_string_like<T>::value;

// ---------- to_string overloads (dbg::to_string) ----------
inline std::string to_string(const std::string& s) { return '"' + s + '"'; }
inline std::string to_string(std::string_view sv) {
    return to_string(std::string(sv));
}
inline std::string to_string(const char* s) {
    return s ? to_string(std::string(s)) : "null";
}
inline std::string to_string(char* s) {
    return s ? to_string(std::string(s)) : "null";
}

inline std::string to_string(char c) { return std::string("'") + c + "'"; }
inline std::string to_string(unsigned char c) {
    return std::to_string(static_cast<unsigned>(c));
}
inline std::string to_string(signed char c) {
    return std::to_string(static_cast<int>(c));
}

inline std::string to_string(bool b) { return b ? "true" : "false"; }

// arithmetic (except char already handled)
template <class T, std::enable_if_t<std::is_arithmetic_v<T> &&
                                                                                !std::is_same_v<T, char> &&
                                                                                !std::is_same_v<T, signed char> &&
                                                                                !std::is_same_v<T, unsigned char>,
                                                                        int> = 0>
std::string to_string(T v) {
    if constexpr (std::is_floating_point_v<T>) {
        std::ostringstream oss;
        oss.setf(std::ios::fixed);
        oss << std::setprecision(12) << v;
        return trim_float(oss.str());
    } else {
        return std::to_string(v);
    }
}

// pointers
inline std::string to_string(const void* p) {
    if (!p) return "nullptr";
    std::ostringstream oss;
    oss << "ptr(" << p << ")";
    return oss.str();
}
template <class T>
std::string to_string(T* p) {
    if (!p) return "nullptr";
    std::ostringstream oss;
    oss << "ptr(" << static_cast<const void*>(p) << ")";
    return oss.str();
}

// std::pair
template <class A, class B>
std::string to_string(const std::pair<A, B>& p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

// std::tuple
template <class Tup, std::size_t... I>
std::string tuple_impl(const Tup& t, std::index_sequence<I...>) {
    std::string res = "(";
    bool fst = true;
    ((res += (fst ? (fst = false, "") : ", ") + to_string(std::get<I>(t))), ...);
    res += ")";
    return res;
}
template <class... Ts>
std::string to_string(const std::tuple<Ts...>& t) {
    return tuple_impl(t, std::index_sequence_for<Ts...>{});
}

// std::optional
template <class T>
std::string to_string(const std::optional<T>& o) {
    if (!o) return "nullopt";
    return "opt(" + to_string(*o) + ")";
}

// std::variant
template <class... Ts>
std::string to_string(const std::variant<Ts...>& v) {
    std::string res = "var(";
    std::visit([&](auto const& val) { res += to_string(val); }, v);
    res += ")";
    return res;
}

// std::complex
template <class T>
std::string to_string(const std::complex<T>& z) {
    return "(" + to_string(z.real()) + (z.imag() < 0 ? "" : "+") +
                 to_string(z.imag()) + "i)";
}

// std::bitset
template <size_t N>
std::string to_string(const std::bitset<N>& b) {
    return "0b" + b.to_string();
}

// std::valarray
template <class T>
std::string to_string(const std::valarray<T>& v) {
    std::string res = "{";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) res += ", ";
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

// chrono durations
template <class Rep, class Period>
std::string to_string(const std::chrono::duration<Rep, Period>& d) {
    using ns = std::chrono::nanoseconds;
    auto n = std::chrono::duration_cast<ns>(d).count();
    return to_string(n) + "ns";
}
// chrono time_point (prints since epoch in ns)
template <class Clock, class Dur>
std::string to_string(const std::chrono::time_point<Clock, Dur>& tp) {
    using ns = std::chrono::nanoseconds;
    auto n = std::chrono::duration_cast<ns>(tp.time_since_epoch()).count();
    return "tp(" + to_string(n) + "ns)";
}

// string-like containers special casing is handled by trait below
// generic iterable containers (vector/list/deque/set/map/unordered_* etc.)
template <class T,
                    std::enable_if_t<is_iterable_v<T> && !is_string_like_v<T>, int> = 0>
std::string to_string(const T& cont) {
    std::string res = "{";
    bool fst = true;
    for (auto&& x : cont) {
        if (!fst) res += ", ";
        fst = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

// array already covered by iterable;
// forward_list/list/deque/set/multiset/unordered_* 也都覆盖

// adapters: stack / queue / priority_queue
template <class T, class C>
std::string to_string(std::stack<T, C> st) {
    std::string res = "stack[";
    bool fst = true;
    while (!st.empty()) {
        if (!fst) res += ", ";
        fst = false;
        res += to_string(st.top());
        st.pop();
    }
    res += "]";
    return res;
}

template <class T, class C>
std::string to_string(std::queue<T, C> q) {
    std::string res = "queue<";
    bool fst = true;
    while (!q.empty()) {
        if (!fst) res += ", ";
        fst = false;
        res += to_string(q.front());
        q.pop();
    }
    res += ">";
    return res;
}

template <class T, class C, class Cmp>
std::string to_string(std::priority_queue<T, C, Cmp> pq) {
    std::string res = "pq<";
    bool fst = true;
    while (!pq.empty()) {
        if (!fst) res += ", ";
        fst = false;
        res += to_string(pq.top());
        pq.pop();
    }
    res += ">";
    return res;
}

// span (C++20)
#if defined(__cpp_lib_span) && __cpp_lib_span >= 202002L
template <class T, size_t Ext>
std::string to_string(std::span<T, Ext> sp) {
    std::string res = "{";
    for (size_t i = 0; i < sp.size(); ++i) {
        if (i) res += ", ";
        res += to_string(sp[i]);
    }
    res += "}";
    return res;
}
#endif

// string_view is already handled above; pair/tuple handled; map-like -> pair
// 打印

// ---------- debug out ----------
inline void out() { std::cerr << std::endl; }
template <class Head, class... Tail>
void out(const Head& h, const Tail&... t) {
    std::cerr << " " << to_string(h);
    out(t...);
}

}  // namespace dbg

// =========================== macro ===========================
#ifdef LOCAL
#define debug(...)                         \
    do {                                     \
        std::cerr << "[" #__VA_ARGS__ << "]:"; \
        ::dbg::out(__VA_ARGS__);               \
    } while (0)
#else
#define debug(...) ((void)0)
#endif
