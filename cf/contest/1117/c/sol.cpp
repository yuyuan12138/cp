#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    string s;
    cin >> s;

    // check 函数：判断 t 天是否可达
    auto check = [&](long long t) -> bool {
        long long dx = 0, dy = 0;
        for (char c : s) {
            if (c == 'U') dy++;
            if (c == 'D') dy--;
            if (c == 'R') dx++;
            if (c == 'L') dx--;
        }

        long long cycles = t / n;
        long long rem = t % n;

        long long wx = cycles * dx, wy = cycles * dy;
        for (int i = 0; i < rem; i++) {
            if (s[i] == 'U') wy++;
            if (s[i] == 'D') wy--;
            if (s[i] == 'R') wx++;
            if (s[i] == 'L') wx--;
        }

        long long cx = x1 + wx;
        long long cy = y1 + wy;

        long long dist = llabs(x2 - cx) + llabs(y2 - cy);
        return dist <= t;
    };

    long long lo = 1, hi = 1e18, ans = -1;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
