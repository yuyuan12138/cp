#include <bits/stdc++.h>

void solve() {
    int q;
    std::cin >> q;
    std::deque<int> a, rev_a;
    int64_t ans = 0;
    int64_t rev_ans = 0;
    int64_t sum_a = 0;
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 3) {
            int64_t x;
            std::cin >> x;

            a.push_back(x);
            rev_a.push_front(x);
            sum_a += x;
            ans += x * a.size();
            rev_ans += sum_a;
        } else if (op == 2) {
            std::swap(a, rev_a);
            std::swap(rev_ans, ans);
        } else {
            ans = ans - a.back() * a.size() + sum_a;
            a.push_front(a.back());
            a.pop_back();
            rev_ans = rev_ans - sum_a + *rev_a.begin() * rev_a.size();
            rev_a.push_back(rev_a.front());
            rev_a.pop_front();
        }
        std::cout << ans << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
