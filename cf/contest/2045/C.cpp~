/**
 *      author:  yuyuan567
 *      created: 2025-07-28 17:48:50
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
    string a, b;
    cin >> a >> b;
    // vector<int> dis_b(b.size(););
    map<char, int> dis_b;

    for (int i = 0; i < b.size() - 1; i++) {
        dis_b[b[i]] = (int)b.size() - i - 1;
    }
    // debug(dis_b);
    int minx = 0x3f3f3f3f;
    string res = "";
    for (int i = 1; i < a.size(); i++) {
        if (dis_b.find(a[i]) == dis_b.end()) {
            continue;
        }
        if (minx > i + dis_b[a[i]]) {
            // if (i + dis_b[a[i]] + 1 <= 2) {
            //     continue;
            // }
            minx = i + dis_b[a[i]];
            debug(a.substr(0, i + 1));
            debug(b.substr(b.size() - dis_b[a[i]], dis_b[a[i]]));
            res = a.substr(0, i + 1) + b.substr(b.size() - dis_b[a[i]], dis_b[a[i]]);
        }
    }
    if (res.empty()) {
        cout << "-1\n";
    } else {
        cout << res << "\n";
    }
    return;
}

int main() {
    speedup();
    solve();
    return 0;
}