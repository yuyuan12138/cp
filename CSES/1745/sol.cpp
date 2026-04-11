/**
 *    author:  yuyuan
 *    created: 2025-12-26 09:14:52
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

constexpr int N = 1e5;
int dp[N + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        for (int v = N; v >= x; v--) {
            dp[v] |= dp[v - x];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (dp[i]) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    for (int i = 1; i <= N; i++) {
        if (dp[i]) {
            cout << i << ' ';
        }
    }

    return 0;
}

