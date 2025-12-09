#include <bits/stdc++.h>

constexpr int N = 1e5 + 3;

std::vector<std::vector<int>> init(N + 1);

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int cur = 0;
    std::vector<int> cnt(m + 1);
    std::set<int> st;
    int ans = INT32_MAX;
    int fast = 0;
    int glob = 0;
    for (int slow = 0; slow < n; slow++) {
        while (fast < n && glob < m) {
            for (int x: init[a[fast]]) {
                if (x <= m) {
                    cnt[x]++;
                    if (cnt[x] == 1) {
                        glob++;
                    }
                }
            }
            fast++;
        }
        if (glob == m) {
            ans = std::min(ans, a[fast - 1] - a[slow]);
        }
        for (int x: init[a[slow]]) {
            if (x <= m) {
                cnt[x]--;
                if (cnt[x] == 0) {
                    glob--;
                }
            }
        }
    }
    std::cout << (ans == INT32_MAX ? -1 : ans) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                init[i].push_back(j);
                init[i].push_back(i / j);
            }
        }
    }
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
