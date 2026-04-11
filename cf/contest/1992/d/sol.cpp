/**
 *      author:  yuyuan567
 *      created: 2025-08-18 14:42:39
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        std::string s;
        std::cin >> s;

        if (m >= n + 1) {
            std::cout << "YES\n";
        } else {
            int cur = -1;
            int cnt = 0;
            bool ok = true;
            int x = -1;
            if (s[0] == 'L') {
                cur = 0;
                x = 0;
            } else {
                for (int i = 0; i < m; i++) {
                    if (s[i] == 'L') {
                        x = i;
                        break;
                    }
                }
                if (x == -1) {
                    for (int i = m - 1; i >= 0; i--) {
                        if (s[i] != 'C') {
                            x = i;
                            break;
                        }
                    }
                }
            }
            if (x == -1) {
                std::cout << "NO\n";
                continue;
            }
            cur = x;
            while (true) {
                if (cur == n) {
                    ok = true;
                    break;
                }
                if (s[cur] == 'L') {
                    if (n + 1 - cur <= m) {
                        ok = true;
                        break;
                    } else {
                        bool flag = false;
                        for (int i = cur + 1; i <= cur + m; i++) {
                            if (s[i] == 'L') {
                                cur = i;
                                flag = true;
                            }
                        }
                        if (flag) {
                            continue;
                        }
                        for (int i = cur + m; i >= cur + 1; i--) {
                            if (s[i] != 'C') {
                                cur = i;
                                flag = true;
                                break;
                            }
                        }

                        if (!flag) {
                            ok = false;
                            break;
                        }
                    }
                } else if (s[cur] == 'W') {
                    if (cnt >= k || s[cur + 1] == 'C') {
                        ok = false;
                        break;
                    } else {
                        cnt ++;
                        cur += 1;
                    }
                } else {
                    ok = false;
                    break;
                }
            }
            debug(ok);
            if (ok) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        }
    }
    return 0;
}
