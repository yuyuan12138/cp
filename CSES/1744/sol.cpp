/**
 *    author:  yuyuan
 *    created: 2025-12-25 10:46:28
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

    int a, b;
    cin >> a >> b;
    vector<vector<int>> f(a + 1, vector<int> (b + 1, inf));
    for (int i = 1; i <= a; i++) {
        f[i][1] = i - 1;
    }
    for (int i = 1; i <= b; i++) {
        f[1][i] = i - 1;
    }
    for (int i = 2; i <= a; i++) {
        for (int j = 2; j <= b; j++) {
            if (i == j) {
                f[i][j] = 0;
            }
            for (int k = 1; k <= i - 1; k++) {
                f[i][j] = min(f[i][j], 1 + f[k][j] + f[i - k][j]);
            }
            for (int k = 1; k <= j - 1; k++) {
                f[i][j] = min(f[i][j], 1 + f[i][k] + f[i][j - k]);
            }
        }
    }
    cout << f[a][b];

    return 0;
}


