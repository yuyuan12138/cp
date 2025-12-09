#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (count(a.begin(), a.end(), a[0]) == n) {
        cout << "NO\n";
        return;
    }

    multiset<int> st;
    for (int x = 1; x <= n; ++x) st.insert(x);
    vector<int> ans(n, -1);

    for (int i = 0; i < n; ++i) {
        if (st.size() > 1) {
            auto it = st.begin();
            if (*it == a[i]) ++it; 
            ans[i] = *it;
            st.erase(it);
        } else {
            int x = *st.begin();
            if (x != a[i]) {
                ans[i] = x;
                st.erase(st.begin());
            } else {
                bool done = false;
                for (int j = 0; j < i; ++j) {
                    if (a[j] != a[i] && ans[j] != a[i]) {
                        int tmp = ans[j];
                        ans[j] = x;   
                        ans[i] = tmp; 
                        st.erase(st.begin());
                        done = true;
                        break;
                    }
                }
                if (!done) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i + 1 == n ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
