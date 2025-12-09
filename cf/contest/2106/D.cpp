/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-05-09 19:17:09
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-05-09 20:59:03
 * @FilePath: \Codeforces Round 1020 (Div. 3)\D.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    vector<int> prefix(m + 1, -1);
    prefix[0] = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] >= b[j]) {
            j++;
            prefix[j] = i + 1;
        }
        i++;
    }

    if (prefix[m] != -1 && prefix[m] <= n) {
        cout << 0 << endl;
        return;
    }

    vector<int> suffix(m + 1, -1);
    suffix[m] = n;
    for (int k = m - 1; k >= 0; --k) {
        int pos = suffix[k + 1] - 1;
        while (pos >= 0 && a[pos] < b[k]) {
            pos--;
        }
        if (pos >= 0) {
            suffix[k] = pos;
        } else {
            suffix[k] = -1;
        }
    }

    vector<int> candidates;
    for (int k = 0; k < m; ++k) {
        if (prefix[k] != -1 && suffix[k + 1] != -1) {
            if (prefix[k] <= suffix[k + 1]) {
                candidates.push_back(b[k]);
            }
        }
    }

    if (candidates.empty()) {
        cout << -1 << endl;
    } else {
        cout << *min_element(candidates.begin(), candidates.end()) << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
