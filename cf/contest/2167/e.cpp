#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k, x;
    std::cin >> n >> k >> x;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    auto possible = [&](int d) -> bool {
        i64 cnt = 0;
        int L0 = a[0] - d;
        if (L0 > 0) {
            cnt += L0;
        }

        int prevR = a[0] + d;
        for (int i = 1; i < n; i++) {
            int Li = a[i] - d;
            if (Li - prevR - 1 > 0) {
                cnt += (Li - prevR - 1);
            }
            prevR = std::max(prevR, a[i] + d); 
        }
        if (x - prevR > 0) {
            cnt += (x - prevR);
        }
        return cnt >= k;
    };

    int lo = 0, hi = x, best = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (possible(mid)) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    if (best == -1) {
        for (int i = 0; i < k; i++) {
            std::cout << i << " \n"[i == k - 1];
        }
        return;
    }

    std::vector<int> res;
    int L0 = a[0] - best;
    for (int p = 0; p < L0 && res.size() < k; p++) {
        res.push_back(p);
    }

    int prevR = a[0] + best;
    for (int i = 1; i < n && res.size() < k; i++) {
        int Li = a[i] - best;
        for (int p = prevR + 1; p <= Li - 1 && res.size() < k; p++) {
            res.push_back(p);
        }
        prevR = std::max(prevR, a[i] + best);
    }
    for (int p = prevR + 1; p <= x && res.size() < k; ++p) {
        res.push_back(p);
    }

    for (int p = 0; res.size() < k && p <= x; p++) {
        bool ok = true;
        for (int v : res) {
            if (v == p) { 
                ok = false; 
                break; 
            }
        }
        if (ok) {
            res.push_back(p);
        }
    }

    for (int i = 0; i < k; i++) {
        std::cout << res[i] << " \n"[i == k - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
