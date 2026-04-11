#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <bitset>
#include <forward_list>
#include <deque>
#include <set>
#include <tuple>
#include <utility>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <chrono>
#include <random>
#include <complex>
#include <functional>
#include <cassert>
#include <climits>
#include <limits>
#include <tuple>
#include <cstdint>
#include <array>

using namespace std;

#define ll long long

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grids(n + 1, vector<int>(m + 1));
    vector<pair<int, int>> idx_sum(n + 1);
    for (int i = 1; i <= n; i++) {
        int tot = 0;
        for (int j = 1; j <= m; j++) {
            cin >> grids[i][j];
            tot += grids[i][j];
        }
        idx_sum[i] = make_pair(i, tot);
    }
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; };
    sort(idx_sum.begin() + 1, idx_sum.end(), cmp);

    ll ans = 0;
    vector<ll> prefix_sum(n * m + 1);
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix_sum[idx] = prefix_sum[idx - 1] + grids[idx_sum[i].first][j];
            idx++;
        }
    }
    for (int i = 1; i <= n * m; i++) {
        ans += prefix_sum[i];
    }
    cout << ans << "\n";
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