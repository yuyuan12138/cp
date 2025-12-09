/**
 *      author:  yuyuan567
 *      created: 2025-07-30 16:23:26
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

struct Seg {
    int l, r, idx;
};

void solve() {
    int n;
    cin >> n;
    vector<Seg> segs(n);
    for (int i = 0; i < n; i++) {
        cin >> segs[i].l >> segs[i].r;
        segs[i].idx = i;
    }
    vector<int> l(n), r(n);
    sort(all(segs), [=](Seg& a, Seg& b) { return a.l < b.l || a.l == b.l && a.r > b.r; });
    set<int> right;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        auto it = right.lower_bound(segs[i].r);
        if (it != right.end()) {
            r[segs[i].idx] = *it;
        } else {
            r[segs[i].idx] = -1;
        }
        if (i < n - 1 && segs[i].l == segs[i + 1].l && segs[i].r == segs[i + 1].r)
            r[segs[i].idx] = -1;
        right.insert(segs[i].r);
    }
    set<int> left;
    sort(all(segs), [=](Seg& a, Seg& b) { return a.r > b.r || a.r == b.r && a.l < b.l; });
    for (int i = 0; i < n; i++) {
        auto it = left.upper_bound(segs[i].l);
        if (it != left.begin()) {
            l[segs[i].idx] = *(--it);
        } else {
            l[segs[i].idx] = -1;
        }
        if (i < n - 1 && segs[i].l == segs[i + 1].l && segs[i].r == segs[i + 1].r)
            l[segs[i].idx] = -1;
        left.insert(segs[i].l);
    }
    sort(all(segs), [=](Seg& a, Seg& b) { return a.idx < b.idx; });
    for (int i = 0; i < n; i++) {
        if (l[i] == -1 || r[i] == -1)
            cout << "0\n";
        else
            cout << (r[i] - l[i]) - (segs[i].r - segs[i].l) << "\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}