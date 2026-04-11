/**
 *    author:  yuyuan
 *    created: 2025-12-25 11:11:18
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

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    string ans = "";
    ans += s[0][0];
    vector<vector<bool>> chosen(n, vector<bool> (n));
    chosen[0][0] = 1;
    for (int k = 1; k <= 2 * n - 2; k++) {
        char mn = 'Z';
        for (int i = 0; k - i >= 0; i++) {
            int j = k - i;
            if (i >= n || j >= n) {
                continue; 
            }
            if (i > 0 && chosen[i - 1][j]) {
                mn = min(mn, s[i][j]); 
            }
            if (j > 0 && chosen[i][j - 1]) {
                mn = min(mn, s[i][j]);
            }
        }
        for (int i = 0; k - i >= 0; i++) {
            int j = k - i;
            if (i >= n || j >= n) {
                continue;
            }
            if (s[i][j] == mn && ((i > 0 && chosen[i - 1][j]) || (j > 0 && chosen[i][j - 1]))) {
                chosen[i][j] = true;
            }
        }
        ans += mn;
    }
    debug(chosen);
    cout << ans;
  
    return 0;
}


