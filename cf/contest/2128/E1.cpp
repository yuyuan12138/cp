/**
 *      author:  yuyuan567
 *      created: 2025-07-27 23:44:35
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
    int n, k;
    cin >> n >> k;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<int> a(n + 1);
    int l = 1, r = n;
    int v = 1, L = 1, R = k;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if ([&]() {
                vector<int> a(n + 1);
                for (int i = 1; i <= n; i++) {
                    if (b[i] >= mid) {
                        a[i] = 1;
                    } else {
                        a[i] = -1;
                    }
                }

                vector<int> prefix_sum(n + 1);
                for (int i = 1; i <= n; i++) {
                    prefix_sum[i] = prefix_sum[i - 1] + a[i];
                }
                int minv1 = 0x3f3f3f3f, minv2 = 0x3f3f3f3f, minidx1 = -1, minidx2 = -1;
                for (int r = 1; r <= n; r++) {
                    if (r - k >= 0) {
                        if ((r - k) % 2) {
                            if (prefix_sum[r - k] < minv2) {
                                minv2 = prefix_sum[r - k];
                                minidx2 = r - k;
                            }
                        } else {
                            if (prefix_sum[r - k] < minv1) {
                                minv1 = prefix_sum[r - k];
                                minidx1 = r - k;
                            }
                        }
                    }

                    if (r % 2) {
                        if (minidx2 != -1 && prefix_sum[r] - minv2 >= 0) {
                            L = minidx2 + 1, R = r;
                            return true;
                        }
                    } else {
                        if (minidx1 != -1 && prefix_sum[r] - minv1 >= 0) {
                            L = minidx1 + 1, R = r;
                            return true;
                        }
                    }
                    if (r % 2) {
                        if (minidx1 != -1 && prefix_sum[r] - minv1 >= 1) {
                            L = minidx1 + 1, R = r;
                            return true;
                        }
                    } else {
                        if (minidx2 != -1 && prefix_sum[r] - minv2 >= 1) {
                            L = minidx2 + 1, R = r;
                            return true;
                        }
                    }
                }
                return false;
            }()) {
            v = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << v << " " << L << " " << R << "\n";
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