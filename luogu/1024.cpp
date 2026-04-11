#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    auto cal = [&](double x) -> double {
        return a * x * x * x + b * x * x + c * x + d;
    };
    auto get = [&](double l, double r) -> double {
        double ans;
        while (fabs(r - l) > 1e-9) {
            double mid = (l + r) / 2;
            if (cal(l) * cal(mid) < 0) {
                r = mid;
                ans = r;
            } else {
                l = mid;
            }
        }
        return ans;
    };
    vector<double> ans;
    for (double l = -101; l <= 101; l++) {
        if (cal(l) == 0) {
            ans.push_back(l);
            continue;
        }
        if (cal(l) * cal(l + 1) < 0) {
            ans.push_back(get(l, l + 1));
        }
    }
    cout << fixed << setprecision(2);
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << " ";
    }
    return 0;
}
