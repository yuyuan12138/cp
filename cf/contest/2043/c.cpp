#include <bits/stdc++.h>

constexpr int inf = 1e9;

void solve() {
    int n;
    std::cin >> n;
    int idx = -1;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] != -1 && a[i] != 1) {
            idx = i;
        }
    }
    idx = (idx == -1 ? n / 2 : idx);
    auto work = [&](int l, int r) -> std::pair<int, int> {
        std::vector<int> pref(r - l + 1);
        const int m = r - l;
        for (int i = 0; i < m; i++) {
            pref[i + 1] = pref[i] + a[l + i];
        }
        int min = inf, max = -inf;
        std::set<int> st;
        for (int i = 0; i <= m; i++) {
            st.insert(pref[i]);
            min = std::min(min, pref[i] - *st.rbegin());
            max = std::max(max, pref[i] - *st.begin());
        }
        return {min, max};
    };
    auto [l1, r1] = work(0, idx);
    auto [l2, r2] = work(idx + 1, n);
    // std::cerr << "(l: " << l1 << "), (r: " << r1 << ")\n";
    // std::cerr << "(l: " << l2 << "), (r: " << r2 << ")\n";

    std::set<int> ans;
    auto add = [&](int l, int r, int c) -> void {
        for (int i = l; i <= r; i++) {
            ans.insert(i + c);
        }
    };
    add(l1, r1, 0);
    add(l2, r2, 0);
    // add(l1, r1, a[idx]);
    // add(l2, r2, a[idx]);
    std::vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    std::set<int> st;
    for (int i = 0; i <= idx; i++) {
        st.insert(pref[i]);
    }
    int max = 0, min = inf;
    // std::cerr << idx << '\n';
    for (int i = idx + 1; i <= n; i++) {
        max = std::max(max, pref[i]);
        min = std::min(min, pref[i]);
    }
    add(min - *std::prev(st.end()), max - *st.begin(), 0);
    std::cout << ans.size() << '\n';
    for (int x : ans) {
        std::cout << x << " ";
    }
    std::cout << '\n';
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
