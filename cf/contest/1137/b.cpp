#include <bits/stdc++.h>

std::vector<int> kmp(std::string s) {
    int n = s.size();
    std::vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) {
            j = f[j];
        }
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    return f;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s, t;
    std::cin >> s >> t;
    bool ok = true;
    int n = s.size(), m = t.size();
    for (int i = 1; i < m; i++) {
        if (t[i] != t[i - 1]) {
            ok = false;
        }
    }
    if (ok) {
        std::sort(s.begin(), s.end());
        std::cout << s << '\n';
    } else {
        std::vector<int> v = kmp(t);
        int cnt = v[m];     
        // std::cerr << cnt << '\n';   
        std::array<int, 2> ct = {0, 0}, cs = {0, 0};
        for (int i = 0; i < n; i++) {
            cs[s[i] - '0']++;
        }
        for (int i = 0; i < m; i++) {
            ct[t[i] - '0']++;
        }
        std::string res;
        int cur = 0;
        while (cs[0] || cs[1]) {
            if (!cs[0]) {
                res += '1';
                cs[1]--;
            } else if (!cs[1]) {
                res += '0';
                cs[0]--;
            } else {
                if (cur == m) {
                    cur = cnt;
                }
                if (t[cur] == '1') {
                    cs[1]--;
                    res += '1';
                } else {
                    cs[0]--;
                    res += '0';
                }
                cur++;
            }
        }
        std::cout << res << '\n';
    }
    return 0;
}