/**
 *    author:  yuyuan
 *    created: 2025-12-24 16:39:17
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

constexpr int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    const int n = s.size(), m = t.size();
    
    vector<vector<int>> f(n, vector<int> (m, inf));
    
    for (int i = 0, x = 1; i < n; i++) {
        if (s[i] == t[0]) {
            x = 0;
        }
        f[i][0] = i + x;
    }
    for (int i = 0, x = 1; i < m; i++) {
        if (s[0] == t[i]) {
            x = 0;
        }
        f[0][i] = i + x;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (s[i] == t[j]) {
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            }
            f[i][j] = min({f[i][j], f[i - 1][j - 1] + 1, f[i - 1][j] + 1, f[i][j - 1] + 1});
        }
    }
    cout << f[n - 1][m - 1];

    return 0;
}


