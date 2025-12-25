/**
 *    author:  yuyuan
 *    created: 2025-12-24 23:08:24
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<vector<int>> f(n, vector<int> (m));
    for (int i = 0, x = 0; i < n; i++) {
        if (a[i] == b[0]) {
            x = 1;
        }
        f[i][0] = x;
    }
    for (int i = 0, x = 0; i < m; i++) {
        if (a[0] == b[i]) {
            x = 1;
        }
        f[0][i] = x;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i] == b[j]) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
            f[i][j] = max(f[i][j], f[i - 1][j]);
            f[i][j] = max(f[i][j], f[i][j - 1]);
        }
    }
    cout << f[n - 1][m - 1] << '\n';
    vector<int> ans;
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0) {
        if (a[i] == b[j]) {
            ans.push_back(a[i]);
            i--, j--;
        } else if (j == 0) { 
            i--;
        } else if (i == 0) {
            j--;
        } else if (f[i - 1][j] > f[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans) {
        cout << x << ' ';
    }
    return 0;
}

