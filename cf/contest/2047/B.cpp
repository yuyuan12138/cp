/**
 *      author:  yuyuan567
 *      created: 2025-07-28 15:53:18
 */
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(100);
    for (auto& c : s) {
        cnt[c - 'a']++;
    }
    sort(all(s), [&](char x, char y) { return cnt[x - 'a'] >= cnt[y - 'a']; });
    debug(s);
    for (auto& c : s) {
        if (c == s.back()) {
            c = s[0];
            break;
        }
    }
    cout << s << "\n";
    return;
}

int main() {
    speedup();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}